# Traverse for C++ Core

The purpose of this library is to strictly check JSON objects in less code.

## Example

For a JSON like that:

``` json
{
    "a": "b",
    "b": 72341
}
```

We can parse in a more elegant way, like that:

``` C++
try {
    std::string a = root.sub("a")
                        .not_null()
                        .type_of(xap::core::json::string)
                        .string()
                        .inner_as_string();
    int b = root.sub("b")
                .not_null()
                .integer()
                .inner_as_int();
} catch (xap::core::json::Exception &error) {
    //
    //  TODO: Handle error.
    //
}
```

## Build

You can run the following command to build the project.

```
cmake .
make
```

## Test

Run the following command to test.

```
make test
```
