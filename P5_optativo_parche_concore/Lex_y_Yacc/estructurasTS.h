#ifndef ESTTS
#define ESTTS


typedef enum {
	marca, funcion, variable, parametro_formal
} tipoEntrada ;

typedef enum {
	booleano, entero, real, caracter, desconocido, no_asignado
} dtipo;

typedef struct {
	tipoEntrada entrada;
	char* nombre;
	dtipo tipoDato;
	unsigned int parametros;
	unsigned int dimensiones;
	int TamDimen1;
	int TamDimen2;
	int valido;
} entradaTS;

// Entrada para llamada a funcione
typedef struct{
	int indiceTS;
	int n_param;
} entradaFuncion;

#endif
