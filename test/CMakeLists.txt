#
#  Copyright 2019 - 2020 The XOrange Studio. All rights reserved.
#  Use of this source code is governed by a BSD-style license that can be
#  found in the LICENSE.md file.
#

#
#  Private functions.
#

function(add_executable_dependencies PROJ_NAME)

    #
    #  xapcppcore-jsontraverse
    #
    target_include_directories(
        ${PROJ_NAME}
        PRIVATE
        ${CMAKE_BINARY_DIR}/include
    )
    target_link_libraries(
        ${PROJ_NAME}
        ${CMAKE_BINARY_DIR}/lib/libxapcppcore-traverse-static.a
    )

endfunction()

#  Test case.
add_executable(traverse-unittest traverse.unittest.cc)

add_executable_dependencies(traverse-unittest)

add_test(
    NAME                xaptest-traverse
    COMMAND             ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/traverse-unittest
    WORKING_DIRECTORY   ${CMAKE_BINARY_DIR}
)

#  Timeout.
set_tests_properties(xaptest-traverse PROPERTIES TIMEOUT 1)
