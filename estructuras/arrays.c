#include "estructuras.h"

int buscarEnArrayInt(const int buscar, const int array[], const int cantElementos)
{
    int retorno = -1;
    int i;

    for(i=0 ; i< cantElementos ; i++)
    {
        if(array[i] == buscar)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int buscarProducto(const int buscar, const eProducto inventario[])
{
    int retorno = -1;
    int i;

    for(i=0 ; i<NRO_MAX_PRODUCTOS ; i++)
    {
        if(inventario[i].codigo == buscar)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}
