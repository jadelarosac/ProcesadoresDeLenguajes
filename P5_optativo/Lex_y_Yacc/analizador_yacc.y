%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "estructurasTS.h"
void yyerror(char * msg);

int linea_actual = 1;
int nivel_profundidad_funciones_anidadas = 0;
int funciones_anidadas = 0;

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
FILE* dec_fun_c;
FILE* dec_fun_h;


/*                      */
int Ntmp = 0;
int Netiqueta = 0;
int noBloqueMain = 0; // Estamos en el bloque main
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
  char* cod_fun;
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

char* enumAString();
char* enumATipoForm(dtipo t);


void genCodigoOperadorBin(atributos* obj, atributos* at1, atributos* at2, int opdor);
void genCodigoOperadorMix(atributos* obj, atributos* at1, atributos* at2, int opdor);
void genCodigoOperadorUn(atributos* obj, atributos* at1, int opdor);
void genCodigoOperadorUnNeg(atributos* obj, atributos* at1);

void genCodigoAsignacion(atributos*, atributos*, atributos*);
void genCodigoSino(atributos* ,atributos*,atributos*,atributos*);
void genCodigoSi(atributos* ,atributos*,atributos*);
void genCodigoMientras(atributos* obj,atributos* cond,atributos* sent);
void genCodigoHacerHasta(atributos* obj,atributos* cond,atributos* sent);

char* opdorUnAString(int opdor);
char* opdorBinAString(int opdor);

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

Programa                    : Cabecera_programa {empezarGEN();} bloque {
                                                                        fputs($3.codigo,intermain);
                                                                        if(funciones_anidadas > 0)
                                                                        {
                                                                          fputs($3.cod_fun,intermain);
                                                                        }
                                                                        finalizarGEN();}
bloque                      : Inicio_de_bloque {TS_InsertaMARCA();}
                                  Declar_de_variables_locales {
                                                                char** codigo3 = &$3.codigo;
                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo3 = &$3.cod_fun;
                                                                }
                                                                if (noBloqueMain == 0){
                                                                  noBloqueMain = 1;
                                                                  paux = strdup("\n");
                                                                  mystrcat(codigo3,&paux);
                                                                  paux = strdup("int main(){//inicio bloque\n");
                                                                  mystrcat(codigo3,&paux);
                                                                }else{
                                                                  char* tmp = strdup("{//inicio bloque\n");
                                                                  mystrcat(&tmp,codigo3);
                                                                  paux = strdup(tmp);
                                                                  mystrcpy(codigo3,&paux);
                                                                }
                                                                }
                                  Declar_subprogs
                                  Sentencias
                              Fin_de_bloque {
                                                                char** codigo3 = &$3.codigo;
                                                                char** codigo6 = &$6.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo3 = &$3.cod_fun;
                                                                  codigo6 = &$6.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                TS_VaciarENTRADAS();
                                                                mystrcat(codigo3, codigo6);
                                                                paux = strdup("\n}//fin bloque\n");
                                                                mystrcat(codigo3, &paux);
                                                                mystrcpy(codigoS, codigo3 );
                                              }
Declar_subprogs             : Declar_subprogs Declar_subprog
                              |
Declar_subprog              : Cabecera_subprog {subprog = 1; nivel_profundidad_funciones_anidadas++; funciones_anidadas++;}
                                                                 bloque
                                                                {subprog = 0; nivel_profundidad_funciones_anidadas--;}
Declar_de_variables_locales : Marca_ini_declar_variables
                                  Variables_locales
                                  Marca_fin_declar_variables {
                                                                char** codigo2 = &$2.codigo;
                                                                char** codigoS = &$$.codigo;
                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo2 = &$2.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }
                                                                mystrcpy(codigoS, codigo2);
                                                                }
                              |   {
                                                                char** lugar_donde_escribir = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  lugar_donde_escribir = &$$.cod_fun;
                                                                }

                                                                paux = strdup("");
                                                                mystrcpy(lugar_donde_escribir,&paux);
                                  }
Marca_ini_declar_variables  : INIDEC
Marca_fin_declar_variables  : FINDEC
Cabecera_programa           : MAIN
Inicio_de_bloque            : LLAIZQ
Fin_de_bloque               : LLADER
Variables_locales           : Variables_locales Cuerpo_declar_variables {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigo2 = &$2.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigo2 = &$2.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup("\n");
                                                                mystrcat(codigo1, &paux );
                                                                mystrcat(codigo1, codigo2 );
                                                                mystrcpy(codigoS, codigo1 );
                                                                }
                              | Cuerpo_declar_variables {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup(*codigo1);
                                                                mystrcpy(codigoS,&paux);
                                                                }
Cuerpo_declar_variables      : tipo {tipoTmp=atributoAEnum($1.atrib);} lista_declaracion_variables PYC {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigo3 = &$3.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigo3 = &$3.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup(enumAString(tipoTmp));
                                                                mystrcpy(codigo1,&paux);
                                                                paux=strdup(" ");
                                                                mystrcat(codigo1,&paux);
                                                                mystrcat(codigo1,codigo3);
                                                                paux=strdup(";\n");
                                                                mystrcat(codigo1,&paux);
                                                                paux=strdup(*codigo1);
                                                                mystrcpy(codigoS,&paux);}
                              | error
Cabecera_subprog            :   tipo variable PARIZQ argumentos PARDER {tipoTmp=atributoAEnum($1.atrib);TS_InsertaSUBPROG($2);}
                              | tipo variable PARIZQ PARDER {tipoTmp=atributoAEnum($1.atrib);TS_InsertaSUBPROG($2);}
argumentos                  : tipo {tipoTmp=atributoAEnum($1.atrib);} variable {TS_InsertaPARAMF($3);}
                              |   argumentos COMA tipo {tipoTmp=atributoAEnum($3.atrib);} variable {TS_InsertaPARAMF($5);}
                              |   error
variable                    : identificador {
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                $$.lexema = $1.lexema;
                                                                $$.dimensiones=0;
                                                                $$.TamDimen1=0;
                                                                $$.TamDimen2=0;
                                                                paux = strdup($1.lexema);

                                                                mystrcpy(codigoS,&paux);
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

variable_expresion          : identificador  {entradaTS ets = buscarEntrada($1.lexema); $$ = entradaAAtributos(ets);
                            paux = strdup($1.lexema);
                            mystrcpy(&$$.codigo,&paux);}
                              |   elemento_de_array  {$$ = $1;}
elemento_de_array           : identificador CORIZQ expresion CORDER {entradaTS ets = buscarEntrada($1.lexema);
                                                                     ets.dimensiones = 0;
                                                                     $$ = entradaAAtributos(ets);}
                              |   identificador CORIZQ expresion
                              COMA expresion CORDER {entradaTS ets = buscarEntrada($1.lexema);
                                                     ets.dimensiones = 0;
                                                     $$ = entradaAAtributos(ets);}
Sentencias                  : Sentencias Sentencia {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigo2 = &$2.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigo2 = &$2.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                mystrcpy(codigoS,codigo1);
                                                                paux=strdup("\n");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo2);
                                                                }
                              |   Sentencia {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                mystrcpy(codigoS, codigo1);
                                                                }
Sentencia                   : bloque {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                mystrcpy(codigoS,codigo1);
                                                                }
                              |   sentencia_asignacion {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia asig\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS, codigo1);
                                                                paux = strdup("}//fin sentencia asig\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
                              |   sentencia_si  {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia if\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux=strdup("}//finsentenciaif\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
                              |   sentencia_mientras {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia while\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux=strdup("}//finsentenciawhile\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
                              |   sentencia_hacer_hasta{
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux=strdup("{//iniciosentenciado-until\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux=strdup("}//finsentenciado-until\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
                              |   sentencia_entrada {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia entrada\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux = strdup("}//fin sentencia entrada\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
                              |   sentencia_salida {
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup("{//inicio sentencia salida\n");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux=strdup("}//finsentenciasalida\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
                              |   sentencia_retornar {
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup("SENTENCIA RETORNAR");
                                                                mystrcpy(codigoS,&paux);
                                                                }
sentencia_asignacion        : variable_expresion ASIG expresion PYC {procesaSentenciaAsignacion($1,$3);genCodigoAsignacion(&$$,&$1,&$3);}
                              |   error
sentencia_si                : SI PARIZQ expresion PARDER Sentencia {procesaSentenciaControl($3);
                            genCodigoSi(&$$,&$3,&$5);}
                              |   SI PARIZQ expresion PARDER Sentencia
                              SINO Sentencia {procesaSentenciaControl($3);genCodigoSino(&$$,&$3,&$5,&$7);}
sentencia_mientras          : MIENTRAS PARIZQ expresion PARDER Sentencia {procesaSentenciaControl($3);
                            genCodigoMientras(&$$,&$3,&$5);}
sentencia_hacer_hasta       : HACER Sentencia HASTA PARIZQ expresion PARDER PYC {procesaSentenciaControl($5);genCodigoHacerHasta(&$$,&$5,&$2);}
sentencia_entrada           : ENTRADA lista_variables PYC {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo2 = &$2.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo2 = &$2.cod_fun;
                                                                }

                                                                paux = strdup("scanf(\"");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,&textoScanf);
                                                                paux=strdup("\",");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo2);
                                                                paux=strdup(");\n");
                                                                mystrcat(codigoS,&paux);
                                                                //Se resetea la variable global
                                                                textoScanf=NULL;
                            }
sentencia_salida            : SALIDA lista_expresiones_cadena PYC {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo2 = &$2.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo2 = &$2.cod_fun;
                                                                }

                                                                mystrcpy(codigoS,codigo2);
                                                                paux=strdup("printf(\"");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,&textoPrintf);
                                                                paux=strdup("\",");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,&$2.nombreTmp);
                                                                paux=strdup(");\n");
                                                                mystrcat(codigoS,&paux);
                                                                //Se resetea la variable global
                                                                textoPrintf=NULL;
}
sentencia_retornar          : DEVOLVER expresion PYC {procesaSentenciaRetornar($2);}
lista_expresiones_cadena    : lista_expresiones_cadena COMA expresion_cadena {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigo3 = &$3.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigo3 = &$3.cod_fun;
                                                                }

                                                                mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                                                                paux=strdup(",");
                                                                mystrcat(&$$.nombreTmp,&paux);
                                                                mystrcat(&$$.nombreTmp,&$3.nombreTmp);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux=strdup("\n");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo3);
                                                                }
                              |   expresion_cadena {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                }

                                                                mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                                                                mystrcpy(codigoS,codigo1);
                                                                }
expresion_cadena            : expresion {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                }

                                                                mystrcpy(&$$.nombreTmp,&$1.nombreTmp);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux=strdup(enumATipoForm($1.tipo));
                                                                if(textoPrintf==NULL)mystrcpy(&textoPrintf,&paux);
                                                                else mystrcat(&textoPrintf,&paux);
                                                                paux=strdup(" ");
                                                                mystrcat(&textoPrintf,&paux);
                                                                }
                            | cadena {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                }

                                                                mystrcpy(&$$.nombreTmp,codigo1);
                                                                paux = strdup("");
                                                                mystrcpy(codigoS,&paux);
                                                                paux = strdup("%s ");
                                                                if (textoPrintf == NULL) mystrcpy(&textoPrintf, &paux);
                                                                else mystrcat(&textoPrintf,&paux);
                                                                }
lista_variables             : variable {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                }

                                                                entradaTS ets = buscarEntrada($1.lexema);
                                                                $1.tipo = ets.tipoDato;
                                                                paux = strdup("&");
                                                                mystrcpy(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);

                                                                if (textoScanf == NULL){
                                                                  paux = strdup(enumATipoForm($1.tipo));
                                                                  mystrcpy(&textoScanf, &paux);
                                                                }
                                                                else {
                                                                  paux = strdup(enumATipoForm($1.tipo));
                                                                  mystrcat(&textoScanf,&paux);
                                                                }
                                                                }
                              |   lista_variables COMA variable {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigo3 = &$3.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigo3 = &$3.cod_fun;
                                                                }

                                                                mystrcpy(codigoS,codigo1);
                                                                paux=strdup(",&");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo3);
                                                                entradaTS ets=buscarEntrada($3.lexema);
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
lista_declaracion_variables :  variable {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                }

                                                                TS_InsertaIDENT($1);
                                                                paux = strdup(*codigo1);
                                                                mystrcpy(codigoS,&paux);
                                                                }
                              |   lista_declaracion_variables COMA variable {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigo3 = &$3.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigo3 = &$3.cod_fun;
                                                                }

                                                                TS_InsertaIDENT($3);
                                                                paux = strdup(",");
                                                                mystrcat(codigo1,&paux);
                                                                mystrcat(codigo1,codigo3);
                                                                paux = strdup($1.codigo);
                                                                mystrcpy(codigoS,&paux);
                                                                }
                              |   error
lista_expresiones           : expresion {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                }

                                                                PILARG_insertaARG($1);
                                                                mystrcpy(codigoS,codigo1);
                                                                }
                              |   lista_expresiones COMA expresion {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigo3 = &$3.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigo3 = &$3.cod_fun;
                                                                }

                                                                PILARG_insertaARG($3);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux = strdup(",");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo3);
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
                              |   variable_expresion {
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                $$ = $1;
                                                                mystrcpy(&$$.nombreTmp,&$1.lexema);
                                                                paux = strdup("");
                                                                mystrcpy(codigoS,&paux);
                              }
                              |   constante {
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                $$ = $1;
                                                                mystrcpy(&$$.nombreTmp,&$1.lexema);
                                                                paux = strdup("");
                                                                mystrcpy(codigoS,&paux);
                                                                }
                              |   funcion {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                }

                                                                $$ = $1;
                                                                paux = temporal();
                                                                mystrcpy(&$$.nombreTmp,&paux);
                                                                paux = strdup(enumAString($$.tipo));
                                                                mystrcpy(codigoS,&paux);
                                                                paux = strdup(" ");
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup($$.nombreTmp);
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup(";\n");
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup($$.nombreTmp);
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup("=");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo1);
                                                                paux = strdup(";\n");
                                                                mystrcat(codigoS,&paux);
                                                                }
                              |   error
funcion                     : identificador PARIZQ PARDER {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                }

                                                                entradaTS ets = buscarEntrada($1.lexema);
                                                                procesaLlamadaFuncionSinArgumentos(ets);
                                                                $$ = entradaAAtributos(ets);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux = strdup("(");
                                                                mystrcat(codigoS,&paux);
                                                                paux = strdup(")");
                                                                mystrcat(codigoS,&paux);
                                                                }
                              |   identificador PARIZQ {PILARG_insertaMARCA();} lista_expresiones PARDER
                              {
                                                                char** codigoS = &$$.codigo;
                                                                char** codigo1 = &$1.codigo;
                                                                char** codigo4 = &$4.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                  codigo1 = &$1.cod_fun;
                                                                  codigo4 = &$4.cod_fun;
                                                                }

                                                                entradaTS ets = buscarEntrada($1.lexema);
                                                                procesaLlamadaFuncionConArgumentos(ets);
                                                                $$ = entradaAAtributos(ets);
                                                                mystrcpy(codigoS,codigo1);
                                                                paux = strdup("(");
                                                                mystrcat(codigoS,&paux);
                                                                mystrcat(codigoS,codigo4);
                                                                paux = strdup(")");
                                                                mystrcat(codigoS,&paux);
                                                                }
tipo                        : TIPOEL {$$.atrib = $1.atrib;}
cadena                      : CADENA {
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup($1.lexema);
                                                                mystrcpy(codigoS,&paux);
                                                                }
identificador               : IDEN  {
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                paux = strdup($1.lexema);
                                                                mystrcpy(codigoS,&paux);
                                                                }
constante                   : CONST {
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                $$.tipo = atributoAEnum($1.atrib+1);
                                                                paux = strdup($1.lexema);
                                                                mystrcpy(codigoS,&paux);
                                                                }
                              | CONSTENT  {
                                                                char** codigoS = &$$.codigo;

                                                                if (nivel_profundidad_funciones_anidadas != 0)
                                                                {
                                                                  codigoS = &$$.cod_fun;
                                                                }

                                                                $$.tipo = entero;
                                                                paux = strdup($1.lexema);
                                                                mystrcpy(codigoS,&paux);
                                                                }
                              |   CORIZQ ini_elementos_array CORDER { $$.tipo = $2.tipo;
                                                                    if ($2.TamDimen2==1){$$.TamDimen2 = 0; $$.TamDimen1 = $2.TamDimen1; $$.dimensiones = 1;}
                                                                    else{$$.TamDimen2 = $2.TamDimen2; $$.TamDimen1 = $2.TamDimen1; $$.dimensiones = 2;}}
ini_elementos_array         : ini_elementos_array PYC lista_expresiones_array {$$.TamDimen2 = $1.TamDimen2 + 1;

                                                                              if ($1.tipo != $3.tipo){
                                                                                printf("[Linea %d]",linea_actual);
                                                                                printf("ERROR SEMÁNTICO: Matriz con distintos tipos en distintas columnas.\n");
                                                                              }
                                                                              if ($1.TamDimen1 != $3.TamDimen1){
                                                                                printf("[Linea %d]",linea_actual);
                                                                                printf("ERROR SEMÁNTICO: La matriz tiene distinto número de filas en distintas columnas.\n");
                                                                              }else{
                                                                                $$.TamDimen1 = $1.TamDimen1;
                                                                              }}
                              |   lista_expresiones_array {$$.TamDimen2 = 1;$$.TamDimen1 = $1.TamDimen1;$$.tipo = $1.tipo;}

lista_expresiones_array       : expresion {$$.TamDimen1 = 1; $$.tipo = $1.tipo;}
                              |   lista_expresiones_array COMA expresion {$$.TamDimen1 = $1.TamDimen1 + 1;
                                                                          if ($1.tipo != $3.tipo){
                                                                                printf("[Linea %d]",linea_actual);
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
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: Doble declaración de la variable '%s'\n",ets.nombre);
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
    if (strcmp(TS_aux[tope_aux].nombre,ets.nombre) == 0) {
      printf("[Linea %d]",linea_actual);
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
    printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: se utiliza un identificador no declarado: '%s'\n", nombre);
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

  // Caso == y !=
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
          printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d es de tipo distinto al esperado.\n",ets.nombre,n_params+1);
        }
        if (TS[i].dimensiones != PILA_ARG[indice_args].dimensiones){
          printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimensiones distintas a las esperadas.\n",ets.nombre,n_params+1);
        }else{
          if (TS[i].dimensiones == 1){
            if (TS[i].TamDimen1 != PILA_ARG[indice_args].TamDimen1){
              printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimension 1 distinta al esperado.\n",ets.nombre,n_params+1);
            }
          }

          if (TS[i].dimensiones == 2){
            if (TS[i].TamDimen1 != PILA_ARG[indice_args].TamDimen1){
              printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimension 1 distinta al esperado.\n",ets.nombre,n_params+1);
            }

            if (TS[i].TamDimen2 != PILA_ARG[indice_args].TamDimen2){
              printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Argumento de la llamada a %s numero %d tiene dimension 2 distinta al esperado.\n",ets.nombre,n_params+1);
            }
          }

        }

        i = i + 1;
        indice_args = indice_args + 1;
        n_params = n_params + 1;
      }
      if (indice_args != TOPE_ARG){
          printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Se han pasado más argumentos de los esperados a la funcion %s.\n",ets.nombre);
      }
      if (ets.parametros > n_params){
          printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Se han pasado menos argumentos de los esperados a la funcion %s.\n",ets.nombre);
      }
    }
  }

  TOPE_ARG = indice_borrado;
}

void procesaLlamadaFuncionSinArgumentos(entradaTS ets){
  if (ets.parametros > 0){
      printf("[Linea %d]",linea_actual); printf("ERROR SEMÁNTICO: Se han pasado 0 argmuentos a la funcion %s, se esperan más.\n",ets.nombre);
  }
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

void procesaSentenciaRetornar(atributos ret){

  int i = TOPE-1;

  while (i>=1){
    if (TS[i].entrada == marca && (TS[i-1].entrada == parametro_formal || TS[i-1].entrada == funcion)) break;
    i--;
  }

  if (i == 0){
      printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: No se deben retornar valores en el programa principal.\n");
  }else{
     while (i>=0){
       if (TS[i].entrada == funcion) break;
        i--;
     }
     if (i == 0){
       printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: no se encontró la función del devolver en el analisis semántico\n");
       return;
     }
     if (TS[i].tipoDato != ret.tipo){
       printf("[Linea %d]",linea_actual);   printf("ERROR SEMÁNTICO: El valor retornado no se corresponde con el que devuelve la función.\n");
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





/* GENERACIÓN DE CÓDIGO */



void empezarGEN(){

  intermain = fopen("main_inter.c","w");
  dec_fun_c = fopen("dec_fun.c","w");
  dec_fun_h = fopen("dec_fun.h","w");

  fputs("#include <stdio.h>\n",intermain);
  fputs("#include <stdlib.h>\n",intermain);
  fputs("#include <stdbool.h>\n",intermain);
  fputs("#include \"dec_fun.h\"\n",intermain);

  fputs("#include \"dec_fun.h\"\n",dec_fun_c);

  fputs("#ifndef DEC_FUN_H\n#define DEC_FUN_H\n",dec_fun_h);
}


void finalizarGEN(){
  fputs("#endif\n",dec_fun_h);

  fputs("\n",intermain);
  fputs("\n",dec_fun_c);
  fputs("\n",dec_fun_h);

  fclose(intermain);
  fclose(dec_fun_c);
  fclose(dec_fun_h);
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



void genCodigoOperadorMix(atributos* obj, atributos* at1, atributos* at2, int opdor){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;
  char** at2_codigo = &(*at2).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
    at2_codigo = &(*at2).cod_fun;
  }

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(obj_codigo,at1_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,at2_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  paux = enumAString((*obj).tipo);
  mystrcat(obj_codigo,&paux);
  paux = strdup(" ");
  mystrcat(obj_codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(obj_codigo,&paux);
  paux = strdup("=");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at1).nombreTmp);
  paux = strdup(opdorUnAString(opdor));
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at2).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}

void genCodigoOperadorBin(atributos* obj, atributos* at1, atributos* at2, int opdor){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;
  char** at2_codigo = &(*at2).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
    at2_codigo = &(*at2).cod_fun;
  }

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(obj_codigo,at1_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,at2_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  paux = enumAString((*obj).tipo);
  mystrcat(obj_codigo,&paux);
  paux = strdup(" ");
  mystrcat(obj_codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
  paux = strdup((*obj).nombreTmp);
  mystrcat(obj_codigo,&paux);
  paux = strdup("=");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at1).nombreTmp);
  paux = strdup(opdorBinAString(opdor));
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at2).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}

void genCodigoOperadorUn(atributos* obj, atributos* at1, int opdor){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
  }

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(obj_codigo,at1_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  paux = (*obj).nombreTmp;
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
  paux = (*obj).nombreTmp;
  mystrcat(obj_codigo,&paux);
  paux = strdup("=");
  mystrcat(obj_codigo,&paux);
  paux = strdup(opdorBinAString(opdor));
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at1).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}

void genCodigoOperadorUnNeg(atributos* obj, atributos* at1){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
  }

  paux = temporal();
  mystrcpy(&(*obj).nombreTmp,&paux);
  mystrcpy(obj_codigo,at1_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  paux = strdup(" ");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*obj).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*obj).nombreTmp);
  paux = strdup("=");
  mystrcat(obj_codigo,&paux);
  paux = strdup("!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at1).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}

void genCodigoAsignacion(atributos* obj, atributos* at1, atributos* at2){

  char** obj_codigo = &(*obj).codigo;
  char** at1_codigo = &(*at1).codigo;
  char** at2_codigo = &(*at2).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    at1_codigo = &(*at1).cod_fun;
    at2_codigo = &(*at2).cod_fun;
  }

  mystrcpy(obj_codigo,at2_codigo);
  paux = strdup("\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,at1_codigo);
  paux = strdup(" = ");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*at2).nombreTmp);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);
}


char* enumATipoForm(dtipo t){

  if (t == entero)return strdup("%d");
  if (t == booleano)return strdup("%d");
  if (t == real)return strdup("%f");
  if (t == caracter)return strdup("%c");

  return strdup("Ninguno");
}

void genCodigoSi(atributos* obj,atributos* cond,atributos* sent){

  char** obj_codigo = &(*obj).codigo;
  char** cond_codigo = &(*cond).codigo;
  char** sent_codigo = &(*sent).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    cond_codigo = &(*cond).cod_fun;
    sent_codigo = &(*sent).cod_fun;
  }

  char* etfin = etiqueta();

  mystrcpy(obj_codigo,cond_codigo);
  paux=strdup("if (!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(obj_codigo,&paux);
  paux=strdup(etfin);
  mystrcat(obj_codigo,&paux);
  paux=strdup(";\n{//inicio if\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,sent_codigo);
  paux=strdup("}//fin if\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&etfin);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);
}


void genCodigoSino(atributos* obj,atributos* cond, atributos* sent, atributos* sent2){

  char** obj_codigo = &(*obj).codigo;
  char** cond_codigo = &(*cond).codigo;
  char** sent_codigo = &(*sent).codigo;
  char** sent2_codigo = &(*sent2).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    cond_codigo = &(*cond).cod_fun;
    sent_codigo = &(*sent).cod_fun;
    sent2_codigo = &(*sent2).cod_fun;
  }

  char* etfin = etiqueta();
  char* etelse = etiqueta();

  mystrcpy(obj_codigo,cond_codigo);
  paux=strdup("if (!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(obj_codigo,&paux);
  paux=strdup(etelse);
  mystrcat(obj_codigo,&paux);
  paux=strdup(";\n{//inicio if\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,sent_codigo);
  paux=strdup("}//fin if\n");
  mystrcat(obj_codigo,&paux);
  paux = strdup("goto ");
  mystrcat(obj_codigo,&paux);
  paux = strdup(etfin);
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);

  mystrcat(obj_codigo,&etelse);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);


  paux=strdup("{//inicio else\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,sent2_codigo);
  paux=strdup("}//fin else\n");
  mystrcat(obj_codigo,&paux);



  mystrcat(obj_codigo,&etfin);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);

}



void genCodigoMientras(atributos* obj,atributos* cond,atributos* sent){

  char** obj_codigo = &(*obj).codigo;
  char** cond_codigo = &(*cond).codigo;
  char** sent_codigo = &(*sent).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    cond_codigo = &(*cond).cod_fun;
    sent_codigo = &(*sent).cod_fun;
  }


  char* etini = etiqueta();
  char* etfin = etiqueta();


  paux = strdup(etini);
  mystrcpy(obj_codigo,&paux);
  paux=strdup(": ;\n");
  mystrcat(obj_codigo,&paux);

  mystrcat(obj_codigo,cond_codigo);
  paux=strdup("if (!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(obj_codigo,&paux);
  paux=strdup(etfin);
  mystrcat(obj_codigo,&paux);
  paux=strdup(";\n");
  mystrcat(obj_codigo,&paux);

  mystrcat(obj_codigo, sent_codigo);

  paux = strdup("\ngoto ");
  mystrcat(obj_codigo,&paux);
  paux = strdup(etini);
  mystrcat(obj_codigo,&paux);
  paux = strdup(";\n");
  mystrcat(obj_codigo,&paux);


  paux = strdup(etfin);
  mystrcat(obj_codigo,&paux);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);
}


void genCodigoHacerHasta(atributos* obj,atributos* cond,atributos* sent){

  char** obj_codigo = &(*obj).codigo;
  char** cond_codigo = &(*cond).codigo;
  char** sent_codigo = &(*sent).codigo;

  if( nivel_profundidad_funciones_anidadas != 0)
  {
    obj_codigo = &(*obj).cod_fun;
    cond_codigo = &(*cond).cod_fun;
    sent_codigo = &(*sent).cod_fun;
  }

  char* etini = etiqueta();

  paux = strdup(etini);
  mystrcpy(obj_codigo,&paux);
  paux = strdup(": ;\n");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,sent_codigo);


  mystrcat(obj_codigo,cond_codigo);

  paux=strdup("if (!");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&(*cond).nombreTmp);
  paux=strdup(") goto ");
  mystrcat(obj_codigo,&paux);
  mystrcat(obj_codigo,&etini);
  paux=strdup(";\n");
  mystrcat(obj_codigo,&paux);

}



void mystrcat(char** c1,char** c2){

  //printf("1:%s\n",*c1);
  //printf("2:%s\n",*c2);

  int newSize = strlen(*c1) + strlen(*c2) + 1;

  char* newC = (char*) malloc(newSize);

  strcpy(newC,*c1);
  strcat(newC,*c2);
  free(*c1);
  free(*c2);
  *c1 = newC;
}

void mystrcpy(char** c1,char** c2){

  //printf("0:%s\n",*c2);
  int newSize = strlen(*c2) + 1;

  *c1 = (char*) malloc(newSize);
  strcpy(*c1,*c2);

  free(*c2);

}
