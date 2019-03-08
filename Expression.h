#pragma once
#include <string>
#include <map>
using namespace std;

class Expr {
   public:
      Expr() { }
      virtual ~Expr(){}
      virtual int eval () = 0;
    
};

class ExprInt : public Expr {
    public:
      ExprInt(int oneValue) : value(oneValue) { }
      virtual ~ExprInt(){}
      int eval (){
        return value;
      }
    protected:
      int value;
};