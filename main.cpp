#include <iostream>
#include "antlr4-runtime.h"
#include "MainLexer.h"
#include "MainParser.h"
#include "MainBaseVisitor.h"


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

    cout << "PLD COMP" << endl;

   /*
    Calc visitor;

    int resultat = (int)visitor.visit(tree);

    cout<<"Résultat "<<resultat<<endl;
    */

    return 0;
}