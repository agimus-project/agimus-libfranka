// Copyright (c) 2023 Franka Robotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#include "agimus_franka/gripper_state.h"

#include <cstring>

namespace agimus_franka {

std::ostream& operator<<(std::ostream& ostream,
                         const agimus_franka::GripperState& gripper_state) {
  ostream << "{\"width\": " << gripper_state.width
          << ", \"max_width\": " << gripper_state.max_width
          << ", \"is_grasped\": " << gripper_state.is_grasped
          << ", \"temperature\": " << gripper_state.temperature
          << ", \"time\": " << gripper_state.time.toSec() << "}";
  return ostream;
}

}  // namespace agimus_franka
