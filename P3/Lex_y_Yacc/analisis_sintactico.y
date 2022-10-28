%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void yyerror(char * msg);

int linea_actual = 1;
%}

//%error-verbose is deprecated, we use instead:
%define parse.error verbose

%token CONST IDEN CADENA OPBIN OPUN OPMIX ASIG CORIZQ CORDER PARIZQ PARDER LLAIZQ LLADER PYC COMA SI SINO MIENTRAS HACER HASTA INIDEC FINDEC SALIDA ENTRADA DEVOLVER MAIN TIPOEL

%%

Programa                    : Cabecera_programa bloque
bloque                      : Inicio_de_bloque
                                  Declar_de_variables_locales
                                  Declar_subprogs
                                  Sentencias Fin_de_bloque
Declar_subprogs             : Declar_subprog Declar_subprogs
                              |
Declar_subprog              : Cabecera_subprog bloque
Declar_de_variables_locales : Marca_ini_declar_variables
                                  Variables_locales
                                  Marca_fin_declar_variables
                              |
Marca_ini_declar_variables  : INIDEC
Marca_fin_declar_variables  : FINDEC
Cabecera_programa           : MAIN
Inicio_de_bloque            : LLAIZQ
Fin_de_bloque               : LLADER
Variables_locales           : Variables_locales Cuerpo_declar_variables
                              |   Cuerpo_declar_variables
Cuerpo_declar_variables      : tipo lista_declaracion_variables PYC
Cabecera_subprog            : tipo variable PARIZQ argumentos PARDER
                              |   tipo variable PARIZQ PARDER
argumentos                  : tipo variable
                              |   tipo variable COMA argumentos
variable                    : identificador
                              |   elemento_de_array
elemento_de_array           : identificador CORIZQ expresion CORDER
                              |   identificador CORIZQ expresion
                              COMA expresion CORDER
Sentencias                  : Sentencias Sentencia
                              |   Sentencia
Sentencia                   : bloque
                              |   sentencia_asignacion
                              |   sentencia_si
                              |   sentencia_mientras
                              |   sentencia_hacer_hasta
                              |   sentencia_entrada
                              |   sentencia_salida
                              |   sentencia_retornar
sentencia_asignacion        : variable ASIG expresion PYC
sentencia_si                : SI PARIZQ expresion PARDER Sentencia
                              |   SI PARIZQ expresion PARDER Sentencia
                              SINO Sentencia
sentencia_mientras          : MIENTRAS PARIZQ expresion PARDER Sentencia
sentencia_hacer_hasta       : HACER Sentencia HASTA PARIZQ expresion PARDER PYC
sentencia_entrada           : ENTRADA lista_variables PYC
sentencia_salida            : SALIDA lista_expresiones_cadena PYC
sentencia_retornar          : DEVOLVER expresion PYC
lista_expresiones_cadena    : lista_expresiones_cadena COMA expresion_cadena
                              |   expresion_cadena
expresion_cadena            : expresion | cadena
lista_variables             : variable
                              |   variable COMA lista_variables
lista_declaracion_variables : lista_declaracion_variables
                              |   variable
                              |   variable COMA lista_declaracion_variables
lista_expresiones           : expresion
                              |   expresion COMA lista_expresiones
expresion                   : PARIZQ expresion PARDER
                              |   op_unario expresion
                              |   expresion op_binario expresion
                              |   variable
                              |   constante
                              |   funcion
funcion                     : identificador PARIZQ PARDER
                              |   identificador PARIZQ lista_expresiones PARDER
tipo                        : TIPOEL
op_binario                  : OPBIN | OPMIX
op_unario                   : OPUN  | OPMIX
cadena                      : CADENA
identificador               : IDEN
constante                   : CONST

%%

#ifdef DOSWINDOWS
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

void yyerror(char *msg)
{
  fprintf(stderr, "[Linea %d]: %s\n", linea_actual, msg);
}


