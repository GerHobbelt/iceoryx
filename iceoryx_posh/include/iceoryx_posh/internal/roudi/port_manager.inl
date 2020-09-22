// Copyright (c) 2020 by Robert Bosch GmbH. All rights reserved.
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
#ifndef IOX_POSH_INTERNAL_ROUDI_PORT_MANAGER_INL
#define IOX_POSH_INTERNAL_ROUDI_PORT_MANAGER_INL

namespace iox
{
namespace roudi
{
template <typename T, cxx::enable_if_t<std::is_same<T, iox::build::OneToManyPolicy>::value>*>
inline bool PortManager::hasDuplicatePublisher(const capro::ServiceDescription& service,
                                               const ProcessName_t& processName) noexcept
{
    // check if the publisher is already in the list
    for (auto publisherPortData : m_portPool->getPublisherPortDataList())
    {
        popo::PublisherPortRouDi publisherPort(publisherPortData);
        if (service == publisherPort.getCaProServiceDescription())
        {
            LogWarn() << "Process '" << processName
                      << "' tried to register an unique PublisherPort which is already used by '"
                      << publisherPortData->m_processName << "' with service '"
                      << service.operator cxx::Serialization().toString() << "'.";
            errorHandler(Error::kPOSH__PORT_MANAGER_PUBLISHERPORT_NOT_UNIQUE, nullptr, ErrorLevel::MODERATE);
            return true;
        }
    }
    return false;
}

template <typename T, cxx::enable_if_t<std::is_same<T, iox::build::ManyToManyPolicy>::value>*>
inline bool PortManager::hasDuplicatePublisher(const capro::ServiceDescription& service [[gnu::unused]],
                                               const ProcessName_t& processName [[gnu::unused]]) noexcept
{
    // Duplicates are allowed when using n:m policy
    return false;
}

} // namespace roudi
} // namespace iox

#endif // IOX_POSH_INTERNAL_ROUDI_PORT_MANAGER_INL
