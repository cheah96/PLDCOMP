#pragma once
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Type.h"
using namespace std;

class CFG;

enum OPTYPE{
  ADD,SUB,MULT,DIV,POSTINC,POSTDEC,PREINC,PREDEC,GREAT,LESS,GREATEQ,LESSEQ,EQUAL,UNEQUAL
};

const string opNames[14] = {"+","-","*","/","++","--","++","--",">","<",">=","<=","==","!="};

/*Node which represents the operator of binary expression*/

/*Node which represents the operator of binary expression*/

/*Node which represents the operator of binary expression*/

class Operator{
	public:
		Operator(OPTYPE oneValue) : value(oneValue) { }
			virtual ~Operator(){}
		string getName(){
			return opNames[value];
		}
		OPTYPE getValue(){
			return value;
		}
    protected:
		OPTYPE value;
};

/*Node which represents an expression*/

class Expr {
   public:
		Expr() : type("unknown") { }
		virtual ~Expr(){}
		virtual int eval () = 0;
		/*Creates the correspondant IR instruction of this node in CFG*/
		virtual string buildIR(CFG * cfg) = 0;
		virtual Type getType(){
			return type;
		}
    protected:
		Type type;
};

class ExprInt : public Expr {
    public:
		ExprInt(int oneValue) : value(oneValue) { type=Type("int"); }
		virtual ~ExprInt(){}
		int eval (){
			return value;
		}
		string buildIR(CFG * cfg);
    protected:
		int value;
};

class ExprVar : public Expr {
    public:
		ExprVar(string oneName) : myName(oneName) {type=Type("int"); }
		virtual ~ExprVar(){}
		int eval (){
			return 0;
		}
		string buildIR(CFG * cfg);
    protected:
		string myName;
};

class ExprChar : public Expr {
    public:
		ExprChar(char oneChar) : value(oneChar) {type=Type("char"); }
		virtual ~ExprChar(){}
		int eval (){
			return 0;
		}
		string buildIR(CFG * cfg);
    protected:
		char value;
};

class ExprBinary : public Expr {
    public:
		ExprBinary(OPTYPE oneType, Expr* oneOp1, Expr* oneOp2) : op1(oneOp1), op2(oneOp2){ myOp = new Operator(oneType); type=Type("int");}
		virtual ~ExprBinary(){ delete op1; delete op2; delete myOp; }
		int eval (){
			return 0;
		}
		string buildIR(CFG * cfg);
    protected:
		Expr* op1;
		Expr* op2;
		Operator* myOp;
};

class ExprUnary : public Expr {
    public:
		ExprUnary(OPTYPE oneType, Expr* oneOp) : op(oneOp){ myOp = new Operator(oneType); type=Type("int");}
		virtual ~ExprUnary(){ delete op;delete myOp; }
		int eval (){
			return 0;
		}
		string buildIR(CFG * cfg);
    protected:
		Expr* op;
		Operator* myOp;
};
