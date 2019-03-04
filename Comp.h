#include "antlr4-runtime.h"
#include "MainBaseVisitor.h"
using namespace std;
class Comp : public MainBaseVisitor {

public:

    antlrcpp::Any visitProg(MainParser::ProgContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitFunct(MainParser::FunctContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitExpr(MainParser::ExprContext *ctx) override {
    return (int)stoi(ctx->INT()->getText());
    }

    antlrcpp::Any visitDeclar(MainParser::DeclarContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitAffect(MainParser::AffectContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitDef(MainParser::DefContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitDeffunc(MainParser::DeffuncContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitDeclarfunc(MainParser::DeclarfuncContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitExecfunc(MainParser::ExecfuncContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitBody(MainParser::BodyContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitStatement(MainParser::StatementContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitRet(MainParser::RetContext *ctx) override {
        int val = (int)visit(ctx->expr());
    return visitChildren(ctx);
    }

    antlrcpp::Any visitParamdec(MainParser::ParamdecContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitParam(MainParser::ParamContext *ctx) override {
    return visitChildren(ctx);
    }

}

