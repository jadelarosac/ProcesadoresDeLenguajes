%{
  #define MAXLONGBUFFER 200
  char buffer[MAXLONGBUFFER];
%}

%option yylineno
%option noyywrap


%%

"real" {return(TIPOEL);}
"booleano" {return(TIPOEL);}
"caracter" {return(TIPOEL);}
"entero" {return(TIPOEL);}
"programa_principal("[[:space:]]*")" {return(MAIN);}
"retornar" {return(DEVOLVER);}
"leer" {return(ENTRADA);}
"escribir" {return(SALIDA);}
"fin"[ \t]+"declarar" {return(FINDEC );}
"declarar" {return(INIDEC);}
"hasta"[ \t]+"que" {return(HASTA);}
"hacer" {return(HACER);}
"mientras" {return(MIENTRAS);}
"si"[ \t]+"no" {return(SINO);}
"si" {return(SI);}
"," {return(COMA);}
";" {return(PYC);}
"}" {return(LLADER);}
"{" {return(LLAIZQ);}
")" {return(PARDER);}
"(" {return(PARIZQ);}
"]" {return(CORDER);}
"[" {return(CORIZQ);}
"=" {return(ASIG);}
"+" {return(OPMIX);}
"-" {return(OPMIX);}
"!" {return(OPUN);}
"*" {return(OPBIN);}
"/" {return(OPBIN);}
"**" {return(OPBIN);}
"&&" {return(OPBIN);}
"||" {return(OPBIN);}
"==" {return(OPBIN);}
"!=" {return(OPBIN);}
"<=" {return(OPBIN);}
">=" {return(OPBIN);}
"<" {return(OPBIN);}
">" {return(OPBIN);}
"%" {return(OPBIN);}
\"[^\"]+\" {return(CADENA);}
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|"_"|[0-9])* {return(IDEN);}
(\'[^\']\'|[0-9]+|[0-9+]\.[0-9]+|"cierto"|"falso") {return(CONST);}
\n {linea_actual++;}
[[:space:]] {}
. {snprintf(buffer, MAXLONGBUFFER, "el o los caracteres '%s' no forman ningún token conocido", yytext);
  yyerror(buffer);}


