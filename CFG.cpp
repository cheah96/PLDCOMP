#include "CFG.h"
#include "Function.h"

CFG::CFG(Function * func)
{
	BasicBlock* bb = new BasicBlock(this);
	bbs.push_back(bb);
	current_bb = bb;
	ast = func;
	nextFreeSymbolIndex = 8;
	nextBBnumber = 1;
	cout << bbs.size()<<endl;
}
void CFG::gen_asm(ostream& o) {
	o << "	.globl	" << ast->getName() << endl;
	o << ast->getName() << ":" << endl;
	gen_asm_prologue(o);
	for (BasicBlock* bb: bbs) {
		bb->gen_asm(o);
	}
	o << endl;
	gen_asm_epilogue(o);
}

string CFG::IR_reg_to_asm(string reg) {
	auto index = SymbolIndex.find(reg);
	if (index == SymbolIndex.end()) {
		return("Erreur");
	}
	return("-"+ to_string(index->second) + "(%rbp)");
}

void CFG::gen_asm_prologue(ostream& o) {
	string pro = "";
    pro += "    pushq   %rbp\n";
    pro += "    movq    %rsp, %rbp\n";
    pro += "    subq    $";
    pro += to_string(nextFreeSymbolIndex);
    pro += ",   %rsp\n";
	o << pro << endl;
}

void CFG::gen_asm_epilogue(ostream& o) {
	string epi = "";
    epi += "    addq    $";
    epi += to_string(nextFreeSymbolIndex);
    epi += ",   %rsp\n";
    epi += "    popq   %rbp\n";
    epi += "    retq\n";
	o << epi;
}

// symbol table methods
void CFG::add_to_symbol_table(string name, Type t) {
	SymbolType.insert(make_pair(name,t));
	SymbolIndex.insert(make_pair(name,nextFreeSymbolIndex));
	nextFreeSymbolIndex +=8;
}

string CFG::create_new_tempvar(Type t) {
	string name = "!tmp" + to_string(nextFreeSymbolIndex);
	add_to_symbol_table(name,t);
	return name;
}
int CFG::get_var_index(string name) {
	auto index = SymbolIndex.find(name);
	if (index == SymbolIndex.end()) {
		return(1);
	}
	return(-1*index->second);
}
Type CFG::get_var_type(string name) {
	auto t = SymbolType.find(name);
	if (t == SymbolType.end()) {
		return(Type("Error"));
	}
	return(t->second);
}
