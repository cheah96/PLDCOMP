
// Generated from Main.g4 by ANTLR 4.7.1


#include "MainVisitor.h"

#include "MainParser.h"


using namespace antlrcpp;
using namespace antlr4;

MainParser::MainParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MainParser::~MainParser() {
  delete _interpreter;
}

std::string MainParser::getGrammarFileName() const {
  return "Main.g4";
}

const std::vector<std::string>& MainParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MainParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

MainParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MainParser::FunctContext *> MainParser::ProgContext::funct() {
  return getRuleContexts<MainParser::FunctContext>();
}

MainParser::FunctContext* MainParser::ProgContext::funct(size_t i) {
  return getRuleContext<MainParser::FunctContext>(i);
}


size_t MainParser::ProgContext::getRuleIndex() const {
  return MainParser::RuleProg;
}

antlrcpp::Any MainParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ProgContext* MainParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MainParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MainParser::TYPE) {
      setState(28);
      funct();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctContext ------------------------------------------------------------------

MainParser::FunctContext::FunctContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::DeffuncContext* MainParser::FunctContext::deffunc() {
  return getRuleContext<MainParser::DeffuncContext>(0);
}

MainParser::DeclarfuncContext* MainParser::FunctContext::declarfunc() {
  return getRuleContext<MainParser::DeclarfuncContext>(0);
}


size_t MainParser::FunctContext::getRuleIndex() const {
  return MainParser::RuleFunct;
}

antlrcpp::Any MainParser::FunctContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitFunct(this);
  else
    return visitor->visitChildren(this);
}

MainParser::FunctContext* MainParser::funct() {
  FunctContext *_localctx = _tracker.createInstance<FunctContext>(_ctx, getState());
  enterRule(_localctx, 2, MainParser::RuleFunct);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(36);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(34);
      deffunc();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(35);
      declarfunc();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MainParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MainParser::ExprContext::getRuleIndex() const {
  return MainParser::RuleExpr;
}

void MainParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParContext ------------------------------------------------------------------

MainParser::ExprContext* MainParser::ParContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

MainParser::ParContext::ParContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::ParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitPar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExfuncContext ------------------------------------------------------------------

MainParser::ExecfuncContext* MainParser::ExfuncContext::execfunc() {
  return getRuleContext<MainParser::ExecfuncContext>(0);
}

MainParser::ExfuncContext::ExfuncContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::ExfuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitExfunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::ConstContext::INT() {
  return getToken(MainParser::INT, 0);
}

MainParser::ConstContext::ConstContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::ConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::VarContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::VarContext::VarContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultdivContext ------------------------------------------------------------------

std::vector<MainParser::ExprContext *> MainParser::MultdivContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::MultdivContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}

MainParser::MultdivContext::MultdivContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::MultdivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitMultdiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::CharContext::CHAR() {
  return getToken(MainParser::CHAR, 0);
}

MainParser::CharContext::CharContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::CharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddsubContext ------------------------------------------------------------------

std::vector<MainParser::ExprContext *> MainParser::AddsubContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::AddsubContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}

MainParser::AddsubContext::AddsubContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::AddsubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitAddsub(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ExprContext* MainParser::expr() {
   return expr(0);
}

MainParser::ExprContext* MainParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MainParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MainParser::ExprContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, MainParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(47);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ConstContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(39);
      match(MainParser::INT);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<VarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(40);
      match(MainParser::VAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CharContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(41);
      match(MainParser::CHAR);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ParContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(42);
      match(MainParser::T__4);
      setState(43);
      expr(0);
      setState(44);
      match(MainParser::T__5);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExfuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(46);
      execfunc();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(57);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(55);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultdivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(49);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(50);
          _la = _input->LA(1);
          if (!(_la == MainParser::T__0

          || _la == MainParser::T__1)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(51);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddsubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(52);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(53);
          _la = _input->LA(1);
          if (!(_la == MainParser::T__2

          || _la == MainParser::T__3)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(54);
          expr(7);
          break;
        }

        } 
      }
      setState(59);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DeclarvarContext ------------------------------------------------------------------

MainParser::DeclarvarContext::DeclarvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MainParser::DeclarvarContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

std::vector<tree::TerminalNode *> MainParser::DeclarvarContext::VAR() {
  return getTokens(MainParser::VAR);
}

tree::TerminalNode* MainParser::DeclarvarContext::VAR(size_t i) {
  return getToken(MainParser::VAR, i);
}


size_t MainParser::DeclarvarContext::getRuleIndex() const {
  return MainParser::RuleDeclarvar;
}

antlrcpp::Any MainParser::DeclarvarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDeclarvar(this);
  else
    return visitor->visitChildren(this);
}

MainParser::DeclarvarContext* MainParser::declarvar() {
  DeclarvarContext *_localctx = _tracker.createInstance<DeclarvarContext>(_ctx, getState());
  enterRule(_localctx, 6, MainParser::RuleDeclarvar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(MainParser::TYPE);
    setState(61);
    match(MainParser::VAR);
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MainParser::T__6) {
      setState(62);
      match(MainParser::T__6);
      setState(63);
      match(MainParser::VAR);
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    match(MainParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefvarContext ------------------------------------------------------------------

MainParser::DefvarContext::DefvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MainParser::DefvarContext::getRuleIndex() const {
  return MainParser::RuleDefvar;
}

void MainParser::DefvarContext::copyFrom(DefvarContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DefWithDeclarContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::DefWithDeclarContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

tree::TerminalNode* MainParser::DefWithDeclarContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ExprContext* MainParser::DefWithDeclarContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

MainParser::DefWithDeclarContext::DefWithDeclarContext(DefvarContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::DefWithDeclarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDefWithDeclar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DefWithoutDeclarContext ------------------------------------------------------------------

tree::TerminalNode* MainParser::DefWithoutDeclarContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ExprContext* MainParser::DefWithoutDeclarContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}

MainParser::DefWithoutDeclarContext::DefWithoutDeclarContext(DefvarContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MainParser::DefWithoutDeclarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDefWithoutDeclar(this);
  else
    return visitor->visitChildren(this);
}
MainParser::DefvarContext* MainParser::defvar() {
  DefvarContext *_localctx = _tracker.createInstance<DefvarContext>(_ctx, getState());
  enterRule(_localctx, 8, MainParser::RuleDefvar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(82);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MainParser::TYPE: {
        _localctx = dynamic_cast<DefvarContext *>(_tracker.createInstance<MainParser::DefWithDeclarContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(71);
        match(MainParser::TYPE);
        setState(72);
        match(MainParser::VAR);
        setState(73);
        match(MainParser::T__8);
        setState(74);
        expr(0);
        setState(75);
        match(MainParser::T__7);
        break;
      }

      case MainParser::VAR: {
        _localctx = dynamic_cast<DefvarContext *>(_tracker.createInstance<MainParser::DefWithoutDeclarContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(77);
        match(MainParser::VAR);
        setState(78);
        match(MainParser::T__8);
        setState(79);
        expr(0);
        setState(80);
        match(MainParser::T__7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeffuncContext ------------------------------------------------------------------

MainParser::DeffuncContext::DeffuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MainParser::DeffuncContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

tree::TerminalNode* MainParser::DeffuncContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::BlockContext* MainParser::DeffuncContext::block() {
  return getRuleContext<MainParser::BlockContext>(0);
}

MainParser::ParamdecContext* MainParser::DeffuncContext::paramdec() {
  return getRuleContext<MainParser::ParamdecContext>(0);
}


size_t MainParser::DeffuncContext::getRuleIndex() const {
  return MainParser::RuleDeffunc;
}

antlrcpp::Any MainParser::DeffuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDeffunc(this);
  else
    return visitor->visitChildren(this);
}

MainParser::DeffuncContext* MainParser::deffunc() {
  DeffuncContext *_localctx = _tracker.createInstance<DeffuncContext>(_ctx, getState());
  enterRule(_localctx, 10, MainParser::RuleDeffunc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(MainParser::TYPE);
    setState(85);
    match(MainParser::VAR);
    setState(86);
    match(MainParser::T__4);
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MainParser::TYPE) {
      setState(87);
      paramdec();
    }
    setState(90);
    match(MainParser::T__5);
    setState(91);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarfuncContext ------------------------------------------------------------------

MainParser::DeclarfuncContext::DeclarfuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MainParser::DeclarfuncContext::TYPE() {
  return getToken(MainParser::TYPE, 0);
}

tree::TerminalNode* MainParser::DeclarfuncContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ParamdecContext* MainParser::DeclarfuncContext::paramdec() {
  return getRuleContext<MainParser::ParamdecContext>(0);
}


size_t MainParser::DeclarfuncContext::getRuleIndex() const {
  return MainParser::RuleDeclarfunc;
}

antlrcpp::Any MainParser::DeclarfuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitDeclarfunc(this);
  else
    return visitor->visitChildren(this);
}

MainParser::DeclarfuncContext* MainParser::declarfunc() {
  DeclarfuncContext *_localctx = _tracker.createInstance<DeclarfuncContext>(_ctx, getState());
  enterRule(_localctx, 12, MainParser::RuleDeclarfunc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(MainParser::TYPE);
    setState(94);
    match(MainParser::VAR);
    setState(95);
    match(MainParser::T__4);
    setState(97);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MainParser::TYPE) {
      setState(96);
      paramdec();
    }
    setState(99);
    match(MainParser::T__5);
    setState(100);
    match(MainParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecfuncContext ------------------------------------------------------------------

MainParser::ExecfuncContext::ExecfuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MainParser::ExecfuncContext::VAR() {
  return getToken(MainParser::VAR, 0);
}

MainParser::ParamContext* MainParser::ExecfuncContext::param() {
  return getRuleContext<MainParser::ParamContext>(0);
}


size_t MainParser::ExecfuncContext::getRuleIndex() const {
  return MainParser::RuleExecfunc;
}

antlrcpp::Any MainParser::ExecfuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitExecfunc(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ExecfuncContext* MainParser::execfunc() {
  ExecfuncContext *_localctx = _tracker.createInstance<ExecfuncContext>(_ctx, getState());
  enterRule(_localctx, 14, MainParser::RuleExecfunc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    match(MainParser::VAR);
    setState(103);
    match(MainParser::T__4);
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MainParser::T__4)
      | (1ULL << MainParser::INT)
      | (1ULL << MainParser::VAR)
      | (1ULL << MainParser::CHAR))) != 0)) {
      setState(104);
      param();
    }
    setState(107);
    match(MainParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MainParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MainParser::StatementContext *> MainParser::BlockContext::statement() {
  return getRuleContexts<MainParser::StatementContext>();
}

MainParser::StatementContext* MainParser::BlockContext::statement(size_t i) {
  return getRuleContext<MainParser::StatementContext>(i);
}


size_t MainParser::BlockContext::getRuleIndex() const {
  return MainParser::RuleBlock;
}

antlrcpp::Any MainParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

MainParser::BlockContext* MainParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 16, MainParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(MainParser::T__9);
    setState(113);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MainParser::T__4)
      | (1ULL << MainParser::T__11)
      | (1ULL << MainParser::TYPE)
      | (1ULL << MainParser::INT)
      | (1ULL << MainParser::VAR)
      | (1ULL << MainParser::CHAR))) != 0)) {
      setState(110);
      statement();
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(116);
    match(MainParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprstatContext ------------------------------------------------------------------

MainParser::ExprstatContext::ExprstatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::ExprContext* MainParser::ExprstatContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}


size_t MainParser::ExprstatContext::getRuleIndex() const {
  return MainParser::RuleExprstat;
}

antlrcpp::Any MainParser::ExprstatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitExprstat(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ExprstatContext* MainParser::exprstat() {
  ExprstatContext *_localctx = _tracker.createInstance<ExprstatContext>(_ctx, getState());
  enterRule(_localctx, 18, MainParser::RuleExprstat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    expr(0);
    setState(119);
    match(MainParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MainParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::RetContext* MainParser::StatementContext::ret() {
  return getRuleContext<MainParser::RetContext>(0);
}

MainParser::DefvarContext* MainParser::StatementContext::defvar() {
  return getRuleContext<MainParser::DefvarContext>(0);
}

MainParser::ExprstatContext* MainParser::StatementContext::exprstat() {
  return getRuleContext<MainParser::ExprstatContext>(0);
}

MainParser::DeclarvarContext* MainParser::StatementContext::declarvar() {
  return getRuleContext<MainParser::DeclarvarContext>(0);
}


size_t MainParser::StatementContext::getRuleIndex() const {
  return MainParser::RuleStatement;
}

antlrcpp::Any MainParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MainParser::StatementContext* MainParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 20, MainParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(121);
      ret();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(122);
      defvar();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(123);
      exprstat();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(124);
      declarvar();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

MainParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MainParser::ExprContext* MainParser::RetContext::expr() {
  return getRuleContext<MainParser::ExprContext>(0);
}


size_t MainParser::RetContext::getRuleIndex() const {
  return MainParser::RuleRet;
}

antlrcpp::Any MainParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}

MainParser::RetContext* MainParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 22, MainParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(MainParser::T__11);
    setState(128);
    expr(0);
    setState(129);
    match(MainParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamdecContext ------------------------------------------------------------------

MainParser::ParamdecContext::ParamdecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MainParser::ParamdecContext::TYPE() {
  return getTokens(MainParser::TYPE);
}

tree::TerminalNode* MainParser::ParamdecContext::TYPE(size_t i) {
  return getToken(MainParser::TYPE, i);
}

std::vector<tree::TerminalNode *> MainParser::ParamdecContext::VAR() {
  return getTokens(MainParser::VAR);
}

tree::TerminalNode* MainParser::ParamdecContext::VAR(size_t i) {
  return getToken(MainParser::VAR, i);
}


size_t MainParser::ParamdecContext::getRuleIndex() const {
  return MainParser::RuleParamdec;
}

antlrcpp::Any MainParser::ParamdecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitParamdec(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ParamdecContext* MainParser::paramdec() {
  ParamdecContext *_localctx = _tracker.createInstance<ParamdecContext>(_ctx, getState());
  enterRule(_localctx, 24, MainParser::RuleParamdec);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(MainParser::TYPE);
    setState(132);
    match(MainParser::VAR);
    setState(138);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MainParser::T__6) {
      setState(133);
      match(MainParser::T__6);
      setState(134);
      match(MainParser::TYPE);
      setState(135);
      match(MainParser::VAR);
      setState(140);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

MainParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MainParser::ExprContext *> MainParser::ParamContext::expr() {
  return getRuleContexts<MainParser::ExprContext>();
}

MainParser::ExprContext* MainParser::ParamContext::expr(size_t i) {
  return getRuleContext<MainParser::ExprContext>(i);
}


size_t MainParser::ParamContext::getRuleIndex() const {
  return MainParser::RuleParam;
}

antlrcpp::Any MainParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MainVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

MainParser::ParamContext* MainParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 26, MainParser::RuleParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    expr(0);
    setState(146);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MainParser::T__6) {
      setState(142);
      match(MainParser::T__6);
      setState(143);
      expr(0);
      setState(148);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MainParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MainParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MainParser::_decisionToDFA;
atn::PredictionContextCache MainParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MainParser::_atn;
std::vector<uint16_t> MainParser::_serializedATN;

std::vector<std::string> MainParser::_ruleNames = {
  "prog", "funct", "expr", "declarvar", "defvar", "deffunc", "declarfunc", 
  "execfunc", "block", "exprstat", "statement", "ret", "paramdec", "param"
};

std::vector<std::string> MainParser::_literalNames = {
  "", "'*'", "'/'", "'+'", "'-'", "'('", "')'", "','", "';'", "'='", "'{'", 
  "'}'", "'return'"
};

std::vector<std::string> MainParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "TYPE", "INT", "VAR", 
  "CHAR", "CHARESC", "WS"
};

dfa::Vocabulary MainParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MainParser::_tokenNames;

MainParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x14, 0x98, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x7, 0x2, 0x20, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x23, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x27, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x32, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x3a, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x3d, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x43, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x46, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x55, 0xa, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x5b, 0xa, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x64, 
    0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0x6c, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x7, 
    0xa, 0x72, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x75, 0xb, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0x80, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x8b, 0xa, 
    0xe, 0xc, 0xe, 0xe, 0xe, 0x8e, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x7, 0xf, 0x93, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x96, 0xb, 0xf, 0x3, 0xf, 
    0x2, 0x3, 0x6, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x2, 0x4, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 
    0x5, 0x6, 0x2, 0x9c, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x4, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x31, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x54, 0x3, 0x2, 0x2, 0x2, 0xc, 0x56, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x68, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x78, 0x3, 0x2, 0x2, 0x2, 0x16, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x81, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x20, 0x5, 0x4, 0x3, 
    0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x24, 0x27, 
    0x5, 0xc, 0x7, 0x2, 0x25, 0x27, 0x5, 0xe, 0x8, 0x2, 0x26, 0x24, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x29, 0x8, 0x4, 0x1, 0x2, 0x29, 0x32, 0x7, 0x10, 0x2, 
    0x2, 0x2a, 0x32, 0x7, 0x11, 0x2, 0x2, 0x2b, 0x32, 0x7, 0x12, 0x2, 0x2, 
    0x2c, 0x2d, 0x7, 0x7, 0x2, 0x2, 0x2d, 0x2e, 0x5, 0x6, 0x4, 0x2, 0x2e, 
    0x2f, 0x7, 0x8, 0x2, 0x2, 0x2f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 
    0x5, 0x10, 0x9, 0x2, 0x31, 0x28, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2c, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x34, 0xc, 0x9, 0x2, 0x2, 0x34, 0x35, 0x9, 0x2, 0x2, 0x2, 
    0x35, 0x3a, 0x5, 0x6, 0x4, 0xa, 0x36, 0x37, 0xc, 0x8, 0x2, 0x2, 0x37, 
    0x38, 0x9, 0x3, 0x2, 0x2, 0x38, 0x3a, 0x5, 0x6, 0x4, 0x9, 0x39, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x3f, 0x7, 0xf, 0x2, 0x2, 0x3f, 0x44, 0x7, 0x11, 0x2, 0x2, 
    0x40, 0x41, 0x7, 0x9, 0x2, 0x2, 0x41, 0x43, 0x7, 0x11, 0x2, 0x2, 0x42, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x46, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0xa, 
    0x2, 0x2, 0x48, 0x9, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0xf, 0x2, 
    0x2, 0x4a, 0x4b, 0x7, 0x11, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0xb, 0x2, 0x2, 
    0x4c, 0x4d, 0x5, 0x6, 0x4, 0x2, 0x4d, 0x4e, 0x7, 0xa, 0x2, 0x2, 0x4e, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x11, 0x2, 0x2, 0x50, 0x51, 
    0x7, 0xb, 0x2, 0x2, 0x51, 0x52, 0x5, 0x6, 0x4, 0x2, 0x52, 0x53, 0x7, 
    0xa, 0x2, 0x2, 0x53, 0x55, 0x3, 0x2, 0x2, 0x2, 0x54, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x55, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x57, 0x7, 0xf, 0x2, 0x2, 0x57, 0x58, 0x7, 0x11, 0x2, 0x2, 
    0x58, 0x5a, 0x7, 0x7, 0x2, 0x2, 0x59, 0x5b, 0x5, 0x1a, 0xe, 0x2, 0x5a, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x8, 0x2, 0x2, 0x5d, 0x5e, 0x5, 
    0x12, 0xa, 0x2, 0x5e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0xf, 
    0x2, 0x2, 0x60, 0x61, 0x7, 0x11, 0x2, 0x2, 0x61, 0x63, 0x7, 0x7, 0x2, 
    0x2, 0x62, 0x64, 0x5, 0x1a, 0xe, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x66, 0x7, 0x8, 0x2, 0x2, 0x66, 0x67, 0x7, 0xa, 0x2, 0x2, 0x67, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x11, 0x2, 0x2, 0x69, 0x6b, 0x7, 
    0x7, 0x2, 0x2, 0x6a, 0x6c, 0x5, 0x1c, 0xf, 0x2, 0x6b, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x6d, 0x6e, 0x7, 0x8, 0x2, 0x2, 0x6e, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x6f, 0x73, 0x7, 0xc, 0x2, 0x2, 0x70, 0x72, 0x5, 0x16, 0xc, 0x2, 0x71, 
    0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0x75, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0xd, 
    0x2, 0x2, 0x77, 0x13, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x5, 0x6, 0x4, 
    0x2, 0x79, 0x7a, 0x7, 0xa, 0x2, 0x2, 0x7a, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x7b, 0x80, 0x5, 0x18, 0xd, 0x2, 0x7c, 0x80, 0x5, 0xa, 0x6, 0x2, 0x7d, 
    0x80, 0x5, 0x14, 0xb, 0x2, 0x7e, 0x80, 0x5, 0x8, 0x5, 0x2, 0x7f, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x82, 0x7, 0xe, 0x2, 0x2, 0x82, 0x83, 0x5, 0x6, 0x4, 
    0x2, 0x83, 0x84, 0x7, 0xa, 0x2, 0x2, 0x84, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x86, 0x7, 0xf, 0x2, 0x2, 0x86, 0x8c, 0x7, 0x11, 0x2, 0x2, 0x87, 
    0x88, 0x7, 0x9, 0x2, 0x2, 0x88, 0x89, 0x7, 0xf, 0x2, 0x2, 0x89, 0x8b, 
    0x7, 0x11, 0x2, 0x2, 0x8a, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 
    0x2, 0x8f, 0x94, 0x5, 0x6, 0x4, 0x2, 0x90, 0x91, 0x7, 0x9, 0x2, 0x2, 
    0x91, 0x93, 0x5, 0x6, 0x4, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x93, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x96, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x10, 0x21, 0x26, 0x31, 0x39, 0x3b, 0x44, 0x54, 0x5a, 
    0x63, 0x6b, 0x73, 0x7f, 0x8c, 0x94, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MainParser::Initializer MainParser::_init;
