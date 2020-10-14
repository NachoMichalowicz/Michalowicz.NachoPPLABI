#include "tipos.h"

void altaTipo(Tipo *TiposList, int *size, Tipo TipoNuevo, int *id)
{
    int newSize = *size +1;
    TiposList[*size] = TipoNuevo;
    TiposList[*size].id = *id;
    *id = *id +1;

    *size = newSize;
}

int bajaTipo(Tipo *TiposList, int *size, int id)
{
    int index = searchTipoById(TiposList, id, *size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        Tipo TipoVacio;
        TiposList[index] = TipoVacio;

        for (int i = index+1; i < *size; i++)
        {
            Tipo auxTipo;
            auxTipo = TiposList[i-1];

            TiposList[i-1] = TiposList[i];
            TiposList[i] = auxTipo;
        }

        *size = *size -1;
        }
}

int modificarTipo(Tipo *TiposList, int size, Tipo TipoSwap, int id)
{
    int index;
    index = searchTipoById(TiposList, id, size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        TiposList[index] = TipoSwap;
    }
}

int listarTipo(Tipo *TiposList, int size)
{
    if (size > 0)
    {
        printf("\n---TIPOS---\n\n");
        organizarTipos(TiposList, size);
        for (int i = 0; i < size; i++)
        {
            Tipo TipoActual;
            TipoActual = TiposList[i];

            printf("\nId: %d", TipoActual.id);
            printf("\nDescripcion: %s\n", TipoActual.descripcion);
        }
    }
    else
    {
        return -1;
    }

}

void organizarTipos(Tipo *TiposList, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (TiposList[i].id < TiposList[j].id)
            {
                Tipo TipoAux;
                TipoAux = TiposList[i];

                TiposList[i] = TiposList[j];
                TiposList[j] = TipoAux;
            }
        }
    }
}

int searchTipoById(Tipo *TiposList, int id, int size)
{
    for (int i = 0; i < size; i++)
    {
        Tipo TipoActual;
        TipoActual = TiposList[i];

        if (TipoActual.id == id)
        {
            return i;
        }
    }
    return -1;
}
