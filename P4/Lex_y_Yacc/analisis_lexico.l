%{
  #define MAXLONGBUFFER 200
  char buffer[MAXLONGBUFFER];
%}

%option yylineno
%option noyywrap


%%

"entero" {yylval.atrib = 0;return(TIPOEL);}
"real" {yylval.atrib = 1;return(TIPOEL);}
"caracter" {yylval.atrib = 2;return(TIPOEL);}
"booleano" {yylval.atrib = 3;return(TIPOEL);}
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
"+" {yylval.atrib = 0;return(OPSUMA);}      //OPMIX
"-" {yylval.atrib = 1;return(OPRESTA);}     //OPMIX
"!" {return(OPNEG);}                       //OPUN
"*" {yylval.atrib = 0;return(OPMULT);}      //OPBIN
"/" {yylval.atrib = 1;return(OPDIV);}       //OPBIN
"**" {yylval.atrib = 2;return(OPMULTM);}    //OPBIN
"&&" {yylval.atrib = 3;return(OPAND);}      //OPBIN
"||" {yylval.atrib = 4;return(OPOR);}       //OPBIN
"==" {yylval.atrib = 5;return(OPEQ);}       //OPBIN
"!=" {yylval.atrib = 6;return(OPNEQ);}      //OPBIN
"<=" {yylval.atrib = 7;return(OPLEQ);}      //OPBIN
">=" {yylval.atrib = 8;return(OPGEQ);}      //OPBIN
"<" {yylval.atrib = 9;return(OPLESS);}      //OPBIN
">" {yylval.atrib = 10;return(OPGR);}       //OPBIN
"%" {yylval.atrib = 11;return(OPMOD);}      //OPBIN
\"[^\"]+\" {return(CADENA);}
([a-z]|[A-Z]|"_")([a-z]|[A-Z]|"_"|[0-9])* { yylval.lexema = strdup(yytext);
                                           return(IDEN);}
[0-9]+ {return(CONSTENT);}
[0-9]+\.[0-9]+ {yylval.atrib = 0;return(CONST);}
\'[^\']\' {yylval.atrib = 1;return(CONST);}
("cierto"|"falso") {yylval.atrib = 2;return(CONST);}
\n {linea_actual++;}
[[:space:]] {}
. {snprintf(buffer, MAXLONGBUFFER, "lexical error: el o los caracteres '%s' no forman ningún token conocido", yytext);
  yyerror(buffer);}
