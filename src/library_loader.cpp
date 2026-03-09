// Copyright (c) 2023 Franka Robotics GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#include "library_loader.h"

#include <Poco/Exception.h>

#include <agimus_franka/exception.h>

using namespace std::string_literals;  // NOLINT(google-build-using-namespace)

namespace agimus_franka {

LibraryLoader::LibraryLoader(const std::string& filepath) try {
  library_.load(filepath);
} catch (const Poco::LibraryAlreadyLoadedException& e) {
  throw ModelException("libagimus_franka: Model library already loaded"s);
} catch (const Poco::LibraryLoadException& e) {
  throw ModelException("libagimus_franka: Cannot load model library: "s + e.what());
} catch (const Poco::Exception& e) {
  throw ModelException("libagimus_franka: Error while loading library: "s + e.what());
}

LibraryLoader::~LibraryLoader() {
  try {
    library_.unload();
  } catch (...) {
  }
}

void* LibraryLoader::getSymbol(const std::string& symbol_name) try {
  return library_.getSymbol(symbol_name);
} catch (const Poco::NotFoundException& e) {
  throw ModelException("libagimus_franka: Symbol cannot be found: "s + e.what());
} catch (const Poco::Exception& e) {
  throw ModelException("libagimus_franka: Error while fetching symbols: "s + e.what());
}

}  // namespace agimus_franka
