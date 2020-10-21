#include <stdio.h>
#include <stdlib.h>
#include "color.h"

void listarColores(eColor coloresList[5], int size);
int obtenerColorIndex(int size, int id);


void listarColores(eColor coloresList[5], int size)
{
    system("cls");
    if (size > 0)
    {
        printf("------Listado de colores------\n");
        for (int i = 0; i < size; i++)
        {
            eColor colorActual;
            colorActual = coloresList[i];

            printf("\n| Id de color: %d", colorActual.id);
            printf("\n| Nombre del color: %s", colorActual.nombreColor);
            printf("\n ------------------");
            printf("\n");
        }
    }
    else
    {
        printf("\nNo es posible listar colores cuando no hay ninguno!");
    }

}

int obtenerColorIndex(int size, int id)
{
    int index;
    index = id - 5000;

    if (index > size-1 || index < 0)
    {
        return -1;
    }
    else
    {
        return index;
    }

}
