//
//  Copyright 2019 - 2021 The XOrange Studio. All rights reserved.
//  Use of this source code is governed by a BSD-style license that can be
//  found in the LICENSE.md file.
//

#ifndef XAP_CORE_JSON_TRAVERSE_P_H__
#define XAP_CORE_JSON_TRAVERSE_P_H__

//
//  Imports.
//
#include <functional>
#include <json/json.h>
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <xap/core/json/build.h>
#include <xap/core/json/traverse.h>

namespace xap {
namespace core {
namespace json {

//
//  Declares.
//
class Traverse;

//
//  Classes.
//

/**
 *  Private traverse.
 */
class TraversePrivate {
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
    TraversePrivate(
        const uint8_t *data, 
        const size_t datalen,
        const std::string &path = "/"
    );
    
    /**
     *  Construct the object.
     * 
     *  @param value
     *      The JSON value.
     *  @param path
     *      The path.
     */
    TraversePrivate(
        const Json::Value &value,
        const std::string &path = "/"
    );

    /**
     *  Construct (Copy) the object.
     * 
     *  @param src
     *      The source.
     */
    TraversePrivate(const TraversePrivate &src);

    /**
     *  Destruct the object.
     */
    virtual ~TraversePrivate() noexcept;

    //
    //  Public methods.
    //

    /**
     *  Check the type of inner object.
     * 
     *  @throw xap::core::json::Exception
     *      Raised in the following situations:
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The type is not null.
     * 
     *          - xap::core::json::ERROR_TYPE:
     *              The type is invalid.
     * 
     *  @param type
     *      The expected type.
     *  @return
     *      Self.
     */
    xap::core::json::TraversePrivate &type_of(
        const xap::core::json::Type &type
    );

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
    xap::core::json::TraversePrivate &numeric();

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
    xap::core::json::TraversePrivate &integer();

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
    xap::core::json::TraversePrivate &unsigned_integer();

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
     *              The inner is not an 64-bit integer.
     * 
     *  @return
     *      Self.
     */
    xap::core::json::TraversePrivate &integer_64();

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
    xap::core::json::TraversePrivate &unsigned_integer_64();

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
    xap::core::json::TraversePrivate &boolean();

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
    xap::core::json::TraversePrivate &string();

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
    xap::core::json::TraversePrivate &array();

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
    xap::core::json::TraversePrivate &object();

    /**
     *  Assume that the inner object is not null.
     * 
     *  @throw xap::core::json::Exception
     *      Raised if value is null (xap::core::json::ERROR_TYPE).
     *  @return
     *      Self.
     */
    xap::core::json::TraversePrivate &not_null();

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
    xap::core::json::TraversePrivate sub(const std::string &name);

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
    xap::core::json::TraversePrivate optional_sub(
        const std::string &name, 
        const Json::Value &default_value
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
    xap::core::json::TraversePrivate &object_set(
        const std::string &key,
        const Json::Value &value
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
     *  @throw std::exception
     *      Any exception rasied by handler.
     *  @param handler
     *      The callback.
     *  @return
     *      Self.
     */
    xap::core::json::TraversePrivate &array_foreach(
        std::function<void(const TraversePrivate &)> handler
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
    xap::core::json::TraversePrivate &array_push_item(
        const Json::Value &value
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
    xap::core::json::TraversePrivate array_pop_item();

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
    //  Friend classes.
    //
    friend class Traverse;

    //
    //  Private methods.
    //

    /**
     *  Get the path of specific sub directory.
     * 
     *  @param name 
     *      The name of sub directory.
     *  @return
     *      The sub path.
     */
    std::string get_sub_path(const std::string &path) const;

    /**
     *  Get the path of specific sub directory.
     * 
     *  @param index 
     *      The index of sub directory.
     *  @return
     *      The sub path.
     */
    std::string get_sub_path(const size_t index) const;

    /**
     *  Get the inner type.
     * 
     *  @return
     *      The type of inner object.
     */
    xap::core::json::Type get_inner_type() const;

    //
    //  Private members.
    //
    Json::Value m_inner;
    std::string m_path;
    xap::core::json::Type m_type;
};

}  //  namespace json
}  //  namespace core
}  //  namespace xap

#endif  //  #ifndef XAP_CORE_JSON_TRAVERSE_P_H__
