#pragma once
#include <string>
#include <map>
#include <fstream>
using namespace std;

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