#include "../inc/code.h"

void init_code() {
	base_prog = prog;
	stack_ptr = stack;
	prog_ptr = base_prog;
	returning = 0;
	fprintf(stdout, "> ");
}


char* getname(void *p) {
		for (int i = 0; i < FNUM; i++) {
				if (fnames[i].addr == p)
						return fnames[i].name;
		}
		static char str[50];

		symbol_t* sp = look_up_symbol(((symbol_t*)p)->name);

		switch (sp->type) {
			case INT:
				sprintf(str, "INT %d", sp->value.ival);
				break;
			case VINT:
				sprintf(str, "%s VINT %d", sp->name, sp->value.ival);
				break;
			case FLOAT:
				sprintf(str, "FLOAT %.8g", sp->value.dval);
				break;
			case VFLOAT:
				sprintf(str, "%s VFLOAT %.8g", sp->name, sp->value.dval);
				break;
			case BOOL:
				sprintf(str, "BOOL %s", (sp->value.bval ? "true" : "false"));
				break;
			case VBOOL:
				sprintf(str, "%s VBOOL %s", sp->name, (sp->value.bval ? "true" : "false"));
				break;
			case UNDEF:
				sprintf(str, "%s UNDEF", sp->name);
				break;
			case CONST:
				sprintf(str, "%s CONST %.8g", sp->name, sp->value.dval);
				break;
			case PREDEF:
				sprintf(str, "%s PREDEF", sp->name);
				break;
			default:
				return(RED "Unrecognized" GRN);
				break;
		}
        return str;
}


insmac_t* code (insmac_t f) {
	insmac_t* localisation = prog_ptr;

	if (prog_ptr >= &prog[MAXPROG])
		printf(RED "(%-16s %-16s %-4d) Program size overflow\n" NRM, __FILE__, __func__, __LINE__);

	*prog_ptr++ = f;

	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Address [@%p] --> Instruction [%s]\n" NRM, __FILE__, __func__, __LINE__, localisation, getname(f));
	#endif

	return localisation;
}


void execute(insmac_t* p) {
	current_ptr = p;

    for (; *current_ptr != STOP && !returning;) {
		#ifdef DEBUG
			printf(YEL "(%-16s %-16s %-4d) Executing %s\n" NRM, __FILE__, __func__, __LINE__, getname(*current_ptr));
		#endif
		(*(*current_ptr++)) ();
	}
}


void print() {
	data_t d = stack_pop();

	switch (d.type) {
		case INT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			printf("= %d\n", d.value.ival);
			break;
		case FLOAT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			printf("= %.8g\n", d.value.dval);
			break;
		case BOOL:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL popped.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
			#endif

			printf("is %s\n", d.value.bval ? "true" : "false");
			break;
		case VINT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name);
			#endif

			printf("%s = %d\n", d.value.var->name, d.value.var->value.ival);
			break;
		case VFLOAT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name);
			#endif

			printf("%s = %.8g\n", d.value.var->name, d.value.var->value.dval);
			break;
		case VBOOL:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VBOOL popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name);
			#endif

			printf("%s is %s\n", d.value.var->name, (d.value.var->value.bval ? "true" : "false"));
			break;
		case UNDEF:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name);
			#endif

			printf("%s is undefined\n", d.value.var->name);
			break;
		case CONST:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name);
			#endif

			printf("%s = %.8g\n", d.value.var->name, d.value.var->value.dval);
			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	} 
}


void data_push() {
	data_t d;
	symbol_t* sp = (symbol_t*) *current_ptr++;

	d.type = sp->type;

	switch (d.type) {
		case INT:
			d.value.ival = sp->value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			break;
		case FLOAT:
			d.value.dval = sp->value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			break;
		case BOOL:
			d.value.bval = sp->value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, (d.value.bval ? "true" : "false"));
			#endif

			break;
		case VINT:
			d.value.var = sp;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, d.value.var->value.ival);
			#endif

			break;
		case VFLOAT:
			d.value.var = sp;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, d.value.var->value.dval);
			#endif

			break;
		case VBOOL:
			d.value.var = sp;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%s\", type VBOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, (d.value.var->value.bval ? "true" : "false"));
			#endif

			break;
		case UNDEF:
			d.value.var = sp;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type UNDEF pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name);
			#endif

			break;
		case CONST:
			d.value.var = sp;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, d.value.var->value.dval);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d to be pushed. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}

	stack_push(d);
}


void assign() {
	data_t val = stack_pop();
	data_t v = stack_pop();

	#ifdef DEBUG
		switch (val.type) {
			case INT:
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, val.value.ival);
				break;
			case FLOAT:
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, val.value.dval);
				break;
			case BOOL:
				printf(GRN "(%-16s %-16s %-4d) Value \"%s\" type BOOL popped.\n" NRM, __FILE__, __func__, __LINE__, (val.value.bval ? "true" : "false"));
				break;
			case VINT:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, val.value.var->name, val.value.var->value.ival);
				break;
			case VFLOAT:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, val.value.var->name, val.value.var->value.dval);				
				break;
			case VBOOL:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%s\", type VBOOL popped.\n" NRM, __FILE__, __func__, __LINE__, val.value.var->name, (val.value.var->value.bval ? "true" : "false"));				
				break;
			case UNDEF:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, val.value.var->name);
				break;
			case CONST:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, val.value.var->name, val.value.var->value.dval);				
				break;
			default:
				printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, val.type);
				exit(EXIT_FAILURE);
				break;
		}

		switch (v.type) {
			case VINT:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name, v.value.var->value.ival);
				break;
			case VFLOAT:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name, v.value.var->value.dval);				
				break;
			case VBOOL:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%s\", type VBOOL popped.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name, (v.value.var->value.bval ? "true" : "false"));				
				break;
			case UNDEF:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type UNDEF popped.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
				break;
			case CONST:
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, val.value.var->name, val.value.var->value.dval);				
				printf(RED "(%-16s %-16s %-4d) Cannot assign to CONST. Exitting...\n" NRM, __FILE__, __func__, __LINE__);
				break;
			default:
				printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, v.type);
				exit(EXIT_FAILURE);
				break;
		}
	#endif

	switch (val.type) {
		case INT:
			v.type = VINT;
			v.value.var->type = VINT;
			v.value.var->value.ival = val.value.ival;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Assigning \"%d\" to var \"%s\" type VINT.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->value.ival, v.value.var->name);
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VINT pushed.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
			#endif

			break;
		case FLOAT:
			v.type = VFLOAT;
			v.value.var->type = VFLOAT;
			v.value.var->value.dval = val.value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Assigning \"%.8g\" to var \"%s\" type VFLOAT.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->value.dval, v.value.var->name);
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VFLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
			#endif

			break;
		case BOOL:
			v.type = VBOOL;
			v.value.var->type = VBOOL;
			v.value.var->value.bval = val.value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Assigning \"%s\" to var \"%s\" type VBOOL.\n" NRM, __FILE__, __func__, __LINE__, (v.value.var->value.bval ? "true" : "false"), v.value.var->name);
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VBOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
			#endif

			break;
		case VINT:
			v.type = VINT;
			v.value.var->type = VINT;
			v.value.var->value.ival = val.value.var->value.ival;
			
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Assigning \"%d\" to var \"%s\" type VINT.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->value.ival, v.value.var->name);
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VINT pushed.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
			#endif

			break;
		case VFLOAT:
			v.type = VFLOAT;
			v.value.var->type = VFLOAT;
			v.value.var->value.dval = val.value.var->value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Assigning \"%.8g\" to var \"%s\" type VFLOAT.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->value.dval, v.value.var->name);
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VFLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
			#endif

			break;
		case VBOOL:
			v.type = VBOOL;
			v.value.var->type = VBOOL;
			v.value.var->value.bval = val.value.var->value.bval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Assigning \"%s\" to var \"%s\" type VBOOL.\n" NRM, __FILE__, __func__, __LINE__, (v.value.var->value.bval ? "true" : "false"), v.value.var->name);
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VBOOL pushed.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
			#endif

			break;
		case UNDEF:
			v.type = UNDEF;
			v.value.var->type = UNDEF;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Assigning \"UNDEF\" to var \"%s\" type UNDEF.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type UNDEF pushed.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
			#endif

			break;
		case CONST:
			v.type = VFLOAT;
			v.value.var->type = VFLOAT;
			v.value.var->value.dval = val.value.var->value.dval;

			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Assigning \"%.8g\" to var \"%s\" type VFLOAT.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->value.dval, v.value.var->name);
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\" type VFLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, v.value.var->name);
			#endif

			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d to be pushed. Exitting...\n" NRM, __FILE__, __func__, __LINE__, val.type);
			exit(EXIT_FAILURE);
			break;
	}

	stack_push(v);
}

void predef() {
	data_t d = stack_pop();
	symbol_t* sp = (symbol_t*) *current_ptr++;

	switch (d.type) {
		case INT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%d\" type INT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.ival);
			#endif

			d.type = FLOAT;
			d.value.dval = (*(double (*)()) (sp->value.func)) ((double) d.value.ival);
			
			break;
		case FLOAT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
			#endif

			d.type = FLOAT;
			d.value.dval = (*(double (*)()) (sp->value.func)) ((double) d.value.dval);

			break;
		case VINT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%d\", type VINT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, d.value.var->value.ival);
			#endif

			d.type = FLOAT;
			d.value.dval = (*(double (*)()) (sp->value.func)) ((double) d.value.var->value.ival);

			break;
		case VFLOAT:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type VFLOAT popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, d.value.var->value.dval);
			#endif

			d.type = FLOAT;
			d.value.dval = (*(double (*)()) (sp->value.func)) ((double) d.value.var->value.dval);

			break;
		case CONST:
			#ifdef DEBUG
				printf(GRN "(%-16s %-16s %-4d) Var \"%s\", of value \"%.8g\", type CONST popped.\n" NRM, __FILE__, __func__, __LINE__, d.value.var->name, d.value.var->value.dval);
			#endif

			d.type = FLOAT;
			d.value.dval = (*(double (*)()) (sp->value.func)) ((double) d.value.dval);
			break;
		default:
			printf(RED "(%-16s %-16s %-4d) Data of unrecognized type %d popped. Exitting...\n" NRM, __FILE__, __func__, __LINE__, d.type);
			exit(EXIT_FAILURE);
			break;
	}

	#ifdef DEBUG
		printf(GRN "(%-16s %-16s %-4d) Value \"%.8g\" type FLOAT pushed.\n" NRM, __FILE__, __func__, __LINE__, d.value.dval);
	#endif

	stack_push(d);
}

void if_code() {
	printf('Hello World !');
}