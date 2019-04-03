grammar Main;

prog: (funct)*;

funct : deffunc | declarfunc;

	
expr: expr ('*'|'/') expr # multdiv
	| expr ('+'|'-') expr # addsub
	| INT			# const
	| VAR			# var
	|  CHAR 		# char
	| '(' expr ')'  	# par
	| execfunc		# exfunc
	| VAR ('++'|'--')	# postop
	| ('++'|'--') VAR	# preop 
	| expr ('&&'|'||') expr	# exprBin
	| expr compare expr 	# cmp
	;

compare: ('<'|'>') '='?
	| ('!'|'=') '='
	;

ifins: 'if' '(' expr ')' (statement|block) elseifins* elseins?;

elseifins : 'else if' '(' expr ')' (statement|block) ;

elseins: 'else' (statement|block) ; 

whileins : 'while' '(' expr ')' (statement|block) ;

declarvar: TYPE VAR (',' VAR)* ';'
	;

defvar : TYPE VAR '=' expr ';' #defWithDeclar
	| VAR '=' expr ';' #defWithoutDeclar
	;

deffunc : TYPE VAR '(' paramdec? ')' block #defFuncNormal
	| 'void' VAR '(' paramdec? ')' block #defFuncVoid
	;

declarfunc : TYPE VAR '(' paramdec? ')' ';' #declarFuncNormal
	| 'void' VAR '(' paramdec? ')' ';' #declarFuncVoid
	;  

execfunc : 'putchar' '(' expr ')' #putchar
	| VAR '(' param? ')' #normalExec
	;

block : '{' statement* '}';

exprstat : expr ';';

statement : ret
	| defvar
	| exprstat 
	| declarvar
	| ifins
	;

ret : 'return' expr ';';

paramdec : TYPE VAR (',' TYPE VAR)*;

param :  expr (',' expr)*;

TYPE: 'int'
	| 'char'
	;

INT : [0-9]+ ;
VAR : [a-zA-Z][a-zA-Z0-9]*;
CHAR : '\'\\'CHARESC '\''
	| '\'' ~['\\\r\n\t] '\'';
CHARESC : [abefnrtv'"?\\];
WS : [\t\r\n ] -> skip;


