#include "../inc/num.h"

void add() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;
	d.type = INT;
	int iv1 = 0;
	double dv1 = 0;
	int iv2 = 0;
	double dv2 = 0;

	switch (d2.type) {
		case INT:
			iv2 = d2.value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.ival);
			#endif

			break;
		case FLOAT:
			dv2 = d2.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.dval);
			#endif

			break;
		case VINT:
			iv2 = d2.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case UNDEF:
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name);
			#endif
			
			break;
		case CONST:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d2.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d1.type) {
		case INT:
			iv1 = d1.value.ival;
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.ival);
			#endif
			
			break;
		case FLOAT:
			dv1 = d1.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.dval);
			#endif

			break;
		case VINT:
			iv1 = d1.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case UNDEF:

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d.type) {
		case INT:
			d.value.ival = iv1 + dv1 + iv2 + dv2;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			break;
		case FLOAT:
			d.value.dval = iv1 + dv1 + iv2 + dv2;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif
			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d to be pushed. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}
	
	stack_push(d);
}


void substract() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;
	d.type = INT;
	int iv1 = 0;
	double dv1 = 0;
	int iv2 = 0;
	double dv2 = 0;

	switch (d2.type) {
		case INT:
			iv2 = d2.value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.ival);
			#endif

			break;
		case FLOAT:
			dv2 = d2.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.dval);
			#endif

			break;
		case VINT:
			iv2 = d2.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case UNDEF:
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name);
			#endif
			
			break;
		case CONST:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d2.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d1.type) {
		case INT:
			iv1 = d1.value.ival;
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.ival);
			#endif
			
			break;
		case FLOAT:
			dv1 = d1.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.dval);
			#endif

			break;
		case VINT:
			iv1 = d1.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case UNDEF:

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d.type) {
		case INT:
			d.value.ival = iv1 + dv1 - (iv2 + dv2);

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			break;
		case FLOAT:
			d.value.dval = iv1 + dv1 - (iv2 + dv2);

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d to be pushed. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}

	stack_push(d);
}


void negate() {
	data_t d = stack_pop();
	
	switch (d.type) {
		case INT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			d.value.ival = - d.value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif
			
			break;
		case FLOAT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			d.value.dval = - d.value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			break;
		case VINT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, d.value.var->value.ival);
			#endif

			d.value.ival = - d.value.var->value.ival;
			d.type = INT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			break;
		case VFLOAT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, d.value.var->value.dval);
			#endif

			d.value.dval = - d.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			break;
		case UNDEF:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name);
			#endif

			break;
		case CONST:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, d.value.var->value.dval);
			#endif

			d.value.dval = - d.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}

	stack_push(d);
}


void multiply() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;
	d.type = INT;
	int iv1 = 0;
	double dv1 = 0;
	int iv2 = 0;
	double dv2 = 0;

	switch (d2.type) {
		case INT:
			iv2 = d2.value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.ival);
			#endif

			break;
		case FLOAT:
			dv2 = d2.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.dval);
			#endif

			break;
		case VINT:
			iv2 = d2.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case UNDEF:
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name);
			#endif
			
			break;
		case CONST:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d2.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d1.type) {
		case INT:
			iv1 = d1.value.ival;
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.ival);
			#endif
			
			break;
		case FLOAT:
			dv1 = d1.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.dval);
			#endif

			break;
		case VINT:
			iv1 = d1.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case UNDEF:

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d.type) {
		case INT:
			d.value.ival = (iv1 + dv1) * (iv2 + dv2);

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			break;
		case FLOAT:
			d.value.dval = (iv1 + dv1) * (iv2 + dv2);

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d to be pushed. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}

	stack_push(d);
}


void divide() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;
	d.type = INT;
	int iv1 = 0;
	double dv1 = 0;
	int iv2 = 0;
	double dv2 = 0;

	switch (d2.type) {
		case INT:
			iv2 = d2.value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.ival);
			#endif

			break;
		case FLOAT:
			dv2 = d2.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.dval);
			#endif

			break;
		case VINT:
			iv2 = d2.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case UNDEF:
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name);
			#endif
			
			break;
		case CONST:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d2.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d1.type) {
		case INT:
			iv1 = d1.value.ival;
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.ival);
			#endif
			
			break;
		case FLOAT:
			dv1 = d1.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.dval);
			#endif

			break;
		case VINT:
			iv1 = d1.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case UNDEF:

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	if (iv2 + dv2 == 0) {
		printf(RED "(%-16s %-16s %-4d) Division by zero. Exitting...\n" NRM, __FILE__, __func__, __LINE__);
		exit(EXIT_FAILURE);
	}

	switch (d.type) {
		case INT:
			d.value.ival = (iv1 + dv1) / (iv2 + dv2);

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			break;
		case FLOAT:
			d.value.dval = (iv1 + dv1) / (iv2 + dv2);

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d to be pushed. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}

	stack_push(d);
}


void power() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;
	d.type = INT;
	int iv1 = 0;
	double dv1 = 0;
	int iv2 = 0;
	double dv2 = 0;

	switch (d2.type) {
		case INT:
			iv2 = d2.value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.ival);
			#endif

			break;
		case FLOAT:
			dv2 = d2.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.dval);
			#endif

			break;
		case VINT:
			iv2 = d2.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case UNDEF:
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name);
			#endif
			
			break;
		case CONST:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d2.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d1.type) {
		case INT:
			iv1 = d1.value.ival;
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.ival);
			#endif
			
			break;
		case FLOAT:
			dv1 = d1.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.dval);
			#endif

			break;
		case VINT:
			iv1 = d1.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case UNDEF:

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d.type) {
		case INT:
			d.value.ival = pow(iv1 + dv1, iv2 + dv2);

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			break;
		case FLOAT:
			d.value.dval = pow(iv1 + dv1, iv2 + dv2);

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d to be pushed. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}

	stack_push(d);
}


void modulo() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;
	d.type = INT;
	int iv1 = 0;
	double dv1 = 0;
	int iv2 = 0;
	double dv2 = 0;

	switch (d2.type) {
		case INT:
			iv2 = d2.value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.ival);
			#endif

			break;
		case FLOAT:
			dv2 = d2.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.dval);
			#endif

			break;
		case VINT:
			iv2 = d2.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case UNDEF:
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name);
			#endif
			
			break;
		case CONST:
			dv2 = d2.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d2.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d1.type) {
		case INT:
			iv1 = d1.value.ival;
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.ival);
			#endif
			
			break;
		case FLOAT:
			dv1 = d1.value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.dval);
			#endif

			break;
		case VINT:
			iv1 = d1.value.var->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case UNDEF:

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value defaulted to \"0\", type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;
			d.type = FLOAT;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d.type) {
		case INT:
			if (iv2 + dv2 == 0) {
				printf(RED "(%-16s %-16s %-4d) Modulo by 0. Exitting...\n" NRM, __FILE__, __func__, __LINE__);
				exit(EXIT_FAILURE);
			}
			d.value.ival = iv1 % iv2;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			break;
		case FLOAT:			
			printf(RED "(%-16s %-16s %-4d) Modulo with floats. Exitting...\n" NRM, __FILE__, __func__, __LINE__);
			exit(EXIT_FAILURE);
			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d to be pushed. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}

	stack_push(d);
}