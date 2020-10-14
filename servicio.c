#include "servicio.h"

void altaServicio(Servicio *serviciosList, int *size, Servicio servicioNuevo, int *id)
{
    int newSize = *size +1;
    serviciosList[*size] = servicioNuevo;
    serviciosList[*size].id = *id;
    *id = *id +1;

    *size = newSize;
}

int bajaServicio(Servicio *serviciosList, int *size, int id)
{
    int index = searchServiceById(serviciosList, id, *size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        Servicio servicioVacio;
        serviciosList[index] = servicioVacio;

        for (int i = index+1; i < *size; i++)
        {
            Servicio auxServicio;
            auxServicio = serviciosList[i-1];

            serviciosList[i-1] = serviciosList[i];
            serviciosList[i] = auxServicio;
        }

        *size = *size -1;
        }
}

int modificarServicio(Servicio *serviciosList, int size, Servicio servicioSwap, int id)
{
    int index;
    index = searchServiceById(serviciosList, id, size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        serviciosList[index] = servicioSwap;
    }
}

int listarServicios(Servicio *serviciosList, int size)
{
    if (size > 0)
    {
        printf("\n---SERVICIOS---\n\n");
        organizarServicios(serviciosList, size);
        for (int i = 0; i < size; i++)
        {
            Servicio servicioActual;
            servicioActual = serviciosList[i];

            printf("\nId: %d", servicioActual.id);
            printf("\nPrecio: %d", servicioActual.precio);
            printf("\nDescripcion: %s\n", servicioActual.descripcion);
        }
    }
    else
    {
        return -1;
    }

}

void organizarServicios(Servicio *serviciosList, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (serviciosList[i].id < serviciosList[j].id)
            {
                Servicio servicioAux;
                servicioAux = serviciosList[i];

                serviciosList[i] = serviciosList[j];
                serviciosList[j] = servicioAux;
            }
        }
    }
}

int searchServiceById(Servicio *serviciosList, int id, int size)
{
    for (int i = 0; i < size; i++)
    {
        Servicio servicioActual;
        servicioActual = serviciosList[i];

        if (servicioActual.id == id)
        {
            return i;
        }
    }
    printf("\nNo existe servicio con dicha ID");
    return -1;
}
