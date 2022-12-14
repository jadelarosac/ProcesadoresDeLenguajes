FUEN=./Codigos_Prueba_Fuentes
OBJ=./Codigos_Prueba_Intermedios
EXE=./Codigos_Prueba_Compilados

.SECONDARY: $(OBJ: .c)



%.c : $(OBJ)/%.c
	@echo "Creando carpeta del programa"

$(OBJ)/%.c: $(FUEN)/%.babad
	@mkdir -p $(OBJ)/$(*F)
	./analizador_yacc $^
	@mv ./main_inter.c $(OBJ)/$(*F)
	@mv ./dec_fun.c $(OBJ)/$(*F)
	@echo "all: main_inter.c\n\tgcc main_inter.c -o main_inter" > $(OBJ)/$(*F)/Makefile

analizador_yacc: main.o y.tab.o
	gcc -g -o analizador_yacc main.o y.tab.o

y.tab.o: y.tab.c
	gcc -g -c y.tab.c

main.o: main.c
	gcc -g -c main.c

y.tab.c: analizador_yacc.y lex.yy.c
	bison -t -v -o y.tab.c analizador_yacc.y

lex.yy.c: analisis_lexico.l
	flex analisis_lexico.l

clean:
	@rm -f analizador_yacc main.o y.tab.o y.tab.c lex.yy.c y.output
	@rm -rf  $(OBJ)/*
	@rm -f $(EXE)/*

all:
	make clean
	make analizador_yacc


