#include <stdio.h>
#include <stdlib.h>

#include "bicicleta.h"
#include "color.h"
#include "tipo.h"
#include "trabajo.h"
#include "cliente.h"


void altaBicicleta(eBici *bicisList, eBici nuevaBici, int index);
void bajaBicicleta(eBici *bicisList, int index, int size);
void modificarBicicleta(eBici *bicisList, eBici biciModificada, int index);
int obtenerIndexBiciPorId(eBici bicisList[100], int id, int size);

void listarBicicletas(eBici bicisList[100], int size, eCliente clietesList[5], int sizeClientes);
void listarBicicletasSeparadasTipo(eBici bicisList[100], int size, eCliente clientesList[5], int sizeClientes);
void listarBicicletasMismoColor(eBici bicisList[100], int size, int idColor, eCliente clientesList[5], int sizeClientes);
void listarBicicletasMismoTipo(eBici bicisList[100], int size, int idTipo, eCliente clientesList[5], int sizeClientes);
void listarBicicletasMenorRodado(eBici bicisList[100], int size, float rodadosList[4], eCliente clientesList[5], int sizeClientes);
int obtenerColorMasElegido(eBici bicisList[100], int size, eColor colorList[5], int sizeColors);

void ContarBicicletasMismoColorYTipo(eBici bicisList[100], int size, int idTipo, int idColor);
void ordenarBicicletas(eBici *bicisList, int size);
void ordenarBicicletasColor(eBici *bicisList, int size, eColor coloresList[5], int sizeColores);


void altaBicicleta(eBici *bicisList, eBici nuevaBici, int index)
{
    bicisList[index] = nuevaBici;
}

void bajaBicicleta(eBici *bicisList, int id, int size)
{
    int index;
    index = obtenerIndexBiciPorId(bicisList, id, size);

    eBici biciVacia;
    bicisList[index] = biciVacia;

    for (int i = index; i < size; i++)
    {
        bicisList[i] = bicisList[i+1];
    }

}

void modificarBicicleta(eBici *bicisList, eBici biciModificada, int index)
{
    bicisList[index] = biciModificada;
}

int obtenerIndexBiciPorId(eBici bicisList[100], int id, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (bicisList[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void listarBicicletas(eBici bicisList[100], int size, eCliente clientesList[5], int sizeClientes)
{
    ordenarBicicletas(bicisList, size);
    system("cls");
    if (size > 0)
    {
        printf("------Listado de bicicletas------\n");
        for (int i = 0; i < size; i++)
        {
            eBici biciActual;
            biciActual = bicisList[i];
            int idCliente = biciActual.idCliente;
            int indexCliente = obtenerIndexClientePorId(clientesList, idCliente, sizeClientes);

            printf("\n| Id de bicicleta: %d", biciActual.id);
            printf("\n| Id de tipo: %d", biciActual.idTipo);
            printf("\n| Id de color: %d", biciActual.idColor);
            printf("\n| Rodado: %.2f", biciActual.rodado);
            printf("\n| Marca: %s", biciActual.marca);
            printf("\n| Nombre del cliente: %s", clientesList[indexCliente].nombre);
            printf("\n ------------------");
            printf("\n");
        }
    }
    else
    {
        printf("\nNo es posible listar bicicletas cuando no hay ninguna!");
    }

}

void listarBicicletasSeparadasTipo(eBici bicisList[100], int size, eCliente clientesList[5], int sizeClientes)
{
    ordenarBicicletas(bicisList, size);
    system("cls");
    if (size > 0)
    {
        printf("------Listado de bicicletas separadas por tipo------\n");
        for (int i = 0; i < size; i++)
        {
            eBici biciActual;
            biciActual = bicisList[i];
            int idCliente = biciActual.idCliente;
            int indexCliente = obtenerIndexClientePorId(clientesList, idCliente, sizeClientes);

            printf("\n| Id de bicicleta: %d", biciActual.id);
            printf("\n| Id de tipo: %d", biciActual.idTipo);
            printf("\n| Id de color: %d", biciActual.idColor);
            printf("\n| Rodado: %.2f", biciActual.rodado);
            printf("\n| Marca: %s", biciActual.marca);
            printf("\n| Nombre del cliente: %s", clientesList[indexCliente].nombre);
            printf("\n ------------------");
            printf("\n");

            if (biciActual.idTipo != bicisList[i+1].idTipo)
            {
                printf("\n\n|----BARRA SEPARADORA-------");
            }
        }
    }
    else
    {
        printf("\nNo es posible listar bicicletas cuando no hay ninguna!");
    }

}

void listarBicicletasMismoColor(eBici bicisList[100], int size, int idColor, eCliente clientesList[5], int sizeClientes)
{
    ordenarBicicletas(bicisList, size);
    int cantidadBicisMismoColor = 0;

    system("cls");
    if (size > 0)
    {
        printf("------Listado de bicicletas de un mismo color------\n");
        for (int i = 0; i < size; i++)
        {
            eBici biciActual;
            biciActual = bicisList[i];
            if (biciActual.idColor == idColor)
            {
                int indexClienteActual = obtenerIndexClientePorId(clientesList, biciActual.idCliente, sizeClientes);
                eCliente clienteActual;
                clienteActual = clientesList[indexClienteActual];

                printf("\n| Id de bicicleta: %d", biciActual.id);
                printf("\n| Id de tipo: %d", biciActual.idTipo);
                printf("\n| Id de color: %d", biciActual.idColor);
                printf("\n| Rodado: %.2f", biciActual.rodado);
                printf("\n| Marca: %s", biciActual.marca);
                printf("\n| Nombre del cliente: %s", clienteActual.nombre);
                printf("\n ------------------");
                printf("\n");
                cantidadBicisMismoColor++;
            }
        }
        if (cantidadBicisMismoColor == 0)
        {
            printf("\n -------------------------------------");
            printf("\n|No hay bicicletas de ese mismo color.");
        }
    }
    else
    {
        printf("\nNo es posible listar bicicletas cuando no hay ninguna!");
    }
}

void listarBicicletasMismoTipo(eBici bicisList[100], int size, int idTipo, eCliente clientesList[5], int sizeClientes)
{
    ordenarBicicletas(bicisList, size);
    int cantidadBicisMismoTipo = 0;

    system("cls");
    if (size > 0)
    {
        printf("------Listado de bicicletas de un mismo tipo------\n");
        for (int i = 0; i < size; i++)
        {
            eBici biciActual;
            biciActual = bicisList[i];
            if (biciActual.idTipo == idTipo)
            {
                int indexClienteActual = obtenerIndexClientePorId(clientesList, biciActual.idCliente, sizeClientes);
                eCliente clienteActual;
                clienteActual = clientesList[indexClienteActual];

                printf("\n| Id de bicicleta: %d", biciActual.id);
                printf("\n| Id de tipo: %d", biciActual.idTipo);
                printf("\n| Id de color: %d", biciActual.idColor);
                printf("\n| Rodado: %.2f", biciActual.rodado);
                printf("\n| Marca: %s", biciActual.marca);
                printf("\n| Nombre del cliente: %s", clienteActual.nombre);
                printf("\n ------------------");
                printf("\n");
                cantidadBicisMismoTipo++;
            }
        }
        if (cantidadBicisMismoTipo == 0)
        {
            printf("\n -------------------------------------");
            printf("\n|No hay bicicletas de ese mismo tipo.");
        }
    }
    else
    {
        printf("\nNo es posible listar bicicletas cuando no hay ninguna!");
    }
}

void listarBicicletasMenorRodado(eBici bicisList[100], int size, float rodadosList[4], eCliente clientesList[5], int sizeClientes)
{
    ordenarBicicletas(bicisList, size);
    float rodadoMin = rodadosList[3];

    system("cls");
    if (size > 0)
    {
        printf("------Listado de bicicletas de menor rodado------\n");

        for (int i = 0; i < size; i++)
        {
            eBici biciActual;
            biciActual = bicisList[i];
            if (biciActual.rodado < rodadoMin)
            {
                rodadoMin = biciActual.rodado;
            }
        }

        for (int i = 0; i < size; i++)
        {
            eBici biciActual;
            biciActual = bicisList[i];

            if (biciActual.rodado == rodadoMin)
            {
                int indexClienteActual = obtenerIndexClientePorId(clientesList, biciActual.idCliente, sizeClientes);
                eCliente clienteActual;
                clienteActual = clientesList[indexClienteActual];

                printf("\n| Id de bicicleta: %d", biciActual.id);
                printf("\n| Id de tipo: %d", biciActual.idTipo);
                printf("\n| Id de color: %d", biciActual.idColor);
                printf("\n| Rodado: %.2f", biciActual.rodado);
                printf("\n| Marca: %s", biciActual.marca);
                printf("\n| Nombre del cliente: %s", clienteActual.nombre);
                printf("\n ------------------");
                printf("\n");
            }
        }
    }
    else
    {
        printf("\nNo es posible listar bicicletas cuando no hay ninguna!");
    }
}

int obtenerColorMasElegido(eBici bicisList[100], int size, eColor colorList[5], int sizeColors)
{
    ordenarBicicletasColor(bicisList, size, colorList, sizeColors);
    if (size > 0)
    {
        int idColorMaximo;
        int idColorActual = bicisList[0].idColor;
        int contadorColorActual = 0;
        int contadorColorMaximo = 0;

        for (int i = 0; i < size; i++)
        {
            if (idColorActual != bicisList[i].idColor)
            {
                if (contadorColorActual > contadorColorMaximo)
                {
                    contadorColorMaximo = contadorColorActual;
                    idColorMaximo = idColorActual;
                }

                idColorActual = bicisList[i].idColor;
                contadorColorActual = 1;
            }
            else
            {
                contadorColorActual++;
            }
        }

        return idColorMaximo;
    }
    else
    {
        printf("\nNo es posible ponderar colores cuando no hay ninguna bicicleta!");
    }
    return 0;
}

void ContarBicicletasMismoColorYTipo(eBici bicisList[100], int size, int idTipo, int idColor)
{
    int cantidadBicisMismoTipoyColor = 0;

    system("cls");
    if (size > 0)
    {

        for (int i = 0; i < size; i++)
        {
            eBici biciActual;
            biciActual = bicisList[i];
            if (biciActual.idTipo == idTipo && biciActual.idColor == idColor)
            {
                cantidadBicisMismoTipoyColor++;
            }
        }
        printf("\n -------------------------------------");
        if (cantidadBicisMismoTipoyColor == 0)
        {
            printf("\n|No hay bicicletas de ese mismo tipo y color.");
        }
        else
        {
            printf("\nCantidad de bicicletas del mismo tipo y color: %d", cantidadBicisMismoTipoyColor);
        }
    }
    else
    {
        printf("\nNo es posible listar bicicletas cuando no hay ninguna!");
    }
}

void ordenarBicicletas(eBici *bicisList, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (bicisList[i].idTipo > bicisList[j].idTipo)
            {
                eBici aux;
                aux = bicisList[i];
                bicisList[i] = bicisList[j];
                bicisList[j] = aux;
            }
            else
            {
                if (bicisList[i].idTipo == bicisList[j].idTipo)
                {
                    if (bicisList[i].rodado > bicisList[j].rodado)
                    {
                        eBici aux;
                        aux = bicisList[i];
                        bicisList[i] = bicisList[j];
                        bicisList[j] = aux;
                    }
                }
            }
        }
    }
}

void ordenarBicicletasColor(eBici *bicisList, int size, eColor coloresList[5], int sizeColores)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (bicisList[i].idColor > bicisList[j].idColor)
            {
                eBici aux;
                aux = bicisList[i];
                bicisList[i] = bicisList[j];
                bicisList[j] = aux;
            }
        }
    }
}
