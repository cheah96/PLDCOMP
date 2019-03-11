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






using namespace std;
class Comp : public MainBaseVisitor {

public:

    antlrcpp::Any visitProg(MainParser::ProgContext *ctx) override {
        Program* prog = new Program;
        vector<MainParser::FunctContext *> funcs = ctx->funct();
        size_t length = funcs.size();
        for(size_t i = 0; i < length; i++){
            Function* func = (Function*)visit(funcs[i]);
            //cout << "Prog "<<endl;
            prog->addFunction(func);
        }
        return prog;
    }

    antlrcpp::Any visitFunct(MainParser::FunctContext *ctx) override {
        Function* func = nullptr; 
        if(ctx->deffunc() != nullptr){
            //cout << "func "<<endl;
            func = (Function*)visit(ctx->deffunc());
             //cout << "func "<<endl;
        }
        if(ctx->declarfunc() != nullptr){
            func = (Function*)visit(ctx->declarfunc());
        }
    return func;
    }

    antlrcpp::Any visitExpr(MainParser::ExprContext *ctx) override {
        if(ctx->INT() != nullptr){
            int val = (int)stoi(ctx->INT()->getText());
            //cout << "Expr "<<endl;
            return (Expr*)new ExprInt(val); 
        }
        return nullptr;
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
        /*string funcname = ctx->VAR()->getText();
        string* asscode = new string("  .globl    " + funcname + "\n");
        *asscode += funcname + ":\n";
        *asscode += "pushq   %rbp\n";
        *asscode += "movq    %rsp, %rbp\n";

        string *test = (string *)visit(ctx->body());
        //cout<<*test<<endl;
        *asscode += "popq    %rbp\n";
        *asscode += "ret\n";
        //cout <<*asscode<<endl;*/
        //cout << "DefFunc "<<endl;
        string type = ctx->TYPE()->getText();
        string name = ctx->VAR()->getText();
        Block* block = (Block*)visit(ctx->block());
        DefFunc* def = new DefFunc(type,name,block);
        //cout << "DefFunc "<<endl;
        return (Function*)def;
    }

    antlrcpp::Any visitDeclarfunc(MainParser::DeclarfuncContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitExecfunc(MainParser::ExecfuncContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitBlock(MainParser::BlockContext *ctx) override {
        vector<MainParser::StatementContext *> stats = ctx->statement();
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

    antlrcpp::Any visitStatement(MainParser::StatementContext *ctx) override {  
        Statement* stat = nullptr; 
        if(ctx->ret() != nullptr){
            //cout << "hhhhh" << endl;
            stat = visit(ctx->ret()).as<Statement*>();
            //cout << "hhhhh" << endl;
        }
        if(ctx->def() != nullptr){
            //stat = (Return*)visit(ctx->def());
        }
        if(ctx->expr() != nullptr){
            //stat = (Return*)visit(ctx->expr());
        }
        if(ctx->declar() != nullptr){
            //stat = (Return*)visit(ctx->declar());
        }
        
        return stat;
    }

    antlrcpp::Any visitRet(MainParser::RetContext *ctx) override {
        
        Expr* expr = (Expr*)visit(ctx->expr());
        return (Statement*)new Return(expr);
    }

    antlrcpp::Any visitParamdec(MainParser::ParamdecContext *ctx) override {
    return visitChildren(ctx);
    }

    antlrcpp::Any visitParam(MainParser::ParamContext *ctx) override {
    return visitChildren(ctx);
    }

};

