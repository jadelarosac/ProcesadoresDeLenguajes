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
int TOPE_AUX = 0;
int TOPE_ARG = 0;

entradaTS PILA_ARG[MAX_TS];


/* GENERACIÓN DE CÓDIGO */

char VACIO[5] = "";

FILE* intermain;
FILE* dec_fun;

int anidado_nivel = 0;
int n_errores = 0;

/*                      */
int Ntmp = 0;
int Netiqueta = 0;
int bloqueMain = 0; //True
char* paux;
char* textoPrintf = NULL;
char* textoScanf = NULL;


typedef struct{
  int atrib;
  char* lexema;
  dtipo tipo;
  unsigned int dimensiones;
  int TamDimen1;
  int TamDimen2;

  char* nombreTmp;
  char* codigo;
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

void PILARG_insertaENTRADA(entradaTS ets);
void PILARG_insertaMARCA();
void PILARG_insertaARG(atributos arg);

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
void procesaSentenciaRetornar(atributos ret);
void procesaLlamadaFuncionConArgumentos(entradaTS ets);
void procesaLlamadaFuncionSinArgumentos(entradaTS ets);

/*
  Funciones para debuggear
*/

void mostrar_tabla();
char* entrada_a_string(entradaTS);
char* enumAChar(dtipo t);

/*
  FUNCIONES PARA GENERAR CODIGO
*/
void empezarGEN();
void finalizarGEN();
char* temporal();
char* etiqueta();
int enumATamByte(dtipo t);

char* enumAString();
char* enumATipoForm(dtipo t);


void genCodigoOperadorBin(atributos* obj, atributos* at1, atributos* at2, int opdor);
void genCodigoOperadorMix(atributos* obj, atributos* at1, atributos* at2, int opdor);
void genCodigoOperadorUn(atributos* obj, atributos* at1, int opdor);
void genCodigoOperadorUnNeg(atributos* obj, atributos* at1);

void genCodigoAsignacion(atributos*, atributos*, atributos*);
void genCodigoExpresionEntreCorchetes(char** obj, atributos* atr);
void genCodigoSino(atributos* ,atributos*,atributos*,atributos*);
void genCodigoSi(atributos* ,atributos*,atributos*);
void genCodigoMientras(atributos* obj,atributos* cond,atributos* sent);
void genCodigoHacerHasta(atributos* obj,atributos* cond,atributos* sent);

void genCabeceraSubprograma(atributos* obj, char* tipo, atributos* atr, atributos* args);

char* opdorUnAString(int opdor);
char* opdorBinAString(int opdor);
char* opdorMatBinAString(int opdor);

void mystrcat(char**,char**);
void mystrcpy(char**,char**);

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

Programa                    : Cabecera_programa {empezarGEN();} bloque {if (n_errores == 0) {fputs($3.codigo,intermain);}finalizarGEN();}
bloque                      : Inicio_de_bloque {TS_InsertaMARCA();}
                                  Declar_de_variables_locales {
                                                                          if (n_errores == 0){
                                                                if (bloqueMain == 0){
                                                                  bloqueMain = 1;
                                                                  paux = strdup("\n");
                                                                  mystrcat(&$3.codigo,&paux);
                                                                  paux = strdup("#include \"dec_fun.c\"\n\n");
                                                                  mystrcat(&$3.codigo,&paux);
                                                                  paux = strdup("int main(){//inicio bloque\n");
                                                                  mystrcat(&$3.codigo,&paux);
                                                                }else{
                                                                  char* tmp = strdup("{//inicio bloque\n");
                                                                  mystrcat(&tmp,&$3.codigo);
                                                                  paux = strdup(tmp);
                                                                  mystrcpy(&$3.codigo,&paux);
                                                                }
                                                                }}
                                  Declar_subprogs
                                  Sentencias
                              Fin_de_bloque { TS_VaciarENTRADAS();
                                                                          if (n_errores == 0){
                                                                   mystrcat(&$3.codigo,&$5.codigo);
                                                                   mystrcat(&$3.codigo,&$6.codigo);
                                                                   paux = strdup("\n}//fin bloque\n");
                                                                   mystrcat(&$3.codigo,&paux);
                                                                   mystrcpy(&$$.codigo,&$3.codigo);
                                                                   }}
Declar_subprogs             : Declar_subprogs Declar_subprog{
                                                                          if (n_errores == 0){
                            mystrcpy(&$$.codigo,&$1.codigo);
                            paux = strdup("\n");
                            mystrcat(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&$2.codigo);}}
                              | { 
                                                                          if (n_errores == 0){
                              paux = strdup("");mystrcpy(&$$.codigo,&paux);
                              }}
Declar_subprog              : {anidado_nivel++;} Cabecera_subprog
                              {subprog = 1;}     bloque
                              {
                                                                          if (n_errores == 0){

                                  if (anidado_nivel == 1)
                                  {
                                    paux = strdup("//Inicio declaracion funcion\n");
                                    fputs(paux, dec_fun);
                                    fputs($2.codigo,dec_fun); // Esto da el nombre de la función
                                    paux = strdup("\n");
                                    fputs(paux, dec_fun);
                                    fputs($4.codigo,dec_fun); // Esto da el código de la función
                                    paux = strdup("//Fin declaracion funcion\n");
                                    fputs(paux, dec_fun);
                                    paux = strdup("");
                                    mystrcpy(&$$.codigo,&paux);

                                  }else{
                                    paux = strdup("//Inicio declaracion funcion\n");
                                    mystrcpy(&$$.codigo,&paux);
                                    mystrcat(&$$.codigo,&$2.codigo);
                                    mystrcat(&$$.codigo,&$4.codigo);
                                    paux = strdup("//Fin declaracion funcion\n");
                                    mystrcat(&$$.codigo,&paux);
                                  }
                                  subprog = 0;
                                  anidado_nivel--;
                              }}

Declar_de_variables_locales : Marca_ini_declar_variables
                                  Variables_locales
                                  Marca_fin_declar_variables {if (n_errores == 0) mystrcpy(&$$.codigo,&$2.codigo);}
                              |   {paux = strdup("");mystrcpy(&$$.codigo,&paux);}
Marca_ini_declar_variables  : INIDEC
Marca_fin_declar_variables  : FINDEC
Cabecera_programa           : MAIN
Inicio_de_bloque            : LLAIZQ
Fin_de_bloque               : LLADER
Variables_locales           : Variables_locales Cuerpo_declar_variables {
                                                                          if (n_errores == 0){
                                                                         paux = strdup("\n");
                                                                         mystrcat(&$1.codigo,&paux);
                                                                         mystrcat(&$1.codigo,&$2.codigo);
                                                                         mystrcpy(&$$.codigo,&$1.codigo);}}
                              | Cuerpo_declar_variables {if (n_errores == 0){ paux = strdup($1.codigo);
                              mystrcpy(&$$.codigo,&paux);}}
Cuerpo_declar_variables      : tipo {tipoTmp=atributoAEnum($1.atrib);} lista_declaracion_variables PYC {
                                                                          if (n_errores == 0){
                                                                                                        paux = strdup(enumAString(tipoTmp));
                                                                                                        mystrcpy(&$1.codigo,&paux);
                                                                                                        paux = strdup(" ");
                                                                                                        mystrcat(&$1.codigo,&paux);
                                                                                                        mystrcat(&$1.codigo,&$3.codigo);
                                                                                                        paux = strdup(";\n");
                                                                                                        mystrcat(&$1.codigo,&paux);
                                                                                                        paux = strdup($1.codigo);
                                                                                                        mystrcpy(&$$.codigo,&paux);}}
                              | error {paux = strdup(""); mystrcpy(&$$.codigo,&paux);paux = strdup(""); mystrcpy(&$$.nombreTmp,&paux);n_errores = n_errores+1;}
Cabecera_subprog            :   tipo variable PARIZQ argumentos PARDER {
                                  tipoTmp=atributoAEnum($1.atrib);
                                  TS_InsertaSUBPROG($2);
                                                                          if (n_errores == 0){
                                  paux = strdup(enumAString(tipoTmp));
                                  genCabeceraSubprograma(&$$, paux, &$2, &$4);
                                  }}
                              | tipo variable PARIZQ PARDER {tipoTmp=atributoAEnum($1.atrib);
                              TS_InsertaSUBPROG($2);
                                                                          if (n_errores == 0){
                              paux = strdup(enumAString(tipoTmp));
                              genCabeceraSubprograma(&$$, paux, &$2, NULL);
                              }}
argumentos                  : tipo {tipoTmp=atributoAEnum($1.atrib);} variable {TS_InsertaPARAMF($3);
                                                                          if (n_errores == 0){
                            paux = strdup(enumAString(tipoTmp));
                            mystrcpy(&$$.codigo,&paux);
                            paux = strdup(" ");
                            mystrcat(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&$3.codigo);}}
                              |   argumentos COMA tipo {tipoTmp=atributoAEnum($3.atrib);} variable {TS_InsertaPARAMF($5);
                                                                          if (n_errores == 0){
                              mystrcpy(&$$.codigo,&$1.codigo);
                              paux = strdup(", ");
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(enumAString(tipoTmp));
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(" ");
                              mystrcat(&$$.codigo,&paux);
                              mystrcat(&$$.codigo,&$5.codigo);
                              }}
                              |   error {paux = strdup(""); mystrcpy(&$$.codigo,&paux);paux = strdup(""); mystrcpy(&$$.nombreTmp,&paux);n_errores = n_errores+1;}
variable                    : identificador {$$.lexema = $1.lexema;
                                             $$.dimensiones=0; $$.TamDimen1=0; $$.TamDimen2=0;
                                                                          if (n_errores == 0){
                                             paux = strdup($1.lexema);
                                             mystrcpy(&$$.codigo,&paux);
                                              }
                                             }

                              |   elemento_de_array_decl {
                                                                    $$.lexema = $1.lexema;
                                                                    $$.dimensiones = $1.dimensiones;
                                                                    $$.TamDimen1 = $1.TamDimen1;
                                                                    $$.TamDimen2 = $1.TamDimen2;
                                                                          if (n_errores == 0){
                                                                    mystrcpy(&$$.codigo,&$1.codigo);
                                                                    }}
elemento_de_array_decl      : identificador CORIZQ CONSTENT CORDER {
                                                                    $$.lexema = $1.lexema;
                                                                    $$.dimensiones=1;
                                                                    $$.TamDimen1=atoi($3.lexema);
                                                                    $$.TamDimen2=0;

                                                                          if (n_errores == 0){
                                                                    char saux[100];
                                                                    sprintf(saux, "%s[%d]",$$.lexema,$$.TamDimen1);
                                                                    paux = strdup(saux);
                                                                    mystrcpy(&$$.codigo, &paux);
                                                                    }}
                              |   identificador CORIZQ CONSTENT
                              COMA CONSTENT CORDER {
                                                                    $$.lexema = $1.lexema;
                                                                    $$.dimensiones=2;
                                                                    $$.TamDimen1=atoi($3.lexema);
                                                                    $$.TamDimen2=atoi($5.lexema);
                                                                          if (n_errores == 0){

                                                                    char saux[100];
                                                                    sprintf(saux, "%s[%d][%d]",$$.lexema,$$.TamDimen1,$$.TamDimen2);
                                                                    paux = strdup(saux);
                                                                    mystrcpy(&$$.codigo, &paux);
                                                                    }}

variable_expresion          : identificador  {entradaTS ets = buscarEntrada($1.lexema); $$ = entradaAAtributos(ets);
                                                                          if (n_errores == 0){
                            paux = strdup($1.lexema);
                            mystrcpy(&$$.nombreTmp,&paux);
                            paux = strdup("");
                            mystrcpy(&$$.codigo,&paux);}}
                              |   elemento_de_array  {$$ = $1;
                                                                          if (n_errores == 0){
                                                      mystrcpy(&$$.codigo,&$1.codigo);
                                                      mystrcpy(&$$.nombreTmp,&$1.nombreTmp);}}
elemento_de_array           : identificador CORIZQ expresion CORDER {
                                                                    entradaTS ets = buscarEntrada($1.lexema);
                                                                    ets.dimensiones = 0;
                                                                    $$ = entradaAAtributos(ets);
                                                                          if (n_errores == 0){

                                                                    mystrcpy(&$$.codigo, &$3.codigo);
                                                                    paux = strdup($1.lexema);
                                                                    mystrcpy(&$$.nombreTmp,&paux);
                                                                    paux = strdup("[");
                                                                    mystrcat(&$$.nombreTmp,&paux);
                                                                    mystrcat(&$$.nombreTmp, &$3.nombreTmp);
                                                                    paux = strdup("]");
                                                                    mystrcat(&$$.nombreTmp,&paux);
                                                                    }}
                              |   identificador CORIZQ expresion
                              COMA expresion CORDER {
                                                                    entradaTS ets = buscarEntrada($1.lexema);
                                                                    ets.dimensiones = 0;
                                                                    $$ = entradaAAtributos(ets);
                                                                          if (n_errores == 0){
                                                                    mystrcpy(&$$.codigo, &$3.codigo);
                                                                    paux = strdup("\n");
                                                                    mystrcat(&$$.codigo, &paux);
                                                                    mystrcat(&$$.codigo, &$5.codigo);

                                                                    paux = strdup($1.lexema);
                                                                    mystrcpy(&$$.nombreTmp,&paux);
                                                                    paux = strdup("[");
                                                                    mystrcat(&$$.nombreTmp, &paux);
                                                                    mystrcat(&$$.nombreTmp, &$3.nombreTmp);
                                                                    paux = strdup("][");
                                                                    mystrcat(&$$.nombreTmp, &paux);
                                                                    mystrcat(&$$.nombreTmp, &$5.nombreTmp);
                                                                    paux = strdup("]");
                                                                    mystrcat(&$$.nombreTmp,&paux);

                                                                    }}
Sentencias                  : Sentencias Sentencia {
                                                                          if (n_errores == 0){
                            mystrcpy(&$$.codigo,&$1.codigo);
                            paux = strdup("\n");
                            mystrcat(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&$2.codigo);}}
                              |   Sentencia {if (n_errores == 0) mystrcpy(&$$.codigo, &$1.codigo);}
Sentencia                   : bloque {if (n_errores==0) mystrcpy(&$$.codigo,&$1.codigo);}
                              |   sentencia_asignacion {
                                                                          if (n_errores == 0){
                              paux = strdup("{//inicio sentencia asig\n");
                              mystrcpy(&$$.codigo,&paux);
                              mystrcat(&$$.codigo, &$1.codigo);
                              paux = strdup("}//fin sentencia asig\n");
                              mystrcat(&$$.codigo,&paux);}}
                              |   sentencia_si  {
                                                                          if (n_errores == 0){
                              paux = strdup("{//inicio sentencia if\n");
                              mystrcpy(&$$.codigo,&paux);
                              mystrcat(&$$.codigo,&$1.codigo);
                              paux = strdup("}//fin sentencia if\n");
                              mystrcat(&$$.codigo,&paux);}}
                              |   sentencia_mientras {
                                                                          if (n_errores == 0){
                              paux = strdup("{//inicio sentencia while\n");
                              mystrcpy(&$$.codigo,&paux);
                              mystrcat(&$$.codigo,&$1.codigo);
                              paux = strdup("}//fin sentencia while\n");
                              mystrcat(&$$.codigo,&paux);}}
                              |   sentencia_hacer_hasta { 
                                                                          if (n_errores == 0){
                              paux = strdup("{//inicio sentencia do-until\n");
                              mystrcpy(&$$.codigo,&paux);
                              mystrcat(&$$.codigo,&$1.codigo);
                              paux = strdup("}//fin sentencia do-until\n");
                              mystrcat(&$$.codigo,&paux);
                              }}
                              |   sentencia_entrada {
                                                                          if (n_errores == 0){
                              paux = strdup("{//inicio sentencia entrada\n");
                              mystrcpy(&$$.codigo,&paux);
                              mystrcat(&$$.codigo,&$1.codigo);
                              paux = strdup("}//fin sentencia entrada\n");
                              mystrcat(&$$.codigo,&paux);
                              }}
                              |   sentencia_salida {
                                                                          if (n_errores == 0){
                              paux = strdup("{//inicio sentencia salida\n");
                              mystrcpy(&$$.codigo,&paux);
                              mystrcat(&$$.codigo,&$1.codigo);
                              paux = strdup("}//fin sentencia salida\n");
                              mystrcat(&$$.codigo,&paux);
                              }}
                              |   sentencia_retornar {
                                                                          if (n_errores == 0){
                              paux = strdup("{//inicio sentencia return\n");
                              mystrcpy(&$$.codigo,&paux);
                              mystrcat(&$$.codigo,&$1.codigo);
                              paux = strdup("}//fin sentencia return\n");
                              mystrcat(&$$.codigo,&paux);}}
sentencia_asignacion        : variable_expresion ASIG expresion PYC {procesaSentenciaAsignacion($1,$3);genCodigoAsignacion(&$$,&$1,&$3);}
                              |   error{paux = strdup(""); mystrcpy(&$$.codigo,&paux);paux = strdup(""); mystrcpy(&$$.nombreTmp,&paux);n_errores = n_errores+1;}
sentencia_si                : SI PARIZQ expresion PARDER Sentencia {procesaSentenciaControl($3);
                            genCodigoSi(&$$,&$3,&$5);}
                              |   SI PARIZQ expresion PARDER Sentencia
                              SINO Sentencia {procesaSentenciaControl($3);genCodigoSino(&$$,&$3,&$5,&$7);}
sentencia_mientras          : MIENTRAS PARIZQ expresion PARDER Sentencia {procesaSentenciaControl($3);
                            genCodigoMientras(&$$,&$3,&$5);}
sentencia_hacer_hasta       : HACER Sentencia HASTA PARIZQ expresion PARDER PYC {procesaSentenciaControl($5);genCodigoHacerHasta(&$$,&$5,&$2);}
sentencia_entrada           : ENTRADA lista_variables PYC {
                                                                          if (n_errores == 0){
                            paux = strdup("scanf(\"");
                            mystrcpy(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&textoScanf);
                            paux = strdup("\",");
                            mystrcat(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&$2.codigo);
                            paux = strdup(");\n");
                            mystrcat(&$$.codigo,&paux);
                            // Se resetea la variable global
                            textoScanf = NULL;
                                                                          }
                            }
sentencia_salida            : SALIDA lista_expresiones_cadena PYC {
                                                                          if (n_errores == 0){
                            mystrcpy(&$$.codigo,&$2.codigo);
                            paux = strdup("printf(\"");
                            mystrcat(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&textoPrintf);
                            paux = strdup("\",");
                            mystrcat(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&$2.nombreTmp);
                            paux = strdup(");\n");
                            mystrcat(&$$.codigo,&paux);
                            // Se resetea la variable global
                            textoPrintf = NULL;
                                                                          }
                            }


sentencia_retornar          : DEVOLVER expresion PYC {procesaSentenciaRetornar($2);
                                                                          if (n_errores == 0){
                            mystrcpy(&$$.codigo,&$2.codigo);
                            
                            if ($2.dimensiones == 1){
    
                              char* temporal_ret = temporal();
                              paux = strdup("\n");
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(enumAString($2.tipo));
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup("* ");
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(temporal_ret);
                              mystrcat(&$$.codigo,&paux);
                              
                              char numero[50];
                              paux = strdup("=(");
                              mystrcat(&$$.codigo,&paux);

                              paux = strdup(enumAString($2.tipo));
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(" *) ");
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup("malloc(");
                              mystrcat(&$$.codigo,&paux);

                              sprintf(numero,"%d",$2.TamDimen1*enumATamByte($2.tipo));
                              paux = strdup(numero);
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(");\nmemcpy(");
                              mystrcat(&$$.codigo,&paux);
                            
                              paux = strdup(temporal_ret);
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(",");
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup($2.nombreTmp);
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(",");
                              mystrcat(&$$.codigo,&paux);
                              
                              sprintf(numero,"%d",$2.TamDimen1*enumATamByte($2.tipo));
                              paux = strdup(numero);
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(");");
                              mystrcat(&$$.codigo,&paux);

                              mystrcpy(&$2.nombreTmp,&temporal_ret);
                            }else if ($2.dimensiones == 2){
                              char* temporal_ret = temporal();
                              paux = strdup("\n");
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(enumAString($2.tipo));
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup("** ");
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(temporal_ret);
                              mystrcat(&$$.codigo,&paux);
                              
                              char numero[50];
                              
                              paux = strdup("=(");
                              mystrcat(&$$.codigo,&paux);

                              paux = strdup(enumAString($2.tipo));
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(" **) ");
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup("malloc(");
                              mystrcat(&$$.codigo,&paux);

                              sprintf(numero,"%d",$2.TamDimen1*$2.TamDimen2*enumATamByte($2.tipo));
                              paux = strdup(numero);
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(");\nmemcpy(");
                              mystrcat(&$$.codigo,&paux);
                            
                              paux = strdup(temporal_ret);
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(",");
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup($2.nombreTmp);
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(",");
                              mystrcat(&$$.codigo,&paux);
                              
                              sprintf(numero,"%d",$2.TamDimen1*$2.TamDimen2*enumATamByte($2.tipo));
                              paux = strdup(numero);
                              mystrcat(&$$.codigo,&paux);
                              paux = strdup(");");
                              mystrcat(&$$.codigo,&paux);

                              mystrcpy(&$2.nombreTmp,&temporal_ret);

                            }

                            paux = strdup("\nreturn ");
                            mystrcat(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&$2.nombreTmp);
                            paux = strdup(";\n");
                            mystrcat(&$$.codigo,&paux);
                                                                }
                            }
lista_expresiones_cadena    : lista_expresiones_cadena COMA expresion_cadena {
                                                                          if (n_errores == 0){
                            mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                            paux = strdup(",");
                            mystrcat(&$$.nombreTmp,&paux);
                            mystrcat(&$$.nombreTmp,&$3.nombreTmp);
                            mystrcpy(&$$.codigo,&$1.codigo);
                            paux = strdup("\n");
                            mystrcat(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&$3.codigo);
                                                                          }
                            }
                              |   expresion_cadena {
                                                                          if (n_errores == 0){
                              mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                              mystrcpy(&$$.codigo,&$1.codigo);
                                                                          }
                            }
expresion_cadena            : expresion {
                                                                          if (n_errores == 0){
                            mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                            mystrcpy(&$$.codigo,&$1.codigo);
                            paux = strdup(enumATipoForm($1.tipo));
                            if (textoPrintf == NULL) mystrcpy(&textoPrintf, &paux);
                            else mystrcat(&textoPrintf,&paux);
                            paux = strdup(" ");
                            mystrcat(&textoPrintf,&paux);
                                                                          }
                            }
                            | cadena {
                                                                          if (n_errores == 0){
                            mystrcpy(&$$.nombreTmp,&$1.codigo);
                            paux = strdup("");
                            mystrcpy(&$$.codigo,&paux);
                            paux = strdup("%s ");
                            if (textoPrintf == NULL) mystrcpy(&textoPrintf, &paux);
                            else mystrcat(&textoPrintf,&paux);
                                                                        
                                                                          }
                            }
lista_variables             : variable {
                            entradaTS ets = buscarEntrada($1.lexema);
                            $1.tipo = ets.tipoDato;
                                                                          if (n_errores == 0){
                            paux = strdup("&");
                            mystrcpy(&$$.codigo,&paux);
                            mystrcat(&$$.codigo,&$1.codigo);
                            if (textoScanf == NULL){
                              paux = strdup(enumATipoForm($1.tipo));
                              mystrcpy(&textoScanf, &paux);
                            }
                            else {
                              paux = strdup(enumATipoForm($1.tipo));
                              mystrcat(&textoScanf,&paux);
                            }
                                                                        }
                            }
                              |   lista_variables COMA variable {
                                                                          if (n_errores == 0){
                              mystrcpy(&$$.codigo,&$1.codigo);
                              paux = strdup(",&");
                              mystrcat(&$$.codigo,&paux);
                              mystrcat(&$$.codigo,&$3.codigo);
                              entradaTS ets = buscarEntrada($3.lexema);
                              $3.tipo = ets.tipoDato;
                              if (textoScanf == NULL){
                                paux = strdup(enumATipoForm($3.tipo));
                                mystrcpy(&textoScanf, &paux);
                              }
                              else{
                                paux = strdup("\\n");
                                mystrcat(&textoScanf,&paux);
                                paux = strdup(enumATipoForm($3.tipo));
                                mystrcat(&textoScanf,&paux);
                              }
                                                                      }
                              }
lista_declaracion_variables :  variable {TS_InsertaIDENT($1);
                                                                          if (n_errores == 0){
                            paux = strdup($1.codigo);
                            mystrcpy(&$$.codigo,&paux);
                                                                          }
                            }
                              |   lista_declaracion_variables COMA variable {TS_InsertaIDENT($3);
                                                                          if (n_errores == 0){
                                                                             paux = strdup(",");
                                                                             mystrcat(&$1.codigo,&paux);
                                                                             mystrcat(&$1.codigo,&$3.codigo);
                                                                             paux = strdup($1.codigo);
                                                                             mystrcpy(&$$.codigo,&paux);
                                                                           }
                                                                             }
                              |   error{paux = strdup(""); mystrcpy(&$$.codigo,&paux);paux = strdup(""); mystrcpy(&$$.nombreTmp,&paux);n_errores = n_errores+1;}
lista_expresiones           : expresion {PILARG_insertaARG($1);
                                                                          if (n_errores == 0){
                            mystrcpy(&$$.codigo,&$1.codigo);
                            mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                                                                          }
                            }
                              |   lista_expresiones COMA expresion {PILARG_insertaARG($3);
                                                                          if (n_errores == 0){
                              mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                              paux = strdup(",");
                              mystrcat(&$$.nombreTmp,&paux);
                              mystrcat(&$$.nombreTmp,&$3.nombreTmp);
                              mystrcpy(&$$.codigo,&$1.codigo);
                              paux = strdup("\n");
                              mystrcat(&$$.codigo,&paux);
                              mystrcat(&$$.codigo,&$3.codigo);
                                                                          }
                              }
expresion                   : PARIZQ expresion PARDER {$$ = $2;}
                              |   OPNEG expresion {$$ = procesaOperacionNegacion($2);genCodigoOperadorUnNeg(&$$,&$2);}
                              |   OPSUMA expresion {$$ = procesaOperacionMixtaCuandoUnaria($2);genCodigoOperadorUn(&$$,&$2,$1.atrib);}
                              |   OPRESTA expresion %prec OPNEG {$$ = procesaOperacionMixtaCuandoUnaria($2);genCodigoOperadorUn(&$$,&$2,$1.atrib);}
                              |   expresion OPMULT expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
  
                              |   expresion OPDIV expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPMULTM expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPAND expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPOR expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPEQ expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPNEQ expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPLEQ expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPGEQ expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPLESS expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPGR expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPMOD expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorBin(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPSUMA expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorMix(&$$,&$1,&$3,$2.atrib);}
                              |   expresion OPRESTA expresion {$$ = procesaOperacionBinariaOMixta($1,$3,$2.atrib);genCodigoOperadorMix(&$$,&$1,&$3,$2.atrib);}
                              |   variable_expresion {$$ = $1;
                                                                          if (n_errores == 0){
                              mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                              mystrcpy(&$$.codigo,&$1.codigo);
                                                                          }
                              }
                              |   constante {$$ = $1;
                                                                          if (n_errores == 0){
                              mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                              mystrcpy(&$$.codigo,&$1.codigo);
                                                                          }
                              }
                              |   funcion {$$ = $1;

                                                                          if (n_errores == 0){
                              mystrcpy(&$$.codigo, &$1.codigo);
                              paux = strdup("\n");
                              mystrcat(&$$.codigo,&paux);
                              paux = temporal();
                              mystrcpy(&$$.nombreTmp,&paux);
                              if ($$.dimensiones == 0){
                                paux = strdup(enumAString($$.tipo));
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup(" ");
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup($$.nombreTmp);
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup(";\n");
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup($$.nombreTmp);
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup("=");
                                mystrcat(&$$.codigo,&paux);
                                mystrcat(&$$.codigo,&$1.nombreTmp);
                                paux = strdup(";\n");
                                mystrcat(&$$.codigo,&paux);
                              }else if ($$.dimensiones == 1){
                                paux = strdup(enumAString($$.tipo));
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup(" ");
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup($$.nombreTmp);
                                mystrcat(&$$.codigo,&paux);

                                char numero[50];
                                sprintf(numero,"[%d];\n",$$.TamDimen1);
                                paux = strdup(numero);
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup("memcpy(");
                                mystrcat(&$$.codigo, &paux);
                                paux = strdup($$.nombreTmp);
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup(",");
                                mystrcat(&$$.codigo,&paux);
                                mystrcat(&$$.codigo, &$1.nombreTmp);
                                paux = strdup(",");
                                mystrcat(&$$.codigo,&paux);
                                sprintf(numero,"%d);\n",$$.TamDimen1*enumATamByte($$.tipo));
                                paux = strdup(numero);
                                mystrcat(&$$.codigo,&paux);

                              }else if ($$.dimensiones == 2){
                                paux = strdup(enumAString($$.tipo));
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup(" ");
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup($$.nombreTmp);
                                mystrcat(&$$.codigo,&paux);

                                char numero[50];
                                sprintf(numero,"[%d][%d];\n",$$.TamDimen1,$$.TamDimen2);
                                paux = strdup(numero);
                                mystrcat(&$$.codigo,&paux);

                                paux = strdup("memcpy(");
                                mystrcat(&$$.codigo, &paux);
                                paux = strdup($$.nombreTmp);
                                mystrcat(&$$.codigo,&paux);
                                paux = strdup(",");
                                mystrcat(&$$.codigo,&paux);
                                mystrcat(&$$.codigo, &$1.nombreTmp);
                                paux = strdup(",");
                                mystrcat(&$$.codigo,&paux);
                                sprintf(numero,"%d);\n",$$.TamDimen1*$$.TamDimen2*enumATamByte($$.tipo));
                                paux = strdup(numero);
                                mystrcat(&$$.codigo,&paux);
                              }
                                                                    }
                              }
                              |   error{paux = strdup(""); mystrcpy(&$$.codigo,&paux);paux = strdup(""); mystrcpy(&$$.nombreTmp,&paux);n_errores = n_errores+1;}
funcion                     : identificador PARIZQ PARDER {entradaTS ets = buscarEntrada($1.lexema);
                                                           procesaLlamadaFuncionSinArgumentos(ets);
                                                           $$ = entradaAAtributos(ets);
                                                                          if (n_errores == 0){

                                                           mystrcpy(&$$.nombreTmp,&$1.codigo);
                                                           paux = strdup("(");
                                                           mystrcat(&$$.nombreTmp,&paux);
                                                           paux = strdup(")");
                                                           mystrcat(&$$.nombreTmp,&paux);
                                                           paux = strdup("");
                                                           mystrcpy(&$$.codigo,&paux);}
                                                           }
                              |   identificador PARIZQ {PILARG_insertaMARCA();} lista_expresiones PARDER
                              {entradaTS ets = buscarEntrada($1.lexema);
                               procesaLlamadaFuncionConArgumentos(ets);
                               $$ = entradaAAtributos(ets);
                                                                          if (n_errores == 0){

                               mystrcpy(&$$.codigo,&$4.codigo);
                               paux = strdup("\n");
                               mystrcat(&$$.codigo,&paux);
                               mystrcpy(&$$.nombreTmp,&$1.codigo);
                               paux = strdup("(");
                               mystrcat(&$$.nombreTmp,&paux);
                               mystrcat(&$$.nombreTmp,&$4.nombreTmp);
                               paux = strdup(")");
                               mystrcat(&$$.nombreTmp,&paux);
                                                                        }
                              }
tipo                        : TIPOEL {$$.atrib = $1.atrib;}
cadena                      : CADENA {paux = strdup($1.lexema);if (n_errores == 0) mystrcpy(&$$.codigo,&paux);}
identificador               : IDEN  {paux = strdup($1.lexema);if (n_errores == 0) mystrcpy(&$$.codigo,&paux);}
constante                   : CONST {$$.tipo = atributoAEnum($1.atrib+1);

                                                                          if (n_errores == 0){
                            paux = strdup("");
                            mystrcpy(&$$.codigo,&paux);
                            paux = strdup($1.lexema);
                            mystrcpy(&$$.nombreTmp,&paux);
                                                                          }
                            }
                              | CONSTENT  {$$.tipo = entero;
                                                                          if (n_errores == 0){
                              paux = strdup("");
                              mystrcpy(&$$.codigo,&paux);
                              paux = strdup($1.lexema);
                              mystrcpy(&$$.nombreTmp,&paux);
                                                                          }
                              }
                              |   CORIZQ ini_elementos_array CORDER { $$.tipo = $2.tipo;
 
                                                                    if (n_errores == 0){
                                                                      mystrcpy(&$$.codigo,&$2.codigo);
                                                                      paux = temporal();
                                                                      mystrcpy(&$$.nombreTmp,&paux);
                                                                      paux = strdup("\n");
                                                                      mystrcat(&$$.codigo,&paux);
                                                                      paux = strdup(enumAString($2.tipo));
                                                                      mystrcat(&$$.codigo,&paux);
                                                                      paux = strdup(" ");
                                                                      mystrcat(&$$.codigo,&paux);
                                                                      paux = strdup($$.nombreTmp);
                                                                      mystrcat(&$$.codigo,&paux);
                                                                    }
                                                                      if ($2.TamDimen2==1){
                                                                        $$.TamDimen2 = 0;
                                                                        $$.TamDimen1 = $2.TamDimen1;
                                                                        $$.dimensiones = 1;
                                                                        
                                                                          if (n_errores == 0){
                                                                        char numero[50];
                                                                        sprintf(numero,"[%d]=",$2.TamDimen1);
                                                                        paux = strdup(numero);
                                                                        mystrcat(&$$.codigo,&paux);
                                                                        mystrcat(&$$.codigo, &$2.nombreTmp);
                                                                        paux = strdup(";");
                                                                        mystrcat(&$$.codigo,&paux);
                                                                          }
                                                                      }
                                                                      else{
                                                                        $$.TamDimen2 = $2.TamDimen1;
                                                                        $$.TamDimen1 = $2.TamDimen2;
                                                                        $$.dimensiones = 2;
                                                                        
                                                                          if (n_errores == 0){
                                                                        char numero[50];
                                                                        sprintf(numero,"[%d][%d]={",$$.TamDimen1,$$.TamDimen2);
                                                                        paux = strdup(numero);
                                                                        mystrcat(&$$.codigo,&paux);

                                                                        mystrcat(&$$.codigo,&$2.nombreTmp);
                                                                        paux = strdup("};");
                                                                        mystrcat(&$$.codigo,&paux);
                                                                          }
                                                                      }
                                                                      }
ini_elementos_array         : ini_elementos_array PYC lista_expresiones_array {$$.TamDimen2 = $1.TamDimen2 + 1;

                                                                          if (n_errores == 0){
                                                                              mystrcpy(&$$.codigo,&$1.codigo);
                                                                              paux = strdup("\n");
                                                                              mystrcat(&$$.codigo, &paux);
                                                                              mystrcat(&$$.codigo, &$3.codigo);

                                                                              mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                                                                              paux = strdup(",{");
                                                                              mystrcat(&$$.nombreTmp,&paux);
                                                                              mystrcat(&$$.nombreTmp,&$3.nombreTmp);
                                                                              paux = strdup("}");
                                                                              mystrcat(&$$.nombreTmp,&paux);
                                                                          }
                                                                              if ($1.tipo != $3.tipo){
                                                                                printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;
                                                                                printf("ERROR SEMÁNTICO: Matriz con distintos tipos en distintas columnas.\n");
                                                                              }
                                                                              if ($1.TamDimen1 != $3.TamDimen1){
                                                                                printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;
                                                                                printf("ERROR SEMÁNTICO: La matriz tiene distinto número de filas en distintas columnas.\n");
                                                                              }else{
                                                                                $$.TamDimen1 = $1.TamDimen1;
                                                                              }}
                              |   lista_expresiones_array {
                                                                          $$.TamDimen2 = 1;
                                                                          $$.TamDimen1 = $1.TamDimen1;
                                                                          $$.tipo = $1.tipo;
                                                                          if (n_errores == 0){
                                                                          mystrcpy(&$$.codigo,&$1.codigo);
                                                                          paux = strdup("{");
                                                                          mystrcpy(&$$.nombreTmp,&paux);
                                                                          mystrcat(&$$.nombreTmp,&$1.nombreTmp);
                                                                          paux = strdup("}");
                                                                          mystrcat(&$$.nombreTmp,&paux);
                                                                          }
                                                                          }

lista_expresiones_array       : expresion {
                                                                          $$.TamDimen1 = 1;
                                                                          $$.tipo = $1.tipo;
                                                                          if (n_errores == 0){
                                                                          mystrcpy(&$$.nombreTmp, &$1.nombreTmp);
                                                                          mystrcpy(&$$.codigo, &$1.codigo);
                                                                          }
                                                                          }
                              |   lista_expresiones_array COMA expresion {$$.TamDimen1 = $1.TamDimen1 + 1;
                                                                          if (n_errores == 0){

                                                                          mystrcpy(&$$.codigo,&$1.codigo);
                                                                          paux = strdup("\n");
                                                                          mystrcat(&$$.codigo,&paux);
                                                                          mystrcat(&$$.codigo, &$3.codigo);

                                                                          mystrcpy(&$$.nombreTmp, &$1.nombreTmp);
                                                                          paux = strdup(", ");
                                                                          mystrcat(&$$.nombreTmp,&paux);
                                                                          mystrcat(&$$.nombreTmp,&$3.nombreTmp);
                                                                          }
                                                                          if ($1.tipo != $3.tipo){
                                                                                printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;
                                                                                printf("ERROR SEMÁNTICO: Array con distintos tipos.\n");
                                                                          }}


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
























/* ANALISIS SEMÁNTICO */


void PILARG_insertaENTRADA(entradaTS ets){

  if (TOPE_ARG == MAX_TS){
    fprintf(stderr, "Error: Se ha alcanzado el máximo tamaño de la pila argumentos. \n ABORTANDO\n");
    exit(-1);
  }else{
    /* Introduzco el valor en la pila y cambio el tope */
    PILA_ARG[TOPE_ARG] = ets;
    TOPE_ARG = TOPE_ARG + 1;
  }
}

void PILARG_insertaMARCA(){

  entradaTS ets;
  ets.entrada = marca;
  ets.nombre = "";
  ets.tipoDato = no_asignado;
  ets.parametros = 0;
  ets.dimensiones = 0;
  ets.TamDimen1 = 0;
  ets.TamDimen2 = 0;

  PILARG_insertaENTRADA(ets);
}

void PILARG_insertaARG(atributos arg){
  entradaTS ets;
  ets.tipoDato = arg.tipo;
  ets.dimensiones = arg.dimensiones;
  ets.TamDimen1 = arg.TamDimen1;
  ets.TamDimen2 = arg.TamDimen2;

PILARG_insertaENTRADA(ets);
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

 //mostrar_tabla();
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
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Doble declaración de la variable '%s'\n",ets.nombre);
    }

    if (TS[tope_aux].entrada == marca) break;
    tope_aux--;
  }

  TS_InsertaENTRADA(ets);
}



void TS_VaciarENTRADAS(){

  if (TOPE == 0) fprintf(stderr, "Error: intenta vaciar tabla de símbolos vacía\n");

  while (TS[TOPE-1].entrada != marca) TOPE--;

  if (TOPE > 0){
    TOPE--;
    int iaux = TOPE-1;
    if (iaux > 0){
      while (TS[iaux].entrada != funcion){TS[iaux].valido = -1;iaux--;}
      TS[iaux].valido = -1;
    }
  }else{
    fprintf(stderr, "Error: No se encontró marca al vaciar tabla de símbolos\n");
  }
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
    if (strcmp(TS_aux[tope_aux].nombre,ets.nombre) == 0) {
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;
      printf("ERROR SEMÁNTICO:se ha encontrado otro parámetro formal con el mismo identificador: '%s'\n", ets.nombre);
    }
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
    printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: se utiliza un identificador no declarado: '%s'\n", nombre);
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

  //printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;
  //printf("OP1: tipo:%s dim:%d t1:%d t2:%d  OP2: tipo:%s dim:%d t1:%d t2:%d\n",enumAChar(op1.tipo),op1.dimensiones,op1.TamDimen1,op1.TamDimen2,enumAChar(op2.tipo),op2.dimensiones,op2.TamDimen1,op2.TamDimen2);

  // Caso (+,*)
  if (opdor == 0){
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador (+|*) espera tipo entero/real\n");
    }
    
    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }
    if( (op1.dimensiones==1 && op2.dimensiones==2) ||
              (op1.dimensiones==2 && op2.dimensiones==1)){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con una array y una matriz.\n");
    }
    if (op1.dimensiones==0){
      atr = op2;
    }else if (op2.dimensiones==0){
      atr = op1;
    }
    if (op1.dimensiones==1 && op2.dimensiones==1){
      if (op1.TamDimen1 == op2.TamDimen1) atr = op1;
      else {
        printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con arrays de distintos tamaños.\n");
      }
    }else if(op1.dimensiones==2 && op2.dimensiones==2){
      if (op1.TamDimen1 == op2.TamDimen1 && op1.TamDimen2 == op2.TamDimen2) atr = op1;
      else {
        printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con matrices de distintos tamaños.\n");
      }
    }
  }
  
  // Caso (-,/)
  if (opdor == 1){
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador (-|/) espera tipo entero/real\n");
    }
    
    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }
    if( (op1.dimensiones==1 && op2.dimensiones==2) ||
              (op1.dimensiones==2 && op2.dimensiones==1)){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con una array y una matriz.\n");
    }
    if (op1.dimensiones==0 && op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: No se puede restar/dividir un array/matriz a un valor.\n");
    }else if (op2.dimensiones==0){
      atr = op1;
    }
    if (op1.dimensiones==1 && op2.dimensiones==1){
      if (op1.TamDimen1 == op2.TamDimen1) atr = op1;
      else{
        printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con arrays de distintos tamaños.\n");
      }
    }else if(op1.dimensiones==2 && op2.dimensiones==2){
      if (op1.TamDimen1 == op2.TamDimen1 && op1.TamDimen2 == op2.TamDimen2) atr = op1;
      else {
        printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con matrices de distintos tamaños.\n");
      }
    }
  }

  // Caso **
  if (opdor == 2){
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador ** espera tipo entero/real\n");
    }
    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }
    if (op1.dimensiones == 1 || op1.dimensiones == 0){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador ** espera matrices\n");
    }
    if (op2.dimensiones == 1 || op2.dimensiones == 0){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador ** espera matrices\n");
    }
    if (op1.dimensiones == 2 && op2.dimensiones ==2){
      if (op1.TamDimen2 != op2.TamDimen1){
        printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Multiplicación de matrices inválida. No se puede multiplicar dimensiones (%dX%d)**(%dX%d)\n",op1.TamDimen1,op1.TamDimen2,op2.TamDimen1,op2.TamDimen2);
      }else{
        atr = op1;
        atr.TamDimen2 = op2.TamDimen2;
      }
    }
  }

  // Caso (&&,||)
  if (opdor == 3  || opdor == 4){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: No se puede utilizar el operador (&&,||) con arrays/matrices.\n");
    }else if (op1.tipo != booleano || op2.tipo != booleano){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador (&&,||) espera tipo booleano\n");
    }else{
      atr = op1;
    }
  }

  // Caso == y !=
  if (opdor == 5 || opdor == 6){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: No se puede comparar arrays/matrices.\n");
    }else if(op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: No se puede comparar expresiones de distinto tipo\n");
    }else{
      atr = op1;
      atr.tipo = booleano;
    }
  }

  // Caso operador relacional >,<,>=,...
  if (opdor >= 7 && opdor <= 10){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: No se puede utilizar un operador relacional con arrays/matrices.\n");
    }
    if ((op1.tipo != entero && op1.tipo != real) || (op2.tipo != entero && op2.tipo != real)){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador ** espera tipo entero/real\n");
    }

    if (op1.tipo != op2.tipo){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Se intenta operar con expresiones de distinto tipo.\n");
    }else if(op1.dimensiones == 0 && op2.dimensiones == 0){
      atr = op1;
      atr.tipo = booleano;
    }
  }

  // Caso módulo %
  if (opdor == 11){
    if (op1.dimensiones != 0 || op2.dimensiones != 0){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: No se puede hacer módulo de arrays/matrices.\n");
    }else if(op1.tipo != entero || op2.tipo != entero){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador módulo espera dos enteros.\n");
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
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador unario (+ | -) no espera un array o matriz.\n");
  }

  if (op1.tipo != entero && op1.tipo != real){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador unario (+ | -) espera tipo real o entero.\n");
  }

  if ((op1.tipo == entero || op1.tipo == real) && op1.dimensiones == 0){
    atr = op1;
  }

  return atr;
}

atributos procesaOperacionNegacion(atributos op1){

  atributos atr;

  if (op1.tipo != booleano){
    printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador de negación espera un booleano.\n");
  }

  if (op1.dimensiones != 0){
    printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El operador de negación no espera un array o matriz.\n");
  }

  if (op1.dimensiones == 0 && op1.tipo == booleano){
    atr = op1;
  }

  return atr;
}




void procesaLlamadaFuncionConArgumentos(entradaTS ets){

  int i = TOPE-1;
  int indice_args;
  int n_params = 0;
  int indice_borrado;
  while (i>=0){
    if (strcmp(TS[i].nombre,ets.nombre) == 0) break;
    i--;
  }

  if (i >= 0){
    indice_args = TOPE_ARG-1;

    while (PILA_ARG[indice_args].entrada != marca){indice_args--;}
    indice_borrado = indice_args;
    indice_args++;

    if (indice_args == 0){
      printf("ERROR: No hay argumentos en la llamada de la función %s.\n",ets.nombre);
    }else{
      i = i + 1;
      while (TS[i].entrada == parametro_formal && i < TOPE && indice_args < TOPE_ARG){
        if (TS[i].tipoDato != PILA_ARG[indice_args].tipoDato){
          printf("[Linea %d]",linea_actual); n_errores = n_errores + 1; printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d es de tipo distinto al esperado.\n",ets.nombre,n_params+1);
        }
        if (TS[i].dimensiones != PILA_ARG[indice_args].dimensiones){
          printf("[Linea %d]",linea_actual); n_errores = n_errores + 1; printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimensiones distintas a las esperadas.\n",ets.nombre,n_params+1);
        }else{
          if (TS[i].dimensiones == 1){
            if (TS[i].TamDimen1 != PILA_ARG[indice_args].TamDimen1){
              printf("[Linea %d]",linea_actual); n_errores = n_errores + 1; printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimension 1 distinta al esperado.\n",ets.nombre,n_params+1);
            }
          }

          if (TS[i].dimensiones == 2){
            if (TS[i].TamDimen1 != PILA_ARG[indice_args].TamDimen1){
              printf("[Linea %d]",linea_actual); n_errores = n_errores + 1; printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimension 1 distinta al esperado.\n",ets.nombre,n_params+1);
            }

            if (TS[i].TamDimen2 != PILA_ARG[indice_args].TamDimen2){
              printf("[Linea %d]",linea_actual); n_errores = n_errores + 1; printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimension 2 distinta al esperado.\n",ets.nombre,n_params+1);
            }
          }

        }

        i = i + 1;
        indice_args = indice_args + 1;
        n_params = n_params + 1;
      }
      if (indice_args != TOPE_ARG){
          printf("[Linea %d]",linea_actual); n_errores = n_errores + 1; printf("ERROR SEMÁNTICO: Se han pasado más argumentos de los esperados a la funcion %s.\n",ets.nombre);
      }
      if (ets.parametros > n_params){
          printf("[Linea %d]",linea_actual); n_errores = n_errores + 1; printf("ERROR SEMÁNTICO: Se han pasado menos argumentos de los esperados a la funcion %s.\n",ets.nombre);
      }
    }
  }

  TOPE_ARG = indice_borrado;
}

void procesaLlamadaFuncionSinArgumentos(entradaTS ets){
  if (ets.parametros > 0){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1; printf("ERROR SEMÁNTICO: Se han pasado 0 argmuentos a la funcion %s, se esperan más.\n",ets.nombre);
  }
}




void procesaSentenciaAsignacion(atributos op1, atributos op2){
  if (op1.tipo != op2.tipo){
    printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Asignacion de tipos distintos.\n");
  }
  if (op1.dimensiones != op2.dimensiones){
    printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Asignacion variables con dimensiones distintas.\n");
  }else{
    if (op1.dimensiones == 1){
      if (op1.TamDimen1 != op2.TamDimen1){
        printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Asignacion de arrays de distinto tamaño.\n");
      }
    }
    if (op1.dimensiones == 2){
      if ((op1.TamDimen1 != op2.TamDimen1) || (op1.TamDimen2 != op2.TamDimen2)){
        printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: Asignacion de matrices de distintos tamaños.\n");
      }
    }
  }
}

void procesaSentenciaRetornar(atributos ret){

  int i = TOPE-1;

  while (i>=1){
    if (TS[i].entrada == marca && TS[i-1].valido != -1  && (TS[i-1].entrada == parametro_formal || TS[i-1].entrada == funcion)) break;
    i--;
  }

  if (i == 0){
      printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: No se deben retornar valores en el programa principal.\n");
  }else{
     while (i>=0){
       if (TS[i].entrada == funcion) break;
        i--;
     }
     if (i == 0){
       printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: no se encontró la función del devolver en el analisis semántico\n");
       return;
     }
     if (TS[i].tipoDato != ret.tipo){
       printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: El valor retornado no se corresponde con el que devuelve la función.\n");
     }
     if (TS[i].dimensiones != ret.dimensiones){
       printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: La dimension del valor retornado no se corresponde con la que devuelve la función.\n");
     }


     if (TS[i].TamDimen1 != ret.TamDimen1){
       printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: La dimension 1 del valor retornado no se corresponde con la que devuelve la función.\n");
     }

     if (TS[i].TamDimen2 != ret.TamDimen2){
       printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: La dimension 2 del valor retornado no se corresponde con la que devuelve la función.\n");
     }
  }
}

void procesaSentenciaControl(atributos exp){
  if (exp.tipo != booleano){
    printf("[Linea %d]",linea_actual); n_errores = n_errores + 1;   printf("ERROR SEMÁNTICO: La sentencia de control (si|mientras|hasta) espera una expresión booleana.\n");
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

int enumATamByte(dtipo t){

  if (t == entero)return 4;
  if (t == booleano)return 4;
  if (t == real)return 8; 
  if (t == caracter)return 1;

  return 0;
}




/* GENERACIÓN DE CÓDIGO */



void empezarGEN(){

  intermain = fopen("main_inter.c","w");
  dec_fun = fopen("dec_fun.c","w");

  fputs("#include <stdio.h>\n",intermain);
  fputs("#include <stdlib.h>\n",intermain);
  fputs("#include <string.h>\n",intermain);
  fputs("#include <stdbool.h>\n",intermain);
  fputs("#include \"FuncionesArrays/dec_dat.h\"\n",intermain);

  fputs("#ifndef FUNCIONES_DEC\n",dec_fun);
  fputs("#define FUNCIONES_DEC\n",dec_fun);

}


void finalizarGEN(){
  fputs("\n",intermain);
  fputs("\n",dec_fun);
  fputs("#endif\n",dec_fun);
  fclose(dec_fun);
  fclose(intermain);

}


char* temporal(){
  char tmp[10];
  sprintf(tmp,"tmp%d",Ntmp);
  Ntmp = Ntmp + 1;
  return strdup(tmp);
}


char* etiqueta(){
  char etiqueta[20];
  sprintf(etiqueta,"etiqueta%d",Netiqueta);
  Netiqueta = Netiqueta + 1;
  return strdup(etiqueta);
}

char* enumAString(dtipo t){

  if (t == entero)return strdup("int");
  if (t == booleano)return strdup("int");
  if (t == real)return strdup("double");
  if (t == caracter)return strdup("char");

  return strdup("Ninguno");
}

char* opdorUnAString(int opdor){
  if (opdor == 0) return strdup("+");
  if (opdor == 1) return strdup("-");
  return strdup("Ninguno");
}




char* opdorBinAString(int opdor){
  if (opdor == 0) return strdup("*");
  if (opdor == 1) return strdup("/");
  if (opdor == 2) return strdup("**");
  if (opdor == 3) return strdup("&&");
  if (opdor == 4) return strdup("||");
  if (opdor == 5) return strdup("==");
  if (opdor == 6) return strdup("!=");
  if (opdor == 7) return strdup("<=");
  if (opdor == 8) return strdup(">=");
  if (opdor == 9) return strdup("<");
  if (opdor == 10) return strdup(">");
  if (opdor == 11) return strdup("%");
  return strdup("Ninguno");
}

char* opdorMatBinAString(int opdor){
  if (opdor == 0) return strdup("producto");
  if (opdor == 1) return strdup("division");
  if (opdor == 2) return strdup("producto_mat");
  return strdup("Ninguno");
}

char* opdorMatUnAString(int opdor){
  if (opdor == 0) return strdup("suma");
  if (opdor == 1) return strdup("diferencia");
  return strdup("Ninguno");
}

void genCodigoOperadorMix(atributos* obj, atributos* at1, atributos* at2, int opdor){
if (n_errores == 0){
  if ((*at1).dimensiones > 0 && (*at2).dimensiones == 0){
    // tipo_operador_array_num(tmp%d,op1,op2,dimx,dimy)
    // tipo_operador_array_num(tmp%d,op1,op2,dimx,1)
    genCodigoOperadorMix(obj, at2, at1, opdor);
    return;
  }

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(&(*obj).codigo,&(*at1).codigo);
  paux = strdup("\n");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*at2).codigo);
  paux = strdup("\n");
  mystrcat(&(*obj).codigo,&paux);
  paux = enumAString((*obj).tipo);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(" ");


  if ((*at1).dimensiones == 0 && (*at2).dimensiones == 0){
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(";\n");

  mystrcat(&(*obj).codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup("=");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*at1).nombreTmp);
  paux = strdup(opdorUnAString(opdor));
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*at2).nombreTmp);
  paux = strdup(";\n");
  mystrcat(&(*obj).codigo,&paux);
  }
  else if ((*at1).dimensiones == 1 && (*at2).dimensiones == 1){
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("[");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("]");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
    // tipo_operador_array(tmp%d,op1,op2,dimx,1)
    sprintf(paux, "%s",enumAString((*at1).tipo));//tipo
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(opdorMatUnAString(opdor));//operador
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_array(");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);//tmp%d
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);//op1
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);//op2
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("1);\n");
    mystrcat(&(*obj).codigo,&paux);
  }else if ((*at1).dimensiones == 2 && (*at2).dimensiones == 2){
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("[");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("][");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen2);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("]");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
    // tipo_operador_array(tmp%d,op1,op2,dimx,dimy)
    sprintf(paux, "%s",enumAString((*at1).tipo));//tipo
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(opdorMatUnAString(opdor));//operador
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_array(");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);//tmp%d
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);//op1
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);//op2
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen2);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(");\n");
    mystrcat(&(*obj).codigo,&paux);
  }else if ((*at1).dimensiones == 0 && (*at2).dimensiones == 1){
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("[");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("]");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
    // tipo_operador_array_num(tmp%d,op1,op2,dimx,1)
    sprintf(paux, "%s",enumAString((*at1).tipo));//tipo
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(opdorMatUnAString(opdor));//operador
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_array_num(");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);//tmp%d
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);//op1
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);//op2
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("1);\n");
    mystrcat(&(*obj).codigo,&paux);
  }else if ((*at1).dimensiones == 0 && (*at2).dimensiones == 2){
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("[");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("][");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen2);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("]");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
    // tipo_operador_array_num(tmp%d,op1,op2,dimx,dimy)
    sprintf(paux, "%s",enumAString((*at1).tipo));//tipo
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(opdorMatUnAString(opdor));//operador
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_array_num(");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);//tmp%d
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);//op1
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);//op2
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen2);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(");\n");
    mystrcat(&(*obj).codigo,&paux);
  }
}
}

void genCodigoOperadorBin(atributos* obj, atributos* at1, atributos* at2, int opdor){
if (n_errores == 0){
  if ((*at1).dimensiones > 0 && (*at2).dimensiones == 0){
    // tipo_operador_array_num(tmp%d,op1,op2,dimx,dimy)
    // tipo_operador_array_num(tmp%d,op1,op2,dimx,1)
    genCodigoOperadorBin(obj, at2, at1, opdor);
    return;
  }
  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(&(*obj).codigo,&(*at1).codigo);
  paux = strdup("\n");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*at2).codigo);
  paux = strdup("\n");
  mystrcat(&(*obj).codigo,&paux);
  paux = enumAString((*obj).tipo);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(" ");

  if ((*at1).dimensiones == 0 && (*at2).dimensiones == 0){
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(";\n");
    // tmp%d = op1 operador op2
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);//tmp%d
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("=");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);//op1
    paux = strdup(opdorBinAString(opdor));//operador
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);//op2
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
  }
  else if ((*at1).dimensiones == 1 && (*at2).dimensiones == 1){
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("[");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("]");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
    // tipo_operador_array(tmp%d,op1,op2,dimx,1)
    sprintf(paux, "%s",enumAString((*at1).tipo));//tipo
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(opdorMatBinAString(opdor));//operador
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_array(");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);//tmp%d
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);//op1
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);//op2
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("1);\n");
    mystrcat(&(*obj).codigo,&paux);
  }else if ((*at1).dimensiones == 2 && (*at2).dimensiones == 2){
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("[");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("][");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen2);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("]");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
    // tipo_operador_array(tmp%d,op1,op2,dimx,dimy)
    sprintf(paux, "%s",enumAString((*at1).tipo));//tipo
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(opdorMatBinAString(opdor));//operador
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_array(");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);//tmp%d
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);//op1
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);//op2
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at1).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    if (opdor == 2){
        
      paux = strdup("");
      sprintf(paux, "%d", (*at1).TamDimen2);
      mystrcat(&(*obj).codigo,&paux);
      paux = strdup(", ");
      mystrcat(&(*obj).codigo,&paux);
    }
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen2);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(");\n");
    mystrcat(&(*obj).codigo,&paux);
  }else if ((*at1).dimensiones == 0 && (*at2).dimensiones == 1){
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("[");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("]");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
    // tipo_operador_array_num(tmp%d,op1,op2,dimx,1)
    sprintf(paux, "%s",enumAString((*at1).tipo));//tipo
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(opdorMatBinAString(opdor));//operador
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_array_num(");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);//tmp%d
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);//op1
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);//op2
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("1);\n");
    mystrcat(&(*obj).codigo,&paux);
  }else if ((*at1).dimensiones == 0 && (*at2).dimensiones == 2){
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("[");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("][");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen2);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("]");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
    // tipo_operador_array_num(tmp%d,op1,op2,dimx,dimy)
    sprintf(paux, "%s",enumAString((*at1).tipo));//tipo
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(opdorMatBinAString(opdor));//operador
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("_array_num(");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*obj).nombreTmp);//tmp%d
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);//op1
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);//op2
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen1);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(", ");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup("");
    sprintf(paux, "%d", (*at2).TamDimen2);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(");\n");
    mystrcat(&(*obj).codigo,&paux);
  }
}
}

void genCodigoOperadorUn(atributos* obj, atributos* at1, int opdor){
if (n_errores == 0){
  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(&(*obj).codigo,&(*at1).codigo);
  paux = strdup("\n");
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(enumAString((*obj).tipo));
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(" ");
  mystrcat(&(*obj).codigo,&paux);

  paux = strdup((*obj).nombreTmp);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(";\n");
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup("=");
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(opdorUnAString(opdor));
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*at1).nombreTmp);
  paux = strdup(";\n");
  mystrcat(&(*obj).codigo,&paux);
}
}

void genCodigoOperadorUnNeg(atributos* obj, atributos* at1){

if (n_errores == 0){

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(&(*obj).codigo,&(*at1).codigo);
  paux = strdup("\n");
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(enumAString((*obj).tipo));
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(" ");
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(";\n");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*obj).nombreTmp);
  paux = strdup("=");
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup("!");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*at1).nombreTmp);
  paux = strdup(";\n");
  mystrcat(&(*obj).codigo,&paux);
}
}

void genCodigoAsignacion(atributos* obj, atributos* at1, atributos* at2){
if (n_errores == 0){
  mystrcpy(&(*obj).codigo,&(*at2).codigo);
  paux = strdup("\n");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*at1).codigo);
  paux = strdup("\n");
  mystrcat(&(*obj).codigo,&paux);

  if((*at1).dimensiones == 0 && (*at2).dimensiones == 0)
  {
    mystrcat(&(*obj).codigo,&(*at1).nombreTmp);
    paux = strdup(" = ");
    mystrcat(&(*obj).codigo,&paux);
    mystrcat(&(*obj).codigo,&(*at2).nombreTmp);
    paux = strdup(";\n");
    mystrcat(&(*obj).codigo,&paux);
  }
  else
  {
    int dx = (*at2).TamDimen1;
    int dy = ((*at2).dimensiones == 2)? (*at2).TamDimen2 : 1;
    int tam_bytes = enumATamByte((*obj).tipo);
    paux = strdup("memcpy(");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*at1).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(",");
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup((*at2).nombreTmp);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(",");
    mystrcat(&(*obj).codigo,&paux);
    char numero[50];
    sprintf(numero,"%d",dy*dx*tam_bytes);
    paux = strdup(numero);
    mystrcat(&(*obj).codigo,&paux);
    paux = strdup(");\n");
    mystrcat(&(*obj).codigo,&paux);
  }
}
}

void genCodigoExpresionEntreCorchetes(char** obj, atributos* atr){
  mystrcpy(obj,&(*atr).codigo);
  mystrcat(obj,&(*atr).nombreTmp);
}


char* enumATipoForm(dtipo t){

  if (t == entero)return strdup("%d");
  if (t == booleano)return strdup("%d");
  if (t == real)return strdup("%f");
  if (t == caracter)return strdup("%c");

  return strdup("Ninguno");
}

void genCodigoSi(atributos* obj,atributos* cond,atributos* sent){
if (n_errores == 0){

  char* etfin = etiqueta();

  mystrcpy(&(*obj).codigo,&(*cond).codigo);
  paux=strdup("if (!");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(&(*obj).codigo,&paux);
  paux=strdup(etfin);
  mystrcat(&(*obj).codigo,&paux);
  paux=strdup(";\n{//inicio if\n");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*sent).codigo);
  paux=strdup("}//fin if\n");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&etfin);
  paux = strdup(": ;\n");
  mystrcat(&(*obj).codigo,&paux);
}
}


void genCodigoSino(atributos* obj,atributos* cond, atributos* sent, atributos* sent2){
if (n_errores == 0){

  char* etfin = etiqueta();
  char* etelse = etiqueta();

  mystrcpy(&(*obj).codigo,&(*cond).codigo);
  paux=strdup("if (!");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(&(*obj).codigo,&paux);
  paux=strdup(etelse);
  mystrcat(&(*obj).codigo,&paux);
  paux=strdup(";\n{//inicio if\n");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*sent).codigo);
  paux=strdup("}//fin if\n");
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup("goto ");
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(etfin);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(";\n");
  mystrcat(&(*obj).codigo,&paux);

  mystrcat(&(*obj).codigo,&etelse);
  paux = strdup(": ;\n");
  mystrcat(&(*obj).codigo,&paux);


  paux=strdup("{//inicio else\n");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*sent2).codigo);
  paux=strdup("}//fin else\n");
  mystrcat(&(*obj).codigo,&paux);



  mystrcat(&(*obj).codigo,&etfin);
  paux = strdup(": ;\n");
  mystrcat(&(*obj).codigo,&paux);
}
}



void genCodigoMientras(atributos* obj,atributos* cond,atributos* sent){
if (n_errores == 0){
  char* etini = etiqueta();
  char* etfin = etiqueta();
  paux = strdup(etini);
  mystrcpy(&(*obj).codigo,&paux);
  paux=strdup(": ;\n");
  mystrcat(&(*obj).codigo,&paux);

  mystrcat(&(*obj).codigo,&(*cond).codigo);
  paux=strdup("if (!");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(&(*obj).codigo,&paux);
  paux=strdup(etfin);
  mystrcat(&(*obj).codigo,&paux);
  paux=strdup(";\n");
  mystrcat(&(*obj).codigo,&paux);

  mystrcat(&(*obj).codigo, &(*sent).codigo);

  paux = strdup("\ngoto ");
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(etini);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(";\n");
  mystrcat(&(*obj).codigo,&paux);


  paux = strdup(etfin);
  mystrcat(&(*obj).codigo,&paux);
  paux = strdup(": ;\n");
  mystrcat(&(*obj).codigo,&paux);
}
}


void genCodigoHacerHasta(atributos* obj,atributos* cond,atributos* sent){

if (n_errores == 0){
  char* etini = etiqueta();

  paux = strdup(etini);
  mystrcpy(&(*obj).codigo,&paux);
  paux = strdup(": ;\n");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*sent).codigo);


  mystrcat(&(*obj).codigo,&(*cond).codigo);

  paux=strdup("if (!");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(&(*obj).codigo,&paux);
  mystrcat(&(*obj).codigo,&etini);
  paux=strdup(";\n");
  mystrcat(&(*obj).codigo,&paux);
}
}

void quitarCorchetesCabecera(char* cadena){
if (n_errores == 0){

  char* aux;
  int i = 0;
  while (i < strlen(cadena)){
    if (cadena[i] == '[') break;
    i++;
  }

  while (i < strlen(cadena)){
    cadena[i] = '\0';
  }
}
}

void genCabeceraSubprograma(atributos* obj, char* tipo, atributos* atr, atributos* args)
{
if (n_errores == 0){
  sprintf(paux,"%s", tipo);
  mystrcpy(&(*obj).codigo, &paux);

  if ((*atr).dimensiones == 1){
    paux = strdup("*");
    mystrcat(&(*obj).codigo, &paux);
    quitarCorchetesCabecera((*atr).codigo);
  } else if ((*atr).dimensiones == 2){
    paux = strdup("**");
    mystrcat(&(*obj).codigo, &paux);
    quitarCorchetesCabecera((*atr).codigo);
 }

  paux = strdup(" ");
  mystrcat(&(*obj).codigo, &paux);
  
  mystrcat(&(*obj).codigo, &(*atr).codigo);
  paux = strdup("(");
  mystrcat(&(*obj).codigo,&paux);

  if (args != NULL){
    mystrcat(&(*obj).codigo,&(*args).codigo);
  }

  paux = strdup(")");
  mystrcat(&(*obj).codigo,&paux);
}
}


void mystrcat(char** c1,char** c2){

  //printf("1:%s\n",*c1);
  //printf("2:%s\n",*c2);
  if (n_errores == 0){
    int newSize = strlen(*c1) + strlen(*c2) + 1;

    char* newC = (char*) malloc(newSize);

    strcpy(newC,*c1);
    strcat(newC,*c2);
    free(*c1);
    free(*c2);
    *c1 = newC;
  }
}

void mystrcpy(char** c1,char** c2){

  //printf("0:%s\n",*c2);
  if (n_errores == 0){
    int newSize = strlen(*c2) + 1;

    *c1 = (char*) malloc(newSize);
    strcpy(*c1,*c2);

    free(*c2);
  }
}
