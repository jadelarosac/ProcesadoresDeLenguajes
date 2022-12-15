#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "FuncionesArrays/dec_dat.h"
int ve;

int ve2;

double vf;

char vc;

int vl;

int pe[5],pe2[2][2],pe23[2][3],pe32[3][2];

double pf[5],pf2[2][10];

char pc[2][2],pc2[5];

int pl[300][1000];

#include "dec_fun.c"

int main(){//inicio bloque


{//inicio sentencia asig






double tmp20[5]={5.1, 2.03, 3.1415, 0.01, 1.0};
double tmp21[5];
double_suma_array_num(tmp21, vf, tmp20, 5, 1);


memcpy(pf,tmp21,40);
}//fin sentencia asig

{//inicio sentencia asig



pc[1][1] = '#';
}//fin sentencia asig

{//inicio sentencia asig


int tmp22[3][2];
int_producto_mat_array(tmp22, pe23, pe32, 2, 3, 2);


memcpy(pe2,tmp22,16);
}//fin sentencia asig

{//inicio sentencia if


int tmp23;
tmp23=pe[1]-20;


int tmp24;
tmp24=tmp23==20;
if (!tmp24) goto etiqueta11;
{//inicio if
{//inicio sentencia asig


ve = pe[2];
}//fin sentencia asig
}//fin if
goto etiqueta10;
etiqueta11: ;
{//inicio else
{//inicio sentencia asig


int tmp25[2][2];
int_producto_mat_array(tmp25, pe2, pe2, 2, 2, 2);


memcpy(pe2,tmp25,16);
}//fin sentencia asig
}//fin else
etiqueta10: ;
}//fin sentencia if

{//inicio sentencia asig



int tmp26;
tmp26=pe2[0][1]-pe[2];




int tmp27;
tmp27=20/2000;

int tmp28;
tmp28=10*tmp27;

int tmp29;
tmp29=tmp26+tmp28;


pe[3] = tmp29;
}//fin sentencia asig

}//fin bloque

