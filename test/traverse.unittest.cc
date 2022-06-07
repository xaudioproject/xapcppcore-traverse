//
//  Copyright 2019 - 2021 The XOrange Studio. All rights reserved.
//  Use of this source code is governed by a BSD-style license that can be
//  found in the LICENSE.md file.
//

//
//  Imports.
//
#include "common.h"

#include <iostream>
#include <xap/core/json/all.h>

//
//  Entry.
//

int main() {
    const char data[] = R"(
        {
            "a": "b",
            "b": "123123",
            "c": 12,
            "d": 1.1,
            "e": -1,
            "f": 1.0,
            "g": true,
            "h": false,
            "i": {"a": "123"},
            "j": [1, 2, 3, 4, 5]
        }
    )";
    try {
        xap::core::json::Traverse root(data, sizeof(data));
        root.not_null().object();
        std::string a = root.sub("a")
                            .not_null()
                            .type_of(xap::core::json::string)
                            .string()
                            .inner_as_string();
        xap::test::assert_equal<std::string>(a, "b", "a != \"b\"");
        xap::test::assert_throw<xap::core::json::Exception>([&] {
            root.sub("b")
                .not_null()
                .integer();
        });
        printf("%s\n", root.sub("a").get_path().c_str());
        xap::test::assert_equal<std::string>(
            root.sub("a").get_path(), 
            "/a", 
            "root.sub(\"a\") != \"/a\""
        );
        int c1 = root.sub("c")
                     .not_null()
                     .numeric()
                     .integer()
                     .unsigned_integer()
#if defined(XAPCORE_JSON_INT64)
                     .unsigned_integer_64()
                     .integer_64()
#endif  //  #if defined(XAPCORE_JSON_INT64)
                     .inner_as_int();
        xap::test::assert_equal<int>(
            c1,
            12,
            "c1 != 12"
        );
        float c2 = root.sub("c").inner_as_float();
        xap::test::assert_equal<float>(
            c2,
            12.0,
            "c2 != 12.0"
        );          

        double d1 = root.sub("d")
                        .not_null()
                        .numeric()
                        .inner_as_double();
        xap::test::assert_equal<double>(
            d1,
            1.1,
            "d1 != 1.1"
        );
        float d2 = root.sub("d")
                       .inner_as_float();
        xap::test::assert_equal<float>(
            d2,
            1.1,
            "d2 != 1.1"
        );
        xap::test::assert_throw<xap::core::json::Exception>([&] {
            root.sub("d").integer();
        });
        xap::test::assert_throw<xap::core::json::Exception>([&] {
            root.sub("e").unsigned_integer();
        });

        int f1 = root.sub("f")
                     .not_null()
                     .integer()
                     .inner_as_int();
        xap::test::assert_equal<int>(
            f1,
            1,
            "f1 != 1"
        );
        
        bool g1 = root.sub("g")
                      .not_null()
                      .boolean()
                      .inner_as_boolean();
        xap::test::assert_ok(g1, "g1 != true");
        bool h1 = root.sub("h")
                      .not_null()
                      .boolean()
                      .inner_as_boolean();
        xap::test::assert_ok(!h1, "h1 != false");

        std::string i_a = root.sub("i")
                              .not_null()
                              .object()
                              .sub("a")
                              .string()
                              .inner_as_string();
        xap::test::assert_equal<std::string>(
            i_a,
            "123",
            "i_a != 123"
        );

        int j_test = 1;
        root.sub("j")
            .not_null()
            .array()
            .array_foreach([&] (xap::core::json::Traverse &item) {
                xap::test::assert_equal<int>(
                    item.inner_as_int(),
                    j_test++,
                    "item.inner_as_int() != j_test"
                );
            });

        xap::test::assert_throw<xap::core::json::Exception>([&] {
            root.sub("fake_key");
        });
        xap::test::assert_equal<uint8_t>(
            root.optional_sub("fake_key").type(),
            xap::core::json::Type::null,
            "fake_value != null"
        );
        xap::test::assert_equal<int>(
            root.optional_sub(
                "fake_key", 
                xap::core::json::Traverse("456")
            ).inner_as_int(),
            456,
            "fake_value != 456"
        );
        xap::test::assert_equal<uint8_t>(
            root.optional_sub("fake_key", xap::core::json::Traverse::null()).type(),
            xap::core::json::Type::null,
            "Optional fake value's type is not 'null'."
        );
        xap::test::assert_equal<int>(
            root.optional_sub("fake_key", 11).inner_as_int(),
            11,
            "fake_value != 11"
        );
        xap::test::assert_equal<int>(
            root.optional_sub("fake_key", 11u).inner_as_int(),
            11u,
            "fake_value != 11u"
        );
        xap::test::assert_equal<float>(
            root.optional_sub("fake_key", 11.1).inner_as_float(),
            11.1f,
            "fake_value != 11.1f"
        );
        xap::test::assert_equal<double>(
            root.optional_sub("fake_key", 12.2).inner_as_double(),
            12.2,
            "fake_value != 12.2"
        );
        xap::test::assert_equal<bool>(
            root.optional_sub("fake_key", true).inner_as_boolean(),
            true,
            "fake_value != true"
        );
        xap::test::assert_equal<std::string>(
            root.optional_sub(
                "fake_key", 
                std::string("THIS IS A TEST")
            ).inner_as_string(),
            "THIS IS A TEST",
            "fake_value != 'THIS IS A TEST'"
        );
        xap::test::assert_equal<std::string>(
            root.optional_sub("fake_key", "THIS IS A TEST").inner_as_string(),
            "THIS IS A TEST",
            "fake_value != 'THIS IS A TEST'"
        );
        xap::test::assert_equal<std::string>(
            root.optional_sub("fake_key", "THIS ", 4).inner_as_string(),
            "THIS",
            "fake_value != 'THIS'"
        );
        xap::test::assert_equal<std::string>(
            root.optional_sub("fake_key").get_path(),
            "/fake_key",
            "root.optional_sub(\"fake_key\").get_path() != \"/fake_key\""
        );

        xap::test::assert_equal<xap::core::json::Type>(
            xap::core::json::Traverse::null().type(),
            xap::core::json::Type::null,
            "xap::core::json::Traverse::null().type() != "
            "xap::core::json::Type::null"
        );
        xap::test::assert_equal<std::string>(
            xap::core::json::Traverse::null("/a/b/c").get_path(),
            "/a/b/c",
            "xap::core::json::Traverse::null(\"/a/b/c\").get_path() != "
            "\"/a/b/c\""
        );
    } catch (xap::core::json::Exception &error) {
        printf("Throw unexpected XAP JSON error (\"%s\").\n", error.what());
        xap::test::assert_ok(false, "Throw unexpected XAP JSON error.");
    } catch (std::exception &error) {
        printf(
            "Throw unexpected std::exception error (\"%s\").\n", 
            error.what()
        );
        xap::test::assert_ok(false, "Throw unexpected std::exception error.");
    }
}