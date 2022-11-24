#ifndef ESTTS
#define ESTTS


typedef enum {
	marca, funcion, variable, parametro_formal
} tipoEntrada ;

typedef enum {
	booleano, entero, real, caracter, array, desconocido, no_asignado
} dtipo;

typedef struct {
	tipoEntrada entrada;
	char* nombre;
	dtipo tipoDato;
	unsigned int parametros;
	unsigned int dimensiones;
	int TamDimen1;
	int TamDimen2;
} entradaTS;

#endif
