#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FuncionesArrays/dec_dat.h"
double vec[30];

int mat[3][2];

#include "dec_fun.c"

int main(){//inicio bloque
{//inicio sentencia asig

vec[4] = 7.0;
}//fin sentencia asig

{//inicio sentencia asig

mat[2][1] = 1;
}//fin sentencia asig

{//inicio sentencia salida
printf("%s ","Hola, mundo");
}//fin sentencia salida

}//fin bloque

