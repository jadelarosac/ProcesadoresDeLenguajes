main: lex.yy.c
	gcc -o main lex.yy.c

lex.yy.c: tabla_tokens.h analisis_lexico.l
	flex analisis_lexico.l 

clean:
	rm lex.yy.c
	rm main
