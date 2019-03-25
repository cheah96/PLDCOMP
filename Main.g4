grammar Main;

prog: (funct)*;

funct : deffunc | declarfunc;

	
expr: expr ('*'|'/') expr # multdiv
	| expr ('+'|'-') expr # addsub
	| INT			# const
	| VAR			# var
	|  CHAR 		# char
	| '(' expr ')'  # par
	| execfunc		# exfunc
	;

declarvar: TYPE VAR (',' VAR)* ';'
	;

defvar : TYPE VAR '=' expr ';' #defWithDeclar
	| VAR '=' expr ';' #defWithoutDeclar
	;

deffunc : TYPE VAR '(' paramdec? ')' block 
	;

declarfunc : TYPE VAR '(' paramdec? ')' ';';  

execfunc : VAR '(' param? ')';

block : '{' statement* '}';

exprstat : expr ';';

statement : ret
	| defvar
	| exprstat 
	| declarvar
	;

ret : 'return' expr ';';

paramdec : TYPE VAR (',' TYPE VAR)*;

param :  expr (',' expr)*;

TYPE: 'int'
	| 'char'
	| 'void'
	;

INT : [0-9]+ ;
VAR : [a-zA-Z][a-zA-Z0-9]*;
CHAR : '\'\\'CHARESC '\''
	| '\'' ~['\\\r\n\t] '\'';
CHARESC : [abefnrtv'"?\\];
WS : [\t\r\n ] -> skip;


