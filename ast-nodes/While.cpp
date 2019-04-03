#include "While.h"

While::While(Expr* oneExpr, Statement* oneStatement) : myCondition(oneExpr)
{
	myBlock = new Block;
	myBlock->addStatement(oneStatement);
}

While::~While()
{
	if(myBlock != nullptr){
		delete myBlock;
	}
	delete myCondition;
}

string While::buildIR(CFG* cfg){
	BasicBlock* beforeWhileBB = cfg->current_bb;
	BasicBlock* testBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->currentBB = testBB;
	myCondition->buildIR(cfg);
	BasicBlock* bodyBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->currentBB = bodyBB;
	myBlock->buildIR(cfg);
	BasicBlock* afterWhileBB = new BasicBlock(cfg, cfg->new_BB_name());
	afterWhileBB->set_exit_true(beforeWhileBB->get_exit_true());
	afterWhileBB->set_exit_false(beforeWhileBB->get_exit_false());
	testBB->set_exit_true(bodyBB);
	testBB->set_exit_false(afterWhileBB);
	bodyBB->set_exit_true(testBB);
	bodyBB->set_exit_false(nullptr);
	cfg->current_bb = afterWhileBB;
    return "";
}
