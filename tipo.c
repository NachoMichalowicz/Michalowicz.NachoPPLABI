#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"

void listarTipos(eTipo tiposList[4], int size);
int obtenerTipoIndex(eTipo tiposList[4], int size, int id);


void listarTipos(eTipo tiposList[4], int size)
{
    system("cls");
    if (size > 0)
    {
        printf("------Listado de tipos------\n");
        for (int i = 0; i < size; i++)
        {
            eTipo tipoActual;
            tipoActual = tiposList[i];

            printf("\n| Id de tipo: %d", tipoActual.id);
            printf("\n| Descripcion de tipo: %s", tipoActual.descripcion);
            printf("\n ------------------");
            printf("\n");
        }
    }
    else
    {
        printf("\nNo es posible listar tipos cuando no hay ninguno!");
    }
}

int obtenerTipoIndex(eTipo tiposList[4], int size, int id)
{
    int index;
    index = id - 1000;

    if (index > size-1 || index < 0)
    {
        return -1;
    }
    else
    {
        return index;
    }

}
