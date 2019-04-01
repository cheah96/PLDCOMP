#include "IRInstr.h"
#include "BasicBlock.h"
#include "CFG.h"

void RetInstr::gen_asm(ostream &o) {
	Type retType = bb->get_ftg()->get_var_type("retValue");
	if(retType.getText()!= "void"){
	    int offsetReturn = bb->get_cfg()->get_var_index("retValue");
	    int offsetValue = bb->get_cfg()->get_var_index(value);
	    if(retType.getText() == "int"){
		    o << "	movl  ";
        	o << offsetValue <<"(%rbp)";
		    o << "," << offset <<"(%rbp)";
	    }else if(retType.getText() == "char"){
		    o << "	movb  ";
        	o << offset <<"(%rbp)";
		    o << "," << offset <<"(%rbp)";
	    }
	}
}

void LdconstInstr::gen_asm(ostream &o) {
	int offset = bb->get_cfg()->get_var_index(d);
	if(t.getText() == "int"){
		o << "	movq  ";
		o << "$" << c;
    	o << "," << offset <<"(%rbp)\n";
	}else if(t.getText() == "char"){
		o << "	movb  ";
		o << "$" << c;
    	o << "," << offset <<"(%rbp)\n";
	}	
}

void CopyInstr::gen_asm(ostream &o) {
	int offsetD = bb->get_cfg()->get_var_index(d);
	int offsetS = bb->get_cfg()->get_var_index(s);
	if(t.getText() == "int"){
		o << "\n";
		o << "	movq  ";
		o << offsetS <<"(%rbp)";
    	o << "," << "%rax\n";
		o << "	movq  ";
		o << "%rax";
    	o << "," << offsetD <<"(%rbp)\n";
		o << "\n";
	}else if(t.getText() == "char"){
		o << "	movb  ";
		o << offsetS <<"(%rbp)";
    	o << "," << "%dl\n";
		o << "	movb  ";
		o << "%dl";
    	o << "," << offsetD <<"(%rbp)\n";
	}	
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

void SubInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	subq  ";
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

void MulInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	mulq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o << "\n";
	/*o <<", %rax\n";*/
	
	o << "	movq  ";
	o << "%rax, ";
	if(d == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(d);
		o << offset << "(%rbp)\n";
	}
}

void DivInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	o << "	divq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<"\n";
	
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

void CallInstr::gen_asm(ostream &o) {
	int offset;
	if(params.size() > 6) {
	    cout << "Error";
	}
	for(int i =0; i<params.size(); ++i) {
	    offset = bb->get_cfg()->get_var_index(params[i]);
	    o << "        movq    ";
	    o << offset << "(%rbp), ";
	    o << "%" << ParamRegister[i] << "\n";
	}
	o << "        call " << label << "\n";
}

void WmemInstr::gen_asm(ostream &o) {
	int offset = bb->get_cfg()->get_var_index(dest);
	if(t.getText() == "int"){
		o << "	movq  ";
		o << offset <<"(%rbp), %rax\n";	
		offset = bb->get_cfg()->get_var_index(val);
		o << "	movq  ";
		o << offset <<"(%rbp), %r10\n";	
		o << "	movq  ";
		o << "%r10, (%rax)\n";	
	}else if(t.getText() == "char"){
		o << "	movq  ";
		o << offset <<"(%rbp), %rax\n";	
		offset = bb->get_cfg()->get_var_index(val);
		o << "	movb  ";
		o << offset <<"(%rbp), %dl\n";	
		o << "	movb  ";
		o << "%dl, (%rax)\n";
	}	
}
