#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "FuncionesArrays/dec_dat.h"
int m[2][2],d[2][2],pi[2][2],pd[2][2];

int r1[2][2],r2[2][2];

int i,j,n;

int diff[2][2];

#include "dec_fun.c"

int main(){//inicio bloque
{//inicio sentencia asig

int tmp0;
tmp0=-10;



int tmp1;
tmp1=-36;


int tmp2[2][2]={{tmp0, 3},{tmp1, 11}};

memcpy(m,tmp2,16);
}//fin sentencia asig

{//inicio sentencia asig

int tmp3;
tmp3=-1;




int tmp4[2][2]={{tmp3, 0},{0, 2}};

memcpy(d,tmp4,16);
}//fin sentencia asig

{//inicio sentencia asig


int tmp5;
tmp5=-1;


int tmp6;
tmp6=-3;


int tmp7[2][2]={{4, tmp5},{tmp6, 1}};

memcpy(pd,tmp7,16);
}//fin sentencia asig

{//inicio sentencia asig




int tmp8[2][2]={{1, 1},{3, 4}};

memcpy(pi,tmp8,16);
}//fin sentencia asig

{//inicio sentencia salida
printf("%s ","introduce numero :");
}//fin sentencia salida

{//inicio sentencia entrada
scanf("%d",&n);
}//fin sentencia entrada

{//inicio sentencia asig


memcpy(r1,m,16);
}//fin sentencia asig

{//inicio sentencia asig


memcpy(r2,d,16);
}//fin sentencia asig

{//inicio sentencia while
etiqueta0: ;


int tmp9;
tmp9=n>1;
if (!tmp9) goto etiqueta1;
{//inicio bloque
{//inicio sentencia asig


int tmp10[2][2];
int_producto_mat_array(tmp10, r1, m, 2, 2, 2);


memcpy(r1,tmp10,16);
}//fin sentencia asig

{//inicio sentencia asig


int tmp11[2][2];
int_producto_mat_array(tmp11, r2, d, 2, 2, 2);


memcpy(r2,tmp11,16);
}//fin sentencia asig

{//inicio sentencia asig


int tmp12;
tmp12=n-1;


n = tmp12;
}//fin sentencia asig

{//inicio sentencia salida

printf("%d %s ",n,"\n");
}//fin sentencia salida

}//fin bloque

goto etiqueta0;
etiqueta1: ;
}//fin sentencia while

{//inicio sentencia asig


int tmp13[2][2];
int_producto_mat_array(tmp13, pi, r2, 2, 2, 2);


int tmp14[2][2];
int_producto_mat_array(tmp14, tmp13, pd, 2, 2, 2);


memcpy(r2,tmp14,16);
}//fin sentencia asig

{//inicio sentencia asig


int tmp15[2][2];
int_diferencia_array(tmp15, r2, r1, 2, 2);


memcpy(diff,tmp15,16);
}//fin sentencia asig

{//inicio sentencia salida









printf("%s %d %d %d %d %s ","Las diferencias en cada componente son :",diff[0][0],diff[0][1],diff[1][0],diff[1][1],"\n");
}//fin sentencia salida

}//fin bloque

