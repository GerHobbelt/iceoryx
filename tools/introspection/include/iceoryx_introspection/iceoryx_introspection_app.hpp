// Copyright (c) 2019 by Robert Bosch GmbH. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0
#ifndef IOX_TOOLS_ICEORYX_INTROSPECTION_ICEORYX_INTROSPECTION_APP_HPP
#define IOX_TOOLS_ICEORYX_INTROSPECTION_ICEORYX_INTROSPECTION_APP_HPP

#include "iceoryx_introspection/introspection_app.hpp"

namespace iox
{
namespace client
{
namespace introspection
{
class IceOryxIntrospectionApp : public IntrospectionApp
{
  public:
    /// @brief constructor to create the introspection
    /// @param[in] argc forwarding of command line arguments
    /// @param[in] argv forwarding of command line arguments
    IceOryxIntrospectionApp(int argc, const char* argv[]) noexcept;

    /// @brief starts the execution of introspection
    void run() noexcept override;
};

} // namespace introspection
} // namespace client
} // namespace iox

#endif // IOX_TOOLS_ICEORYX_INTROSPECTION_ICEORYX_INTROSPECTION_APP_HPP
