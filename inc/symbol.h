#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "color.h"

typedef union {
	int ival;
	double dval;
	double (* func)();
	bool bval;
} svalue_t;

typedef struct symbol {
	char* name;
	short type;
	svalue_t value;
	struct symbol* next;
}	symbol_t;

#ifndef _CALC_Y_
#define _CALC_Y
#include "calc.tab.h"
#endif

#define SVALUE_NULL	((svalue_t) 0)
#define SYMBOL_NULL ((symbol_t*) 0)

/**
 * Installe un symbole dans la table 
 */
symbol_t* install (char* name, short type, svalue_t value);
/**
 * Recherche un symbole dans la table 
 */
symbol_t* look_up_symbol (char* name);
/**
 * Affiche les symboles définis
 */
void print_symbol_list(void);
/**
 * Efface les symboles anonymes de la table
 */
void clean_symbol_list(void); 
#endif