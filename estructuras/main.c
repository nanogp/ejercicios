#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "funciones_generales.h"
#include "menus.h"
#include "procesamiento.h"

/*
Crear un lista de productos y mostrarlos-----  función mostrarInventario que reciba el array de productos y llame a mostrarProducto
*/


int main()
{
    eProducto inventario[NRO_MAX_PRODUCTOS] = {};//inicializo con cantidad cero
    const eMenu menuPrincipal={3,{1,2,9},{"1. Alta producto","2. Listar productos", "9. Salir"}};
    int opcion;
    char salirDePrograma = 'N';
    int lugarEnInventario;

    /*
    unProducto.codigo       = 3;
    strcpy(unProducto.descripcion, "adelgamate");
    unProducto.precioCosto  = 35.80;
    unProducto.stock        = 720;
    */
    do
    {
        opcion = pedirOpcion(menuPrincipal);

        switch(opcion)
        {
            case 1:
                lugarEnInventario = buscarLugarLibre(inventario);
                if(lugarEnInventario == -1)
                {
                    printf("\n No se encontr¢ m s lugar para agregar productos al inventario.");
                }
                else
                {
                    inventario[lugarEnInventario] = CrearProducto();
                }
                break;
            case 2:
                mostrarInventario(inventario);
                break;
            case 9:
                salirDePrograma = pedirConfirmacion("Desea salir del programa?");
                break;

        }
    }
    while(salirDePrograma == 'N');

    return 0;
}
