#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FuncionesArrays/dec_dat.h"
int n;

#include "dec_fun.c"

int main(){//inicio bloque

{//inicio sentencia salida
printf("%s ","introduce numero :");
}//fin sentencia salida

{//inicio sentencia entrada
scanf("%d",&n);
}//fin sentencia entrada

{//inicio sentencia salida




int tmp4;
tmp4=fact(n);
printf("%d %s %d ",n,"!==",tmp4);
}//fin sentencia salida

{//inicio sentencia salida
printf("%s ","\n");
}//fin sentencia salida

}//fin bloque

