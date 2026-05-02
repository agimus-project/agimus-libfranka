// Copyright (c) 2023 Franka Robotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#include <agimus_franka/exception.h>
#include <agimus_franka/gripper.h>
#include <agimus_research_interface/gripper/types.h>
#include <gmock/gmock.h>

#include <atomic>
#include <functional>

#include "helpers.h"
#include "mock_server.h"

using ::testing::_;
using ::testing::Return;

using agimus_franka::Gripper;
using agimus_franka::IncompatibleVersionException;
using agimus_franka::NetworkException;

using agimus_research_interface::gripper::Connect;
using agimus_research_interface::gripper::GripperState;

TEST(Gripper, CannotConnectIfNoServerRunning) {
  EXPECT_THROW(Gripper gripper("127.0.0.1"), NetworkException)
      << "Shut down local gripper service to run tests.";
}

TEST(Gripper, CanPerformHandshake) {
  GripperMockServer server;

  Gripper gripper("127.0.0.1");
  EXPECT_EQ(agimus_research_interface::gripper::kVersion,
            gripper.serverVersion());
}

TEST(Gripper, ThrowsOnIncompatibleLibraryVersion) {
  GripperMockServer server([](const Connect::Request&) {
    return Connect::Response(Connect::Status::kIncompatibleLibraryVersion);
  });

  EXPECT_THROW(Gripper("127.0.0.1"), IncompatibleVersionException);
}
