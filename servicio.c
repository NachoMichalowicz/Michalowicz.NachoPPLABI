#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"


void listarServicios(eServicio serviciosList[4], int size);
int obtenerServicioIndex(eServicio serviciosList[4], int size, int id);

void listarServicios(eServicio serviciosList[4], int size)
{
    system("cls");
    if (size > 0)
    {
        printf("------Listado de servicios------\n");
        for (int i = 0; i < size; i++)
        {
            eServicio servicioActual;
            servicioActual = serviciosList[i];

            printf("\n| Id de servicio: %d", servicioActual.id);
            printf("\n| Descripcion de servicio: %s", servicioActual.descripcion);
            printf("\n| Precio de servicio: %d$", servicioActual.precio);
            printf("\n ------------------");
            printf("\n");
        }
    }
    else
    {
        printf("\nNo es posible listar servicios cuando no hay ninguno!");
    }
}

int obtenerServicioIndex(eServicio serviciosList[4], int size, int id)
{
    int index;
    index = id - 20000;

    if (index > size-1 || index < 0)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

int obtenerIndexPorIdServicio(eServicio serviciosList[4], int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        eServicio servicioActual;
        servicioActual = serviciosList[i];

        if (servicioActual.id == id)
        {
            return i;
        }
    }
    return 0;
}
