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
  Funciones para hacer comprobaciones semánticas
*/
entradaTS buscarEntrada(char* nombre);
atributos entradaAAtributos(entradaTS ets);
atributos procesaOperacionBinariaOMixta(atributos op1, atributos op2, int opdor);
atributos procesaOperacionMixtaCuandoUnaria(atributos op1);
atributos procesaOperacionNegacion(atributos op1);
void procesaSentenciaAsignacion(atributos op1, atributos op2);
void procesaSentenciaControl(atributos exp);

/*
  Funciones para debuggear
*/

void mostrar_tabla();
char* entrada_a_string(entradaTS);
char* enumAChar(dtipo t);

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

variable_expresion          : identificador  {entradaTS ets = buscarEntrada($1.lexema); $$ = entradaAAtributos(ets);}
                              |   elemento_de_array  {$$ = $1;}
elemento_de_array           : identificador CORIZQ expresion CORDER {entradaTS ets = buscarEntrada($1.lexema);
                                                                     ets.dimensiones = 0;
                                                                     $$ = entradaAAtributos(ets);}
                              |   identificador CORIZQ expresion 
                              COMA expresion CORDER {entradaTS ets = buscarEntrada($1.lexema);
                                                     ets.dimensiones = 0;
                                                     $$ = entradaAAtributos(ets);}
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
sentencia_asignacion        : variable_expresion ASIG expresion PYC {procesaSentenciaAsignacion($1,$3);}
                              |   error
sentencia_si                : SI PARIZQ expresion PARDER Sentencia {procesaSentenciaControl($3);}
                              |   SI PARIZQ expresion PARDER Sentencia 
                              SINO Sentencia {procesaSentenciaControl($3);}
sentencia_mientras          : MIENTRAS PARIZQ expresion PARDER Sentencia {procesaSentenciaControl($3);}
sentencia_hacer_hasta       : HACER Sentencia HASTA PARIZQ expresion PARDER PYC {procesaSentenciaControl($5);}
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
expresion                   : PARIZQ expresion PARDER {$$ = $2;}
                              |   OPNEG expresion {$$ = procesaOperacionMixtaCuandoUnaria($2);}
                              |   OPSUMA expresion {$$ = procesaOperacionMixtaCuandoUnaria($2);}
                              |   OPRESTA expresion %prec OPNEG {$$ = procesaOperacionNegacion($2);}
                              |   expresion OPMULT expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPDIV expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPMULTM expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPAND expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPOR expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPEQ expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPNEQ expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPLEQ expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPGEQ expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPLESS expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPGR expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPMOD expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPSUMA expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   expresion OPRESTA expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);}
                              |   variable_expresion {$$ = $1;}
                              |   constante {$$ = $1;}
                              |   funcion {$$ = $1;}
                              |   error
funcion                     : identificador PARIZQ PARDER {entradaTS ets = buscarEntrada($1.lexema);
                                                           $$ = entradaAAtributos(ets);}
                              |   identificador PARIZQ lista_expresiones PARDER {entradaTS ets = buscarEntrada($1.lexema);
                                                                                 $$ = entradaAAtributos(ets);}
tipo                        : TIPOEL {$$.atrib = $1.atrib;}
cadena                      : CADENA 
identificador               : IDEN   
constante                   : CONST {$$.tipo = atributoAEnum($1.atrib+1);}
                              | CONSTENT  {$$.tipo = entero;}
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
    fprintf(stderr, "Error: Se ha alcanzado el máximo tamaño de la tabla de símbolos.\n ABORTANDO\n");
    exit(-1);
  }else{
    /* Introduzco el valor en la pila y cambio el tope */
    TS[TOPE] = ets;
    TOPE = TOPE + 1;
  }

 // mostrar_tabla();
}

void TSAUX_InsertaENTRADA(entradaTS ets){
  if (TOPE_AUX == MAX_TS){
    fprintf(stderr, "Error: Se ha alcanzado el máximo tamaño de la tabla de símbolos.\n ABORTANDO\n");
    exit(-1);
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
    if (strcmp(TS_aux[tope_aux].nombre,ets.nombre) == 0) fprintf(stderr, "Error semántico:se ha encontrado otro parámetro formal con el mismo identificador: '%s'\n", ets.nombre);
    tope_aux--;
  }

  TSAUX_InsertaENTRADA(ets);
}


entradaTS buscarEntrada(char* nombre){
  entradaTS ets;

  int i = TOPE-1;
  
  while (i>=0){
    if (strcmp(TS[i].nombre,nombre) == 0) break;
    i--;
  }

  if (i == -1){
    fprintf(stderr, "Error semántico: se utiliza un identificador no declarado: '%s'\n", nombre);
    ets.nombre = strdup("");
  }else{
    ets = TS[i];
  }

  return ets;
}


atributos entradaAAtributos(entradaTS ets){
  atributos atr; 
  atr.tipo = ets.tipoDato; 
  atr.dimensiones = ets.dimensiones;
  atr.TamDimen1 = ets.TamDimen1;
  atr.TamDimen2 = ets.TamDimen2;

  return atr;
}



atributos procesaOperacionBinariaOMixta(atributos op1, atributos op2, int opdor){

  atributos atr;

  //printf("[Linea %d]",linea_actual);
  //printf("OP1: tipo:%s dim:%d t1:%d t2:%d  OP2: tipo:%s dim:%d t1:%d t2:%d\n",enumAChar(op1.tipo),op1.dimensiones,op1.TamDimen1,op1.TamDimen2,enumAChar(op2.tipo),op2.dimensiones,op2.TamDimen1,op2.TamDimen2);

  // Caso (+,*)
  if (opdor == 0){
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador (+|*) espera tipo entero/real\n");
    }
    
    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }
    if( (op1.dimensiones==1 && op2.dimensiones==2) ||
              (op1.dimensiones==2 && op2.dimensiones==1)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con una array y una matriz.\n");
    }
    if (op1.dimensiones==0){
      atr = op2;
    }else if (op2.dimensiones==0){
      atr = op1;
    }
    if (op1.dimensiones==1 && op2.dimensiones==1){
      if (op1.TamDimen1 == op2.TamDimen1) atr = op1;
      else {
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con arrays de distintos tamaños.\n");
      }
    }else if(op1.dimensiones==2 && op2.dimensiones==2){
      if (op1.TamDimen1 == op2.TamDimen1 && op1.TamDimen2 == op2.TamDimen2) atr = op1;
      else {
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con matrices de distintos tamaños.\n");
      }
    }
  }
  
  // Caso (-,/)
  if (opdor == 1){
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador (-|/) espera tipo entero/real\n");
    }
    
    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }
    if( (op1.dimensiones==1 && op2.dimensiones==2) ||
              (op1.dimensiones==2 && op2.dimensiones==1)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con una array y una matriz.\n");
    }
    if (op1.dimensiones==0 && op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede restar/dividir un array/matriz a un valor.\n");
    }else if (op2.dimensiones==0){
      atr = op1;
    }
    if (op1.dimensiones==1 && op2.dimensiones==1){
      if (op1.TamDimen1 == op2.TamDimen1) atr = op1;
      else{
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con arrays de distintos tamaños.\n");
      }
    }else if(op1.dimensiones==2 && op2.dimensiones==2){
      if (op1.TamDimen1 == op2.TamDimen1 && op1.TamDimen2 == op2.TamDimen2) atr = op1;
      else {
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con matrices de distintos tamaños.\n");
      }
    }
  }

  // Caso **
  if (opdor == 2){
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador ** espera tipo entero/real\n");
    }
    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }
    if (op1.dimensiones == 1 || op1.dimensiones == 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador ** espera matrices\n");
    }
    if (op2.dimensiones == 1 || op2.dimensiones == 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador ** espera matrices\n");
    }
    if (op1.dimensiones == 2 && op2.dimensiones ==2){
      if (op1.TamDimen2 != op2.TamDimen1){
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Multiplicación de matrices inválida. No se puede multiplicar dimensiones (%dX%d)**(%dX%d)\n",op1.TamDimen1,op1.TamDimen2,op2.TamDimen1,op2.TamDimen2);
      }else{
        atr = op1;
        atr.TamDimen2 = op2.TamDimen2;
      }
    }
  }

  // Caso (&&,||)
  if (opdor == 3  || opdor == 4){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede utilizar el operador (&&,||) con arrays/matrices.\n");
    }else if (op1.tipo != booleano || op2.tipo != booleano){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador (&&,||) espera tipo booleano\n");
    }else{
      atr = op1;
    }
  }


  if (opdor == 5 || opdor == 6){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede comparar arrays/matrices.\n");
    }else if(op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede comparar expresiones de distinto tipo\n");
    }else{
      atr = op1;
      atr.tipo = booleano;
    }
  }

  // Caso operador relacional >,<,>=,...
  if (opdor >= 7 && opdor <= 10){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede utilizar un operador relacional con arrays/matrices.\n");
    }
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador ** espera tipo entero/real\n");
    }

    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }else if(op1.dimensiones == 0 && op2.dimensiones == 0){
      atr = op1;
      atr.tipo = booleano;
    }
  }

  // Caso módulo %
  if (opdor == 11){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se puede hacer módulo de arrays/matrices.\n");
    }else if(op1.tipo != entero || op2.tipo != entero){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador módulo espera dos enteros.\n");
    }else{
      atr = op1;
    }
  }

  //printf("RES: tipo:%s dim:%d t1:%d t2:%d\n",enumAChar(atr.tipo),atr.dimensiones,atr.TamDimen1,atr.TamDimen2);
  return atr;
}

atributos procesaOperacionMixtaCuandoUnaria(atributos op1){

  atributos atr;

  if (op1.dimensiones != 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador unario (+ | -) no espera un array o matriz.\n");
  }

  if (op1.tipo != entero && op1.tipo != real){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador unario (+ | -) espera tipo real o entero.\n");
  }
  
  if ((op1.tipo == entero || op1.tipo == real) && op1.dimensiones == 0){
    atr = op1;
  }

  return atr;
}

atributos procesaOperacionNegacion(atributos op1){

  atributos atr;

  if (op1.tipo != booleano){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador de negación espera un booleano.\n");
  }

  if (op1.dimensiones != 0){ 
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El operador de negación no espera un array o matriz.\n");
  }

  if (op1.dimensiones == 0 && op1.tipo == booleano){
    atr = op1;
  }

  return atr;
}


void procesaSentenciaAsignacion(atributos op1, atributos op2){
  if (op1.tipo != op2.tipo){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Asignacion de tipos distintos.\n");
  }
  if (op1.dimensiones != op2.dimensiones){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Asignacion variables con dimensiones distintas.\n");
  }else{
    if (op1.dimensiones == 1){
      if (op1.TamDimen1 != op2.TamDimen1){
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Asignacion de arrays de distinto tamaño.\n");
      }
    }
    if (op1.dimensiones == 2){
      if ((op1.TamDimen1 != op2.TamDimen1) || (op1.TamDimen2 != op2.TamDimen2)){
        printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Asignacion de matrices de distintos tamaños.\n");
      }
    }
  }
}

void procesaSentenciaControl(atributos exp){
  if (exp.tipo != booleano){
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: La sentencia de control (si|mientras|hasta) espera una expresión booleana.\n");
  }
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


char* enumAChar(dtipo t){

  if (t == entero)return strdup("entero");
  if (t == booleano)return strdup("booleano");
  if (t == real)return strdup("real");
  if (t == caracter)return strdup("char");

  return strdup("Ninguno");
}
