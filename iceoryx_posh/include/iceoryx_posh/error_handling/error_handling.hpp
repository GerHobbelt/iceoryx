// Copyright (c) 2019 - 2020 by Robert Bosch GmbH. All rights reserved.
// Copyright (c) 2020 - 2022 by Apex.AI Inc. All rights reserved.
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
#ifndef IOX_POSH_ERROR_HANDLING_ERROR_HANDLING_HPP
#define IOX_POSH_ERROR_HANDLING_ERROR_HANDLING_HPP

#include "iceoryx_hoofs/error_handling/error_handler.hpp"

namespace iox
{
// clang-format off
#define POSH_ERRORS(error) \
    error(POSH__ROUDI_PROCESS_SHUTDOWN_FAILED) \
    error(POSH__ROUDI_PROCESS_SEND_VIA_IPC_CHANNEL_FAILED)\
    error(POSH__RUNTIME_FACTORY_IS_NOT_SET) \
    error(POSH__RUNTIME_IS_CREATED_MULTIPLE_TIMES) \
    error(POSH__RUNTIME_PUBLISHER_PORT_NOT_UNIQUE) \
    error(POSH__RUNTIME_SERVICE_DESCRIPTION_FORBIDDEN) \
    error(POSH__RUNTIME_PUBLISHER_PORT_CREATION_UNKNOWN_ERROR) \
    error(POSH__RUNTIME_SUBSCRIBER_PORT_CREATION_UNKNOWN_ERROR) \
    error(POSH__RUNTIME_CLIENT_PORT_CREATION_UNKNOWN_ERROR) \
    error(POSH__RUNTIME_SERVER_PORT_CREATION_UNKNOWN_ERROR) \
    error(POSH__RUNTIME_ROUDI_PUBLISHER_LIST_FULL) \
    error(POSH__RUNTIME_ROUDI_SUBSCRIBER_LIST_FULL) \
    error(POSH__RUNTIME_ROUDI_OUT_OF_CLIENTS) \
    error(POSH__RUNTIME_ROUDI_OUT_OF_SERVERS) \
    error(POSH__RUNTIME_ROUDI_CONDITION_VARIABLE_LIST_FULL) \
    error(POSH__RUNTIME_ROUDI_REQUEST_PUBLISHER_INVALID_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_REQUEST_PUBLISHER_WRONG_IPC_MESSAGE_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_REQUEST_SUBSCRIBER_INVALID_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_REQUEST_SUBSCRIBER_WRONG_IPC_MESSAGE_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_REQUEST_CLIENT_INVALID_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_REQUEST_CLIENT_WRONG_IPC_MESSAGE_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_REQUEST_SERVER_INVALID_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_REQUEST_SERVER_WRONG_IPC_MESSAGE_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_REQUEST_CONDITION_VARIABLE_INVALID_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_REQUEST_CONDITION_VARIABLE_WRONG_IPC_MESSAGE_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_GET_MW_INTERFACE_INVALID_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_GET_MW_INTERFACE_WRONG_IPC_MESSAGE_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_CREATE_NODE_INVALID_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_CREATE_NODE_WRONG_IPC_MESSAGE_RESPONSE) \
    error(POSH__RUNTIME_ROUDI_CONDITION_VARIABLE_CREATION_UNKNOWN_ERROR) \
    error(POSH__RUNTIME_NO_WRITABLE_SHM_SEGMENT) \
    error(POSH__RUNTIME_NO_NAME_PROVIDED) \
    error(POSH__RUNTIME_NAME_NOT_VALID_FILE_NAME) \
    error(POSH__SERVICE_DISCOVERY_UNKNOWN_EVENT_PROVIDED) \
    error(POSH__SERVICE_DISCOVERY_UNKNOWN_MESSAGE_PATTERN_PROVIDED) \
    error(POSH__PORT_MANAGER_PUBLISHERPORT_NOT_UNIQUE) \
    error(POSH__PORT_MANAGER_SERVERPORT_NOT_UNIQUE) \
    error(POSH__PORT_MANAGER_COULD_NOT_ADD_SERVICE_TO_REGISTRY) \
    error(POSH__PORT_MANAGER_INTERNAL_SERVICE_DESCRIPTION_IS_FORBIDDEN) \
    error(POSH__MEMPOOL_POSSIBLE_DOUBLE_FREE) \
    error(POSH__PUBLISHING_EMPTY_SAMPLE) \
    error(POSH__SENDING_EMPTY_REQUEST) \
    error(POSH__SENDING_EMPTY_RESPONSE) \
    error(POSH__SHM_APP_MAPP_ERR) \
    error(POSH__SHM_APP_SEGMENT_MAPP_ERR) \
    error(POSH__SHM_APP_COULD_NOT_REGISTER_PTR_WITH_GIVEN_SEGMENT_ID) \
    error(POSH__SHM_APP_SEGMENT_COUNT_OVERFLOW) \
    error(POSH__INTERFACEPORT_CAPRO_MESSAGE_DISMISSED) \
    error(POPO__BASE_SUBSCRIBER_OVERRIDING_WITH_EVENT_SINCE_HAS_DATA_OR_DATA_RECEIVED_ALREADY_ATTACHED) \
    error(POPO__BASE_SUBSCRIBER_OVERRIDING_WITH_STATE_SINCE_HAS_DATA_OR_DATA_RECEIVED_ALREADY_ATTACHED) \
    error(POPO__BASE_CLIENT_OVERRIDING_WITH_EVENT_SINCE_HAS_RESPONSE_OR_RESPONSE_RECEIVED_ALREADY_ATTACHED) \
    error(POPO__BASE_CLIENT_OVERRIDING_WITH_STATE_SINCE_HAS_RESPONSE_OR_RESPONSE_RECEIVED_ALREADY_ATTACHED) \
    error(POPO__BASE_SERVER_OVERRIDING_WITH_EVENT_SINCE_HAS_REQUEST_OR_REQUEST_RECEIVED_ALREADY_ATTACHED) \
    error(POPO__BASE_SERVER_OVERRIDING_WITH_STATE_SINCE_HAS_REQUEST_OR_REQUEST_RECEIVED_ALREADY_ATTACHED) \
    error(POPO__CHUNK_QUEUE_POPPER_CHUNK_WITH_INCOMPATIBLE_CHUNK_HEADER_VERSION) \
    error(POPO__CHUNK_DISTRIBUTOR_OVERFLOW_OF_QUEUE_CONTAINER) \
    error(POPO__CHUNK_DISTRIBUTOR_CLEANUP_DEADLOCK_BECAUSE_BAD_APPLICATION_TERMINATION) \
    error(POPO__CHUNK_SENDER_INVALID_CHUNK_TO_FREE_FROM_USER) \
    error(POPO__CHUNK_SENDER_INVALID_CHUNK_TO_SEND_FROM_USER) \
    error(POPO__CHUNK_RECEIVER_INVALID_CHUNK_TO_RELEASE_FROM_USER) \
    error(POPO__CHUNK_TRY_LOCK_ERROR) \
    error(POPO__CHUNK_LOCKING_ERROR) \
    error(POPO__CHUNK_UNLOCKING_ERROR) \
    error(POPO__CAPRO_PROTOCOL_ERROR) \
    error(POPO__CLIENT_PORT_INVALID_REQUEST_TO_FREE_FROM_USER) \
    error(POPO__CLIENT_PORT_INVALID_REQUEST_TO_SEND_FROM_USER) \
    error(POPO__CLIENT_PORT_INVALID_RESPONSE_TO_RELEASE_FROM_USER) \
    error(POPO__SERVER_PORT_INVALID_REQUEST_TO_RELEASE_FROM_USER) \
    error(POPO__SERVER_PORT_INVALID_RESPONSE_TO_FREE_FROM_USER) \
    error(POPO__SERVER_PORT_INVALID_RESPONSE_TO_SEND_FROM_USER) \
    error(POPO__SERVER_PORT_NO_CLIENT_RESPONSE_QUEUE_TO_CONNECT) \
    error(POPO__CONDITION_VARIABLE_DATA_FAILED_TO_CREATE_SEMAPHORE) \
    error(POPO__CONDITION_LISTENER_SEMAPHORE_CORRUPTED_IN_WAS_TRIGGERED) \
    error(POPO__CONDITION_LISTENER_SEMAPHORE_CORRUPTED_IN_WAIT) \
    error(POPO__CONDITION_LISTENER_SEMAPHORE_CORRUPTED_IN_TIMED_WAIT) \
    error(POPO__CONDITION_LISTENER_SEMAPHORE_CORRUPTED_IN_RESET) \
    error(POPO__CONDITION_LISTENER_SEMAPHORE_CORRUPTED_IN_DESTROY) \
    error(POPO__CONDITION_NOTIFIER_INDEX_TOO_LARGE) \
    error(POPO__CONDITION_NOTIFIER_SEMAPHORE_CORRUPT_IN_NOTIFY) \
    error(POPO__NOTIFICATION_INFO_TYPE_INCONSISTENCY_IN_GET_ORIGIN) \
    error(POPO__TYPED_UNIQUE_ID_ROUDI_HAS_ALREADY_DEFINED_CUSTOM_UNIQUE_ID) \
    error(POPO__TYPED_UNIQUE_ID_OVERFLOW) \
    error(MEPOO__MEMPOOL_CONFIG_MUST_BE_ORDERED_BY_INCREASING_SIZE) \
    error(MEPOO__MEMPOOL_GETCHUNK_CHUNK_WITHOUT_MEMPOOL) \
    error(MEPOO__MEMPOOL_GETCHUNK_CHUNK_IS_TOO_LARGE) \
    error(MEPOO__MEMPOOL_GETCHUNK_POOL_IS_RUNNING_OUT_OF_CHUNKS) \
    error(MEPOO__MEMPOOL_CHUNKSIZE_MUST_BE_MULTIPLE_OF_CHUNK_MEMORY_ALIGNMENT) \
    error(MEPOO__MEMPOOL_ADDMEMPOOL_AFTER_GENERATECHUNKMANAGEMENTPOOL) \
    error(MEPOO__TYPED_MEMPOOL_HAS_INCONSISTENT_STATE) \
    error(MEPOO__TYPED_MEMPOOL_MANAGEMENT_SEGMENT_IS_BROKEN) \
    error(MEPOO__USER_WITH_MORE_THAN_ONE_WRITE_SEGMENT) \
    error(MEPOO__SEGMENT_COULD_NOT_APPLY_POSIX_RIGHTS_TO_SHARED_MEMORY) \
    error(MEPOO__SEGMENT_UNABLE_TO_CREATE_SHARED_MEMORY_OBJECT) \
    error(MEPOO__SEGMENT_INSUFFICIENT_SEGMENT_IDS) \
    error(MEPOO__INTROSPECTION_CONTAINER_FULL) \
    error(MEPOO__CANNOT_ALLOCATE_CHUNK) \
    error(MEPOO__MAXIMUM_NUMBER_OF_MEMPOOLS_REACHED) \
    error(PORT_POOL__PUBLISHERLIST_OVERFLOW) \
    error(PORT_POOL__SUBSCRIBERLIST_OVERFLOW) \
    error(PORT_POOL__CLIENTLIST_OVERFLOW) \
    error(PORT_POOL__SERVERLIST_OVERFLOW) \
    error(PORT_POOL__INTERFACELIST_OVERFLOW) \
    error(PORT_POOL__NODELIST_OVERFLOW) \
    error(PORT_POOL__CONDITION_VARIABLE_LIST_OVERFLOW) \
    error(PORT_MANAGER__PORT_POOL_UNAVAILABLE) \
    error(PORT_MANAGER__INTROSPECTION_MEMORY_MANAGER_UNAVAILABLE) \
    error(PORT_MANAGER__HANDLE_PUBLISHER_PORTS_INVALID_CAPRO_MESSAGE) \
    error(PORT_MANAGER__HANDLE_SUBSCRIBER_PORTS_INVALID_CAPRO_MESSAGE) \
    error(PORT_MANAGER__HANDLE_CLIENT_PORTS_INVALID_CAPRO_MESSAGE) \
    error(PORT_MANAGER__HANDLE_SERVER_PORTS_INVALID_CAPRO_MESSAGE) \
    error(PORT_MANAGER__NO_PUBLISHER_PORT_FOR_INTERNAL_SERVICE) \
    error(ROUDI_COMPONENTS__SHARED_MEMORY_UNAVAILABLE) \
    error(ROUDI_APP__FAILED_TO_CREATE_SEMAPHORE) \
    error(ROUDI_APP__FAILED_TO_UNLOCK_SEMAPHORE_IN_SIG_HANDLER) \
    error(ROUDI__DEFAULT_ROUDI_MEMORY_FAILED_TO_ADD_SEGMENT_MANAGER_MEMORY_BLOCK) \
    error(ROUDI__DEFAULT_ROUDI_MEMORY_FAILED_TO_ADD_INTROSPECTION_MEMORY_BLOCK) \
    error(ROUDI__PRECONDITIONS_FOR_PROCESS_MANAGER_NOT_FULFILLED) \
    error(MEMORY_PROVIDER__INSUFFICIENT_SEGMENT_IDS) \
    error(ICEORYX_ROUDI_MEMORY_MANAGER__COULD_NOT_ACQUIRE_FILE_LOCK) \
    error(ICEORYX_ROUDI_MEMORY_MANAGER__ROUDI_STILL_RUNNING) \
    error(ICEORYX_ROUDI_MEMORY_MANAGER__FAILED_TO_ADD_PORTPOOL_MEMORY_BLOCK) \
    error(ICEORYX_ROUDI_MEMORY_MANAGER__FAILED_TO_ADD_MANAGEMENT_MEMORY_BLOCK) \
    error(IPC_INTERFACE__UNABLE_TO_CREATE_APPLICATION_CHANNEL) \
    error(IPC_INTERFACE__REG_ROUDI_NOT_AVAILABLE) \
    error(IPC_INTERFACE__REG_UNABLE_TO_WRITE_TO_ROUDI_CHANNEL) \
    error(IPC_INTERFACE__REG_ACK_INVALIG_NUMBER_OF_PARAMS) \
    error(IPC_INTERFACE__REG_ACK_NO_RESPONSE) \
    error(IPC_INTERFACE__APP_WITH_SAME_NAME_STILL_RUNNING) \
    error(IPC_INTERFACE__COULD_NOT_ACQUIRE_FILE_LOCK)

// clang-format on

// DO NOT TOUCH THE ENUM, you can doodle around with the lines above!!!

enum class PoshError : uint32_t
{
    NO_ERROR = POSH_MODULE_IDENTIFIER << ERROR_ENUM_OFFSET_IN_BITS,
    POSH_ERRORS(CREATE_ICEORYX_ERROR_ENUM)
};

const char* asStringLiteral(const PoshError error) noexcept;

} // namespace iox
#endif // IOX_POSH_ERROR_HANDLING_ERROR_HANDLING_HPP
