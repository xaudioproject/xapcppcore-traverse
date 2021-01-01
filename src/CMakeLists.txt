#
#  Copyright 2019 - 2021 The XOrange Studio. All rights reserved.
#  Use of this source code is governed by a BSD-style license that can be
#  found in the LICENSE.md file.
#

#  Project name.
project(xapcppcore-traverse VERSION 1.0.0)

#  Add static library.
add_library(
    xapcppcore-traverse-static
    STATIC

    traverse.cc
    error.cc

    #
    #  jsoncpp.
    #
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_tool.h
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_reader.cpp
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_valueiterator.inl
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_value.cpp
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_writer.cpp
)
target_include_directories(
    xapcppcore-traverse-static
    PUBLIC 
    ${CMAKE_BINARY_DIR}/include
)
target_include_directories(
    xapcppcore-traverse-static
    PRIVATE
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/include
)

#  Added shared library.
add_library(
    xapcppcore-traverse
    SHARED

    traverse.cc
    error.cc

    #
    #  jsoncpp.
    #
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_tool.h
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_reader.cpp
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_valueiterator.inl
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_value.cpp
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/src/lib_json/json_writer.cpp
)
target_include_directories(
    xapcppcore-traverse
    PUBLIC 
    ${CMAKE_BINARY_DIR}/include
)
target_include_directories(
    xapcppcore-traverse
    PRIVATE
    ${CMAKE_BINARY_DIR}/third_party/jsoncpp/include
)

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()