
// Generated from Main.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "MainVisitor.h"


/**
 * This class provides an empty implementation of MainVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MainBaseVisitor : public MainVisitor {
public:

  virtual antlrcpp::Any visitProg(MainParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunct(MainParser::FunctContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPar(MainParser::ParContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExfunc(MainParser::ExfuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst(MainParser::ConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar(MainParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultdiv(MainParser::MultdivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChar(MainParser::CharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddsub(MainParser::AddsubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarvar(MainParser::DeclarvarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefWithDeclar(MainParser::DefWithDeclarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefWithoutDeclar(MainParser::DefWithoutDeclarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeffunc(MainParser::DeffuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarfunc(MainParser::DeclarfuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExecfunc(MainParser::ExecfuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(MainParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprstat(MainParser::ExprstatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(MainParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet(MainParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamdec(MainParser::ParamdecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam(MainParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }


};

