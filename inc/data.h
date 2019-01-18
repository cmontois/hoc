#ifndef _DATA_H_
#define _DATA_H_

#include <stdio.h>
#include "color.h"
#include "symbol.h"

typedef union {
	int ival;
	double dval;
	bool bval;
	symbol_t* var;
} dvalue_t;

typedef struct {
	short type;
	dvalue_t value;
} data_t;

#define MAXSTACK 256        // Taille maximale de la pile
data_t stack[MAXSTACK]; 	// La pile
data_t *stack_ptr;       	// Prochain emplacement libre


data_t stack_pop();			// Fonction qui dépile une donnée de la pile
void stack_push(data_t d);				// Fonction qui empile une donnée dans la pile

#endif