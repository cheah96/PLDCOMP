#pragma once
#include "IRInstr.h"
#include <string>
#include <iostream>
/**  The class for a basic block */

/* A few important comments.
	 IRInstr has no jump instructions:
	 assembly jumps are generated as follows in BasicBlock::gen_asm():
     1/ a cmp_* comparison instructions, if it is the last instruction of its block, 
       generates an actual assembly comparison followed by a conditional jump to the exit_false branch
			 If it is not the last instruction of its block, it behaves as an arithmetic two-operand instruction (add or mult)
		 2/ BasicBlock::gen_asm() first calls IRInstr::gen_asm() on all its instructions, and then 
		    if  exit_true  is a  nullptr, it generates the epilogue
				if  exit_false is not a nullptr, and the last instruction is not a cmp, it generates two conditional branches based on the value of the last variable assigned 
        otherwise it generates an unconditional jmp to the exit_true branch 
*/

class CFG;

class BasicBlock {
 public:
	BasicBlock(CFG* cfg, string entry_label = "") : cfg(cfg), label(entry_label) {}
	void gen_asm(ostream &o); /**< x86 assembly code generation for this basic block (very simple) */

	void add_IRInstr(IRInstr::Operation op, Type t, vector<string> params);

	string get_label() { return label;}
	BasicBlock* get_exit_true() { return exit_true; }
	BasicBlock* get_exit_false() { return exit_false; }

	CFG* get_cfg() { return cfg;}

	BasicBlock* get_exit_true(){return exit_true;}

	BasicBlock* get_exit_false(){return exit_false;}

	void set_exit_true(BasicBlock* oneBlock){exit_true = oneBlock;}

	void set_exit_false(BasicBlock* oneBlock){exit_false = oneBlock;}

 protected:
	// No encapsulation whatsoever here. Feel free to do better.
	BasicBlock* exit_true;  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */ 
	BasicBlock* exit_false; /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
	string label; /**< label of the BB, also will be the label in the generated code */
	CFG* cfg; /** < the CFG where this block belongs */
	vector<IRInstr*> instrs; /** < the instructions themselves. */
 
};
