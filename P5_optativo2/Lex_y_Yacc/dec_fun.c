#ifndef FUNCIONES_DEC
#define FUNCIONES_DEC
//Inicio declaracion funcion
int** diferenciaPotencias(int num, int a[2][2], int diag[2][2], int mi[2][2], int md[2][2])
{//inicio bloque
int r1[2][2],r2[2][2];
{//inicio sentencia asig


memcpy(r1,a,16);
}//fin sentencia asig

{//inicio sentencia asig


memcpy(r2,diag,16);
}//fin sentencia asig

{//inicio sentencia while
etiqueta0: ;


int tmp0;
tmp0=num>1;
if (!tmp0) goto etiqueta1;
{//inicio bloque
{//inicio sentencia asig


int tmp1[2][2];
int_producto_mat_array(tmp1, r1, a, 2, 2, 2);


memcpy(r1,tmp1,16);
}//fin sentencia asig

{//inicio sentencia asig


int tmp2[2][2];
int_producto_mat_array(tmp2, r2, diag, 2, 2, 2);


memcpy(r2,tmp2,16);
}//fin sentencia asig

{//inicio sentencia asig


int tmp3;
tmp3=num-1;


num = tmp3;
}//fin sentencia asig

}//fin bloque

goto etiqueta0;
etiqueta1: ;
}//fin sentencia while

{//inicio sentencia asig


int tmp4[2][2];
int_producto_mat_array(tmp4, mi, r2, 2, 2, 2);


int tmp5[2][2];
int_producto_mat_array(tmp5, tmp4, md, 2, 2, 2);


memcpy(r2,tmp5,16);
}//fin sentencia asig

{//inicio sentencia return



int tmp6[2][2];
int_diferencia_array(tmp6, r2, r1, 2, 2);

int tmp7[2][2];
int_suma_array_num(tmp7, 2, tmp6, 2, 2);





int tmp8[2][2]={{2, 1},{1, 2}};
int tmp9[2][2];
int_division_array(tmp9, tmp7, tmp8, 2, 2);

int** tmp10=(int **) malloc(16);
memcpy(tmp10,tmp9,16);
return tmp10;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion

#endif
