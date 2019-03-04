grammar Main;

prog: main;
main : type 'main' deffunc;

instrprep : 'include' '"' CHAR+ '"'
			| 'include' '<' CHAR+ '>';

direct : '#' instrprep;
			

expr: expr '*' expr
	| expr '/' expr
	| expr '+' expr
	| expr '-' expr
	| INT
	| VAR
	| '(' expr ')'
	| execfunc
	;

declar: type VAR 
	;

affect : '=' expr
	;

def : declar affect ';'
	| VAR affect ';'
	;

deffunc : declar '(' param? ')' body 
	;

execfunc : VAR '(' param? ')';

body : '{' statement* '}';

statement : ret
	| def
	| expr
	| declar
	;

ret : 'return' expr ';';

param : declar (',' declar)*;

type: 'int'
	| 'char'
	| 'void'
	;

FILENAME : [a-zA-Z0-9]+('.'[a-zA-Z0-9]+)*;
PATH : (VAR '/')* FILENAME;
WORD : CHAR*;
INT : [0-9]+ ;
CHAR :  .;
VAR : [a-zA-Z][a-zA-Z0-9]*;
WS : [\t\r\n ] -> skip;

