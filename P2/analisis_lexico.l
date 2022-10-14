%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tabla_tokens.h"
%}

%option yylineno
%option noyywrap


%%

("real"|"booleano"|"caracter"|"entero") {printf("%d", TIPOEL);}
"programa_principal()" {printf("%d", MAIN);}
"retornar" {printf("%d", DEVOLVER);}
"leer" {printf("%d", ENTRADA);}
"escribir" {printf("%d", SALIDA);}
"fin declarar" {printf("%d", FINDEC );}
"declarar" {printf("%d", INIDEC);}
"hasta que" {printf("%d", HASTA);}
"hacer" {printf("%d", HACER);}
"mientras" {printf("%d", MIENTRAS);}
"si no" {printf("%d", SINO);}
"si" {printf("%d", SI);}
"," {printf("%d", COMA);}
";" {printf("%d", PYC);}
"}" {printf("%d", LLADER);}
"{" {printf("%d", LLAIZQ);}
")" {printf("%d", PARDER);}
"(" {printf("%d", PARIZQ);}
"]" {printf("%d", CORDER);}
"[" {printf("%d", CORIZQ);}
"=" {printf("%d", ASIG);}
("+"|"-") {printf("%d", OPMIX);}
"!" {printf("%d", OPUN);}
("*"|"/"|"**"|"&&"|"||"|"=="|"!="|"<="|">="|"<"|">"|"%") {printf("%d", OPBIN);}
\"[^\"]+\" {printf("%d", CADENA);}
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|"_"|[0-9])* {printf("%d", IDEN);}
(\'[^\']\'|[0-9]+|[0-9+]\.[0-9]+|"cierto"|"falso") {printf("%d", CONST);}
. {return -1;}
%%

int main(int argc, char* argv[]){
	yylex();
	return 0;
}


