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

printf("%d %s ",n,"==");
}//fin sentencia salida

{//inicio sentencia asig

curr = 2;
}//fin sentencia asig

{//inicio sentencia while
etiqueta2: ;


int tmp0;
tmp0=curr<=n;
if (!tmp0) goto etiqueta3;
{//inicio bloque
int d;
{//inicio sentencia asig


int tmp1;
tmp1=n/curr;

d = tmp1;
}//fin sentencia asig

{//inicio sentencia if


int tmp2;
tmp2=d*curr;


int tmp3;
tmp3=tmp2==n;
if (!tmp3) goto etiqueta1;
{//inicio if
{//inicio bloque
{//inicio sentencia salida

printf("%s %d ","*",curr);
}//fin sentencia salida

{//inicio sentencia asig


int tmp4;
tmp4=n/curr;

n = tmp4;
}//fin sentencia asig

}//fin bloque
}//fin if
goto etiqueta0;
etiqueta1: ;
{//inicio else
{//inicio sentencia asig


int tmp5;
tmp5=curr+1;

curr = tmp5;
}//fin sentencia asig
}//fin else
etiqueta0: ;
}//fin sentencia if

}//fin bloque

goto etiqueta2;
etiqueta3: ;
}//fin sentencia while

{//inicio sentencia salida
printf("%s ","\n");
}//fin sentencia salida

}//fin bloque

