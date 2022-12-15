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

int tmp8;
tmp8=-10;



int tmp9;
tmp9=-36;


int tmp10[2][2]={{tmp8, 3},{tmp9, 11}};

memcpy(m,tmp10,16);
}//fin sentencia asig

{//inicio sentencia asig

int tmp11;
tmp11=-1;




int tmp12[2][2]={{tmp11, 0},{0, 2}};

memcpy(d,tmp12,16);
}//fin sentencia asig

{//inicio sentencia asig


int tmp13;
tmp13=-1;


int tmp14;
tmp14=-3;


int tmp15[2][2]={{4, tmp13},{tmp14, 1}};

memcpy(pd,tmp15,16);
}//fin sentencia asig

{//inicio sentencia asig




int tmp16[2][2]={{1, 1},{3, 4}};

memcpy(pi,tmp16,16);
}//fin sentencia asig

{//inicio sentencia salida
printf("%s ","introduce numero :");
}//fin sentencia salida

{//inicio sentencia entrada
scanf("%d",&n);
}//fin sentencia entrada

{//inicio sentencia asig






int tmp17[2][2];
memcpy(tmp17,diferenciaPotencias(n,m,d,pi,pd),16);


memcpy(diff,tmp17,16);
}//fin sentencia asig

{//inicio sentencia salida









printf("%s %d %d %d %d %s ","Las diferencias en cada componente son :",diff[0][0],diff[0][1],diff[1][0],diff[1][1],"\n");
}//fin sentencia salida

}//fin bloque

