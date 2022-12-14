#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FuncionesArrays/dec_dat.h"
double vec[5];

int mat[2][3];

#include "dec_fun.c"

int main(){//inicio bloque
{//inicio sentencia asig

vec = vec;
}//fin sentencia asig

{//inicio sentencia asig

mat = mat;
}//fin sentencia asig

{//inicio sentencia salida
printf("%s ","Hola, mundo");
}//fin sentencia salida

}//fin bloque

