#include "color.h"

void altaColor(Color *ColorsList, int *size, Color ColorNuevo, int *id)
{
    int newSize = *size +1;
    ColorsList[*size] = ColorNuevo;
    ColorsList[*size].id = *id;
    *id = *id +1;

    *size = newSize;
}

int bajaColor(Color *ColorsList, int *size, int id)
{
    int index = searchColorById(ColorsList, id, *size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        Color ColorVacio;
        ColorsList[index] = ColorVacio;

        for (int i = index+1; i < *size; i++)
        {
            Color auxColor;
            auxColor = ColorsList[i-1];

            ColorsList[i-1] = ColorsList[i];
            ColorsList[i] = auxColor;
        }

        *size = *size -1;
        }
}

int modificarColor(Color *ColorsList, int size, Color ColorSwap, int id)
{
    int index;
    index = searchColorById(ColorsList, id, size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        ColorsList[index] = ColorSwap;
    }
}

int listarColor(Color *ColorsList, int size)
{
    if (size > 0)
    {
        printf("\n---COLORES---\n\n");
        organizarColors(ColorsList, size);
        for (int i = 0; i < size; i++)
        {
            Color ColorActual;
            ColorActual = ColorsList[i];

            printf("\nId: %d", ColorActual.id);
            printf("\nNombre del color: %s\n", ColorActual.nombre);
        }
    }
    else
    {
        return -1;
    }

}

void organizarColors(Color *ColorsList, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (ColorsList[i].id < ColorsList[j].id)
            {
                Color ColorAux;
                ColorAux = ColorsList[i];

                ColorsList[i] = ColorsList[j];
                ColorsList[j] = ColorAux;
            }
        }
    }
}

int searchColorById(Color *ColorsList, int id, int size)
{
    for (int i = 0; i < size; i++)
    {
        Color ColorActual;
        ColorActual = ColorsList[i];

        if (ColorActual.id == id)
        {
            return i;
        }
    }
    return -1;
}
