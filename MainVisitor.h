
// Generated from Main.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "MainParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MainParser.
 */
class  MainVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MainParser.
   */
    virtual antlrcpp::Any visitProg(MainParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitFunct(MainParser::FunctContext *context) = 0;

    virtual antlrcpp::Any visitPar(MainParser::ParContext *context) = 0;

    virtual antlrcpp::Any visitExfunc(MainParser::ExfuncContext *context) = 0;

    virtual antlrcpp::Any visitConst(MainParser::ConstContext *context) = 0;

    virtual antlrcpp::Any visitVar(MainParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitMultdiv(MainParser::MultdivContext *context) = 0;

    virtual antlrcpp::Any visitChar(MainParser::CharContext *context) = 0;

    virtual antlrcpp::Any visitAddsub(MainParser::AddsubContext *context) = 0;

    virtual antlrcpp::Any visitDeclarvar(MainParser::DeclarvarContext *context) = 0;

    virtual antlrcpp::Any visitDefWithDeclar(MainParser::DefWithDeclarContext *context) = 0;

    virtual antlrcpp::Any visitDefWithoutDeclar(MainParser::DefWithoutDeclarContext *context) = 0;

    virtual antlrcpp::Any visitDeffunc(MainParser::DeffuncContext *context) = 0;

    virtual antlrcpp::Any visitDeclarfunc(MainParser::DeclarfuncContext *context) = 0;

    virtual antlrcpp::Any visitExecfunc(MainParser::ExecfuncContext *context) = 0;

    virtual antlrcpp::Any visitBlock(MainParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitExprstat(MainParser::ExprstatContext *context) = 0;

    virtual antlrcpp::Any visitStatement(MainParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitRet(MainParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitParamdec(MainParser::ParamdecContext *context) = 0;

    virtual antlrcpp::Any visitParam(MainParser::ParamContext *context) = 0;


};

