%{
	#include <stdio.h>
	#include <string.h>
	#include "../inc/symbol.h"
	#include "../inc/calc.tab.h"
	#include "../inc/color.h"
%}


exit			("exit"|"quit")
symbols		("symbols")
true			("true"|"True"|"TRUE")
false			("false"|"False"|"FALSE")
not				("not"|"Not"|"NOT")
and				("and"|"And"|"AND")
or				("or"|"Or"|"OR")
nl				\n
int				[0-9]+
float			[0-9]*"."[0-9]*
wrd     	[A-Za-z][A-Za-z0-9]*
add				"+"
sub				"-"
mul				"*"
div				"/"
pow				"^"
mod				"%"
sup				">"
seq				">="
inf				"<"
ieq				"<="
eq				"=="
neq				"!="
asg				"="
if				"if"
else			"else"
ao 				"{"
af 				"}"
pv 				";"



%%
{exit}		{return EXIT;};
{symbols}	{return SYMBOLS;};
{nl}			{return NL;};
{add}			{return ADD;};
{sub}			{return SUB;};
{mul}			{return MUL;};
{div}			{return DIV;};
{pow}			{return POW;};
{mod}			{return MOD;};
{asg}			{return ASG;};
{sup}			{return SUP;};
{inf}			{return INF;};
{seq}			{return SEQ;};
{ieq}			{return IEQ;};
{eq}			{return EQ;};
{neq}			{return NEQ;};
{not}			{return NOT;};
{and}			{return AND;};
{or}			{return OR;};
{ao}			{return AO;};
{af}			{return AF;};
{pv}			{return PV;};
{int}			{
						svalue_t v;
						v.ival = atoi(yytext);
						yylval.symbol = install("", INT, v);
						
						return INT;
					};
{float} 	{
						svalue_t v;
						v.dval = atof(yytext);
						yylval.symbol = install("", FLOAT, v);

						return FLOAT;
					};
{true}		{
						svalue_t v;
						v.bval = true;
						yylval.symbol = install("", BOOL, v);

						return BOOL;
					};
{false}		{
						svalue_t v;
						v.bval = false;
						yylval.symbol = install("", BOOL, v);

						return BOOL;
					};
{wrd}   	{
						symbol_t* sp;
						if ((sp=look_up_symbol(yytext)) == SYMBOL_NULL)	
							sp = install(yytext, UNDEF, SVALUE_NULL);
							
						yylval.symbol = sp;
						return sp->type;
					};
<<EOF>>		{return EXIT;};
[ \t]			;
.					{return yytext[0];};
%%