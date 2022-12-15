#ifndef FUNCIONES_DEC
#define FUNCIONES_DEC
//Inicio declaracion funcion
int funcionA(int a1, double a2, char a3)
{//inicio bloque
int x1,x2;

//Inicio declaracion funcion
char funcionB(char b1, int b2){//inicio bloque
double xf,x2;

//Inicio declaracion funcion
double funcionC(int c1, int c2){//inicio bloque
double x1;
{//inicio sentencia if


int tmp0;
tmp0=c2>10;
if (!tmp0) goto etiqueta1;
{//inicio if
{//inicio sentencia asig


int tmp1;
tmp1=c2-1;


c2 = tmp1;
}//fin sentencia asig
}//fin if
goto etiqueta0;
etiqueta1: ;
{//inicio else
{//inicio sentencia asig


x1 = 3.1;
}//fin sentencia asig
}//fin else
etiqueta0: ;
}//fin sentencia if

{//inicio sentencia return

return x1;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion
{//inicio sentencia asig



double tmp2;
tmp2=funcionC(1,10);


xf = tmp2;
}//fin sentencia asig

{//inicio sentencia asig




double tmp3;
tmp3=funcionC(0,1);




double tmp4;
tmp4=funcionC(1,23);

double tmp5;
tmp5=tmp3-tmp4;

double tmp6;
tmp6=xf*tmp5;


double tmp7;
tmp7=tmp6/10.0;


x2 = tmp7;
}//fin sentencia asig

{//inicio sentencia while
etiqueta2: ;




double tmp8;
tmp8=funcionC(0,1);

double tmp9;
tmp9=x2*tmp8;


double tmp10;
tmp10=tmp9-xf;


int tmp11;
tmp11=tmp10<10.0;
if (!tmp11) goto etiqueta3;
{//inicio sentencia asig


double tmp12;
tmp12=x2*xf;


x2 = tmp12;
}//fin sentencia asig

goto etiqueta2;
etiqueta3: ;
}//fin sentencia while

}//fin bloque
//Fin declaracion funcion
{//inicio sentencia return

return 5;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion
//Inicio declaracion funcion
double funcionD(double d1)
{//inicio bloque
char dato;

int valor;

//Inicio declaracion funcion
char funcionE(char e1, char e2){//inicio bloque
{//inicio sentencia entrada
scanf("%c\n%c",&e1,&e2);
}//fin sentencia entrada

{//inicio sentencia if


int tmp13;
tmp13=e1=='a';
if (!tmp13) goto etiqueta7;
{//inicio if
{//inicio sentencia return

return e1;
}//fin sentencia return
}//fin if
goto etiqueta6;
etiqueta7: ;
{//inicio else
{//inicio sentencia if


int tmp14;
tmp14=e1=='b';
if (!tmp14) goto etiqueta5;
{//inicio if
{//inicio sentencia return

return e2;
}//fin sentencia return
}//fin if
goto etiqueta4;
etiqueta5: ;
{//inicio else
{//inicio sentencia return

return ' ';
}//fin sentencia return
}//fin else
etiqueta4: ;
}//fin sentencia if
}//fin else
etiqueta6: ;
}//fin sentencia if

}//fin bloque
//Fin declaracion funcion
{//inicio sentencia entrada
scanf("%d",&valor);
}//fin sentencia entrada

{//inicio sentencia if


int tmp15;
tmp15=d1>0.0;
if (!tmp15) goto etiqueta9;
{//inicio if
{//inicio bloque
int dato;
{//inicio sentencia asig


dato = 2;
}//fin sentencia asig

{//inicio sentencia asig


int tmp16;
tmp16=valor*20;


int tmp17;
tmp17=tmp16/dato;


dato = tmp17;
}//fin sentencia asig

}//fin bloque
}//fin if
goto etiqueta8;
etiqueta9: ;
{//inicio else
{//inicio bloque
{//inicio sentencia asig


int tmp18;
tmp18=valor*100;


valor = tmp18;
}//fin sentencia asig

{//inicio sentencia asig


double tmp19;
tmp19=d1/1000.0;


d1 = tmp19;
}//fin sentencia asig

}//fin bloque
}//fin else
etiqueta8: ;
}//fin sentencia if

{//inicio sentencia return

return d1;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion

#endif
