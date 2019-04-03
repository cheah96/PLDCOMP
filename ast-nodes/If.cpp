#include "If.h"

If::If(Expr* oneExpr, Statement* oneStatement) : myCondition(oneExpr)
{
	myBlock = new Block;
	myBlock->addStatement(oneStatement);
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
    /*string var = myCondition->buildIR(cfg);
	vector<string> params;
	string var3 = cfg->create_new_tempvar(this->getType());
	params.push_back(var3);
    params.push_back(var);
    params.push_back("0");
    cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),params);
	cfg->current_bb->
	BasicBlock* testBB = cfg->current_bb;
	BasicBlock* thenBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(thenBB);
	cfg->current_bb = thenBB;
	myBlock->buildIR(cfg);
	if(myElse != nullptr){
		BasicBlock* elseBB = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(elseBB);
		cfg->current_bb = elseBB;
		myElse->buildIR(cfg);
		BasicBlock* afterIfBB = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(afterIfBB);
		afterIfBB->set_exit_true(testBB->get_exit_true());
		afterIfBB->set_exit_false(testBB->get_exit_false());
		testBB->set_exit_true(thenBB);
		testBB->set_exit_false(elseBB);
		thenBB->set_exit_true(afterIfBB);
		thenBB->set_exit_false(nullptr);
		elseBB->set_exit_true(afterIfBB);
		elseBB->set_exit_false(nullptr);
		cfg->current_bb = afterIfBB;
	}else{
		BasicBlock* afterIfBB = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(afterIfBB);
		afterIfBB->set_exit_true(testBB->get_exit_true());
		afterIfBB->set_exit_false(testBB->get_exit_false());
		testBB->set_exit_true(thenBB);
		testBB->set_exit_false(nullptr);
		thenBB->set_exit_true(afterIfBB);
		thenBB->set_exit_false(nullptr);
		cfg->current_bb = afterIfBB;
	}*/
    return "";
}
