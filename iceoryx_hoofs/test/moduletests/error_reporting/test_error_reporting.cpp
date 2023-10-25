// Copyright (c) 2023 by Apex.AI Inc. All rights reserved.
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

#include "iceoryx_hoofs/error_reporting/custom/error_kind.hpp"
#include "iceoryx_hoofs/error_reporting/error_kind.hpp"
#include "iceoryx_hoofs/error_reporting/errors.hpp"
#include "iceoryx_hoofs/error_reporting/source_location.hpp"
#include "moduletests/error_reporting/module_a/errors.hpp"
#include "test.hpp"
#include <gtest/gtest.h>

#include "iceoryx_hoofs/error_reporting/custom/error_reporting.hpp"
#include "iceoryx_hoofs/testing/error_reporting/test_support.hpp"

#include "module_a/errors.hpp"

namespace
{

using namespace ::testing;
using namespace iox::err;

constexpr auto CODE{module_a::errors::Code::OutOfBounds};
constexpr module_a::errors::Error ERROR{CODE};

// Here we test the custom API that the public API forwards to.
// To observe the side effects, this requires using the TestErrorHandler (similar to the public API).

class ErrorReporting_test : public Test
{
  public:
    void SetUp() override
    {
        /// @todo iox-#1032 this should be done for all tests (using Gtest hooks) in integration
        iox::testing::ErrorHandler::instance().reset();
    }

    void TearDown() override
    {
    }
};

TEST_F(ErrorReporting_test, panicWorks)
{
    ::testing::Test::RecordProperty("TEST_ID", "5aca0c31-1c1b-4004-bd41-b4b400258c12");

    auto f = []() { panic(CURRENT_SOURCE_LOCATION); };

    iox::testing::runInTestThread(f);

    EXPECT_PANIC();
}

TEST_F(ErrorReporting_test, panicWithMessageWorks)
{
    ::testing::Test::RecordProperty("TEST_ID", "f0e44332-ea9b-4041-88f4-8155ccf7538d");

    auto f = []() { panic(CURRENT_SOURCE_LOCATION, "message"); };

    iox::testing::runInTestThread(f);

    EXPECT_PANIC();
}

TEST_F(ErrorReporting_test, reportNonFatalErrorWorks)
{
    ::testing::Test::RecordProperty("TEST_ID", "1a1cec1b-5297-487a-bb95-e80af99886b6");

    auto f = []() { report(CURRENT_SOURCE_LOCATION, RUNTIME_ERROR, ERROR); };

    iox::testing::runInTestThread(f);

    EXPECT_NO_PANIC();
    EXPECT_ERROR(CODE);
}

TEST_F(ErrorReporting_test, reportFatalErrorWorks)
{
    ::testing::Test::RecordProperty("TEST_ID", "");

    auto f = []() { report(CURRENT_SOURCE_LOCATION, FATAL, ERROR); };

    iox::testing::runInTestThread(f);

    // panic is not required at this level as we cannot trust the custom API to enforce it
    // While we could also call panic in the custom API, there should only be one decison point
    // for it at a higher level
    EXPECT_ERROR(CODE);
}

TEST_F(ErrorReporting_test, reportPreconditionViolatonWorks)
{
    ::testing::Test::RecordProperty("TEST_ID", "feb63aa0-1921-408a-a887-abbb99522b31");

    auto f = []() {
        auto v = Violation::createPreconditionViolation();
        report(CURRENT_SOURCE_LOCATION, PRECONDITION_VIOLATION, v);
    };

    iox::testing::runInTestThread(f);

    EXPECT_PRECONDITION_VIOLATION();
}

// the message is printed but otherwise lost, so we cannot check for it
TEST_F(ErrorReporting_test, reportPreconditionViolatonWithMessageWorks)
{
    ::testing::Test::RecordProperty("TEST_ID", "9228c696-d555-49c5-ade1-b65d16159e8c");

    auto f = []() {
        auto v = Violation::createPreconditionViolation();
        report(CURRENT_SOURCE_LOCATION, PRECONDITION_VIOLATION, v, "message");
    };

    iox::testing::runInTestThread(f);

    EXPECT_PRECONDITION_VIOLATION();
}

TEST_F(ErrorReporting_test, reportAssumptionViolatonWorks)
{
    ::testing::Test::RecordProperty("TEST_ID", "f866b43a-3a88-4097-adde-4704fc1a5e8f");

    auto f = []() {
        auto v = Violation::createAssumptionViolation();
        report(CURRENT_SOURCE_LOCATION, ASSUMPTION_VIOLATION, v);
    };

    iox::testing::runInTestThread(f);

    EXPECT_ASSUMPTION_VIOLATION();
}

// the message is printed but otherwise lost, so we cannot check for it
TEST_F(ErrorReporting_test, reportAssumptionViolatonWithMessageWorks)
{
    ::testing::Test::RecordProperty("TEST_ID", "1cccd0f7-c944-4904-bf64-6f575ea13b85");

    auto f = []() {
        auto v = Violation::createAssumptionViolation();
        report(CURRENT_SOURCE_LOCATION, ASSUMPTION_VIOLATION, v, "message");
    };

    iox::testing::runInTestThread(f);

    EXPECT_ASSUMPTION_VIOLATION();
}

} // namespace