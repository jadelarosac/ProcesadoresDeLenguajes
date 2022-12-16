#ifndef FUNCIONES_DEC
#define FUNCIONES_DEC
//Inicio declaracion funcion
int* finbonnaci(int n)
{//inicio bloque
int lista_fib[10],i;

//Inicio declaracion funcion
int* mult_por_dos(int list[10]){//inicio bloque
int lista_dos[10],j,resultado_final;

//Inicio declaracion funcion
int mult_matrc(int array_a_matriz[10]){//inicio bloque
int m1[1][10],m2[10][1],m_res[1][1],resultado,ind_array_a_mat;
{//inicio sentencia asig


ind_array_a_mat = 0;
}//fin sentencia asig

{//inicio sentencia while
etiqueta0: ;


int tmp0;
tmp0=ind_array_a_mat<10;
if (!tmp0) goto etiqueta1;
{//inicio bloque
{//inicio sentencia asig



m1[0][ind_array_a_mat] = array_a_matriz[ind_array_a_mat];
}//fin sentencia asig

{//inicio sentencia asig



m2[ind_array_a_mat][0] = array_a_matriz[ind_array_a_mat];
}//fin sentencia asig

{//inicio sentencia asig


int tmp1;
tmp1=ind_array_a_mat+1;


ind_array_a_mat = tmp1;
}//fin sentencia asig

}//fin bloque

goto etiqueta0;
etiqueta1: ;
}//fin sentencia while

{//inicio sentencia asig


int tmp2[10][1];
int_producto_mat_array(tmp2, m1, m2, 1, 10, 1);


memcpy(m_res,tmp2,4);
}//fin sentencia asig

{//inicio sentencia asig



resultado = m_res[0][0];
}//fin sentencia asig

{//inicio sentencia salida


printf("%s %d %s ","EL resultado es: ",resultado,"\n");
}//fin sentencia salida

{//inicio sentencia return

return resultado;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion
{//inicio sentencia asig


int tmp3[10];
int_producto_array_num(tmp3, 2, list, 10, 1);


memcpy(lista_dos,tmp3,40);
}//fin sentencia asig

{//inicio sentencia asig


j = 0;
}//fin sentencia asig

{//inicio sentencia while
etiqueta2: ;


int tmp4;
tmp4=j<10;
if (!tmp4) goto etiqueta3;
{//inicio bloque
{//inicio sentencia salida

printf("%d %s ",lista_dos[j]," ");
}//fin sentencia salida

{//inicio sentencia asig


int tmp5;
tmp5=j+1;


j = tmp5;
}//fin sentencia asig

}//fin bloque

goto etiqueta2;
etiqueta3: ;
}//fin sentencia while

{//inicio sentencia salida
printf("%s ","\n");
}//fin sentencia salida

{//inicio sentencia asig


int tmp6;
tmp6=mult_matrc(lista_dos);


resultado_final = tmp6;
}//fin sentencia asig

{//inicio sentencia return

int* tmp7=(int *) malloc(40);
memcpy(tmp7,lista_dos,40);
return tmp7;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion
{//inicio sentencia asig


i = 0;
}//fin sentencia asig

{//inicio sentencia while
etiqueta4: ;


int tmp8;
tmp8=i<10;
if (!tmp8) goto etiqueta5;
{//inicio bloque
{//inicio sentencia asig


lista_fib[i] = 0;
}//fin sentencia asig

{//inicio sentencia asig


int tmp9;
tmp9=i+1;


i = tmp9;
}//fin sentencia asig

}//fin bloque

goto etiqueta4;
etiqueta5: ;
}//fin sentencia while

{//inicio sentencia if


int tmp10;
tmp10=n>1;
if (!tmp10) goto etiqueta6;
{//inicio if
{//inicio bloque
{//inicio sentencia asig


lista_fib[1] = 1;
}//fin sentencia asig

}//fin bloque
}//fin if
etiqueta6: ;
}//fin sentencia if

{//inicio sentencia asig


i = 2;
}//fin sentencia asig

{//inicio sentencia while
etiqueta7: ;


int tmp11;
tmp11=i<n;
if (!tmp11) goto etiqueta8;
{//inicio bloque
{//inicio sentencia asig


int tmp12;
tmp12=i-1;



int tmp13;
tmp13=i-2;

int tmp14;
tmp14=lista_fib[tmp12]+lista_fib[tmp13];


lista_fib[i] = tmp14;
}//fin sentencia asig

{//inicio sentencia asig


int tmp15;
tmp15=i+1;


i = tmp15;
}//fin sentencia asig

}//fin bloque

goto etiqueta7;
etiqueta8: ;
}//fin sentencia while

{//inicio sentencia asig


i = 0;
}//fin sentencia asig

{//inicio sentencia while
etiqueta9: ;


int tmp16;
tmp16=i<10;
if (!tmp16) goto etiqueta10;
{//inicio bloque
{//inicio sentencia salida

printf("%d %s ",lista_fib[i]," ");
}//fin sentencia salida

{//inicio sentencia asig


int tmp17;
tmp17=i+1;


i = tmp17;
}//fin sentencia asig

}//fin bloque

goto etiqueta9;
etiqueta10: ;
}//fin sentencia while

{//inicio sentencia salida
printf("%s ","\n");
}//fin sentencia salida

{//inicio sentencia asig


int tmp18[10];
memcpy(tmp18,mult_por_dos(lista_fib),40);


memcpy(lista_fib,tmp18,40);
}//fin sentencia asig

{//inicio sentencia return

int* tmp19=(int *) malloc(40);
memcpy(tmp19,lista_fib,40);
return tmp19;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion

#endif
