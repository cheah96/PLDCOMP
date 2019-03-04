grammar Main;

prog: (funct)*;

funct : deffunc | declarfunc;

	
expr: expr '*' expr
	| expr '/' expr
	| expr '+' expr
	| expr '-' expr
	| INT
	| VAR
	| '(' expr ')'
	| execfunc
	;

declar: TYPE VAR (',' VAR)* ';'
	;

affect : '=' expr
	;

def : TYPE VAR affect ';'
	| VAR affect ';'
	;

deffunc : TYPE VAR '(' paramdec? ')' body 
	;

declarfunc : TYPE VAR '(' paramdec? ')' ';';  

execfunc : VAR '(' param? ')';

body : '{' statement* '}';

statement : ret
	| def
	| expr
	| declar
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
WS : [\t\r\n ] -> skip;

