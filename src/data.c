#include "../inc/data.h"

void stack_push (data_t d) {

	if (stack_ptr >= &stack[MAXSTACK])
		printf(RED "(data.c push) Stack overflow\n" NRM);

	*stack_ptr = d;
	stack_ptr++;
}

data_t stack_pop () {

	if (stack_ptr <= stack)
		printf(RED "(data.c pop) Empty stack\n" NRM);
	
	return *--stack_ptr;
}