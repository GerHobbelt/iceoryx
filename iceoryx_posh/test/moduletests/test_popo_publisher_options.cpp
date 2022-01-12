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

#include "iceoryx_posh/popo/publisher_options.hpp"

#include "test.hpp"

namespace
{
using namespace ::testing;

TEST(PublisherOptions_test, SerializationRoundTripIsSuccessful)
{
    iox::popo::PublisherOptions defaultOptions;
    iox::popo::PublisherOptions testOptions;

    testOptions.historyCapacity = 42;
    testOptions.nodeName = "hypnotoad";
    testOptions.offerOnCreate = false;
    testOptions.subscriberTooSlowPolicy = iox::popo::SubscriberTooSlowPolicy::WAIT_FOR_SUBSCRIBER;

    iox::popo::PublisherOptions::deserialize(testOptions.serialize())
        .and_then([&](auto& roundTripOptions) {
            EXPECT_THAT(roundTripOptions.historyCapacity, Ne(defaultOptions.historyCapacity));
            EXPECT_THAT(roundTripOptions.historyCapacity, Eq(testOptions.historyCapacity));

            EXPECT_THAT(roundTripOptions.nodeName, Ne(defaultOptions.nodeName));
            EXPECT_THAT(roundTripOptions.nodeName, Eq(testOptions.nodeName));

            EXPECT_THAT(roundTripOptions.offerOnCreate, Ne(defaultOptions.offerOnCreate));
            EXPECT_THAT(roundTripOptions.offerOnCreate, Eq(testOptions.offerOnCreate));

            EXPECT_THAT(roundTripOptions.subscriberTooSlowPolicy, Ne(defaultOptions.subscriberTooSlowPolicy));
            EXPECT_THAT(roundTripOptions.subscriberTooSlowPolicy, Eq(testOptions.subscriberTooSlowPolicy));
        })
        .or_else([&](auto&) { FAIL() << "Serialization/Deserialization of PublisherOptions failed!"; });
}

TEST(PublisherOptions_test, DeserializingBogusDataFails)
{
    const auto bogusSerialization = iox::cxx::Serialization::create("hypnotoad", "brain slug", "rock star");
    iox::popo::PublisherOptions::deserialize(bogusSerialization)
        .and_then([&](auto&) { FAIL() << "Deserialization is expected to fail!"; })
        .or_else([&](auto&) { SUCCEED(); });
}

TEST(PublisherOptions_test, DeserializingInvalidSubscriberTooSlowPolicyFails)
{
    constexpr uint64_t HISTORY_CAPACITY{42U};
    const iox::NodeName_t NODE_NAME{"harr-harr"};
    constexpr bool OFFER_ON_CREATE{true};
    constexpr std::underlying_type_t<iox::popo::SubscriberTooSlowPolicy> SUBSCRIBER_TOO_SLOW_POLICY{111};

    const auto serialized =
        iox::cxx::Serialization::create(HISTORY_CAPACITY, NODE_NAME, OFFER_ON_CREATE, SUBSCRIBER_TOO_SLOW_POLICY);
    iox::popo::PublisherOptions::deserialize(serialized)
        .and_then([&](auto&) { FAIL() << "Deserialization is expected to fail!"; })
        .or_else([&](auto&) { SUCCEED(); });
}

} // namespace