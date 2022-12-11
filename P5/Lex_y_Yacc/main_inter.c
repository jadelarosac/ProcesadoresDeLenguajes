#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n,curr;

int main(){//inicio bloque
{//inicio sentencia salida
printf("%s ","introduce numero :");
}//fin sentencia salida

{//inicio sentencia entrada
scanf("%d",&n);
}//fin sentencia entrada

{//inicio sentencia salida

printf("%d %s ",n,"=");
}//fin sentencia salida

{//inicio sentencia asig

curr = 2;
}//fin sentencia asig

{//inicio sentencia do-until
etiqueta2: ;
{//inicio bloque
int d;
{//inicio sentencia asig


int tmp0;
tmp0=n/curr;

d = tmp0;
}//fin sentencia asig

{//inicio sentencia if


int tmp1;
tmp1=d*curr;


int tmp2;
tmp2=tmp1==n;
if (!tmp2) goto etiqueta1;
{//inicio if
{//inicio bloque
{//inicio sentencia salida

printf("%s %d ","*",curr);
}//fin sentencia salida

{//inicio sentencia asig


int tmp3;
tmp3=n/curr;

n = tmp3;
}//fin sentencia asig

}//fin bloque
}//fin if
goto etiqueta0;
etiqueta1: ;
{//inicio else
{//inicio sentencia asig


int tmp4;
tmp4=curr+1;

curr = tmp4;
}//fin sentencia asig
}//fin else
etiqueta0: ;
}//fin sentencia if

}//fin bloque


int tmp5;
tmp5=curr>n;
if (!tmp5) goto etiqueta2;
}//fin sentencia do-until

{//inicio sentencia salida
printf("%s ","\n");
}//fin sentencia salida

}//fin bloque

