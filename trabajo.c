#include "trabajo.h"

void altaTrabajo(Trabajo *TrabajosList, int *size, Trabajo TrabajoNuevo, int *id)
{
    int newSize = *size +1;
    TrabajosList[*size] = TrabajoNuevo;
    TrabajosList[*size].id = *id;
    *id = *id +1;

    *size = newSize;
}

int bajaTrabajo(Trabajo *TrabajosList, int *size, int id)
{
    int index = searchTrabajoById(TrabajosList, id, *size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        Trabajo TrabajoVacio;
        TrabajosList[index] = TrabajoVacio;

        for (int i = index+1; i < *size; i++)
        {
            Trabajo auxTrabajo;
            auxTrabajo = TrabajosList[i-1];

            TrabajosList[i-1] = TrabajosList[i];
            TrabajosList[i] = auxTrabajo;
        }

        *size = *size -1;
        }
}

int modificarTrabajo(Trabajo *TrabajosList, int size, Trabajo TrabajoSwap, int id)
{
    int index;
    index = searchTrabajoById(TrabajosList, id, size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        TrabajosList[index] = TrabajoSwap;
    }
}

int listarTrabajo(Trabajo *TrabajosList, int size)
{
    if (size > 0)
    {
        printf("\n---TRABAJOS---\n\n");
        organizarTrabajos(TrabajosList, size);
        for (int i = 0; i < size; i++)
        {
            Trabajo TrabajoActual;
            TrabajoActual = TrabajosList[i];

            printf("\nId: %d", TrabajoActual.id);
            printf("\nId de bicicleta: %d", TrabajoActual.idBicicleta);
            printf("\nId del servicio: %d", TrabajoActual.idServicio);
            printf("\nFecha del trabajo: %d/%d/%d", TrabajoActual.fechaTrabajo.dia, TrabajoActual.fechaTrabajo.mes, TrabajoActual.fechaTrabajo.anio);
        }
    }
    else
    {
        return -1;
    }

}

void organizarTrabajos(Trabajo *TrabajosList, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (TrabajosList[i].id < TrabajosList[j].id)
            {
                Trabajo TrabajoAux;
                TrabajoAux = TrabajosList[i];

                TrabajosList[i] = TrabajosList[j];
                TrabajosList[j] = TrabajoAux;
            }
        }
    }
}

int searchTrabajoById(Trabajo *TrabajosList, int id, int size)
{
    for (int i = 0; i < size; i++)
    {
        Trabajo TrabajoActual;
        TrabajoActual = TrabajosList[i];

        if (TrabajoActual.id == id)
        {
            return i;
        }
    }
    printf("\nNo existe Trabajo con dicha ID");
    return -1;
}
