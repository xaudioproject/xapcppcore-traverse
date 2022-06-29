//
//  Copyright 2019 - 2022 The XOrange Studio. All rights reserved.
//  Use of this source code is governed by a BSD-style license that can be
//  found in the LICENSE.md file.
//

//
//  Imports.
//
#include "xap/core/json/traverse.h"
#include "traverse_p.h"
#include "xap/core/json/error.h"

#include "json/json.h"

#include <memory>

namespace xap {
namespace core {
namespace json {

//
//  Traverse constructor & destructor.
//

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
Traverse::Traverse(
    const uint8_t *data, 
    const size_t datalen,
    const std::string &path
) :
    m_traverse(std::make_unique<xap::core::json::TraversePrivate>(
        data,
        datalen,
        path
    ))
{}

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
Traverse::Traverse(
    const char *data,
    const size_t datalen,
    const std::string &path
) :
    m_traverse(std::make_unique<xap::core::json::TraversePrivate>(
        reinterpret_cast<const uint8_t *>(data),
        datalen,
        path
    ))
{}

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
Traverse::Traverse(
    std::string json_string,
    const std::string &path
) :
    m_traverse(std::make_unique<xap::core::json::TraversePrivate>(
        reinterpret_cast<const uint8_t *>(json_string.c_str()),
        json_string.size(),
        path
    ))
{}

/**
 *  Construct (Copy) the object.
 * 
 *  @param src
 *      The source.
 */
Traverse::Traverse(
    const Traverse &src
) :
    m_traverse(std::make_unique<xap::core::json::TraversePrivate>(
        *(src.m_traverse)
    ))
{}

/**
 *  Construct the object.
 * 
 *  @param p_traverse
 *      The private traverse object.
 */
Traverse::Traverse(
    const TraversePrivate &p_traverse
) :
    m_traverse(std::make_unique<xap::core::json::TraversePrivate>(
        p_traverse
    ))
{}

/**
 *  Destruct the object.
 */
Traverse::~Traverse() noexcept {
    //  Do nothing.
}

//
//  Traverse public methods.
//

/**
 *  Get the path.
 *
 *  @return
 *      The path.
 */
std::string Traverse::get_path() const {
    return this->m_traverse->m_path;
}


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
xap::core::json::Traverse &
Traverse::type_of(const xap::core::json::Type &type) {
    this->m_traverse->type_of(type);
    return *this;
}

/**
 *  Get the type of inner object.
 * 
 *  @return
 *      The type.
 */
xap::core::json::Type Traverse::type() const noexcept {
    return this->m_traverse->type();
}

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
xap::core::json::Traverse &Traverse::numeric() {
    this->m_traverse->numeric();
    return *this;
}

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
xap::core::json::Traverse &Traverse::integer() {
    this->m_traverse->integer();
    return *this;
}

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
xap::core::json::Traverse &Traverse::unsigned_integer() {
    this->m_traverse->unsigned_integer();
    return *this;
}

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
xap::core::json::Traverse &Traverse::integer_64() {
    this->m_traverse->integer_64();
    return *this;
}

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
xap::core::json::Traverse &Traverse::unsigned_integer_64() {
    this->m_traverse->unsigned_integer_64();
    return *this;
}

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
xap::core::json::Traverse &Traverse::boolean() {
    this->m_traverse->boolean();
    return *this;
}

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
xap::core::json::Traverse &Traverse::string() {
    this->m_traverse->string();
    return *this;
}

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
xap::core::json::Traverse &Traverse::array() {
    this->m_traverse->array();
    return *this;
}

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
xap::core::json::Traverse &Traverse::object() {
    this->m_traverse->object();
    return *this;
}

/**
 *  Assume that the inner object is not null.
 * 
 *  @throw xap::core::json::Exception
 *      Raised if value is null (xap::core::json::ERROR_TYPE).
 *  @return
 *      Self.
 */
xap::core::json::Traverse &Traverse::not_null() {
    this->m_traverse->not_null();
    return *this;
}

/**
 *  Check whether the inner object is null.
 * 
 *  @return
 *      True if so.
 */
bool Traverse::is_null() const noexcept {
    return this->m_traverse->is_null();
}

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
xap::core::json::Traverse Traverse::sub(const std::string &name) {
    return xap::core::json::Traverse(
        this->m_traverse->sub(name)
    );
}

/**
*  Go to sub directory which can be non-existed.
* 
*  @note 
*      The method will return a Traverse object with 'null' type if sub 
*      directory is non-existed.
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
*  @return
*      Traverse object of sub directory.
*/
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value::null)
    );
}

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
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name, 
    const Traverse &default_value
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, default_value.m_traverse->m_inner)
    );
}

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
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name,
    int                default_value 
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(default_value))
    );
}

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
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name,
    uint               default_value 
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(default_value))
    );
}

#if defined(XAPCORE_JSON_INT64)

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
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name, 
    int64_t            default_value
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(default_value))
    );
}

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
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name, 
    uint64_t           default_value
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(default_value))
    );
}

#endif  //  #if defined(XAPCORE_JSON_INT64)

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
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name, 
    float              default_value
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(default_value))
    );
}

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
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name, 
    double             default_value
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(default_value))
    );
}

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
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name, 
    bool               default_value
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(default_value))
    );
}

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
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name, 
    const std::string &default_value
) {
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(default_value))
    );
}

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
 *      The default (string) value if the directory doesn't existed.
 *  @return
 *      Traverse object of sub directory.
 */
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name, 
    const char        *default_value
) {
    std::string str(default_value);
    
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(str))
    );
}

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
 *      The default (string) value if the directory doesn't existed.
 *  @param default_value_len
 *      The length of the default value.
 *  @return
 *      Traverse object of sub directory.
 */
xap::core::json::Traverse Traverse::optional_sub(
    const std::string &name, 
    const char        *default_value,
    size_t             default_value_len
) {
    std::string str(default_value, default_value_len);
    
    return xap::core::json::Traverse(
        this->m_traverse->optional_sub(name, Json::Value(str))
    );
}

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
xap::core::json::Traverse &Traverse::object_set(
    const std::string &key,
    const Traverse &value
) {
    this->m_traverse->object_set(key, value.m_traverse->m_inner);
    return *this;
}

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
size_t Traverse::array_get_length() {
    return this->m_traverse->array_get_length();
}

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
xap::core::json::Traverse &Traverse::array_foreach(
    std::function<void(xap::core::json::Traverse &)> handler
) {
    this->m_traverse->array_foreach(
        [&] (const xap::core::json::TraversePrivate &item) {
            xap::core::json::Traverse item_traverse = 
                xap::core::json::Traverse(item);
            handler(item_traverse);
        }
    );

    return *this;
}

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
xap::core::json::Traverse &Traverse::array_push_item(
    const Traverse &value
) {
    this->m_traverse->array_push_item(value.m_traverse->m_inner);

    return *this;
}

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
xap::core::json::Traverse Traverse::array_pop_item() {
    return xap::core::json::Traverse(
        this->array_pop_item()
    );
}

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
int Traverse::inner_as_int() {
    return this->m_traverse->inner_as_int();
}

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
uint Traverse::inner_as_uint() {
    return this->m_traverse->inner_as_uint();
}

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
int64_t Traverse::inner_as_int64() {
    return this->m_traverse->inner_as_int64();
}

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
uint64_t Traverse::inner_as_uint64() {
    return this->m_traverse->inner_as_uint64();
}

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
float Traverse::inner_as_float() {
    return this->m_traverse->inner_as_float();
}

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
double Traverse::inner_as_double() {
    return this->m_traverse->inner_as_double();
}

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
bool Traverse::inner_as_boolean() {
    return this->m_traverse->inner_as_boolean();
}

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
std::string Traverse::inner_as_string() {
    return this->m_traverse->inner_as_string();
}

//
//  Traverse public static functions.
//

/**
 *  Get a 'Traverse' object and its type is 'null'.
 *
 *  @param path
 *      The path.
 *  @return
 *      The 'Traverse' object.
 */
xap::core::json::Traverse Traverse::null(const std::string &path) {
    return xap::core::json::Traverse(
        xap::core::json::TraversePrivate(Json::Value::null, path)
    );
}

//
//  TraversePrivate constructor & destructor.
//

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
TraversePrivate::TraversePrivate(
    const uint8_t *data, 
    const size_t datalen,
    const std::string &path
) :
    m_inner(),
    m_path(path),
    m_type(xap::core::json::Type::null)
{
    //  Parse the JSON data.
    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    Json::String error;
    if (!reader->parse(
        reinterpret_cast<const char*>(data), 
        reinterpret_cast<const char*>(data) + datalen, 
        &m_inner, 
        &error
    )) {
        throw xap::core::json::Exception(
            error.c_str(),
            xap::core::json::ERROR_PARAMETER,
            this->m_path.c_str()
        );
    }

    //  Prepare type.
    this->m_type = this->get_inner_type();
}

/**
 *  Constructh the object.
 * 
 *  @param value
 *      The JSON value.
 *  @param path
 *      The path.
 */
TraversePrivate::TraversePrivate(
    const Json::Value &value,
    const std::string &path
) :
    m_inner(value),
    m_path(path),
    m_type(xap::core::json::Type::null)
{
    this->m_type = this->get_inner_type();
}

/**
 *  Construct (Copy) the object.
 * 
 *  @param src
 *      The source.
 */
TraversePrivate::TraversePrivate(const TraversePrivate &src) :
    m_inner(src.m_inner),
    m_path(src.m_path),
    m_type(src.m_type)
{}

/**
 *  Destruct the object.
 */
TraversePrivate::~TraversePrivate() noexcept {
    //  Do nothing.
}

//
//  TraversePrivate public methods.
//

/**
 *  Get the path.
 *
 *  @return
 *      The path.
 */
std::string TraversePrivate::get_path() const {
    return this->m_path;
}

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
xap::core::json::TraversePrivate &
TraversePrivate::type_of(const xap::core::json::Type &type) {
    if (this->m_type == xap::core::json::Type::null) {
        return *this;
    }

    if (this->m_type == type) {
        return *this;
    } else {
        throw xap::core::json::Exception(
            "Invalid object value.",
            xap::core::json::ERROR_TYPE,
            this->m_path.c_str()
        );
    }
}

/**
 *  Get the type of inner object.
 * 
 *  @return
 *      The type.
 */
xap::core::json::Type TraversePrivate::type() const noexcept {
    return this->m_type;
}

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
xap::core::json::TraversePrivate &TraversePrivate::numeric() {
    this->type_of(xap::core::json::Type::numeric);
    return *this;
}

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
xap::core::json::TraversePrivate &TraversePrivate::integer() {
    if (this->m_type == xap::core::json::Type::null) {
        return *this;
    }

    //  Check type.
    if (!this->m_inner.isInt()) {
        throw xap::core::json::Exception(
            "Value should be integer.",
            xap::core::json::ERROR_TYPE,
            this->m_path.c_str()
        );
    }

    return *this;
}

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
xap::core::json::TraversePrivate 
&TraversePrivate::unsigned_integer() {
    if (this->m_type == xap::core::json::Type::null) {
        return *this;
    }

    //  Check type.
    if (!this->m_inner.isUInt()) {
        throw xap::core::json::Exception(
            "Value should be integer.",
            xap::core::json::ERROR_TYPE,
            this->m_path.c_str()
        );
    }

    return *this;
}

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
xap::core::json::TraversePrivate &
TraversePrivate::integer_64() {
    if (this->m_type == xap::core::json::Type::null) {
        return *this;
    }

    //  Check type.
    if (!this->m_inner.isInt64()) {
        throw xap::core::json::Exception(
            "Value should be integer.",
            xap::core::json::ERROR_TYPE,
            this->m_path.c_str()
        );
    }

    return *this;
}

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
xap::core::json::TraversePrivate &
TraversePrivate::unsigned_integer_64() {
    if (this->m_type == xap::core::json::Type::null) {
        return *this;
    }

    //  Check type.
    if (!this->m_inner.isUInt64()) {
        throw xap::core::json::Exception(
            "Value should be unsigned 64-bit integer.",
            xap::core::json::ERROR_TYPE,
            this->m_path.c_str()
        );
    }

    return *this;
}

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
xap::core::json::TraversePrivate &TraversePrivate::boolean() {
    //  Check type.
    this->type_of(xap::core::json::Type::boolean);
    return *this;
}

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
xap::core::json::TraversePrivate &TraversePrivate::string() {
    //  Check type.
    this->type_of(xap::core::json::Type::string);
    return *this;
}

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
xap::core::json::TraversePrivate &TraversePrivate::array() {
    //  Check type.
    this->type_of(xap::core::json::Type::array);
    return *this;
}

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
xap::core::json::TraversePrivate &TraversePrivate::object() {
    //  Check type.
    this->type_of(xap::core::json::Type::object);
    return *this;
}

/**
 *  Assume that the inner object is not null.
 * 
 *  @throw xap::core::json::Exception
 *      Raised if value is null (xap::core::json::ERROR_TYPE).
 *  @return
 *      Self.
 */
xap::core::json::TraversePrivate &TraversePrivate::not_null() {
    //  Check type.
    if (this->m_type == xap::core::json::Type::null) {
        throw xap::core::json::Exception(
            "Value shoud not be null.",
            xap::core::json::ERROR_TYPE,
            this->m_path.c_str()
        );
    }

    return *this;
}

/**
 *  Check whether the inner object is null.
 * 
 *  @return
 *      True if so.
 */
bool TraversePrivate::is_null() const noexcept {
    return this->m_inner.isNull();
}

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
xap::core::json::TraversePrivate TraversePrivate::sub(
    const std::string &name
) {
    //  Check type.
    this->not_null().object();

    //  Sub path.
    std::string sub_path = this->get_sub_path(name);

    //  Check sub item.
    const char *name_cstr = name.c_str();
    const size_t name_size = name.size();
    if (this->m_inner.find(name_cstr, name_cstr + name_size) == nullptr) {
        throw xap::core::json::Exception(
            "Sub path is not existed.",
            xap::core::json::ERROR_NOTFIND,
            sub_path.c_str()
        );
    }

    //  Get sub item.
    Json::Value sub_inner = this->m_inner[name];

    return xap::core::json::TraversePrivate(
        sub_inner,
        sub_path
    );
}

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
xap::core::json::TraversePrivate TraversePrivate::optional_sub(
    const std::string &name, 
    const Json::Value &default_value
) {
    //  Check type.
    this->not_null().object();
    
    //  Sub path.
    std::string sub_path = this->get_sub_path(name);

    //  Get sub item.
    Json::Value sub_inner;
    const char *name_cstr = name.c_str();
    const size_t name_size = name.size();
    if (this->m_inner.find(name_cstr, name_cstr + name_size) == nullptr) {
        sub_inner = default_value;
    } else {
        sub_inner = m_inner[name];
    }

    return xap::core::json::TraversePrivate(sub_inner, sub_path);
}

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
xap::core::json::TraversePrivate &TraversePrivate::object_set(
    const std::string &key,
    const Json::Value &value
) {
    //  Check type.
    this->not_null().object();

    this->m_inner[key] = value;
    return *this;
}

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
size_t TraversePrivate::array_get_length() {
    //  Check type.
    this->not_null().array();

    return static_cast<size_t>(this->m_inner.size());
}

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
xap::core::json::TraversePrivate &TraversePrivate::array_foreach(
    std::function<void(const TraversePrivate &)> handler
) {
    //  Check type.
    this->not_null().array();

    Json::ArrayIndex length = this->m_inner.size();
    for (Json::ArrayIndex i = 0U; i < this->m_inner.size(); ++i) {
        handler(xap::core::json::TraversePrivate(
            this->m_inner[i],
            this->get_sub_path(static_cast<size_t>(i))
        ));
    }

    return *this;
}

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
xap::core::json::TraversePrivate &TraversePrivate::array_push_item(
    const Json::Value &value
) {
    //  Check type.
    this->not_null().array();

    this->m_inner.append(value);
    return *this;
}

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
xap::core::json::TraversePrivate TraversePrivate::array_pop_item() {
    this->not_null().array();

    const Json::ArrayIndex length = this->m_inner.size();
    if (length == 0U) {
        throw xap::core::json::Exception(
            "Array is empty.",
            xap::core::json::ERROR_OVERFLOW,
            this->m_path.c_str()
        );
    }

    const Json::ArrayIndex pop_index = length - 1U;
    const Json::Value pop_item = this->m_inner[pop_index];
    this->m_inner.resize(pop_index);
    return xap::core::json::TraversePrivate(
        pop_item,
        this->get_sub_path(static_cast<size_t>(pop_index))
    );
}

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
int TraversePrivate::inner_as_int() {
    this->not_null().integer();
    return this->m_inner.asInt();
}

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
uint TraversePrivate::inner_as_uint() {
    this->not_null().unsigned_integer();
    return this->m_inner.asUInt();
}

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
int64_t TraversePrivate::inner_as_int64() {
    this->not_null().integer_64();
    return this->m_inner.asInt64();
}

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
uint64_t TraversePrivate::inner_as_uint64() {
    this->not_null().unsigned_integer_64();
    return this->m_inner.asUInt64();
}

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
float TraversePrivate::inner_as_float() {
    this->not_null().numeric();
    return this->m_inner.asFloat();
}

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
double TraversePrivate::inner_as_double() {
    this->not_null().numeric();
    return this->m_inner.asDouble();
}

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
bool TraversePrivate::inner_as_boolean() {
    this->not_null().boolean();
    return this->m_inner.asBool();
}

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
std::string TraversePrivate::inner_as_string() {
    this->not_null().string();
    return this->m_inner.asString();
}

//
//  TraversePrivate private methods.
//

/**
 *  Get the path of specific sub directory.
 * 
 *  @param name 
 *      The name of sub directory.
 *  @return
 *      The sub path.
 */
std::string TraversePrivate::get_sub_path(const std::string &name) const {
    if (this->m_path.size() == 0U || *(this->m_path.end() - 1U) == '/') {
        return m_path + name;
    } else {
        return m_path + std::string("/") + name;
    }
}

/**
 *  Get the path of specific sub directory.
 * 
 *  @param index 
 *      The index of sub directory.
 *  @return
 *      The sub path.
 */
std::string TraversePrivate::get_sub_path(const size_t index) const {
    if (this->m_path.size() == 0U || *(this->m_path.end() - 1U) == '/') {
        return m_path + std::to_string(index);
    } else {
        return m_path + std::string("/") + std::to_string(index);
    }
}

/**
 *  Get the inner type.
 * 
 *  @return
 *      The type of inner object.
 */
xap::core::json::Type TraversePrivate::get_inner_type() const {
    switch (this->m_inner.type()) {
        case Json::nullValue:
            return xap::core::json::Type::null;
        case Json::intValue:
        case Json::uintValue:
        case Json::realValue:
            return xap::core::json::Type::numeric;
        case Json::stringValue:
            return xap::core::json::Type::string;
        case Json::booleanValue:
            return xap::core::json::Type::boolean;
        case Json::arrayValue:
            return xap::core::json::Type::array;
        case Json::objectValue:
            return xap::core::json::Type::object;
        default:
            throw xap::core::json::Exception(
                "Unexpected JSON value type.",
                xap::core::json::ERROR_BUG,
                this->m_path.c_str()
            );
    }
}

}  //  namespace json
}  //  namespace core
}  //  namespace xap