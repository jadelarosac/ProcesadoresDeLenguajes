#ifndef FUNCIONES_DEC
#define FUNCIONES_DEC
//Inicio declaracion funcion
int fact(int a)
{//inicio bloque
{//inicio sentencia if


int tmp0;
tmp0=a>1;
if (!tmp0) goto etiqueta1;
{//inicio if
{//inicio bloque
{//inicio sentencia return


int tmp1;
tmp1=a-1;


int tmp2;
tmp2=fact(tmp1);


int tmp3;
tmp3=tmp2*a;

return tmp3;
}//fin sentencia return

}//fin bloque
}//fin if
goto etiqueta0;
etiqueta1: ;
{//inicio else
{//inicio bloque
{//inicio sentencia return

return a;
}//fin sentencia return

}//fin bloque
}//fin else
etiqueta0: ;
}//fin sentencia if

}//fin bloque
//Fin declaracion funcion

#endif
