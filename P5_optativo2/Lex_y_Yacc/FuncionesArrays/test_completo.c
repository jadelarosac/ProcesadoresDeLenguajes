#include "dec_fun.h"
#include <stdio.h>

int main(int argc, char **argv)
{

    int a_int[4] = {1,2,3,4};
    int b_int[4] = {1,2,3,4};
    int f_int = 2;
    int s_int[4];

    int_suma_array(s_int,a_int,b_int,4,1);

    printf("La suma de los dos arrays de int es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_int[i]);
    }
    printf("\n");

    int_suma_array_num(s_int, &f_int, b_int, 4, 1);

    printf("La suma del array de int con el valor es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_int[i]);
    }
    printf("\n");

    int_diferencia_array(s_int,a_int,b_int,4,1);

    printf("La diferencia de los dos arrays de int es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_int[i]);
    }
    printf("\n");

    int_diferencia_array_num(s_int, &f_int, b_int, 4, 1);

    printf("La diferencia del array de int con el valor es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_int[i]);
    }
    printf("\n");

    int_producto_array(s_int,a_int,b_int,4,1);

    printf("El producto de los dos arrays de int es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_int[i]);
    }
    printf("\n");

    int_producto_array_num(s_int, &f_int, b_int, 4, 1);

    printf("El producto del array de int con el valor es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_int[i]);
    }
    printf("\n");

    int_division_array(s_int,a_int,b_int,4,1);

    printf("La division de los dos arrays de int es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_int[i]);
    }
    printf("\n");

    int_division_array_num(s_int, &f_int, b_int, 4, 1);

    printf("La division del array de int con el valor es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_int[i]);
    }
    printf("\n");

    int A_int[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    int B_int[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    int S_int[4][4];

    int_suma_array(S_int,A_int,B_int,4,4);

    printf("La suma de los dos arrays enteros:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_int[i][j]);
        }
        printf("\n");
    }

    int_suma_array_num(S_int, &f_int, B_int, 4, 4);

    printf("La suma del array entero con el valor:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_int[i][j]);
        }
        printf("\n");
    }


    int_diferencia_array(S_int,A_int,B_int,4,4);

    printf("La diferencia de los dos arrays enteros:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_int[i][j]);
        }
        printf("\n");
    }

    int_diferencia_array_num(S_int, &f_int, B_int, 4, 4);

    printf("La diferencia del array entero con el valor:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_int[i][j]);
        }
        printf("\n");
    }


    int_producto_array(S_int,A_int,B_int,4,4);

    printf("El producto de los dos arrays enteros:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_int[i][j]);
        }
        printf("\n");
    }

    int_producto_array_num(S_int, &f_int, B_int, 4, 4);

    printf("El producto del array entero con el valor:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_int[i][j]);
        }
        printf("\n");
    }


    int_division_array(S_int,A_int,B_int,4,4);

    printf("La division de los dos arrays enteros:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_int[i][j]);
        }
        printf("\n");
    }

    int_division_array_num(S_int, &f_int, B_int, 4, 4);

    printf("La division del array entero con el valor:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_int[i][j]);
        }
        printf("\n");
    }

    int_producto_mat_array(S_int, A_int, B_int, 4, 4, 4);

    printf("El producto matricial de los dos arrays es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_int[i][j]);
        }
        printf("\n");
    }

    double a_double[4] = {1,2,3,4};
    double b_double[4] = {1,2,3,4};
    double f_double = 2;
    double s_double[4];

    double_suma_array(s_double,a_double,b_double,4,1);

    printf("La suma de los dos arrays de double es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_double[i]);
    }
    printf("\n");

    double_suma_array_num(s_double, &f_double, b_double, 4, 1);

    printf("La suma del array de double con el valor es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_double[i]);
    }
    printf("\n");

    double_diferencia_array(s_double,a_double,b_double,4,1);

    printf("La diferencia de los dos arrays de double es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_double[i]);
    }
    printf("\n");

    double_diferencia_array_num(s_double, &f_double, b_double, 4, 1);

    printf("La diferencia del array de double con el valor es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_double[i]);
    }
    printf("\n");

    double_producto_array(s_double,a_double,b_double,4,1);

    printf("El producto de los dos arrays de double es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_double[i]);
    }
    printf("\n");

    double_producto_array_num(s_double, &f_double, b_double, 4, 1);

    printf("El producto del array de double con el valor es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_double[i]);
    }
    printf("\n");

    double_division_array(s_double,a_double,b_double,4,1);

    printf("La division de los dos arrays de double es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_double[i]);
    }
    printf("\n");

    double_division_array_num(s_double, &f_double, b_double, 4, 1);

    printf("La division del array de double con el valor es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        printf("%f\t",(double)s_double[i]);
    }
    printf("\n");

    double A_double[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    double B_double[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    double S_double[4][4];

    double_suma_array(S_double,A_double,B_double,4,4);

    printf("La suma de los dos arrays enteros:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_double[i][j]);
        }
        printf("\n");
    }

    double_suma_array_num(S_double, &f_double, B_double, 4, 4);

    printf("La suma del array entero con el valor:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_double[i][j]);
        }
        printf("\n");
    }


    double_diferencia_array(S_double,A_double,B_double,4,4);

    printf("La diferencia de los dos arrays enteros:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_double[i][j]);
        }
        printf("\n");
    }

    double_diferencia_array_num(S_double, &f_double, B_double, 4, 4);

    printf("La diferencia del array entero con el valor:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_double[i][j]);
        }
        printf("\n");
    }


    double_producto_array(S_double,A_double,B_double,4,4);

    printf("El producto de los dos arrays enteros:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_double[i][j]);
        }
        printf("\n");
    }

    double_producto_array_num(S_double, &f_double, B_double, 4, 4);

    printf("El producto del array entero con el valor:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_double[i][j]);
        }
        printf("\n");
    }


    double_division_array(S_double,A_double,B_double,4,4);

    printf("La division de los dos arrays enteros:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_double[i][j]);
        }
        printf("\n");
    }

    double_division_array_num(S_double, &f_double, B_double, 4, 4);

    printf("La division del array entero con el valor:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_double[i][j]);
        }
        printf("\n");
    }

    double_producto_mat_array(S_double, A_double, B_double, 4, 4, 4);

    printf("El producto matricial de los dos arrays es:\n");
    for(unsigned i = 0; i < 4; ++i)
    {
        for(unsigned j = 0; j < 4; ++j)
        {
            printf("%f\t",(double)S_double[i][j]);
        }
        printf("\n");
    }
    return 0;
}
