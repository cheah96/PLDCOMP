#include "antlr4-runtime.h"
#include "MainBaseVisitor.h"
#include "Return.h"
#include "Expression.h"
#include "Statement.h"
#include "Block.h"
#include "Parameter.h"
#include "Function.h"
#include "DefFunc.h"
#include "DecFunc.h"
#include "Program.h"
#include "DefVar.h"
#include "DeclarVar.h"
#include "Param.h"
#include "ExecFunc.h"
#include "ExprStat.h" 

using namespace std;
class Comp : public MainBaseVisitor {

public:

    antlrcpp::Any visitProg(MainParser::ProgContext *context) override {
        Program* prog = new Program;
        vector<MainParser::FunctContext *> funcs = context->funct();
        size_t length = funcs.size();
        for(size_t i = 0; i < length; i++){
            Function* func = (Function*)visit(funcs[i]);
            //cout << "Prog "<<endl;
            prog->addFunction(func);
        }
        return prog;
    }

    antlrcpp::Any visitFunct(MainParser::FunctContext *context) override {
        Function* func = nullptr; 
        if(context->deffunc() != nullptr){
            //cout << "func "<<endl;
            func = (Function*)visit(context->deffunc());
             //cout << "func "<<endl;
        }
        else if(context->declarfunc() != nullptr){
            func = (Function*)visit(context->declarfunc());
        }
        return func;
    }

    antlrcpp::Any visitPar(MainParser::ParContext *context) override {
        return (Expr*)visit(context->expr());
    }

    antlrcpp::Any visitExfunc(MainParser::ExfuncContext *context) override {
        Expr* e = (Expr*)visit(context->execfunc());
        return e;
    }

    antlrcpp::Any visitConst(MainParser::ConstContext *context) override {
       int val = (int)stoi(context->INT()->getText());
        //cout << "Expr "<<endl;
        return (Expr*)new ExprInt(val); 
    }

    antlrcpp::Any visitVar(MainParser::VarContext *context) override {
        string varName = context->VAR()->getText();
        return (Expr*)new ExprVar(varName); 
    }

    antlrcpp::Any visitMultdiv(MainParser::MultdivContext *context) override {
        Expr* temp = nullptr;
        /* string test = context->children[1]->getText();
         cout << test << endl;*/
        if(context->children[1]->getText() == "*"){
            Expr* op1 = visit(context->expr(0)).as<Expr*>();
            Expr* op2 = visit(context->expr(1)).as<Expr*>();
            temp = new ExprBinary(OPTYPE::MULT,op1,op2);
        }else if(context->children[1]->getText() == "/"){
            Expr* op1 = visit(context->expr(0)).as<Expr*>();
            Expr* op2 = visit(context->expr(1)).as<Expr*>();
            temp = new ExprBinary(OPTYPE::DIV,op1,op2);
        }
        return temp;
    }

    antlrcpp::Any visitChar(MainParser::CharContext *context) override{
        string oneChar = context->CHAR()->getText();
        /*cout << oneChar << endl;
        cout << oneChar.length() << endl;
        for(size_t i = 0; i < oneChar.length(); i++){
            cout << oneChar.at(i) << endl;
        }*/
        char myChar;
        if(oneChar.at(1) == '\\') {
            if(oneChar.at(2) == 'a'){
                myChar = '\a';
            }else if(oneChar.at(2) == 'b'){
                myChar = '\b';
            }else if(oneChar.at(2) == 'e'){
                myChar = '\e';
            }else if(oneChar.at(2) == 'f'){
                myChar = '\f';
            }else if(oneChar.at(2) == 'n'){
                myChar = '\n';
            }else if(oneChar.at(2) == 'r'){
                myChar = '\r';
            }else if(oneChar.at(2) == 't'){
                myChar = '\t';
            }else if(oneChar.at(2) == 'v'){
                myChar = '\v';
            }else if(oneChar.at(2) == '\''){
                myChar = '\'';
            }else if(oneChar.at(2) == '\"'){
                myChar = '\"';
            }else if(oneChar.at(2) == '?'){
                myChar = '\?';
            }else if(oneChar.at(2) == '\\'){
                myChar = '\\'; 
            }
        }else{
            myChar = oneChar.at(1);
        }
        return (Expr*)new ExprChar(myChar);
    }

    antlrcpp::Any visitAddsub(MainParser::AddsubContext *context) override {
         Expr* temp = nullptr;
         /*string test = context->children[1]->getText();
         cout << test << endl;*/
        if(context->children[1]->getText() == "+"){
            Expr* op1 = visit(context->expr(0)).as<Expr*>();
            Expr* op2 = visit(context->expr(1)).as<Expr*>();
            temp = new ExprBinary(OPTYPE::ADD,op1,op2);
        }else if(context->children[1]->getText() == "-"){
            Expr* op1 = visit(context->expr(0)).as<Expr*>();
            Expr* op2 = visit(context->expr(1)).as<Expr*>();
            temp = new ExprBinary(OPTYPE::SUB,op1,op2);
        }
        return temp;
    }

    antlrcpp::Any visitDeclarvar(MainParser::DeclarvarContext *context) override {
        string type = context->TYPE()->getText();
        vector<string>* lesVars = new vector<string>; 
        vector<antlr4::tree::TerminalNode *> vars = context->VAR();
        for(antlr4::tree::TerminalNode * oneVar : vars){
            lesVars->push_back(oneVar->getText());
        }
        Statement* declarVars = new DeclarVar(lesVars, type);
        return declarVars;
    }

    antlrcpp::Any visitDefWithDeclar(MainParser::DefWithDeclarContext *context) override{
        string type = context->TYPE()->getText();
        string name = context->VAR()->getText();
        Expr* expr = visit(context->expr()).as<Expr*>();
        DefVar* def = new DefVarWithDeclar(type,name,expr);
        return (Statement*)def;
    }

    antlrcpp::Any visitDefWithoutDeclar(MainParser::DefWithoutDeclarContext *context) override{
        string name = context->VAR()->getText();
        Expr* expr = visit(context->expr()).as<Expr*>();
        DefVar* def = new DefVarWithoutDeclar(name,expr);
        return (Statement*)def;
    }

    antlrcpp::Any visitDeffunc(MainParser::DeffuncContext *context) override {
        string type = context->TYPE()->getText();
        string name = context->VAR()->getText();
        Block* block = (Block*)visit(context->block());
        DefFunc* def = new DefFunc(type,name,block);
        return (Function*)def;
    }

    antlrcpp::Any visitDeclarfunc(MainParser::DeclarfuncContext *context) override {
    return visitChildren(context);
    }

    antlrcpp::Any visitExecfunc(MainParser::ExecfuncContext *context) override {
        string funcName = context->VAR()->getText();
        Param* myParams = (Param*)visit(context->param());
        ExecFunc* ex = new ExecFunc(funcName, myParams);
        return (Expr*)ex;
    }

    antlrcpp::Any visitBlock(MainParser::BlockContext *context) override {
        vector<MainParser::StatementContext *> stats = context->statement();
        size_t length = stats.size();
        Block* block = new Block;
        for(size_t i = 0; i < length; i++){
            Statement* stat = (Statement*)visit(stats[i]);
            block->addStatement(stat);
        }
        return block;
    }

    antlrcpp::Any visitExprstat(MainParser::ExprstatContext *context) override{
        Expr* myExpr = visit(context->expr()).as<Expr*>();
        Statement* stat = new ExprStat(myExpr);
        return stat;
    }


    antlrcpp::Any visitStatement(MainParser::StatementContext *context) override {  
        Statement* stat = nullptr; 
        if(context->ret() != nullptr){
            stat = visit(context->ret()).as<Statement*>();
        }
        if(context->defvar() != nullptr){
            stat = visit(context->defvar()).as<Statement*>();
        }
        if(context->exprstat() != nullptr){
            stat = visit(context->exprstat()).as<Statement*>();
        }
        if(context->declarvar() != nullptr){
            stat = visit(context->declarvar()).as<Statement*>();
        }
        return stat;
    }

    antlrcpp::Any visitRet(MainParser::RetContext *context) override {
        
        Expr* expr = (Expr*)visit(context->expr());
        return (Statement*)new Return(expr);
    }

    antlrcpp::Any visitParamdec(MainParser::ParamdecContext *context) override {
    return visitChildren(context);
    }

    antlrcpp::Any visitParam(MainParser::ParamContext *context) override {
        vector<MainParser::ExprContext *> exprs = context->expr();
        Param* oneParams = new Param;
        for(MainParser::ExprContext * eContext : exprs){
            Expr* e = (Expr*)visit(eContext);
            oneParams->addExpr(e);
        }
        return oneParams;
    }

};

