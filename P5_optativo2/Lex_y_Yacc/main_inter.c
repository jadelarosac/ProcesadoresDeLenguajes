#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FuncionesArrays/dec_dat.h"
double vec[5];

int mat[2][3];

#include "dec_fun.c"

int main(){//inicio bloque

{//inicio sentencia asig



double tmp0;
tmp0=2.03/3.0;



double tmp1;
tmp1=5.12-8.3;

double tmp2;
tmp2=tmp0*tmp1;



double tmp3;
tmp3=3.1415+5.0;




vec = {5.1, tmp2, tmp3, 0.01, 1.0};
}//fin sentencia asig

{//inicio sentencia asig







mat = {{1, 0},{1, 0},{1, 0}};
}//fin sentencia asig

{//inicio sentencia asig



int tmp8;
tmp8=5*3;


int tmp9;
tmp9=tmp8-13;




int tmp4;
tmp4=3*3;



int tmp5;
tmp5=2*2;


int tmp6;
tmp6=tmp5*2;

int tmp7;
tmp7=tmp4-tmp6;

mat[1][tmp7] = mat[1][tmp9];
}//fin sentencia asig

}//fin bloque

