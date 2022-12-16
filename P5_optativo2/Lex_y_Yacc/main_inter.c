#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "FuncionesArrays/dec_dat.h"
int n_ent,lista_ent[10];

#include "dec_fun.c"

int main(){//inicio bloque

{//inicio sentencia salida
printf("%s ","Introduzca la entrada---->: ");
}//fin sentencia salida

{//inicio sentencia entrada
scanf("%d",&n_ent);
}//fin sentencia entrada

{//inicio sentencia if


int tmp20;
tmp20=n_ent<=10;



int tmp21;
tmp21=n_ent>=1;

int tmp22;
tmp22=tmp20&&tmp21;
if (!tmp22) goto etiqueta12;
{//inicio if
{//inicio bloque
{//inicio sentencia asig


int tmp23[10];
memcpy(tmp23,finbonnaci(n_ent),40);


memcpy(lista_ent,tmp23,40);
}//fin sentencia asig

}//fin bloque
}//fin if
goto etiqueta11;
etiqueta12: ;
{//inicio else
{//inicio bloque
{//inicio sentencia salida
printf("%s ","EL número intrdoducido debe estar entre 1 y 10\n");
}//fin sentencia salida

}//fin bloque
}//fin else
etiqueta11: ;
}//fin sentencia if

}//fin bloque

