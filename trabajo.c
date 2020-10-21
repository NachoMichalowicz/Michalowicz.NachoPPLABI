#include <stdio.h>
#include <stdlib.h>

#include "trabajo.h"
#include "servicio.h"
#include "bicicleta.h"


void altaTrabajo(eTrabajo *trabajosList, eTrabajo nuevoTrabajo, int index);

void listarTrabajos(eTrabajo trabajosList[100], int size);
void listarTrabajosBici(eTrabajo trabajosList[100], int size, int id);
void listarServiciosPorFecha(eTrabajo trabajosList[100], int size, eFecha fechaElegida, eServicio serviciosList[4], int sizeServicios);
int sumaImportes(eTrabajo trabajosList[100], int sizeTrabajos, eServicio serviciosLista[4], int sizeServicio, int idBici);
void mostrarBiciPorServicio(eTrabajo trabajosList[100], int sizeTrabajo, eBici bicisList[100], int sizeBicis, int idServicio, eCliente clientesList[5], int sizeClientes);


void altaTrabajo(eTrabajo *trabajosList, eTrabajo nuevoTrabajo, int index)
{
    trabajosList[index] = nuevoTrabajo;
}

void listarTrabajos(eTrabajo trabajosList[100], int size)
{
    system("cls");
    if (size > 0)
    {
        printf("------Listado de trabajos------\n");
        for (int i = 0; i < size; i++)
        {
            eTrabajo trabajoActual;
            trabajoActual = trabajosList[i];

            printf("\n| Id de trabajo: %d", trabajoActual.id);
            printf("\n| Fecha del trabajo: %d/%d/%d", trabajoActual.fecha.dia, trabajoActual.fecha.mes, trabajoActual.fecha.anio);
            printf("\n| Id de servicio del trabajo: %d", trabajoActual.idServicio);
            printf("\n| Id de bicicleta del trabajo: %d", trabajoActual.idBicicleta);
            printf("\n----------------------------");
            printf("\n");
        }
    }
    else
    {
        printf("\nNo es posible listar trabajos cuando no hay ninguno!");
    }
}

void listarTrabajosBici(eTrabajo trabajosList[100], int size, int id)
{
    int cantidadTrabajos = 0;
    system("cls");
    if (size > 0)
    {
        printf("------Listado de trabajos------\n");
        for (int i = 0; i < size; i++)
        {
            eTrabajo trabajoActual;
            trabajoActual = trabajosList[i];
            if (trabajoActual.idBicicleta == id)
            {
                printf("\n| Id de trabajo: %d", trabajoActual.id);
                printf("\n| Fecha del trabajo: %d/%d/%d", trabajoActual.fecha.dia, trabajoActual.fecha.mes, trabajoActual.fecha.anio);
                printf("\n| Id de servicio del trabajo: %d", trabajoActual.idServicio);
                printf("\n| Id de bicicleta del trabajo: %d", trabajoActual.idBicicleta);
                printf("\n----------------------------");
                printf("\n");
                cantidadTrabajos++;
            }

        }

        if (cantidadTrabajos == 0)
        {
            printf("\n ----------------------------------");
            printf("\nNo hay trabajos para esa bicicleta.");
        }
    }
    else
    {
        printf("\nNo es posible listar bicicletas por trabajo cuando no hay ninguno!");
    }
}

void listarServiciosPorFecha(eTrabajo trabajosList[100], int size, eFecha fechaElegida, eServicio serviciosList[4], int sizeServicios)
{
    int cantidadTrabajos = 0;
    system("cls");
    if (size > 0)
    {
        printf("------Listado de servicios por fecha------\n");
        for (int i = 0; i < size; i++)
        {
            eTrabajo trabajoActual;
            trabajoActual = trabajosList[i];
            eFecha fechaActual;
            fechaActual = trabajoActual.fecha;

            if (fechaActual.dia == fechaElegida.dia && fechaActual.mes == fechaElegida.mes && fechaActual.anio == fechaElegida.anio)
            {
                int index;
                eServicio servicioActual;

                index = trabajoActual.idServicio;
                index = obtenerServicioIndex(serviciosList, sizeServicios, index);
                servicioActual = serviciosList[index];

                printf("\n| Id de servicio: %d", servicioActual.id);
                printf("\n| Descripcion de servicio: %s", servicioActual.descripcion);
                printf("\n| Precio de servicio: %d$", servicioActual.precio);
                printf("\n ------------------");
                printf("\n");
                cantidadTrabajos++;
            }

        }

        if (cantidadTrabajos == 0)
        {
            printf("\n ----------------------------------");
            printf("\nNo hay servicios para esa fecha.");
        }
    }
    else
    {
        printf("\nNo es posible listar servicios cuando no hay ningun trabajo!");
    }
}

int sumaImportes(eTrabajo trabajosList[100], int sizeTrabajos, eServicio serviciosLista[4], int sizeServicio, int idBici)
{
    int acumuladorImportes = 0;

    if (sizeTrabajos > 0)
    {
        for (int i = 0; i < sizeTrabajos; i++)
        {
            eTrabajo trabajoActual;
            trabajoActual = trabajosList[i];

            if (trabajoActual.idBicicleta == idBici)
            {
                int servicioActual = trabajoActual.idServicio;
                int indexServicio = obtenerIndexPorIdServicio(serviciosLista, sizeServicio, servicioActual);
                int monto = serviciosLista[indexServicio].precio;

                acumuladorImportes = acumuladorImportes + monto;
            }
        }
        return acumuladorImportes;
    }
    else
    {
        printf("\nNo es posible sumar el importe de los trabajos cuando no hay ninguno!");
        return 0;
    }
}

void mostrarBiciPorServicio(eTrabajo trabajosList[100], int sizeTrabajo, eBici bicisList[100], int sizeBicis, int idServicio, eCliente clientesList[5], int sizeClientes)
{
    system("cls");
    printf("\n----Bicicletas a las que se les realizo ese servicio----");
    int cantidadBicis = 0;

    for (int i = 0; i < sizeTrabajo; i++)
    {
        eTrabajo trabajoActual;
        trabajoActual = trabajosList[i];

        if (trabajoActual.idServicio == idServicio)
        {
            int index;
            int biciId;
            biciId = trabajoActual.idBicicleta;

            index = obtenerIndexBiciPorId(bicisList, biciId, sizeBicis);
            eBici biciActual;
            biciActual = bicisList[index];

            int indexClienteActual = obtenerIndexClientePorId(clientesList, biciActual.idCliente, sizeClientes);
            eCliente clienteActual;
            clienteActual = clientesList[indexClienteActual];

            printf("\n------------------------");
            printf("\n| Id de bicicleta: %d", biciActual.id);
            printf("\n| Id de tipo: %d", biciActual.idTipo);
            printf("\n| Id de color: %d", biciActual.idColor);
            printf("\n| Rodado: %.2f", biciActual.rodado);
            printf("\n| Marca: %s", biciActual.marca);
            printf("\n| Nombre del cliente: %s", clienteActual.nombre);
            printf("\n ------------------");
            printf("\n");
            cantidadBicis++;
        }
    }
    if (cantidadBicis == 0)
    {
        printf("\nNo hay bicicletas a las que se les haya hecho dicho servicio.");
    }
}
