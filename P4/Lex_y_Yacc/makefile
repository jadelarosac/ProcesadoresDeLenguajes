analisis_sintactico: main.o y.tab.o
	gcc -o analisis_sintactico main.o y.tab.o

y.tab.o: y.tab.c
	gcc -c y.tab.c

main.o: main.c
	gcc -c main.c

y.tab.c: analisis_sintactico.y lex.yy.c
	bison -v -o y.tab.c analisis_sintactico.y

lex.yy.c: analisis_lexico.l
	flex analisis_lexico.l

clean:
	rm -f prueba main.o y.tab.o y.tab.c lex.yy.c

all:
	make clean
	make analisis_sintactico


