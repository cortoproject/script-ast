/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_shorthand_2_collection_anonymous_type_full_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo[bar] /hello: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: StorageInitializer\n"
        "|   |   |   expr: Identifier\n"
        "|   |   |   |   id: 'foo'\n"
        "|   |   |   initializer: Initializer\n"
        "|   |   |   |   values:\n"
        "|   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   value: Identifier\n"
        "|   |   |   |   |   |   |   id: 'bar'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: '/hello'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}


void test_shorthand_2_collection_anonymous_type_full_nested_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo[bar] /hello/world: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: StorageInitializer\n"
        "|   |   |   expr: Identifier\n"
        "|   |   |   |   id: 'foo'\n"
        "|   |   |   initializer: Initializer\n"
        "|   |   |   |   values:\n"
        "|   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   value: Identifier\n"
        "|   |   |   |   |   |   |   id: 'bar'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: '/hello/world'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}


void test_shorthand_2_collection_anonymous_type_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo[bar] hello: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: StorageInitializer\n"
        "|   |   |   expr: Identifier\n"
        "|   |   |   |   id: 'foo'\n"
        "|   |   |   initializer: Initializer\n"
        "|   |   |   |   values:\n"
        "|   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   value: Identifier\n"
        "|   |   |   |   |   |   |   id: 'bar'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: 'hello'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}


void test_shorthand_2_collection_anonymous_type_nested_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo[bar] hello/world: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: StorageInitializer\n"
        "|   |   |   expr: Identifier\n"
        "|   |   |   |   id: 'foo'\n"
        "|   |   |   initializer: Initializer\n"
        "|   |   |   |   values:\n"
        "|   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   value: Identifier\n"
        "|   |   |   |   |   |   |   id: 'bar'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: 'hello/world'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}


void test_shorthand_2_collection_anonymous_type_root_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo[bar] root/: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: StorageInitializer\n"
        "|   |   |   expr: Identifier\n"
        "|   |   |   |   id: 'foo'\n"
        "|   |   |   initializer: Initializer\n"
        "|   |   |   |   values:\n"
        "|   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   value: Identifier\n"
        "|   |   |   |   |   |   |   id: 'bar'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: '/'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}


void test_shorthand_2_collection_named_type_full_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo /hello: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: Identifier\n"
        "|   |   |   id: 'foo'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: '/hello'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}


void test_shorthand_2_collection_named_type_full_nested_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo /hello/world: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: Identifier\n"
        "|   |   |   id: 'foo'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: '/hello/world'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}


void test_shorthand_2_collection_named_type_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo hello: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: Identifier\n"
        "|   |   |   id: 'foo'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: 'hello'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}


void test_shorthand_2_collection_named_type_nested_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo hello/world: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: Identifier\n"
        "|   |   |   id: 'foo'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: 'hello/world'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}


void test_shorthand_2_collection_named_type_root_id(
    test_shorthand_2_collection _this)
{
    char *result, *input = "foo root/: [10, 20], [30, 40]";
    char *expect =
        "statements:\n"
        "|   Declaration\n"
        "|   |   type: Identifier\n"
        "|   |   |   id: 'foo'\n"
        "|   |   id: DeclarationIdentifier\n"
        "|   |   |   ids:\n"
        "|   |   |   |   Identifier\n"
        "|   |   |   |   |   id: '/'\n"
        "|   |   initializer: Initializer\n"
        "|   |   |   values:\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '10'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '20'\n"
        "|   |   |   |   InitializerValue\n"
        "|   |   |   |   |   value: Initializer\n"
        "|   |   |   |   |   |   collection: 'true'\n"
        "|   |   |   |   |   |   values:\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '30'\n"
        "|   |   |   |   |   |   |   InitializerValue\n"
        "|   |   |   |   |   |   |   |   value: Integer\n"
        "|   |   |   |   |   |   |   |   |   value: '40'\n"
        ;

    result = cortoscript_code_to_string(input);
    test_assert(result != NULL);
    test_assertstr(expect, result);
    free(result);
}
