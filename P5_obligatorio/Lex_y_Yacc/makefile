FUEN=./Codigos_Prueba_Fuentes
OBJ=./Codigos_Prueba_Intermedios
EXE=./Codigos_Prueba_Compilados

%.out: $(OBJ)/%.c
	gcc $^ -o $(EXE)/$@

$(OBJ)/%.c: $(FUEN)/%.babad
	./analizador_yacc $^
	mv ./main_inter.c $@

analizador_yacc: main.o y.tab.o
	gcc -o analizador_yacc main.o y.tab.o

y.tab.o: y.tab.c
	gcc -c y.tab.c

main.o: main.c
	gcc -c main.c

y.tab.c: analizador_yacc.y lex.yy.c
	bison -t -v -o y.tab.c analizador_yacc.y

lex.yy.c: analisis_lexico.l
	flex analisis_lexico.l

clean:
	rm -f prueba main.o y.tab.o y.tab.c lex.yy.c y.output

all:
	make clean
	make analizador_yacc


