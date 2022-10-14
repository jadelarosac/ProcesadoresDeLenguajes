%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tabla_tokens.h"
%}

%option yylineno
%option noyywrap

ENTERO [0-9]*

%%

{ENTERO}  {printf("Entero");}

%%

int main(int argc, char* argv[]){
	yylex();
	return 0;
}


