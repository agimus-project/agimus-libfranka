# libagimus_franka: C++ library for Franka Robotics research robots

[![Build Status][travis-status]][travis]
[![codecov][codecov-status]][codecov]

With this library, you can control research versions of Franka Robotics robots. See the [Franka Control Interface (FCI) documentation][fci-docs] for more information about what `libagimus_franka` can do and how to set it up. The [generated API documentation][api-docs] also gives an overview of its capabilities.

## Note

This is a fork of the https://github.com/tingelst/libagimus_franka which is a fork of https://github.com/agimus_frankaemika/libagimus_franka.
This library is originally deprecated for the oldest robots. Hence in order to
prevent the original owners to delete this package we created this fork.

This library has been tested with ROS2 on Panda robot in LAAS-CNRS and CTU-Prague.

## License

`libagimus_franka` is licensed under the [Apache 2.0 license][apache-2.0].

[apache-2.0]: https://www.apache.org/licenses/LICENSE-2.0.html
[api-docs]: https://agimus_frankaemika.github.io/libagimus_franka
[fci-docs]: https://agimus_frankaemika.github.io/docs
[travis-status]: https://travis-ci.org/agimus_frankaemika/libagimus_franka.svg?branch=master
[travis]: https://travis-ci.org/agimus_frankaemika/libagimus_franka
[codecov-status]: https://codecov.io/gh/agimus_frankaemika/libagimus_franka/branch/master/graph/badge.svg
[codecov]: https://codecov.io/gh/agimus_frankaemika/libagimus_franka
