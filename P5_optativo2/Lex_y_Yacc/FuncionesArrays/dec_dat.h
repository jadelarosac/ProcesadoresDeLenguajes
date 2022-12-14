#ifndef MAT_DEC
#define MAT_DEC
// FUNCIONES CON int
#define TIPO_DETERMINADO int

// suma
#define OPERACION_DETERMINADA +
#define FUNCION_DETERMINADA int_suma_array_num
#include "operacion_numero.c"
#undef FUNCION_DETERMINADA

#define FUNCION_DETERMINADA int_suma_array
#include "operacion.c"
#undef FUNCION_DETERMINADA
#undef OPERACION_DETERMINADA

// diferencia
#define OPERACION_DETERMINADA -
#define FUNCION_DETERMINADA int_diferencia_array_num
#include "operacion_numero.c"
#undef FUNCION_DETERMINADA

#define FUNCION_DETERMINADA int_diferencia_array
#include "operacion.c"
#undef FUNCION_DETERMINADA
#undef OPERACION_DETERMINADA

// producto
#define OPERACION_DETERMINADA *
#define FUNCION_DETERMINADA int_producto_array_num
#include "operacion_numero.c"
#undef FUNCION_DETERMINADA

#define FUNCION_DETERMINADA int_producto_array
#include "operacion.c"
#undef FUNCION_DETERMINADA
#undef OPERACION_DETERMINADA

// division
#define OPERACION_DETERMINADA /
#define FUNCION_DETERMINADA int_division_array_num
#include "operacion_numero.c"
#undef FUNCION_DETERMINADA

#define FUNCION_DETERMINADA int_division_array
#include "operacion.c"
#undef FUNCION_DETERMINADA
#undef OPERACION_DETERMINADA

// PRODUCTO MATRICIAL
#define FUNCION_DETERMINADA int_producto_mat_array
#include "producto_matrices.c"
#undef FUNCION_DETERMINADA

#undef TIPO_DETERMINADO

// FUNCIONES CON double
#define TIPO_DETERMINADO double

// suma
#define OPERACION_DETERMINADA +
#define FUNCION_DETERMINADA double_suma_array_num
#include "operacion_numero.c"
#undef FUNCION_DETERMINADA

#define FUNCION_DETERMINADA double_suma_array
#include "operacion.c"
#undef FUNCION_DETERMINADA
#undef OPERACION_DETERMINADA

// diferencia
#define OPERACION_DETERMINADA -
#define FUNCION_DETERMINADA double_diferencia_array_num
#include "operacion_numero.c"
#undef FUNCION_DETERMINADA

#define FUNCION_DETERMINADA double_diferencia_array
#include "operacion.c"
#undef FUNCION_DETERMINADA
#undef OPERACION_DETERMINADA

// producto
#define OPERACION_DETERMINADA *
#define FUNCION_DETERMINADA double_producto_array_num
#include "operacion_numero.c"
#undef FUNCION_DETERMINADA

#define FUNCION_DETERMINADA double_producto_array
#include "operacion.c"
#undef FUNCION_DETERMINADA
#undef OPERACION_DETERMINADA

// division
#define OPERACION_DETERMINADA /
#define FUNCION_DETERMINADA double_division_array_num
#include "operacion_numero.c"
#undef FUNCION_DETERMINADA

#define FUNCION_DETERMINADA double_division_array
#include "operacion.c"
#undef FUNCION_DETERMINADA
#undef OPERACION_DETERMINADA

// PRODUCTO MATRICIAL
#define FUNCION_DETERMINADA double_producto_mat_array
#include "producto_matrices.c"
#undef FUNCION_DETERMINADA

#undef TIPO_DETERMINADO
#endif
