// Copyright (c) 2023 Franka Robotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#include <agimus_franka/exception.h>
#include <agimus_franka/vacuum_gripper.h>
#include <agimus_research_interface/vacuum_gripper/types.h>
#include <gmock/gmock.h>

#include <atomic>
#include <functional>

#include "helpers.h"
#include "mock_server.h"

using ::testing::_;
using ::testing::Return;

using agimus_franka::IncompatibleVersionException;
using agimus_franka::NetworkException;
using agimus_franka::VacuumGripper;

using agimus_research_interface::vacuum_gripper::Connect;
using agimus_research_interface::vacuum_gripper::VacuumGripperState;

TEST(VacuumGripper, CannotConnectIfNoServerRunning) {
  EXPECT_THROW(VacuumGripper vacuum_gripper("127.0.0.1"), NetworkException)
      << "Shut down local vacuum gripper service to run tests.";
}

TEST(VacuumGripper, CanPerformHandshake) {
  VacuumGripperMockServer server;

  VacuumGripper vacuum_gripper("127.0.0.1");
  EXPECT_EQ(agimus_research_interface::vacuum_gripper::kVersion,
            vacuum_gripper.serverVersion());
}

TEST(VacuumGripper, ThrowsOnIncompatibleLibraryVersion) {
  VacuumGripperMockServer server([](const Connect::Request&) {
    return Connect::Response(Connect::Status::kIncompatibleLibraryVersion);
  });

  EXPECT_THROW(VacuumGripper("127.0.0.1"), IncompatibleVersionException);
}
