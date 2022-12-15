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

int tmp11;
tmp11=-10;



int tmp12;
tmp12=-36;


int tmp13[2][2]={{tmp11, 3},{tmp12, 11}};

memcpy(m,tmp13,16);
}//fin sentencia asig

{//inicio sentencia asig

int tmp14;
tmp14=-1;




int tmp15[2][2]={{tmp14, 0},{0, 2}};

memcpy(d,tmp15,16);
}//fin sentencia asig

{//inicio sentencia asig


int tmp16;
tmp16=-1;


int tmp17;
tmp17=-3;


int tmp18[2][2]={{4, tmp16},{tmp17, 1}};

memcpy(pd,tmp18,16);
}//fin sentencia asig

{//inicio sentencia asig




int tmp19[2][2]={{1, 1},{3, 4}};

memcpy(pi,tmp19,16);
}//fin sentencia asig

{//inicio sentencia salida
printf("%s ","introduce numero :");
}//fin sentencia salida

{//inicio sentencia entrada
scanf("%d",&n);
}//fin sentencia entrada

{//inicio sentencia asig






int tmp20[2][2];
memcpy(tmp20,diferenciaPotencias(n,m,d,pi,pd),16);


memcpy(diff,tmp20,16);
}//fin sentencia asig

{//inicio sentencia salida









printf("%s %d %d %d %d %s ","Las diferencias en cada componente son :",diff[0][0],diff[0][1],diff[1][0],diff[1][1],"\n");
}//fin sentencia salida

}//fin bloque

