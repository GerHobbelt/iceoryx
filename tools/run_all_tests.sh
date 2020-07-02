#!/bin/bash

# Copyright (c) 2019 by Robert Bosch GmbH. All rights reserved.
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

# This file runs all tests for Ice0ryx

COMPONENTS="utils posh dds_gateway"
GTEST_FILTER="*"
BASE_DIR=$PWD

for arg in "$@"
do 
    case "$arg" in
        "disable-timing-tests")
            GTEST_FILTER="-*.TimingTest_*"
            ;;
        "only-timing-tests")
            GTEST_FILTER="*.TimingTest_*"
            ;;
        *)
            echo ""
            echo "Test script for iceoryx."
            echo "By default all module-, integration- and componenttests are executed."
            echo ""
            echo "Usage: $0 [OPTIONS]"
            echo "Options:"
            echo "      disable-timing-tests        Disables all timing tests"
            echo "      only-timing-tests           Runs only timing tests"
            echo ""
            exit -1
            ;;
    esac
done 

#check if this script is sourced by another script,
# if yes then exit properly, so the other script can use this
# scripts definitions
[[ "${#BASH_SOURCE[@]}" -gt "1" ]] && { return 0; }

if [ -z "$TEST_RESULTS_DIR" ]
then
    TEST_RESULTS_DIR="$(pwd)/testresults"
fi

mkdir -p "$TEST_RESULTS_DIR"

echo ">>>>>> Running Ice0ryx Tests <<<<<<"

set -e

for COMPONENT in $COMPONENTS; do
    echo ""
    echo "######################## executing moduletests & componenttests for $COMPONENT ########################"
    cd $BASE_DIR/$COMPONENT/test

    # Runs only tests available for the given component
    [ -f ./"$COMPONENT"_moduletests ]      && ./"$COMPONENT"_moduletests --gtest_filter="${GTEST_FILTER}" --gtest_output="xml:$TEST_RESULTS_DIR/"$COMPONENT"_ModuleTestResults.xml"
    [ -f ./"$COMPONENT"_componenttests ]   && ./"$COMPONENT"_componenttests --gtest_filter="${GTEST_FILTER}" --gtest_output="xml:$TEST_RESULTS_DIR/"$COMPONENT"_ComponenttestTestResults.xml"
    [ -f ./"$COMPONENT"_integrationtests ] && ./"$COMPONENT"_integrationtests --gtest_filter="${GTEST_FILTER}" --gtest_output="xml:$TEST_RESULTS_DIR/"$COMPONENT"_IntegrationTestResults.xml"

done

# do not start RouDi while the module and componenttests are running;
# they might do things which hurts RouDi, like in the roudi_shm test where named semaphores are opened and closed

echo ">>>>>> Finished Running Iceoryx Tests <<<<<<"
