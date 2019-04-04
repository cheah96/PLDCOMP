#include "If.h"

If::If(Expr* oneExpr, Statement* oneStatement) : myCondition(oneExpr)
{
	myBlock = new Block;
	myBlock->addStatement(oneStatement);
	myElse = nullptr;
}

If::~If()
{
	if(myBlock != nullptr){
		delete myBlock;
	}
	if(myElse != nullptr){
		delete myElse;
	}
	delete myCondition;
}

string If::buildIR(CFG* cfg){
    string var = myCondition->buildIR(cfg);
	BasicBlock* testBB = cfg->current_bb;
	BasicBlock* thenBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(thenBB);
	BasicBlock* afterIfBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(afterIfBB);
	if(myElse != nullptr){
		BasicBlock* elseBB = new BasicBlock(cfg, cfg->new_BB_name());
        cfg->add_bb(elseBB);	
		afterIfBB->set_exit_true(testBB->get_exit_true());
		afterIfBB->set_exit_false(testBB->get_exit_false());
		testBB->set_exit_true(thenBB);
		testBB->set_exit_false(elseBB);
		thenBB->set_exit_true(afterIfBB);
		thenBB->set_exit_false(nullptr);
		elseBB->set_exit_true(afterIfBB);
		elseBB->set_exit_false(nullptr);
		cfg->current_bb = elseBB;
		myElse->buildIR(cfg);
	}else{
		afterIfBB->set_exit_true(testBB->get_exit_true());
		afterIfBB->set_exit_false(testBB->get_exit_false());
		testBB->set_exit_true(thenBB);
		testBB->set_exit_false(afterIfBB);
		thenBB->set_exit_true(afterIfBB);
		thenBB->set_exit_false(nullptr);
	}
	cfg->current_bb = thenBB;
	myBlock->buildIR(cfg);
	cfg->current_bb = afterIfBB;
    return "";
}
