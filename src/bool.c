#include "../inc/bool.h"

void and() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;

	bool bv1, bv2;

	
	switch (d2.type) {
		case BOOL:
			bv2 = d2.value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL popped.\n" NRM, __FILE__, __func__, __LINE__, (d2.value.bval ? "true" : "false"));
			#endif

			break;
		case VBOOL:
			bv2 = d2.value.var->value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%s\", type VBOOL popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, (d2.value.var->value.bval ? "true" : "false"));
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d2.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d1.type) {
		case BOOL:
			bv1 = d1.value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL popped.\n" NRM, __FILE__, __func__, __LINE__, (d1.value.bval ? "true" : "false"));
			#endif

			break;
		case VBOOL:
			bv1 = d1.value.var->value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%s\", type VBOOL popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, (d1.value.var->value.bval ? "true" : "false"));
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	d.type = BOOL;
	d.value.bval = bv1 && bv2;
	
	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
	#endif

	stack_push(d);
}


void or() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;

	bool bv1, bv2;

	
	switch (d2.type) {
		case BOOL:
			bv2 = d2.value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL popped.\n" NRM, __FILE__, __func__, __LINE__, (d2.value.bval ? "true" : "false"));
			#endif

			break;
		case VBOOL:
			bv2 = d2.value.var->value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%s\", type VBOOL popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, (d2.value.var->value.bval ? "true" : "false"));
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d2.type);
			exit(EXIT_FAILURE);
			break;
	}

	switch (d1.type) {
		case BOOL:
			bv1 = d1.value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL popped.\n" NRM, __FILE__, __func__, __LINE__, (d1.value.bval ? "true" : "false"));
			#endif

			break;
		case VBOOL:
			bv1 = d1.value.var->value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%s\", type VBOOL popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, (d1.value.var->value.bval ? "true" : "false"));
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	d.type = BOOL;
	d.value.bval = bv1 || bv2;
	
	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
	#endif

	stack_push(d);
}


void not() {
	data_t d = stack_pop();
	bool bval;
	
	switch (d.type) {
		case BOOL:
			bval = d.value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL popped.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
			#endif

			break;
		case VBOOL:
			bval = d.value.var->value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%s\", type VBOOL popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, (d.value.var->value.bval ? "true" : "false"));
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}

	d.type = BOOL;
	d.value.bval = !bval;
	
	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
	#endif

	stack_push(d);
}


void inferior() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv2 = d2.value.var->value.dval;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	d.type = BOOL;
	d.value.bval = (iv1 + dv1) < (iv2 + dv2);
	
	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
	#endif

	stack_push(d);
}


void inferior_equal() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv2 = d2.value.var->value.dval;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	d.type = BOOL;
	d.value.bval = (iv1 + dv1) <= (iv2 + dv2);
	
	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
	#endif

	stack_push(d);
}


void superior() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv2 = d2.value.var->value.dval;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	d.type = BOOL;
	d.value.bval = (iv1 + dv1) > (iv2 + dv2);
	
	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
	#endif

	stack_push(d);
}


void superior_equal() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv2 = d2.value.var->value.dval;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	d.type = BOOL;
	d.value.bval = (iv1 + dv1) >= (iv2 + dv2);
	
	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
	#endif

	stack_push(d);
}


void equal() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv2 = d2.value.var->value.dval;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	d.type = BOOL;
	d.value.bval = (iv1 + dv1) == (iv2 + dv2);
	
	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
	#endif

	stack_push(d);
}


void not_equal() {
	data_t d2 = stack_pop();
	data_t d1 = stack_pop();
	data_t d;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d2.value.var->name, d2.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv2 = d2.value.var->value.dval;

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

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		case CONST:
			dv1 = d1.value.var->value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d1.value.var->name, d1.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d1.type);
			exit(EXIT_FAILURE);
			break;
	}

	d.type = BOOL;
	d.value.bval = (iv1 + dv1) != (iv2 + dv2);
	
	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
	#endif

	stack_push(d);
}