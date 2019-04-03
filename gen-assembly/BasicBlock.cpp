#include "BasicBlock.h"
#include "CFG.h"

void BasicBlock::gen_asm(ostream &o) {
	for (IRInstr* instr : instrs) {
	    /*if (instr == instrs.back() && dynamic_cast<CmpInstr*>(instrs.back()) == nullptr) {
	        switch(instr.getOp()) {
	            case IRInstr::cmp_eq : 
	                o << "   jne  ";
	                break;
	            case IRInstr::cmp_neq : 
	                o << "   je  ";
	                break;
	            case IRInstr::cmp_lt : 
	                o <<  "   jge  ";
	                break;
	            case IRInstr::cmp_le : 
	                o << "   jg  ";
	                break;
	        }
    	    o << exit_false->get_label() <<" \n";
	    }
	    else {
		    instr->gen_asm(o);
		}*/
	    instr->gen_asm(o);
	}
	if (exit_true == nullptr) {
	    o << endl;
		cfg->gen_asm_epilogue(o);
		return;
	}else if (exit_false != nullptr/* && dynamic_cast<CmpInstr*>(instrs.back()) != nullptr*/) {
	    /*cmpl    $0, -4(%rbp)
        jne     .LBB0_2*/
		string lastAssigned = instrs.back().getDestination();
		int offset = get_cfg()->get_var_index(lastAssigned);
		o << "   cmpl   $0, " << offset << "(%rbp)";
		o << "   je  ";
    	o << exit_false->get_label() <<" \n";
	}else {
		o << "   jmp  ";
    	o << exit_true->get_label() <<" \n";
	}
}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type t, vector<string> params) {
	switch(op){
        case IRInstr::ldconst :
			instrs.push_back(new LdconstInstr(this, t, params[0], params[1]));
			break;
		case IRInstr::add :
			instrs.push_back(new AddInstr(this, t, params[0], params[1], params[2]));
			break;
		case IRInstr::sub :
			instrs.push_back(new SubInstr(this, t, params[0], params[1], params[2]));
			break;
		case IRInstr::mul :
			instrs.push_back(new MulInstr(this, t, params[0], params[1], params[2]));
			break;
		case IRInstr::div :
			instrs.push_back(new DivInstr(this, t, params[0], params[1], params[2]));
			break;
		case IRInstr::ret :
			instrs.push_back(new RetInstr(this, t, params[0]));
			break;
		case IRInstr::call :
			instrs.push_back(new CallInstr(this, t, params));
			break;
		case IRInstr::wmem :
			instrs.push_back(new WmemInstr(this, t, params[0],params[1]));
			break;
		case IRInstr::copy :
			instrs.push_back(new CopyInstr(this, t, params[0],params[1]));
			break;
	    case IRInstr::cmp_eq :
	    case IRInstr::cmp_neq :
	    case IRInstr::cmp_lt :
	    case IRInstr::cmp_le :
			instrs.push_back(new CmpInstr(this, op, t, params[0], params[1], params[2]));
			break;
	}
}
