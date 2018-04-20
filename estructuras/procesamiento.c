#include <stdio.h>
#include <string.h>
#include "funciones_generales.h"
#include "estructuras.h"
#include "arrays.h"

void mostrarProducto(const eProducto producto)
{
    printf("\nProducto: %d - %s - $%.2f - stock: %d", producto.codigo, producto.descripcion, producto.precioCosto, producto.stock);

}

void mostrarInventario(const eProducto inventario[])
{
    int i;

    for(i=0 ; i<NRO_MAX_PRODUCTOS ; i++)
    {
        if((inventario[i]).codigo != 0)
        {
            mostrarProducto(inventario[i]);
        }
    }
    ejecutarEnConsola(HACER_PAUSA);
}

int pedirInt(const char mensajeIngreso[])
{
    int retorno;

    printf("%s", mensajeIngreso);
    fflush(stdin);
    scanf("%d", &retorno);


    return retorno;
}

float pedirFloat(const char mensajeIngreso[])
{
    float retorno;

    printf("%s", mensajeIngreso);
    fflush(stdin);
    scanf("%f", &retorno);


    return retorno;
}

void pedirString(char *retorno, const char mensajeIngreso[])
{
    printf("%s", mensajeIngreso);
    fflush(stdin);
    gets(retorno);
}

int buscarLugarLibre(const eProducto inventario[])
{
    int retorno = -1; //si no encuentra lugar devuelve -1
    int i;

    for(i=0 ; i<NRO_MAX_PRODUCTOS ; i++)
    {
        if(inventario[i].codigo == 0)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

eProducto CrearProducto()
{
    eProducto retorno;

    ejecutarEnConsola(LIMPIAR_PANTALLA);

    retorno.codigo = pedirInt("\nIngrese c¢digo:");

    pedirString(&(*retorno.descripcion), "\nIngrese descripci¢n:");

    retorno.stock = pedirInt("\nIngrese stock:");

    retorno.precioCosto = pedirFloat("\nIngrese precio de costo:");

    return retorno;
}

void ordenarProductos(eProducto inventario[])
{
    int i;
    int j;
    eProducto aux;

    for(i = 0 ; i < NRO_MAX_PRODUCTOS-1 ; i++)
    {
        for(j = i+1 ; j < NRO_MAX_PRODUCTOS ; j++)
        {
            if(inventario[i].codigo > inventario[j].codigo)
            {
                aux = inventario[i];
                inventario[i] = inventario[j];
                inventario[j] = aux;
            }
        }
    }
}
