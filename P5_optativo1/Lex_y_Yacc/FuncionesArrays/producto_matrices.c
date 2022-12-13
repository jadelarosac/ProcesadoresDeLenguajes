void FUNCION_DETERMINADA(void * resultado, void * a, void * b, unsigned dim_xa, unsigned dim, unsigned dim_yb)
{
    for(unsigned i = 0; i < dim_xa; ++i)
    {
        for(unsigned j = 0; j < dim_yb; ++j)
        {
            *((TIPO_DETERMINADO *) resultado + i*dim_yb + j) = 0;

            for(unsigned k = 0; k < dim; ++k)
            {
                *((TIPO_DETERMINADO *) resultado + i*dim_yb + j) +=
                *((TIPO_DETERMINADO *) a + i*dim + k) *
                *((TIPO_DETERMINADO *) b + k*dim_yb + j);
            }
        }
    }
}

