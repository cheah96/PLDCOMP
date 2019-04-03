#include "antlr4-runtime.h"
#include "MainBaseVisitor.h"
#include "ast-nodes/Return.h"
#include "ast-nodes/Expression.h"
#include "ast-nodes/Statement.h"
#include "ast-nodes/Block.h"
#include "ast-nodes/Parameter.h"
#include "ast-nodes/Function.h"
#include "ast-nodes/DefFunc.h"
#include "ast-nodes/DecFunc.h"
#include "ast-nodes/Program.h"
#include "ast-nodes/DefVar.h"
#include "ast-nodes/DeclarVar.h"
#include "ast-nodes/Param.h"
#include "ast-nodes/ExecFuncNormal.h"
#include "ast-nodes/ExprStat.h"
#include "ast-nodes/PutChar.h"
#include "ast-nodes/ParamDec.h"
#include "ast-nodes/If.h"
#include "ast-nodes/Else.h"
#include "ast-nodes/While.h"

using namespace std;

/*Visits AST generated by antlr4 and creates our own AST by using our own nodes*/

class Comp : public MainBaseVisitor {

public:
    antlrcpp::Any visitProg(MainParser::ProgContext *context) override {
        Program* prog = new Program;
        vector<MainParser::FunctContext *> funcs = context->funct();
        size_t length = funcs.size();
        for(size_t i = 0; i < length; i++){
            Function* func = (Function*)visit(funcs[i]);
            prog->addFunction(func);
        }
        return prog;
    }

    antlrcpp::Any visitFunct(MainParser::FunctContext *context) override {
        Function* func = nullptr;
        if(context->deffunc() != nullptr){
            func = (Function*)visit(context->deffunc());
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
        return (Expr*)new ExprInt(val);
    }

    antlrcpp::Any visitVar(MainParser::VarContext *context) override {
        string varName = context->VAR()->getText();
        return (Expr*)new ExprVar(varName);
    }

    antlrcpp::Any visitMultdiv(MainParser::MultdivContext *context) override {
        Expr* temp = nullptr;
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

    antlrcpp::Any visitPostop(MainParser::PostopContext *context) override {
		cout << "PostopIN" << endl;
        Expr* ex = nullptr;
		Expr* var = new ExprVar(context->VAR()->getText());
		if(context->children[1]->getText() == "++"){
			ex = new ExprUnary(OPTYPE::POSTINC, var);
		}else if(context->children[1]->getText() == "--"){
			ex = new ExprUnary(OPTYPE::POSTDEC, var);
		}
		cout << "PostopOUT" << endl;
        return ex;
    }

    antlrcpp::Any visitPreop(MainParser::PreopContext *context) override {
		cout << "PreopIN" << endl;
        Expr* ex = nullptr;
		Expr* var = new ExprVar(context->VAR()->getText());
		if(context->children[0]->getText() == "++"){
			ex = new ExprUnary(OPTYPE::PREINC, var);
		}else if(context->children[0]->getText() == "--"){
			ex = new ExprUnary(OPTYPE::PREDEC, var);
		}
		cout << "PreopOUT" << endl;
        return ex;
    }

	antlrcpp::Any visitCmp(MainParser::CmpContext *context) override {
		Expr* op1 = visit(context->expr(0)).as<Expr*>();
        Expr* op2 = visit(context->expr(1)).as<Expr*>();
		Operator* op = visit(context->compare());
		Expr* temp = new ExprBinary(op->getValue(),op1,op2);
		delete op;
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

    antlrcpp::Any visitDefFuncNormal(MainParser::DefFuncNormalContext *context) override {
        string type = context->TYPE()->getText();
        string name = context->VAR()->getText();
        Block* block = (Block*)visit(context->block());
        ParamDec* decs = nullptr;
        if(context->paramdec() != nullptr){
                decs = visit(context->paramdec()).as<ParamDec*>();
        }else{
                cout << "Pas de parametres(Normal)" << endl;
        }
        DefFunc* def = new DefFunc(type,name,block,decs);
        return (Function*)def;
    }

    antlrcpp::Any visitDefFuncVoid(MainParser::DefFuncVoidContext *context) override {
        string name = context->VAR()->getText();
        Block* block = (Block*)visit(context->block());
        ParamDec* decs = nullptr;
        if(context->paramdec() != nullptr){
                decs = visit(context->paramdec()).as<ParamDec*>();
        }else{
                cout << "Pas de parametres(Void)" << endl;
        }
        DefFunc* def = new DefFunc("void",name,block,decs);
        return (Function*)def;
    }

    antlrcpp::Any visitDeclarFuncNormal(MainParser::DeclarFuncNormalContext *context) override {
        return visitChildren(context);
    }

    antlrcpp::Any visitDeclarFuncVoid(MainParser::DeclarFuncVoidContext *context) override {
        return visitChildren(context);
    }

    antlrcpp::Any visitPutchar(MainParser::PutcharContext *context) override{
        Expr* oneExpr = (Expr*)visit(context->expr());
        PutChar* ex = new PutChar("putchar", oneExpr);
        return (Expr*)ex;
    }

    antlrcpp::Any visitNormalExec(MainParser::NormalExecContext *context) override{
        string funcName = context->VAR()->getText();
		Param* myParams = nullptr;
		if(context->param() != nullptr){
			myParams = (Param*)visit(context->param());
		}else{
			cout << "Pas de Param" << endl;
		}
        ExecFuncNormal* ex = new ExecFuncNormal(funcName, myParams);
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
		if(context->ifins() != nullptr){
            stat = visit(context->ifins()).as<Statement*>();
        }
		if(context->whileins() != nullptr){
            stat = visit(context->whileins()).as<Statement*>();
        }
        return stat;
    }

    antlrcpp::Any visitRet(MainParser::RetContext *context) override {
		Statement* stat = nullptr;
		if(context->expr() != nullptr){
			Expr* expr = (Expr*)visit(context->expr());
			stat = new Return(expr);
		}else{
			stat = new Return(nullptr);
		}
        return stat;
    }

    antlrcpp::Any visitParamdec(MainParser::ParamdecContext *context) override {
        ParamDec* decs = new ParamDec;        
        vector<antlr4::tree::TerminalNode *> lesTypes = context->TYPE();
        vector<antlr4::tree::TerminalNode *> lesVars = context->VAR();
        size_t length = lesTypes.size();
        for(size_t i = 0; i < length; i++){
                Parameter* temp = new Parameter(lesVars.at(i)->getText(),lesTypes.at(i)->getText());
                decs->addParameter(temp);
                cout << lesTypes.at(i)->getText() << endl;
                cout << lesVars.at(i)->getText() << endl;
        }
        return decs;
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
	
	antlrcpp::Any visitCompare(MainParser::CompareContext *context) override {
		Operator* op = nullptr;
		if(context->children.size() == 1){
			if(context->children[0]->getText() == ">"){
				op = new Operator(OPTYPE::GREAT);
			}else if(context->children[0]->getText() == "<"){
				op = new Operator(OPTYPE::LESS);
			}
		}else if(context->children.size() == 2){
			if(context->children[0]->getText() == ">" && context->children[0]->getText() == "="){
				op = new Operator(OPTYPE::GREATEQ);
			}else if(context->children[0]->getText() == "<" && context->children[0]->getText() == "="){
				op = new Operator(OPTYPE::LESSEQ);
			}else if(context->children[0]->getText() == "=" && context->children[0]->getText() == "="){
				op = new Operator(OPTYPE::EQUAL);
			}else if(context->children[0]->getText() == "!" && context->children[0]->getText() == "="){
				op = new Operator(OPTYPE::UNEQUAL);
			}
		}
		return op;
	}

	antlrcpp::Any visitIfins(MainParser::IfinsContext *context) override {
		Expr* exp = (Expr*)visit(context->expr());  
		If* ifins = nullptr;
		if(context->statement() != nullptr){
			Statement* stat = (Statement*)visit(context->statement());  
			ifins = new If(exp, stat);
		}else if(context->block() != nullptr){
			Block* block = (Block*)visit(context->block());  
			ifins = new If(exp, block);
		}
		if(context->elseins() != nullptr){
			Else* elseins = (Else*)visit(context->elseins());
			ifins->addElse(elseins);
		}
		return (Statement*)ifins;
    }

    antlrcpp::Any visitElseifins(MainParser::ElseifinsContext *context) override {
        return visitChildren(context);
    }

    antlrcpp::Any visitElseins(MainParser::ElseinsContext *context) override {
		Else* elseins = nullptr;
		if(context->statement() != nullptr){
			Statement* stat = (Statement*)visit(context->statement());  
			elseins = new Else(stat);
		}else if(context->block() != nullptr){
			Block* block = (Block*)visit(context->block());  
			elseins = new Else(block);
		}
        return elseins;
    }

	antlrcpp::Any visitWhileins(MainParser::WhileinsContext *context) override {
		Expr* exp = (Expr*)visit(context->expr());
		While* whileins = nullptr;
		if(context->statement() != nullptr){
			Statement* stat = (Statement*)visit(context->statement());  
			whileins = new While(exp, stat);
		}else if(context->block() != nullptr){
			Block* block = (Block*)visit(context->block());  
			whileins = new While(exp, block);
		}
		return whileins;
	}

};
