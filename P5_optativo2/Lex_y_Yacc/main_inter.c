#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n;

#include "dec_fun.c"

int main(){//inicio bloque

{//inicio sentencia salida
printf("%s ","introduce numero :");
}//fin sentencia salida

{//inicio sentencia entrada
scanf("%d",&n);
}//fin sentencia entrada

{//inicio sentencia if


int tmp4;
tmp4=n>0;
if (!tmp4) goto etiqueta3;
{//inicio if
{//inicio bloque
{//inicio sentencia salida




int tmp5;
tmp5=fact(n);
printf("%d %s %d ",n,"!==",tmp5);
}//fin sentencia salida

}//fin bloque
}//fin if
goto etiqueta2;
etiqueta3: ;
{//inicio else
{//inicio bloque
{//inicio sentencia salida
printf("%s ","Debes poner un número positivo");
}//fin sentencia salida

}//fin bloque
}//fin else
etiqueta2: ;
}//fin sentencia if

{//inicio sentencia salida
printf("%s ","\n");
}//fin sentencia salida

}//fin bloque

