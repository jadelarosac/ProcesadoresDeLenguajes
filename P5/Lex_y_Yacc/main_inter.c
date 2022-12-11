#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n,curr;

int main(){//inicio bloque
{//inicio sentencia salida
printf("%s ","introduce numero :");
}//fin sentencia salida
{//inicio sentencia entrada
scanf("%d ",&n);
}//fin sentencia entrada
{//inicio sentencia asig

curr = 2;
}//fin sentencia asig
{//inicio sentencia if


int tmp0;
tmp0=3*curr;


int tmp1;
tmp1=tmp0==n;
if (!tmp1) goto etiqueta0;
{//inicio if
{//inicio bloque
{//inicio sentencia salida

printf("%s %d ","*",curr);
}//fin sentencia salida
{//inicio sentencia asig


int tmp2;
tmp2=n/curr;

n = tmp2;
}//fin sentencia asig
}//fin bloque
}//fin if
etiqueta0:
}//fin sentencia if
SENTENCIA mientras
{//inicio sentencia salida
printf("%s ","\n");
}//fin sentencia salida
}//fin bloque

