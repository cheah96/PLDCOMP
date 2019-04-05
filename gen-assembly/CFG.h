#pragma once
/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)

 */
#include "BasicBlock.h"
#include <map>

using namespace std;
class Function; 
class Program;
class CFG {
	public:
		const string param_register[6] = {"rdi","rsi","rdx","rcx","r8","r9"};
		CFG(Function* ast, Program* oneProg);

		Function* ast; /**< The AST this CFG comes from */
		
		void add_bb(BasicBlock* bb); 
		BasicBlock* get_bb_epilog() { return bbs.back(); }

		// x86 code generation: could be encapsulated in a processor class in a retargetable compiler
		void gen_asm(ostream& o);
		string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
		void gen_asm_prologue(ostream& o);
		void gen_asm_epilogue(ostream& o);

		// symbol table methods
		void add_to_symbol_table(string name, Type t);
		string create_new_tempvar(Type t);
		int get_var_index(string name);
		Type get_var_type(string name);

		// basic block management
		string new_BB_name();
		BasicBlock* current_bb;

		//The program node that this CFG belongs to
		Program* prog;

 	protected:
		map <string, Type> SymbolType; /**< part of the symbol table  */
		map <string, int> SymbolIndex; /**< part of the symbol table  */
		int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
		int nextBBnumber; /**< just for naming */
		
		vector <BasicBlock*> bbs; /**< all the basic blocks of this CFG*/
};

