#include "cliente.h"


void listarClientes(eCliente clientesList[5], int sizeClientes)
{
    printf("\n------------Listado de clientes----------------");

    for (int i = 0; i < sizeClientes; i++)
    {
        eCliente clienteActual;
        clienteActual = clientesList[i];

        printf("\n| Id de cliente: %d", clienteActual.id);
        printf("\n| Nombre de cliente: %s", clienteActual.nombre);
        printf("\n| Sexo de cliente: %c", clienteActual.sexo);
        printf("\n----------------------------");
        printf("\n");
    }
}

int obtenerIndexClientePorId(eCliente clientesList[5], int id, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (clientesList[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
