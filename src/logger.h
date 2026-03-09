// Copyright (c) 2023 Franka Robotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#pragma once

#include <deque>
#include <string>
#include <vector>

#include <agimus_franka/log.h>
#include <agimus_franka/robot_state.h>
#include <agimus_research_interface/robot/rbk_types.h>

namespace agimus_franka {

class Logger {
 public:
  explicit Logger(size_t log_size);

  void log(const RobotState& state, const agimus_research_interface::robot::RobotCommand& command);

  std::vector<agimus_franka::Record> flush();

 private:
  std::vector<RobotState> states_;
  std::vector<agimus_research_interface::robot::RobotCommand> commands_;
  size_t ring_front_{0};
  size_t ring_size_{0};

  const size_t log_size_;  // NOLINT(readability-identifier-naming)
};

}  // namespace agimus_franka
