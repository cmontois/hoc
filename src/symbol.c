#include "../inc/symbol.h"

static symbol_t* symbol_list = SYMBOL_NULL;

symbol_t* install (char* name, short type, svalue_t value) {
	symbol_t* sp;

 	sp = (symbol_t*) malloc(sizeof(symbol_t));

	sp->name = malloc(strlen(name)+1);
	strcpy(sp->name, name);
	sp->type = type;
	sp->value = value;
 	sp->next = symbol_list;
	symbol_list = sp;

	#ifdef DEBUG
		switch (type) {
			case INT:
				printf(CYN "(%-16s %-16s %-4d) Token \"%s\" type INT installed, value %d\n" NRM, __FILE__, __func__, __LINE__, sp->name, sp->value.ival);
				break;
			case FLOAT:
				printf(CYN "(%-16s %-16s %-4d) Token \"%s\" type FLOAT installed, value %.8g\n" NRM, __FILE__, __func__, __LINE__, sp->name, sp->value.dval);
				break;
			case UNDEF:
				printf(CYN "(%-16s %-16s %-4d) Token \"%s\" type UNDEF installed\n" NRM, __FILE__, __func__, __LINE__, sp->name);
				break;
			case BOOL:
				printf(CYN "(%-16s %-16s %-4d) Token \"%s\" type BOOL installed, value %d\n" NRM, __FILE__, __func__, __LINE__, sp->name, sp->value.bval);
				break;
			case CONST:
				printf(CYN "(%-16s %-16s %-4d) Token \"%s\" type CONST installed, value %.8g\n" NRM, __FILE__, __func__, __LINE__, sp->name, sp->value.dval);
				break;
			case PREDEF:
				printf(CYN "(%-16s %-16s %-4d) Token \"%s\" type PREDEF installed\n" NRM, __FILE__, __func__, __LINE__, sp->name);
				break;
			case IF:
				printf(CYN "(%-16s %-16s %-4d) Token \"%s\" type IF installed\n" NRM, __FILE__, __func__, __LINE__, sp->name);
				break;
			case ELSE:
				printf(CYN "(%-16s %-16s %-4d) Token \"%s\" type ELSE installed\n" NRM, __FILE__, __func__, __LINE__, sp->name);
				break;
			default:
				printf(RED "(%-16s %-16s %-4d) Token \"%p\" of unrecognized type installed\n" NRM, __FILE__, __func__, __LINE__, sp->name);
				break;
		}
	#endif

	return sp;
}


symbol_t* look_up_symbol (char* name) {
	symbol_t* sp;
	for (sp = symbol_list; sp != SYMBOL_NULL; sp = sp->next)
		if (strcmp(sp->name, name) == 0) return sp;
	return SYMBOL_NULL;
}


void print_symbol_list (void) {
	symbol_t* sp;

	printf("Symbol List : \n");
	printf("\tAddress\t\tName\tType\tValue\n");
	for (sp = symbol_list; sp != SYMBOL_NULL; sp = sp->next) {
		switch (sp->type) {
			case INT:
				printf(CYN "\t%p\t%s\tINT\t%d\n" NRM, sp, sp->name, sp->value.ival);
				break;
			case FLOAT:
				printf(CYN "\t%p\t%s\tFLOAT\t%.8g\n" NRM, sp, sp->name, sp->value.dval);
				break;
			case BOOL:
				printf(CYN "\t%p\t%s\tBOOL\t%s\n" NRM, sp, sp->name, (sp->value.bval ? "true" : "false"));
				break;
			case VINT:
				printf(CYN "\t%p\t%s\tVINT\t%d\n" NRM, sp, sp->name, sp->value.ival);
				break;
			case VFLOAT:
				printf(CYN "\t%p\t%s\tVFLOAT\t%.8g\n" NRM, sp, sp->name, sp->value.dval);
				break;
			case VBOOL:
				printf(CYN "\t%p\t%s\tVBOOL\t%s\n" NRM, sp, sp->name, (sp->value.bval ? "true" : "false"));
				break;
			case UNDEF:
				printf(RED "\t%p\t%s\tUNDEF\t\n" NRM, sp, sp->name);
				break;
			case CONST:
				printf(YEL "\t%p\t%s\tCONST\t%.8g\n" NRM, sp, sp->name, sp->value.dval);
				break;
			case PREDEF:
				printf(YEL "\t%p\t%s\tPREDEF\t\n" NRM, sp, sp->name);
				break;
			default:
				printf(RED "\t%p\t%s\tERROR\t\n" NRM, sp, sp->name);
				break;
		}
	}
}

void clean_symbol_list (void) {
	symbol_t* previous_sp;
	symbol_t* sp;

	for (sp = symbol_list; sp != SYMBOL_NULL; sp = sp->next) {	
		if (strlen(sp->name) == 0) {
			if (sp != symbol_list) previous_sp->next = sp->next;
			else symbol_list = sp->next;
			free(sp);
		}
		previous_sp = sp;
	}
}