//
//  Copyright 2019 - 2021 The XOrange Studio. All rights reserved.
//  Use of this source code is governed by a BSD-style license that can be
//  found in the LICENSE.md file.
//

#ifndef XAP_CORE_JSON_TRAVERSE_H__
#define XAP_CORE_JSON_TRAVERSE_H__

//
//  Imports.
//
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <xap/core/json/build.h>

namespace xap{
namespace core {
namespace json {

//
//  Declare.
//
class TraversePrivate;

//
//  Enum.
//
enum Type: uint8_t {
    numeric,
    boolean,
    string,
    array,
    object,
    null
};

//
//  Classes.
//

/**
 *  Traverse.
 */
class Traverse {

public:

    /**
     *  Construct the object.
     * 
     *  @throw xap::core::json::Exception
     *      Raised if JSON parsing was failed (ERROR_PARAMETER).
     *  @param data
     *      The JSON data.
     *  @param datalen
     *      The length of JSON data.
     *  @param path
     *      The path.
     */
    Traverse(
        const uint8_t *data, 
        const size_t datalen,
        const std::string &path = "/"
    );

    /**
     *  Construct the object.
     * 
     *  @throw xap::core::json::Exception
     *      Raised if JSON parsing was failed (ERROR_PARAMETER).
     *  @param data
     *      The data.
     *  @param datalen
     *      The length of data.
     *  @param path
     *      The path.
     */
    Traverse(
        const char *data,
        const size_t datalen,
        const std::string &path = "/"
    );

    /**
     *  Construct the object.
     * 
     *  @throw xap::core::json::Exception
     *      Raised if JSON parsing was failed (ERROR_PARAMETER).
     *  @param json_string
     *      The JSON string.
     *  @param path
     *      The path.
     */
    Traverse(
        std::string json_string,
        const std::string &path = "/"
    );

    /**
     *  Construct (Copy) the object.
     * 
     *  @param src
     *      The source.
     */
    Traverse(
        const Traverse &src
    );

    /**
     *  Destruct the object.
     */
    virtual ~Traverse() noexcept;

    //
    //  Public methods.
    //

    /**
     *  Check the type of inner object.
     * 
     *  @param type
     *      The expected type.
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &type_of(const xap::core::json::Type &type);

    /**
     *  Get the type of inner object.
     * 
     *  @return
     *      The type.
     */
    xap::core::json::Type type() const noexcept;

    /**
     *  Assume that the inner object is numeric.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not numeric.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &numeric();

    /**
     *  Assume that the inner object is an integer.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an integer.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &integer();

    /**
     *  Assume that the inner object is an unsigned integer.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an unsigned integer.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &unsigned_integer();

#if defined(XAPCORE_JSON_INT64)

    /**
     *  Assume that the inner object is a 64-bit integer.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not a 64-bit integer.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &integer_64();

    /**
     *  Assume that the inner object is an unsigned 64-bit integer.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an unsigned 64-bit integer.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &unsigned_integer_64();

#endif  //  #if defined(XAPCORE_JSON_INT64)

    /**
     *  Assume that the inner object is a boolean.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not a boolean.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &boolean();

    /**
     *  Assume that the inner object is a string.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not a string.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &string();

    /**
     *  Assume that the inner object is an array.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an array.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &array();

    /**
     *  Assume that the inner object is a JSON object.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an object.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &object();

    /**
     *  Assume that the inner object is not null.
     * 
     *  @throw xap::core::json::Exception
     *      Raised if value is null (xap::core::json::ERROR_TYPE).
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &not_null();

    /**
     *  Check whether the inner object is null.
     * 
     *  @return
     *      True if so.
     */
    bool is_null() const noexcept;

    /**
     *  Go to sub directory.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an object.
     *  
     *          - xap::core::json::ERROR_NOTFIND:
     *              Sub path is not existed.
     * 
     *  @param name
     *      The name (key) of sub directory.
     *  @return
     *      Traverse object of sub directory.
     */
    xap::core::json::Traverse sub(const std::string &name);

    /**
     *  Go to sub directory which can be non-existed.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an object.
     * 
     *  @param name
     *      The name (key) of sub directory.
     *  @param default_value
     *      The default value if the directory doesn't existed.
     *  @return
     *      Traverse object of sub directory.
     */
    xap::core::json::Traverse optional_sub(
        const std::string &name, 
        const Traverse &default_value
    );

    /**
     *  Set a key-value pair within an object.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an object.
     * 
     *  @param key
     *      The key.
     *  @param value
     *      The value.
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &object_set(
        const std::string &key,
        const Traverse &value
    );

    /**
     *  Get the length of an array.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an array.
     * 
     *  @return
     *      The length.
     */
    size_t array_get_length();

    /**
     *  Iterate an array.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an array.
     * 
     *  @param handler
     *      The callback.
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &array_foreach(
        std::function<void(xap::core::json::Traverse &)> handler
    );

    /**
     *  Push an item to an array.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an array.
     * 
     *  @param value
     *      The item value.
     *  @return
     *      Self.
     */
    xap::core::json::Traverse &array_push_item(
        const xap::core::json::Traverse &value
    );

    /**
     *  Pop an item from an array.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an array.
     * 
     *          - xap::core::json::ERROR_OVERFLOW:
     *              The array is empty.
     * 
     *  @return
     *      Traverse object of the popped item.
     */
    xap::core::json::Traverse array_pop_item();

    /**
     *  Get inner as a signed integer.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not a signed integer.
     * 
     * 
     *  @return
     *      The inner.
     */
    int inner_as_int();

    /**
     *  Get inner as an unsigned integer.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not an unsigned integer.
     * 
     *  @return
     *      The inner.
     */
    uint inner_as_uint();

#if defined(XAPCORE_JSON_INT64)

    /**
     *  Get inner as a signed 64-bit integer.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not a signed 64-bit integer.
     * 
     *  @return
     *      The inner.
     */
    int64_t inner_as_int64();

    /**
     *  Get inner as a unsigned 64-bit integer.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not a unsigned 64-bit integer.
     * 
     *  @return
     *      The inner.
     */
    uint64_t inner_as_uint64();

#endif  //  #if defined(XAPCORE_JSON_INT64)

    /**
     *  Get the inner as float.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not numeric.
     * 
     *  @return
     *      The inner.
     */
    float inner_as_float();

    /**
     *  Get the inner as double.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not numeric.
     * 
     *  @return
     *      The inner.
     */
    double inner_as_double();

    /**
     *  Get inner as a boolean.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not a boolean.
     * 
     *  @return
     *      The inner.
     */
    bool inner_as_boolean();

    /**
     *  Get the inner as string.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     *
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The inner is not a string.
     * 
     *  @return
     *      The inner.
     */
    std::string inner_as_string();

private:

    //
    //  Private constructor.
    //

    /**
     *  Construct the object.
     * 
     *  @param p_traverse
     *      The private traverse object.
     */
    Traverse(
        const TraversePrivate &p_traverse
    );

    //
    //  Members.
    //
    std::unique_ptr<TraversePrivate> m_traverse;
};

}  //  namespace json
}  //  namespace core
}  //  namespace xap

#endif  //  #ifndef XAP_CORE_JSON_TRAVERSE_H__
