#include "Expression.h"
#include "../gen-assembly/CFG.h"

string ExprInt::buildIR(CFG * cfg){
    string var = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var);
    params.push_back(to_string(value));
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,this->getType(),params);
    return var;
}

string ExprVar::buildIR(CFG * cfg){
	type = cfg->get_var_type(myName);
    return myName;
}

string ExprChar::buildIR(CFG * cfg){
    string var = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var);
    int valueInt = (int)value;
    params.push_back(to_string(valueInt));
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,this->getType(),params);
    return var;
}

string ExprBinary::buildIR(CFG * cfg){
    OPTYPE value = myOp->getValue();
    string var1 = op1->buildIR(cfg);
    string var2 = op2->buildIR(cfg);
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    switch(value){
        case ADD:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),params);
            break;
        case SUB:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::sub,this->getType(),params);
            break;
        case MULT:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::mul,this->getType(),params);
            break;
        case DIV:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::div,this->getType(),params);
            break;
		case GREAT:
			params.push_back(var3);
            params.push_back(var2);
            params.push_back(var1);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_lt,this->getType(),params);
            break;
		case LESS:
			params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_lt,this->getType(),params);
            break;
		case GREATEQ:
			params.push_back(var3);
            params.push_back(var2);
            params.push_back(var1);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_le,this->getType(),params);
            break;
		case LESSEQ:
		    cout << "dqsdq" << endl;
			params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_le,this->getType(),params);
            break;
		case EQUAL:
			params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_eq,this->getType(),params);
            break;
		case UNEQUAL:
			params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_neq,this->getType(),params);/*ueq*/
            break;
		default:
	    	break;   
    }
    return var3;
}

string ExprUnary::buildIR(CFG * cfg){
    OPTYPE value = myOp->getValue();
    string var = op->buildIR(cfg);
	string returnStr = "";
	vector<string> params;
	string tmp = cfg->create_new_tempvar(this->getType());
	params.push_back(tmp);
	params.push_back("1");
	cfg->current_bb->add_IRInstr(IRInstr::ldconst,this->getType(),params);
	vector<string> para1;
	vector<string> para2;
	vector<string> para3;
	string tmp1 = "";
	string tmp2 = "";
    switch(value){
        case POSTINC:
			cout << "POSTINCINqsf" << endl;
			tmp1 = cfg->create_new_tempvar(this->getType());
			para1.push_back(tmp1);
			para1.push_back(var);
			cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para1);
			tmp2 = cfg->create_new_tempvar(this->getType());
            para2.push_back(tmp2);
            para2.push_back(var);
			para2.push_back(tmp);
            cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),para2);
            para3.push_back(var);
			para3.push_back(tmp2);
            cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para3);
			cout << "POSTINCOUTdsqqsd" << endl;
			returnStr = tmp1;
            break;
        case POSTDEC:
			tmp1 = cfg->create_new_tempvar(this->getType());
			para1.push_back(tmp1);
			para1.push_back(var);
			cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para1);
			tmp2 = cfg->create_new_tempvar(this->getType());
            para2.push_back(tmp2);
            para2.push_back(var);
			para2.push_back(tmp);
            cfg->current_bb->add_IRInstr(IRInstr::sub,this->getType(),para2);
            para3.push_back(var);
			para3.push_back(tmp2);
            cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para3);
			returnStr = tmp1;
            break;
        case PREINC:
			tmp2 = cfg->create_new_tempvar(this->getType());
            para2.push_back(tmp2);
            para2.push_back(var);
			para2.push_back(tmp);
            cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),para2);
            para3.push_back(var);
			para3.push_back(tmp2);
            cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para3);
			returnStr = var;
            break;
        case PREDEC:
			tmp2 = cfg->create_new_tempvar(this->getType());
            para2.push_back(tmp2);
            para2.push_back(var);
			para2.push_back(tmp);
            cfg->current_bb->add_IRInstr(IRInstr::sub,this->getType(),para2);
            para3.push_back(var);
			para3.push_back(tmp2);
            cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para3);
			returnStr = var;
            break; 
		default:
	    	break;  
    }
    return returnStr;
}

string ExprAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
	this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Get the address of the variable
    Type typeInt("int");
    string var = cfg->create_new_tempvar(typeInt);
    int offset = cfg->get_var_index(left);
    vector<string> params1;
    params1.push_back(var);
    params1.push_back(to_string(offset));
    vector<string> params2;
    params2.push_back(var);
    params2.push_back("!bp");
    params2.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params1);
    cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params2);
    //Assignment
    vector<string> params3;
    params3.push_back(var);//Here, we use the value in var
    params3.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    return left;
}

string ExprMultAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Multiplication
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::mul,this->getType(),params);
    //Get the address of the variable
    Type typeInt("int");
    string var = cfg->create_new_tempvar(typeInt);
    int offset = cfg->get_var_index(left);
    vector<string> params1;
    params1.push_back(var);
    params1.push_back(to_string(offset));
    vector<string> params2;
    params2.push_back(var);
    params2.push_back("!bp");
    params2.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params1);
    cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params2);
    //Assignment
    vector<string> params3;
    params3.push_back(var);//Here, we use the value in var
    params3.push_back(var3);
    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    return left;
}

string ExprDivAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Division
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::div,this->getType(),params);
    //Get the address of the variable
    Type typeInt("int");
    string var = cfg->create_new_tempvar(typeInt);
    int offset = cfg->get_var_index(left);
    vector<string> params1;
    params1.push_back(var);
    params1.push_back(to_string(offset));
    vector<string> params2;
    params2.push_back(var);
    params2.push_back("!bp");
    params2.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params1);
    cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params2);
    //Assignment
    vector<string> params3;
    params3.push_back(var);//Here, we use the value in var
    params3.push_back(var3);
    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    return left;
}

string ExprAddAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Addition
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),params);
    //Get the address of the variable
    Type typeInt("int");
    string var = cfg->create_new_tempvar(typeInt);
    int offset = cfg->get_var_index(left);
    vector<string> params1;
    params1.push_back(var);
    params1.push_back(to_string(offset));
    vector<string> params2;
    params2.push_back(var);
    params2.push_back("!bp");
    params2.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params1);
    cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params2);
    //Assignment
    vector<string> params3;
    params3.push_back(var);//Here, we use the value in var
    params3.push_back(var3);
    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    return left;
}

string ExprSubAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Subtraction
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::sub,this->getType(),params);
    //Get the address of the variable
    Type typeInt("int");
    string var = cfg->create_new_tempvar(typeInt);
    int offset = cfg->get_var_index(left);
    vector<string> params1;
    params1.push_back(var);
    params1.push_back(to_string(offset));
    vector<string> params2;
    params2.push_back(var);
    params2.push_back("!bp");
    params2.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params1);
    cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params2);
    //Assignment
    vector<string> params3;
    params3.push_back(var);//Here, we use the value in var
    params3.push_back(var3);
    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    return left;
}
