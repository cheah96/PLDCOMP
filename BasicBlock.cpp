#include "BasicBlock.h"
#include "CFG.h"

void BasicBlock::gen_asm(ostream &o) {
	for (IRInstr* instr : instrs) {
		instr->gen_asm(o);
	}
	/*if (exit_true == nullptr) {
		cfg->gen_asm_epilogue(o);
		return;
	}else if (exit_false != nullptr && dynamic_cast<CmpInstr*>(instrs.back()) != nullptr) {
		

	}else {
		o << "   jmp  ";
    	o << exit_true->get_label() <<" \n";
	}*/
}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type t, vector<string> params) {
	switch(op){
		case IRInstr::ldconst :
			instrs.push_back(new LdconstInstr(this, t, params[0], params[1]));
			break;
		case IRInstr::add :
			instrs.push_back(new AddInstr(this, t, params[0], params[1], params[2]));
			break;
		case IRInstr::ret :
			instrs.push_back(new RetInstr(this, t, params[0]));
			break;
		case IRInstr::wmem :
			instrs.push_back(new WmemInstr(this, t, params[0],params[1]));
			break;
	}
}
