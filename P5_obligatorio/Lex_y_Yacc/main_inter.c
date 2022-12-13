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
etiqueta4: ;


int tmp3;
tmp3=curr<=n;
if (!tmp3) goto etiqueta5;
{//inicio bloque
{//inicio sentencia if
int tmp4;
tmp4=es_divisible(,);
if (!tmp4) goto etiqueta3;
{//inicio if
{//inicio bloque
{//inicio sentencia salida

printf("%s %d ","*",curr);
}//fin sentencia salida

{//inicio sentencia asig


int tmp5;
tmp5=n/curr;

n = tmp5;
}//fin sentencia asig

}//fin bloque
}//fin if
goto etiqueta2;
etiqueta3: ;
{//inicio else
{//inicio sentencia asig


int tmp6;
tmp6=curr+1;

curr = tmp6;
}//fin sentencia asig
}//fin else
etiqueta2: ;
}//fin sentencia if

}//fin bloque

goto etiqueta4;
etiqueta5: ;
}//fin sentencia while

{//inicio sentencia salida
printf("%s ","\n");
}//fin sentencia salida

}//fin bloque

