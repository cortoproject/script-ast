/* This is a managed file. Do not delete this comment. */

#include <corto/script/ast/ast.h>

int16_t ast_Visitor_visit(
    ast_Visitor _this,
    ast_Node node)
{
    if (corto_instanceof(ast_Block_o, node)) {
        corto_set_ref(&_this->ctx->block, node);
        if (ast_Visitor_visitBlock(_this, node, _this->ctx)) {
            goto error;
        }

        if (corto_instanceof(ast_Scope_o, node)) {
            if (ast_Visitor_visitScope(_this, node, _this->ctx)) {
                goto error;
            }
        }
    }
    if (corto_instanceof(ast_Declaration_o, node)) {
        if (ast_Visitor_visitDeclaration(_this, node, _this->ctx)) {
            goto error;
        }
    }
    if (corto_instanceof(ast_Statement_o, node)) {
        if (ast_Visitor_visitStatement(_this, node, _this->ctx)) {
            goto error;
        }
    }
    if (corto_instanceof(ast_Expression_o, node)) {
        if (ast_Visitor_visitExpression(_this, node, _this->ctx)) {
            goto error;
        }
    }
    if (corto_instanceof(ast_Id_o, node)) {
        if (ast_Visitor_visitId(_this, node, _this->ctx)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

int16_t ast_Visitor_visitBlock_v(
    ast_Visitor _this,
    ast_Block node,
    ast_Context ctx)
{
    corto_debug("parser: visit block");

    if (ast_Node_visit(node, _this)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t ast_Visitor_visitDeclaration_v(
    ast_Visitor _this,
    ast_Declaration node,
    ast_Context ctx)
{
    corto_debug("parser: visit declaration");
    return 0;
}

int16_t ast_Visitor_visitExpression_v(
    ast_Visitor _this,
    ast_Expression node,
    ast_Context ctx)
{
    corto_debug("parser: visit expression");
    return 0;
}

int16_t ast_Visitor_visitId_v(
    ast_Visitor _this,
    ast_Id node,
    ast_Context ctx)
{
    corto_debug("parser: visit id");
    return 0;
}

int16_t ast_Visitor_visitScope_v(
    ast_Visitor _this,
    ast_Scope node,
    ast_Context ctx)
{
    corto_debug("parser: visit scope");
    return 0;
}

int16_t ast_Visitor_visitStatement_v(
    ast_Visitor _this,
    ast_Statement node,
    ast_Context ctx)
{
    corto_debug("parser: visit statement");
    return 0;
}
