// Copyright (c) 2022 by Apex.AI Inc. All rights reserved.
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

#include "iceoryx_hoofs/internal/cli/command_line_option_value.hpp"

namespace iox
{
namespace cli
{
namespace internal
{
const char* CommandLineOptionValue::binaryName() const noexcept
{
    return m_binaryName;
}

bool CommandLineOptionValue::isSwitchSet(const OptionName_t& switchName) const noexcept
{
    for (const auto& a : m_arguments)
    {
        if (a.isSwitch && a.hasOptionName(switchName))
        {
            return true;
        }
    }
    return false;
}
} // namespace internal
} // namespace cli
} // namespace iox
