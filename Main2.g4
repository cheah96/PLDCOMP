grammar Main;

prog: direct* (funct)*;

funct : deffunc | declarfunc;

instrprep : 'include' '"' FILENAME '"'
			| 'include' '<' FILENAME '>';

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

FILENAME : [a-zA-Z0-9]+('.'[a-zA-Z0-9]+)*;
PATH : (VAR '/')* FILENAME;
INT : [0-9]+ ;
VAR : [a-zA-Z][a-zA-Z0-9]*;
WS : [\t\r\n ] -> skip;

