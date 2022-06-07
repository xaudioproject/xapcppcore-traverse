//
//  Copyright 2019 - 2022 The XOrange Studio. All rights reserved.
//  Use of this source code is governed by a BSD-style license that can be
//  found in the LICENSE.md file.
//

//
//  Imports.
//
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <xap/core/json/error.h>

namespace xap {
namespace core {
namespace json {

/**
 *  Construct the object.
 * 
 *  @param message
 *      The error message.
 *  @param code
 *      The error code.
 */
Exception::Exception(
    const char        *message,
    const uint16_t     code,
    const char        *path
) :
    m_message(message),
    m_code(code),
    m_path(path)
{}

/**
 *  Construct (Copy) the object.
 * 
 *  @param src
 *      The source object.
 */
Exception::Exception(
    const xap::core::json::Exception &src
) :
    m_message(src.m_message),
    m_code(src.m_code),
    m_path(src.m_path)
{}

/**
 *  Destruct the object.
 */
Exception::~Exception() noexcept {
    //  Do nothing.
}

//
//  Public methods.
//

/**
 *  Get the error message.
 * 
 *  @return
 *      The error message.
 */
const char* Exception::what() const noexcept {
    return this->m_message.c_str();
}

/**
 *  Get the error code.
 * 
 *  @return
 *      The error code.
 */
uint16_t Exception::get_code() const noexcept {
    return this->m_code;
}

/**
 *  Get the path.
 * 
 *  @return
 *      The path.
 */
const char* Exception::get_path() const noexcept {
    return this->m_path.c_str();
}

}  //  namespace json
}  //  namespace core
}  //  namespace xap