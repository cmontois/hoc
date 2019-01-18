#include "../inc/error.h"

void yyerror(char* msg) {
	printf("Syntax Error : [%s]\n", msg);
	printf("Exitting...\n");
	exit(EXIT_FAILURE);
}