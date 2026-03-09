// Copyright (c) 2023 Franka Robotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE

#include <agimus_franka/active_control.h>
#include <agimus_franka/exception.h>
#include <agimus_franka/robot.h>
#include <agimus_research_interface/robot/rbk_types.h>

#include "robot_impl.h"

namespace agimus_franka {

ActiveControl::ActiveControl(std::shared_ptr<Robot::Impl> robot_impl,
                             uint32_t motion_id,
                             std::unique_lock<std::mutex> control_lock)
    : robot_impl(std::move(robot_impl)),
      motion_id(motion_id),
      control_lock(std::move(control_lock)),
      control_finished(false) {}

ActiveControl::~ActiveControl() {
  if (!control_finished) {
    robot_impl->cancelMotion(motion_id);
  }
}

std::pair<RobotState, Duration> ActiveControl::readOnce() {
  auto robot_state = robot_impl->readOnce();
  robot_impl->throwOnMotionError(robot_state, motion_id);

  if (!last_read_access.has_value()) {
    last_read_access = robot_state.time;
  }

  auto time_since_last_read = robot_state.time - last_read_access.value();
  last_read_access = robot_state.time;

  return std::make_pair(robot_state, time_since_last_read);
}

}  // namespace agimus_franka
