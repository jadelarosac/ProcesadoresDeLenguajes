void FUNCION_DETERMINADA(void * resultado, void * a, void * b, unsigned dim_x, unsigned dim_y)
{
    for(unsigned i = 0; i < dim_x; ++i)
    {
        for(unsigned j = 0; j < dim_y; ++j)
        {
            *((TIPO_DETERMINADO *) resultado + i*dim_y + j) =
            *((TIPO_DETERMINADO *) b + i*dim_y + j) OPERACION_DETERMINADA
            *((TIPO_DETERMINADO*) a);
        }
    }
}

