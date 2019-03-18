#include "IRInstr.h"
#include "BasicBlock.h"
#include "CFG.h"

void RetInstr::gen_asm(ostream &o) {
	/*int offset = bb->get_cfg()->get_var_index("retvalue");
	o << "	movq  ";
	o << "$" << value;
    o << "," << offset <<"(%rbp)\n";*/
    int offset = bb->get_cfg()->get_var_index(value);
    o << "	movl  ";
    o << offset <<"(%rbp)";
	o << "," << "%eax\n";
}

void LdconstInstr::gen_asm(ostream &o) {
	int offset = bb->get_cfg()->get_var_index(d);
	o << "	movq  ";
	o << "$" << c;
    o << "," << offset <<"(%rbp)\n";
}


void AddInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	addq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	movq  ";
	o << "%rax, ";
	if(d == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(d);
		o << offset << "(%rbp)\n";
	}
}

void CmpInstr::gen_asm(ostream &o) {

}

void WmemInstr::gen_asm(ostream &o) {
	int offset = bb->get_cfg()->get_var_index(dest);
	o << "	movq  ";
    o << offset <<"(%rbp), %rax\n";	
	offset = bb->get_cfg()->get_var_index(val);
	o << "	movq  ";
    o << offset <<"(%rbp), %r10\n";	
	o << "	movq  ";
    o << "%r10, (%rax)\n";	
}
