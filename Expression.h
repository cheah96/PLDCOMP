#pragma once
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "CFG.h"
using namespace std;

enum OPTYPE{
  ADD,SUB,MULT,DIV
};

const string opNames[4] = {"+","-","*","/"};

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

class Expr {
   public:
      Expr() : type("error") { }
      virtual ~Expr(){}
      virtual int eval () = 0;
      virtual void generateCode(ofstream& o) = 0;
      virtual string buildIR(CFG * cfg) = 0;
      virtual Type getType(){
        return type;
      }
    protected:
      Type type;
};

class ExprInt : public Expr {
    public:
      ExprInt(int oneValue) : value(oneValue), type("int") { }
      virtual ~ExprInt(){}
      int eval (){
        return value;
      }
      void generateCode(ofstream& o){
        o << "$" << value;
      }
      string buildIR(CFG * cfg);
    protected:
      int value;
};

class ExprVar : public Expr {
    public:
      ExprVar(string oneName) : myName(oneName), type("int") { }
      virtual ~ExprVar(){}
      int eval (){
        return 0;
      }
      void generateCode(ofstream& o){
      }
      string buildIR(CFG * cfg);
    protected:
      string myName;
};

class ExprBinary : public Expr {
    public:
      ExprBinary(OPTYPE oneType, Expr* oneOp1, Expr* oneOp2) : op1(oneOp1), op2(oneOp2), , type("int") { myOp = new Operator(oneType);}
      virtual ~ExprBinary(){ delete op1; delete op2; delete myOp; }
      int eval (){
        return 0;
      }
      void generateCode(ofstream& o){}
      string buildIR(CFG * cfg);
    protected:
      Expr* op1;
      Expr* op2;
      Operator* myOp;
};