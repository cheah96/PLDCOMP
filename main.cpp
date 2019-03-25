#include <iostream>
#include "antlr4-runtime.h"
#include "MainLexer.h"
#include "MainParser.h"
#include "Comp.h"
#include "MainBaseVisitor.h"
#include "dotexport.h"
#include <string>

using namespace antlr4;
using namespace std;

int main(int , const char **) 
{
    ifstream is ("ret42.c");

    if (!is) 
    {
        cout << "erreur ouverture fichier" << endl;
        return -1;
    }

    ANTLRInputStream input(is);

    MainLexer lexer(&input);

    CommonTokenStream tokens(&lexer);

    MainParser parser(&tokens);

    tree::ParseTree* tree = parser.prog();

    DotExport dotexport(&parser);
    tree::ParseTreeWalker::DEFAULT.walk(&dotexport,tree);
    ofstream out;
    out.open("tmp.dot");
    out<<dotexport.getDotFile();
    out.close();
    system("dot -Tpdf -o out.pdf tmp.dot");
   
    Comp visitor;


    Program* prog = (Program*)visitor.visit(tree);
    prog->buildIR();
    ofstream o;
    o.open("test.s");

    prog->generateCode(o);
	cout << "PLD COMP Success" << endl;
    
    //cout << r <<endl;

    
    return 0;
}
