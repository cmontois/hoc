#ifndef _CODE_H_
#define _CODE_H_

#include "symbol.h"
#include "data.h"
#include "color.h"
#include "num.h"
#include "bool.h"

typedef void (*insmac_t) ();
#define STOP (insmac_t) 0
#define MAXPROG 2000
insmac_t 	prog[MAXPROG];	// Table du code intermédiaire
insmac_t* 	prog_ptr; 	// Pointeur sur la première case libre de la table
insmac_t* 	current_ptr;	// Pointeur sur la prochaine instruction à exécuter
insmac_t* 	base_prog;	// Debut de sous programme
int returning;

insmac_t* code(insmac_t f);	 	// Fonction qui range une instruction dans la table
#define code2(c1,c2)	code(c1); code(c2)
#define code3(c1,c2,c3)	code(c1); code(c2); code(c3)
void execute(insmac_t *p);			// Fonction d’exécution du code intermédiaire

void init_code();
void print();
void data_push();
void assign();
void predef();

#define FNUM 22

static struct fnc {
    void *addr;
    char name[32];}
fnames[FNUM] = {
	print, 							"print",
	data_push, 					"data_push",
	add, 								"add",
	substract,					"substract",
	negate, 						"negate",
	multiply, 					"multiply",
	divide,							"divide",
	power,							"power",
	modulo,							"modulo",
	assign,							"assign",
	predef,							"predef",
	print_symbol_list, 	"print_symbol_list",
	not,								"not",
	and,								"and",
	or,									"or",
	inferior,						"inferior",
	inferior_equal,			"inferior_equal",
	superior,						"superior",
	superior_equal,			"superior_equal",
	equal,							"equal",
	not_equal,					"not_equal",
	if_code, 						"if_code",
	0,									"STOP",
};

char* getname(void*);

#endif