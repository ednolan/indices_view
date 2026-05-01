# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

find_package(GTest REQUIRED)

add_executable(beman.indices_view.tests.basic)
target_sources(beman.indices_view.tests.basic PRIVATE basic.test.cpp)
target_link_libraries(
    beman.indices_view.tests.basic
    PRIVATE beman::indices_view GTest::gtest GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(beman.indices_view.tests.basic DISCOVERY_TIMEOUT 60)
