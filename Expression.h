#pragma once
#include <string>
#include <map>
#include <fstream>
using namespace std;

enum OPTYPE{
  ADD,MULT,DIV,SUB
};

class Expr {
   public:
      Expr() { }
      virtual ~Expr(){}
      virtual int eval () = 0;
      virtual void generateCode(ofstream& o) = 0;
};

class ExprInt : public Expr {
    public:
      ExprInt(int oneValue) : value(oneValue) { }
      virtual ~ExprInt(){}
      int eval (){
        return value;
      }
      void generateCode(ofstream& o){
        o << "$" << value;
      }
    protected:
      int value;
};

class ExprBinary : public Expr {
    public:
      ExprBinary(OPTYPE oneType, Expr* oneOp1, Expr* oneOp2) : myType(oneType), op1(oneOp1), op2(oneOp2) { }
      virtual ~ExprBinary(){}
      int eval (){
        return 0;
      }
      void generateCode(ofstream& o){}
    protected:
      Expr* op1;
      Expr* op2;
      OPTYPE myType;
};