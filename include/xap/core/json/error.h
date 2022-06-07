//
//  Copyright 2019 - 2022 The XOrange Studio. All rights reserved.
//  Use of this source code is governed by a BSD-style license that can be
//  found in the LICENSE.md file.
//

#ifndef XAP_CORE_JSON_ERROR_H__
#define XAP_CORE_JSON_ERROR_H__

//
//  Imports.
//
#include <stdint.h>
#include <stdlib.h>
#include <string>

namespace xap{
namespace core {
namespace json {

//
//  Constants.
//

//  Error code.
const static uint16_t ERROR_PARAMETER        = 5201U;
const static uint16_t ERROR_TYPE             = 5202U;
const static uint16_t ERROR_BUG              = 5203U;
const static uint16_t ERROR_NOTFIND          = 5204U;
const static uint16_t ERROR_OVERFLOW         = 5205U;

//
//  Classes.
//

class Exception: public std::exception {
public:
    //
    //  Constructor & destructor.
    //

    /**
     *  Construct the object.
     * 
     *  @param message
     *      The error message.
     *  @param code
     *      The error code.
     */
    Exception(
        const char        *message,
        const uint16_t     code,
        const char        *path
    );

    /**
     *  Construct (Copy) the object.
     * 
     *  @param src
     *      The source object.
     */
    Exception(
        const Exception &src
    );

    /**
     *  Destruct the object.
     */
    virtual ~Exception() noexcept;

    /**
     *  Get the error message.
     * 
     *  @return
     *      The error message.
     */
    virtual const char* what() const noexcept;

    /**
     *  Get the error code.
     * 
     *  @return
     *      The error code.
     */
    virtual uint16_t get_code() const noexcept;

    /**
     *  Get the path.
     * 
     *  @return
     *      The path.
     */
    virtual const char* get_path() const noexcept;

private:
    //
    //  Members.
    //

    //  The error message.
    std::string m_message;
    uint16_t    m_code;
    std::string m_path;
};

}  //  namespace json
}  //  namespace core
}  //  namespace xap

#endif  //  #ifndef XAP_CORE_JSON_ERROR_H__
