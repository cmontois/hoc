%{
	#include "../inc/calc.h"
%}

%union {symbol_t* symbol;}
%token EXIT SYMBOLS PROG STACK NL ADD SUB MUL DIV POW MOD ASG NOT AND OR SUP INF SEQ IEQ EQ NEQ AO AF PV
%token <symbol> INT FLOAT UNDEF VINT VFLOAT CONST PREDEF BOOL VBOOL IF ELSE
%type <symbol> axiom exp asg numvar bool

%left ASG
%left ADD SUB OR XOR
%left MUL DIV POW MOD AND
%nonassoc MINUS NON
%start axiom

%%
axiom:		EXIT							{printf("See you soon !.\n"); return 0;}
		|	NL										{code(STOP); return 1;}
    | exp NL   							{code2(print, STOP); return 1;}
		|	bool NL								{code2(print, STOP); return 1;}
		|	asg NL								{code2(print, STOP); return 1;}
		|	SYMBOLS NL 						{code2(print_symbol_list, STOP); return 1;}
		;

numvar:		VINT							{code2(data_push, (insmac_t) $1);}
		|	VFLOAT								{code2(data_push, (insmac_t) $1);}
		;

boolvar:	VBOOL							{code2(data_push, (insmac_t) $1);}
		;

var:		UNDEF								{code2(data_push, (insmac_t) $1);}
		|	numvar								{}
		|	boolvar								{}
		;

asg:   		var ASG exp     	{code(assign);}
		|	var ASG bool					{code(assign);}
		;

exp:		INT 								{code2(data_push, (insmac_t) $1);}
		|	FLOAT									{code2(data_push, (insmac_t) $1);}	
		|	PREDEF '(' exp ')'		{code2(predef, (insmac_t) $1);}
		|	CONST									{code2(data_push, (insmac_t) $1);}
		|	numvar								{}
		|	'(' exp ')'						{}
		|   SUB exp %prec MINUS {code(negate);}
		|	exp ADD exp 					{code(add);}
		|	exp SUB exp						{code(substract);}
		|	exp MUL exp						{code(multiply);}
		|	exp DIV exp						{code(divide);}
		|	exp POW exp						{code(power);}
		|	exp MOD exp						{code(modulo);}
		| IF '(' bool ')'				{code(if_code);}
		;

bool:		BOOL								{code2(data_push, (insmac_t) $1);}
		|	boolvar								{}
		|	'(' bool ')'					{}
		|	NOT bool %prec NON		{code(not);}
		|	exp INF exp						{code(inferior);}
		|	exp IEQ exp						{code(inferior_equal);}
		|	exp SUP exp						{code(superior);}
		|	exp SEQ exp						{code(superior_equal);}
		|	exp EQ exp						{code(equal);}
		|	exp NEQ exp						{code(not_equal);}
		|	bool AND bool					{code(and);}
		|	bool OR bool					{code(or);}
		;

%%

int main (int argc, char* argv[]) {
	init_prog();
	for (init_code(); yyparse(); init_code()) {
		execute(base_prog);
		#ifdef AUTOCLEAN
			clean_symbol_list();
		#endif
	}
	return 0;
}