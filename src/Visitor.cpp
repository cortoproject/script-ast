/* This is a managed file. Do not delete this comment. */

#include <corto/script/ast/ast.h>

int16_t ast_Visitor_visit(
    ast_Visitor _this,
    ast_Node node)
{
    if (corto_instanceof(ast_Scope_o, node)) {
        if (ast_Visitor_visitScope(_this, node)) {
            goto error;
        }
    } else
    if (corto_instanceof(ast_Declaration_o, node)) {
        if (ast_Visitor_visitDeclaration(_this, node)) {
            goto error;
        }
    } else
    if (corto_instanceof(ast_Initializer_o, node)) {
        if (ast_Visitor_visitInitializer(_this, node)) {
            goto error;
        }
    } else
    if (corto_instanceof(ast_Storage_o, node)) {
        if (ast_Visitor_visitStorage(_this, node)) {
            goto error;
        }
    } else
    if (corto_instanceof(ast_Expression_o, node)) {
        if (ast_Visitor_visitExpression(_this, node)) {
            goto error;
        }
    } else
    if (corto_instanceof(ast_Statement_o, node)) {
        if (ast_Visitor_visitStatement(_this, node)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

int16_t ast_Visitor_visitScope_v(
    ast_Visitor _this,
    ast_Scope node)
{
    corto_debug("parser: visit scope");

    corto_iter it = corto_ll_iter(node->statements);
    while (corto_iter_hasNext(&it)) {
        if (ast_Visitor_visit(_this, ast_Node( corto_iter_next(&it)))) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

int16_t ast_Visitor_visitDeclaration_v(
    ast_Visitor _this,
    ast_Declaration node)
{
    corto_debug("parser: visit declaration");
    return 0;
}

int16_t ast_Visitor_visitExpression_v(
    ast_Visitor _this,
    ast_Expression node)
{
    corto_debug("parser: visit expression");
    return 0;
}

int16_t ast_Visitor_visitId_v(
    ast_Visitor _this,
    ast_Storage node)
{
    corto_debug("parser: visit id");
    return 0;
}

int16_t ast_Visitor_visitStatement_v(
    ast_Visitor _this,
    ast_Statement node)
{
    corto_debug("parser: visit statement");
    return 0;
}

int16_t ast_Visitor_visitStorage_v(
    ast_Visitor _this,
    ast_Storage node)
{
    corto_debug("parser: visit object");
    return 0;
}

int16_t ast_Visitor_visitInitializer_v(
    ast_Visitor _this,
    ast_Initializer node)
{
    corto_debug("parser: visit initializer");

    corto_iter it = corto_ll_iter(node->values);
    while (corto_iter_hasNext(&it)) {
        ast_InitializerValue value = ast_InitializerValue(corto_iter_next(&it));
        if (ast_Visitor_visit(_this, ast_Node(value->value))) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}
