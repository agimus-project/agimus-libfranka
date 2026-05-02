// Copyright (c) 2023 Franka Robotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#pragma once

#include <Poco/TemporaryFile.h>

#include <string>

#include "network.h"

namespace agimus_franka {

class LibraryDownloader {
 public:
  LibraryDownloader(Network& network);
  ~LibraryDownloader();

  const std::string& path() const noexcept;

 private:
  Poco::File model_library_file_;
};

};  // namespace agimus_franka
