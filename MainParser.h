
// Generated from Main.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  MainParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, TYPE = 13, INT = 14, 
    VAR = 15, CHAR = 16, CHARESC = 17, WS = 18
  };

  enum {
    RuleProg = 0, RuleFunct = 1, RuleExpr = 2, RuleDeclarvar = 3, RuleDefvar = 4, 
    RuleDeffunc = 5, RuleDeclarfunc = 6, RuleExecfunc = 7, RuleBlock = 8, 
    RuleExprstat = 9, RuleStatement = 10, RuleRet = 11, RuleParamdec = 12, 
    RuleParam = 13
  };

  MainParser(antlr4::TokenStream *input);
  ~MainParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class FunctContext;
  class ExprContext;
  class DeclarvarContext;
  class DefvarContext;
  class DeffuncContext;
  class DeclarfuncContext;
  class ExecfuncContext;
  class BlockContext;
  class ExprstatContext;
  class StatementContext;
  class RetContext;
  class ParamdecContext;
  class ParamContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FunctContext *> funct();
    FunctContext* funct(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  FunctContext : public antlr4::ParserRuleContext {
  public:
    FunctContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeffuncContext *deffunc();
    DeclarfuncContext *declarfunc();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctContext* funct();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParContext : public ExprContext {
  public:
    ParContext(ExprContext *ctx);

    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExfuncContext : public ExprContext {
  public:
    ExfuncContext(ExprContext *ctx);

    ExecfuncContext *execfunc();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConstContext : public ExprContext {
  public:
    ConstContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarContext : public ExprContext {
  public:
    VarContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultdivContext : public ExprContext {
  public:
    MultdivContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharContext : public ExprContext {
  public:
    CharContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *CHAR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddsubContext : public ExprContext {
  public:
    AddsubContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  DeclarvarContext : public antlr4::ParserRuleContext {
  public:
    DeclarvarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarvarContext* declarvar();

  class  DefvarContext : public antlr4::ParserRuleContext {
  public:
    DefvarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DefvarContext() : antlr4::ParserRuleContext() { }
    void copyFrom(DefvarContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DefWithDeclarContext : public DefvarContext {
  public:
    DefWithDeclarContext(DefvarContext *ctx);

    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *VAR();
    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DefWithoutDeclarContext : public DefvarContext {
  public:
    DefWithoutDeclarContext(DefvarContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    ExprContext *expr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DefvarContext* defvar();

  class  DeffuncContext : public antlr4::ParserRuleContext {
  public:
    DeffuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *VAR();
    BlockContext *block();
    ParamdecContext *paramdec();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeffuncContext* deffunc();

  class  DeclarfuncContext : public antlr4::ParserRuleContext {
  public:
    DeclarfuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *VAR();
    ParamdecContext *paramdec();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarfuncContext* declarfunc();

  class  ExecfuncContext : public antlr4::ParserRuleContext {
  public:
    ExecfuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    ParamContext *param();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExecfuncContext* execfunc();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  ExprstatContext : public antlr4::ParserRuleContext {
  public:
    ExprstatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprstatContext* exprstat();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RetContext *ret();
    DefvarContext *defvar();
    ExprstatContext *exprstat();
    DeclarvarContext *declarvar();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  RetContext : public antlr4::ParserRuleContext {
  public:
    RetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RetContext* ret();

  class  ParamdecContext : public antlr4::ParserRuleContext {
  public:
    ParamdecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> TYPE();
    antlr4::tree::TerminalNode* TYPE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamdecContext* paramdec();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

