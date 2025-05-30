# Copyright (c) 2019 - 2020 by Robert Bosch GmbH. All rights reserved.
# Copyright (c) 2020 - 2022 by Apex.AI Inc. All rights reserved.
# Copyright (c) 2024 by ekxide IO GmbH. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.16)
project(example_experimental_node)

include(GNUInstallDirs)

find_package(iceoryx_platform REQUIRED)
find_package(iceoryx_posh CONFIG REQUIRED)
find_package(iceoryx_hoofs CONFIG REQUIRED)

include(IceoryxPackageHelper)
include(IceoryxPlatform)
include(IceoryxPlatformSettings)

iox_add_executable(
    TARGET  iox-cpp-node-publisher
    FILES   ./iox_cpp_node_publisher.cpp
    LIBS    iceoryx_posh::iceoryx_posh
)

iox_add_executable(
    TARGET  iox-cpp-node-subscriber
    FILES   ./iox_cpp_node_subscriber.cpp
    LIBS    iceoryx_posh::iceoryx_posh
)

iox_add_executable(
    TARGET  iox-cpp-node-server
    FILES   ./iox_cpp_node_server.cpp
    LIBS    iceoryx_posh::iceoryx_posh
)

iox_add_executable(
    TARGET  iox-cpp-node-client
    FILES   ./iox_cpp_node_client.cpp
    LIBS    iceoryx_posh::iceoryx_posh
)
