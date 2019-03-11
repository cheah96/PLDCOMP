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

    /*antlrcpp::Any visitExpr(MainParser::ExprContext *context) override {
        if(context->INT() != nullptr){
            int val = (int)stoi(context->INT()->getText());
            //cout << "Expr "<<endl;
            return (Expr*)new ExprInt(val); 
        }
        else if(!context->expr().empty()){
            vector<MainParser::ExprContext *> exprVec = context->expr();
            for(MainParser::ExprContext * cont : exprVec){
                cout << cont->getText() << endl;
            }
        }
        return nullptr;
    }*/

    antlrcpp::Any visitPar(MainParser::ParContext *context) override {
        return visitChildren(context);
    }

    antlrcpp::Any visitExfunc(MainParser::ExfuncContext *context) override {
        return visitChildren(context);
    }

    antlrcpp::Any visitConst(MainParser::ConstContext *context) override {
        return visitChildren(context);
    }

    antlrcpp::Any visitVar(MainParser::VarContext *context) override {
        return visitChildren(context);
    }

    antlrcpp::Any visitMultdiv(MainParser::MultdivContext *context) override {
        return visitChildren(context);
    }

    antlrcpp::Any visitAddsub(MainParser::AddsubContext *context) override {
        return visitChildren(context);
    }

    antlrcpp::Any visitDeclarvar(MainParser::DeclarvarContext *context) override {
    return visitChildren(context);
    }

    antlrcpp::Any visitDefvar(MainParser::DefvarContext *context) override {
        string type = context->TYPE()->getText();
        string name = context->VAR()->getText();
        Expr* expr = visit(context->expr()).as<Expr*>();
        DefVar* def = new DefVar(type,name,expr);
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
    return visitChildren(context);
    }

    antlrcpp::Any visitBlock(MainParser::BlockContext *context) override {
        vector<MainParser::StatementContext *> stats = context->statement();
        size_t length = stats.size();
        Block* block = new Block;
        //cout <<"Block" <<endl;
        for(size_t i = 0; i < length; i++){
            Statement* stat = (Statement*)visit(stats[i]);
            block->addStatement(stat);
        }
        //cout <<"Block" <<endl;
        return block;
    }

    antlrcpp::Any visitStatement(MainParser::StatementContext *context) override {  
        Statement* stat = nullptr; 
        if(context->ret() != nullptr){
            //cout << "hhhhh" << endl;
            stat = visit(context->ret()).as<Statement*>();
            //cout << "hhhhh" << endl;
        }
        if(context->defvar() != nullptr){
            stat = visit(context->defvar()).as<Statement*>();
        }
        if(context->expr() != nullptr){
            //stat = (Return*)visit(context->expr());
        }
        if(context->declarvar() != nullptr){
            //stat = (Return*)visit(context->declar());
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
    return visitChildren(context);
    }

};

