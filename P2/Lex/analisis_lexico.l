%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tabla_tokens.h"
%}

%option yylineno
%option noyywrap


%%

("real"|"booleano"|"caracter"|"entero") {printf("%d\t", TIPOEL);}
"programa_principal("[[:space:]]+")" {printf("%d\t", MAIN);}
"retornar" {printf("%d\t", DEVOLVER);}
"leer" {printf("%d\t", ENTRADA);}
"escribir" {printf("%d\t", SALIDA);}
"fin"[[:space:]]+"declarar" {printf("%d\t", FINDEC );}
"declarar" {printf("%d\t", INIDEC);}
"hasta"[[:space:]]+"que" {printf("%d\t", HASTA);}
"hacer" {printf("%d\t", HACER);}
"mientras" {printf("%d\t", MIENTRAS);}
"si"[[:space:]]+"no" {printf("%d\t", SINO);}
"si" {printf("%d\t", SI);}
"," {printf("%d\t", COMA);}
";" {printf("%d\t", PYC);}
"}" {printf("%d\t", LLADER);}
"{" {printf("%d\t", LLAIZQ);}
")" {printf("%d\t", PARDER);}
"(" {printf("%d\t", PARIZQ);}
"]" {printf("%d\t", CORDER);}
"[" {printf("%d\t", CORIZQ);}
"=" {printf("%d\t", ASIG);}
("+"|"-") {printf("%d\t", OPMIX);}
"!" {printf("%d\t", OPUN);}
("*"|"/"|"**"|"&&"|"||"|"=="|"!="|"<="|">="|"<"|">"|"%") {printf("%d\t", OPBIN);}
\"[^\"]+\" {printf("%d\t", CADENA);}
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|"_"|[0-9])* {printf("%d\t", IDEN);}
(\'[^\']\'|[0-9]+|[0-9+]\.[0-9]+|"cierto"|"falso") {printf("%d\t", CONST);}
[[:space:]] {}
. {printf("ERROR LÉXICO\n");return -1;}
%%

int main(int argc, char* argv[]){
	yylex();
	return 0;
}

