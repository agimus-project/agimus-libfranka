// Copyright (c) 2023 Franka Robotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE

#include <agimus_franka/active_torque_control.h>
#include <agimus_franka/exception.h>
#include <agimus_franka/robot.h>

#include "robot_impl.h"

namespace agimus_franka {

void ActiveTorqueControl::writeOnce(const Torques& control_input) {
  if (control_finished) {
    throw agimus_franka::ControlException(
        "writeOnce must not be called after the motion has finished.");
  }

  if (control_input.motion_finished) {
    agimus_research_interface::robot::MotionGeneratorCommand motion_command{};
    motion_command.dq_c = {0, 0, 0, 0, 0, 0, 0};
    agimus_research_interface::robot::ControllerCommand controller_command =
        robot_impl->createControllerCommand(control_input);

    robot_impl->finishMotion(motion_id, &motion_command, &controller_command);
    control_finished = true;
    control_lock.unlock();
    return;
  }

  robot_impl->writeOnce(control_input);
}

}  // namespace agimus_franka
