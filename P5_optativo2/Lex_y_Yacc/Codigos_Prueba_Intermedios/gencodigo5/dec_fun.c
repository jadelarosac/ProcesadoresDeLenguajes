#ifndef FUNCIONES_DEC
#define FUNCIONES_DEC
//Inicio declaracion funcion
int fact(int a)
{//inicio bloque
int d,resultado;

//Inicio declaracion funcion
int multiplicar(int e1, int e2){//inicio bloque
{//inicio sentencia return


int tmp0;
tmp0=e1*e2;

return tmp0;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion
{//inicio sentencia asig

d = a;
}//fin sentencia asig

{//inicio sentencia asig

resultado = 1;
}//fin sentencia asig

{//inicio sentencia while
etiqueta0: ;


int tmp1;
tmp1=d>=1;
if (!tmp1) goto etiqueta1;
{//inicio bloque
{//inicio sentencia asig



int tmp2;
tmp2=multiplicar(resultado,d);

resultado = tmp2;
}//fin sentencia asig

{//inicio sentencia asig


int tmp3;
tmp3=d-1;

d = tmp3;
}//fin sentencia asig

}//fin bloque

goto etiqueta0;
etiqueta1: ;
}//fin sentencia while

{//inicio sentencia return

return resultado;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion

#endif
