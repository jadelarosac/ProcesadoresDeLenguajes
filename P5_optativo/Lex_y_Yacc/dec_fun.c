int es_divisible{//inicio bloque
int d;

int resultado;
{//inicio sentencia asig


int tmp0;
tmp0=a/b;

d = tmp0;
}//fin sentencia asig

{//inicio sentencia if


int tmp1;
tmp1=d*b;


int tmp2;
tmp2=tmp1==a;
if (!tmp2) goto etiqueta1;
{//inicio if
{//inicio sentencia asig

resultado = 1;
}//fin sentencia asig
}//fin if
goto etiqueta0;
etiqueta1: ;
{//inicio else
{//inicio sentencia asig

resultado = 0;
}//fin sentencia asig
}//fin else
etiqueta0: ;
}//fin sentencia if

SENTENCIA RETORNAR
}//fin bloque

