/* This is a managed file. Do not delete this comment. */

#include <corto/script/ast/ast.h>

int16_t ast_Initializer_apply(
    ast_Initializer _this,
    ast_InitializerHelper helper)
{
    corto_iter it = corto_ll_iter(_this->values);

    while (corto_iter_hasNext(&it)) {
        ast_InitializerValue arg = (ast_InitializerValue)corto_iter_next(&it);

        if (arg->key) {
            if (ast_InitializerHelper_member(helper, arg->key)) {
                corto_throw(NULL);
                goto error;
            }
        }

        if (corto_instanceof(ast_Initializer_o, arg->value)) {
            if (ast_InitializerHelper_push(helper)) {
                corto_throw(NULL);
                goto error;
            }

            if (safe_ast_Initializer_apply(arg->value, helper)) {
                corto_throw(NULL);
                goto error;
            }

            if (ast_InitializerHelper_pop(helper)) {
                corto_throw(NULL);
                goto error;
            }
        } else {
            if (ast_InitializerHelper_value(helper, arg->value)) {
                corto_throw(NULL);
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}

static
int16_t ast_Initializer_propagateTypes(
    ast_Initializer _this,
    ast_InitializerHelper helper)
{
    corto_iter it = corto_ll_iter(_this->values);
    corto_type type = ast_Expression(_this)->type;

    /* Visit the values in the initializer, pre-set their type */
    while (corto_iter_hasNext(&it)) {
        ast_InitializerValue arg = (ast_InitializerValue)corto_iter_next(&it);

        if (arg->key) {
            if (ast_InitializerHelper_member(helper, arg->key)) {
                corto_throw(NULL);
                goto error;
            }
        }

        if (corto_instanceof(ast_Initializer_o, arg->value)) {
            if (ast_InitializerHelper_push(helper)) {
                goto error;
            }

            if (!arg->value->type) {
                corto_type value_type =
                    ast_InitializerHelper(helper)->frames[helper->fp].type;
                if (!value_type) {
                    corto_throw("initializer unexpected for type '%s'",
                        corto_fullpath(NULL, type));
                    goto error;
                }
                ast_Expression_setType(arg->value, value_type);
                if (ast_Initializer_propagateTypes(
                    ast_Initializer(arg->value),
                    helper))
                {
                    corto_throw(NULL);
                    goto error;
                }
            }

            if (ast_InitializerHelper_pop(helper)) {
                goto error;
            }
        } else {
            if (!arg->value->type) {
                corto_type value_type =
                    ast_InitializerHelper(helper)->frames[helper->fp].type;
                if (!value_type) {
                    corto_throw("value unexpected for type '%s'",
                        corto_fullpath(NULL, type));
                    goto error;
                }

                ast_Expression_setType(arg->value, value_type);
            }
        }
    }

    return 0;
error:
    return -1;
}

int16_t ast_Initializer_propagateType(
    ast_Initializer _this,
    corto_type type)
{
    safe_ast_Expression_setType_v(_this, type);
    ast_InitializerHelper helper = NULL;

    /* Create an initializer helper to determine the type for the initializer
     * value expressions. This is needed because some of the values cannot
     * be serialized without knowing their type in advance (like enums). */
    helper = ast_InitializerHelper__declare(NULL, NULL);
    if (!helper) {
        goto error;
    }

    /* Since we don't have an expression for the helper, manually initializer
     * the type */
    corto_set_ref(&helper->frames[helper->fp].type, type);

    if (corto_define(helper)) {
        goto error;
    }

    if (ast_Initializer_propagateTypes(_this, helper)) {
        goto error;
    }

    corto_delete(helper);

    return 0;
error:
    return -1;
}

ast_Expression ast_Initializer_fold(
    ast_Initializer _this)
{
    corto_iter it = corto_ll_iter(_this->values);

    /* Visit the values in the initializer, pre-set their type */
    while (corto_iter_hasNext(&it)) {
        ast_InitializerValue arg = (ast_InitializerValue)corto_iter_next(&it);
        corto_set_ref(&arg->value, ast_Expression_fold(arg->value));
        if (!arg->value) {
            goto error;
        }
    }

    return ast_Expression(_this);
error:
    return NULL;
}
