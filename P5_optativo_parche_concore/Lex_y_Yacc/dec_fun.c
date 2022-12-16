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
{//inicio sentencia asig

double tmp0;
tmp0=+1.3;


x1 = tmp0;
}//fin sentencia asig

{//inicio sentencia if


int tmp1;
tmp1=c2<10;
if (!tmp1) goto etiqueta1;
{//inicio if
{//inicio sentencia asig


int tmp2;
tmp2=c2-1;


c2 = tmp2;
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



double tmp3;
tmp3=funcionC(1,10);


xf = tmp3;
}//fin sentencia asig

{//inicio sentencia asig




double tmp4;
tmp4=funcionC(0,1);




double tmp5;
tmp5=funcionC(1,23);

double tmp6;
tmp6=tmp4-tmp5;

double tmp7;
tmp7=xf*tmp6;


double tmp8;
tmp8=tmp7/10.0;


x2 = tmp8;
}//fin sentencia asig

{//inicio sentencia do-until
etiqueta2: ;
{//inicio bloque
{//inicio sentencia asig


double tmp9;
tmp9=x2*xf;


x2 = tmp9;
}//fin sentencia asig

}//fin bloque




double tmp10;
tmp10=funcionC(0,1);

double tmp11;
tmp11=x2*tmp10;


double tmp12;
tmp12=tmp11-xf;


int tmp13;
tmp13=tmp12<10.0;
if (!tmp13) goto etiqueta2;
}//fin sentencia do-until

}//fin bloque
//Fin declaracion funcion

//Inicio declaracion funcion
double funcionD(double d1){//inicio bloque
char dato;

int valor;

//Inicio declaracion funcion
char funcionE(char e1, char e2){//inicio bloque
{//inicio sentencia salida
printf("%s ","introduzca dos caracteres: ");
}//fin sentencia salida

{//inicio sentencia entrada
scanf("%c\n%c",&e1,&e2);
}//fin sentencia entrada

{//inicio sentencia if


int tmp14;
tmp14=e1=='a';
if (!tmp14) goto etiqueta6;
{//inicio if
{//inicio sentencia return

return e1;
}//fin sentencia return
}//fin if
goto etiqueta5;
etiqueta6: ;
{//inicio else
{//inicio sentencia if


int tmp15;
tmp15=e1=='b';
if (!tmp15) goto etiqueta4;
{//inicio if
{//inicio sentencia return

return e2;
}//fin sentencia return
}//fin if
goto etiqueta3;
etiqueta4: ;
{//inicio else
{//inicio sentencia return

return ' ';
}//fin sentencia return
}//fin else
etiqueta3: ;
}//fin sentencia if
}//fin else
etiqueta5: ;
}//fin sentencia if

}//fin bloque
//Fin declaracion funcion
{//inicio sentencia salida
printf("%s ","introduzca un valor entero: ");
}//fin sentencia salida

{//inicio sentencia entrada
scanf("%d",&valor);
}//fin sentencia entrada

{//inicio sentencia if


int tmp16;
tmp16=d1>1.1;
if (!tmp16) goto etiqueta8;
{//inicio if
{//inicio bloque
int dato;
{//inicio sentencia asig


dato = 2;
}//fin sentencia asig

{//inicio sentencia asig


int tmp17;
tmp17=valor*20;


int tmp18;
tmp18=tmp17/dato;


dato = tmp18;
}//fin sentencia asig

}//fin bloque
}//fin if
goto etiqueta7;
etiqueta8: ;
{//inicio else
{//inicio bloque
{//inicio sentencia asig


int tmp19;
tmp19=valor*100;


valor = tmp19;
}//fin sentencia asig

{//inicio sentencia asig


double tmp20;
tmp20=d1/1000.0;


d1 = tmp20;
}//fin sentencia asig

}//fin bloque
}//fin else
etiqueta7: ;
}//fin sentencia if

{//inicio sentencia if


int tmp21;
tmp21=d1>1.1;
if (!tmp21) goto etiqueta9;
{//inicio if
{//inicio bloque
{//inicio sentencia return

return 5.0;
}//fin sentencia return

}//fin bloque
}//fin if
etiqueta9: ;
}//fin sentencia if

{//inicio sentencia return

return d1;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion
{//inicio sentencia return

return 1;
}//fin sentencia return

}//fin bloque
//Fin declaracion funcion

#endif
