%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "estructurasTS.h"
void yyerror(char * msg);

int linea_actual = 1;

#define MAX_TS 500

unsigned int TOPE = 0; /* Tope de la pila */
unsigned int subprog;  /* Indicador de comienzo de bloque de subprog */
dtipo tipoTmp; 

entradaTS TS[MAX_TS];  /* TABLA DE SÍMBOLOS */
entradaTS TS_aux[MAX_TS]; /* Tabla auxiliar para paramf */
unsigned int TOPE_AUX = 0;


typedef struct{
  int atrib;
  char* lexema;
  dtipo tipo;
  unsigned int dimensiones;
  int TamDimen1;
  int TamDimen2;
} atributos;

#define YYSTYPE atributos /* Cada símbolo tiene una estructura de tipo atributos */

/* Funciones y procedimientos de manejo de TS */

void TS_InsertaENTRADA(entradaTS ets);
void TSAUX_InsertaENTRADA(entradaTS ets);
void TS_InsertaMARCA();
void TS_InsertaIDENT(atributos atr);
void TS_VaciarENTRADAS();
void TS_InsertaSUBPROG(atributos atr);
void TS_InsertaPARAMF(atributos atr);

dtipo atributoAEnum(int atr);
/* Fin de declaraciones */

/*
  Funciones para debuggear
*/

void mostrar_tabla();
char* entrada_a_string(entradaTS);

%}

//%error-verbose
%define parse.error verbose


%left OPOR
%left OPAND
%left OPEQ OPNEQ
%left OPLEQ OPGEQ OPLESS OPGR
%left OPSUMA OPRESTA
%left OPMULT OPMULTM OPDIV OPMOD
%right OPNEG

%token CONST CONSTENT IDEN CADENA ASIG CORIZQ CORDER PARIZQ PARDER LLAIZQ LLADER PYC COMA SI SINO MIENTRAS HACER HASTA INIDEC FINDEC SALIDA ENTRADA DEVOLVER MAIN TIPOEL



%%

Programa                    : Cabecera_programa bloque
bloque                      : Inicio_de_bloque {TS_InsertaMARCA();}
                                  Declar_de_variables_locales
                                  Declar_subprogs
                                  Sentencias 
                              Fin_de_bloque { TS_VaciarENTRADAS();}
Declar_subprogs             : Declar_subprogs Declar_subprog
                              |
Declar_subprog              : Cabecera_subprog {subprog = 1;} bloque {subprog = 0;}
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
                              | Cuerpo_declar_variables
Cuerpo_declar_variables      : tipo {tipoTmp=atributoAEnum($1.atrib);} lista_declaracion_variables PYC
                              | error
Cabecera_subprog            :   tipo variable PARIZQ argumentos PARDER {tipoTmp=atributoAEnum($1.atrib);TS_InsertaSUBPROG($2);}
                              | tipo variable PARIZQ PARDER {tipoTmp=atributoAEnum($1.atrib);TS_InsertaSUBPROG($2);}
argumentos                  : tipo {tipoTmp=atributoAEnum($1.atrib);} variable {TS_InsertaPARAMF($3);}
                              |   argumentos COMA tipo {tipoTmp=atributoAEnum($3.atrib);} variable {TS_InsertaPARAMF($5);}
                              |   error
variable                    : identificador {$$.lexema = $1.lexema;
                                             $$.dimensiones=0; $$.TamDimen1=0; $$.TamDimen2=0;
                                            }
                              |   elemento_de_array_decl {$$.lexema = $1.lexema;}
elemento_de_array_decl      : identificador CORIZQ CONSTENT CORDER {$$.lexema = $1.lexema; 
                                                                    $$.dimensiones=1;
                                                                    $$.TamDimen1=atoi($3.lexema);
                                                                    $$.TamDimen2=0;}
                              |   identificador CORIZQ CONSTENT 
                              COMA CONSTENT CORDER {$$.lexema = $1.lexema;
                                                    $$.dimensiones=2;
                                                    $$.TamDimen1=atoi($3.lexema);
                                                    $$.TamDimen2=atoi($5.lexema);}

variable_expresion          : identificador  
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
sentencia_asignacion        : variable_expresion ASIG expresion PYC
                              |   error
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
                              |   lista_variables COMA variable
lista_declaracion_variables :  variable {TS_InsertaIDENT($1);}
                              |   lista_declaracion_variables COMA variable {TS_InsertaIDENT($3);}

                              |   error
lista_expresiones           : expresion
                              |   lista_expresiones COMA expresion
expresion                   : PARIZQ expresion PARDER
                              |   OPNEG expresion
                              |   OPSUMA expresion
                              |   OPRESTA expresion %prec OPNEG
                              |   expresion OPMULT expresion
                              |   expresion OPDIV expresion
                              |   expresion OPMULTM expresion
                              |   expresion OPAND expresion
                              |   expresion OPOR expresion
                              |   expresion OPEQ expresion
                              |   expresion OPNEQ expresion
                              |   expresion OPLEQ expresion
                              |   expresion OPGEQ expresion
                              |   expresion OPLESS expresion
                              |   expresion OPGR expresion
                              |   expresion OPMOD expresion
                              |   expresion OPSUMA expresion
                              |   expresion OPRESTA expresion
                              |   variable_expresion
                              |   constante
                              |   funcion
                              |   error
funcion                     : identificador PARIZQ PARDER
                              |   identificador PARIZQ lista_expresiones PARDER
tipo                        : TIPOEL {$$.atrib = $1.atrib;}
cadena                      : CADENA
identificador               : IDEN
constante                   : CONST 
                              | CONSTENT  
                              |   CORIZQ ini_elementos_array CORDER
ini_elementos_array         : ini_elementos_array PYC lista_expresiones 
                              |   lista_expresiones

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


void TS_InsertaENTRADA(entradaTS ets){
  
  if (TOPE == MAX_TS){
    fprintf(stderr, "Error: Se ha alcanzado el máximo tamaño de la tabla de símbolos.\n");
  }else{
    /* Introduzco el valor en la pila y cambio el tope */
    TS[TOPE] = ets;
    TOPE = TOPE + 1;
  }

  mostrar_tabla();
}

void TSAUX_InsertaENTRADA(entradaTS ets){
  if (TOPE_AUX == MAX_TS){
    fprintf(stderr, "Error: Se ha alcanzado el máximo tamaño de la tabla de símbolos.\n");
  }else{
    /* Introduzco el valor en la pila y cambio el tope */
    TS_aux[TOPE_AUX] = ets;
    TOPE_AUX = TOPE_AUX + 1;
  }
}

void TS_InsertaMARCA(){

  entradaTS ets;
  ets.entrada = marca;
  ets.nombre = "";
  ets.tipoDato = no_asignado;
  ets.parametros = 0;
  ets.dimensiones = 0;
  ets.TamDimen1 = 0;
  ets.TamDimen2 = 0;
 
  TS_InsertaENTRADA(ets);

  entradaTS ets_aux;
  if (subprog == 1){ 
    unsigned int i = 0;
    /* INserto parametros formales */
    while (i < TOPE_AUX){
      ets_aux = TS_aux[i];
      ets_aux.entrada = variable;
      TS_InsertaENTRADA(ets_aux);
      i++;
    }
    TOPE_AUX = 0;
  }
}


void TS_InsertaIDENT(atributos atr){

  entradaTS ets;
  ets.entrada = variable;
  ets.nombre = atr.lexema;
  ets.tipoDato = tipoTmp;
  ets.parametros = 0;
  ets.dimensiones = atr.dimensiones;
  ets.TamDimen1 = atr.TamDimen1;
  ets.TamDimen2 = atr.TamDimen2;

  int tope_aux = TOPE-1;

  while (tope_aux > 0 ){
    if (strcmp(TS[tope_aux].nombre,ets.nombre) == 0){
      fprintf(stderr, "Error semántico: Doble declaración de la variable '%s'\n",ets.nombre);
    }

    if (TS[tope_aux].entrada == marca) break;
    tope_aux--;
  }

  TS_InsertaENTRADA(ets);
}



void TS_VaciarENTRADAS(){

  if (TOPE == 0) fprintf(stderr, "Error: intenta vaciar tabla de símbolos vacía\n");

  while (TS[TOPE-1].entrada != marca) TOPE--;

  if (TOPE > 0)
    TOPE--;
  else
    fprintf(stderr, "Error: No se encontró marca al vaciar tabla de símbolos\n");
}



void TS_InsertaSUBPROG(atributos atr){

  entradaTS ets;
  ets.entrada = funcion;
  ets.nombre = atr.lexema;
  ets.tipoDato = tipoTmp;
  ets.parametros = TOPE_AUX;
  ets.dimensiones = atr.dimensiones;
  ets.TamDimen1 = atr.TamDimen1;
  ets.TamDimen2 = atr.TamDimen2;

  unsigned int i = 0;


  TS_InsertaENTRADA(ets);
  
  /* INserto parametros formales */
  while (i < TOPE_AUX){
    TS_InsertaENTRADA(TS_aux[i]);
    i++;
  }
 
}


void TS_InsertaPARAMF(atributos atr){

  entradaTS ets;
  ets.entrada = parametro_formal;
  ets.nombre = atr.lexema;
  ets.tipoDato = tipoTmp;
  ets.parametros = 0;
  ets.dimensiones = atr.dimensiones;
  ets.TamDimen1 = atr.TamDimen1;
  ets.TamDimen2 = atr.TamDimen2;
  

  int tope_aux = TOPE_AUX - 1;

  while (tope_aux >= 0){
  
    if (TS_aux[tope_aux].nombre == ets.nombre) fprintf(stderr, "Error:se ha encontrado otro parámetro formal con el mismo identificador: '%s'\n", ets.nombre);
    tope_aux--;
  }

  TSAUX_InsertaENTRADA(ets);
}


dtipo atributoAEnum(int atr){

  if (atr == 0) return entero;
  if (atr == 1) return real;
  if (atr == 2) return caracter;
  if (atr == 3) return booleano;
  printf("ERROR: Atributo de tipo no válido: atributo == %d\n", atr);
}

/****************************************************************************************/
void mostrar_tabla(){

  unsigned int entrada = 0;

  printf("-------------------TABLA-------------------\n");
  printf("entrada\tnombre\ttipoDato\tparametros\tdimensiones\tTamDimen1\tTamDimen2\n");

  while (entrada < TOPE){
    printf("%s\n",entrada_a_string(TS[entrada]));
    entrada++;
  }

  printf("\n\n");

}

char* entrada_a_string(entradaTS es){

  char salida[2000];
  char formato[] = "%s \t%s \t%s \t%d \t%d \t%d \t%d";
  char* c1, *c2, *c3;
  unsigned int c4,c5,c6,c7;

  if (es.entrada == marca) c1 = "marca";
  else if (es.entrada == funcion) c1 = "funcion";
  else if (es.entrada == variable) c1 = "variable";
  else if (es.entrada == parametro_formal) c1 = "paramFormal";

  
  if (es.tipoDato == booleano) c3 = "booleano";
  else if (es.tipoDato == entero) c3 = "entero";
  else if (es.tipoDato == real) c3 = "real";
  else if (es.tipoDato == caracter) c3 = "caracter";
  else if (es.tipoDato == desconocido) c3 = "desconocido";
  else if (es.tipoDato == no_asignado) c3 = "no asignado";
  c4 = es.parametros;
  c5 = es.dimensiones;
  c6 = es.TamDimen1;
  c7 = es.TamDimen2;
  sprintf(salida,formato,c1,es.nombre,c3,c4,c5,c6,c7);
  return strdup(salida);  
}
