#include <stdio.h>
#include <stdlib.h>

#include "validaciones.h"
#include "tipo.h"
#include "bicicleta.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

void ejecutarTareaComplementaria(int opcion, eBici bicisList[100], int sizeBicis, eColor coloresList[5], int sizeColores, float rodados[3], int sizeRodados, eTipo tiposList[4], int sizeTipos, eTrabajo trabajosList[100], int sizeTrabajos, eServicio serviciosList[4], int sizeServicios, eCliente clientesList[5], int sizeClientes);

int main()
{
    eBici bicicletasList[100];
    eTipo tiposList[4];
    eColor coloresList[5];
    eServicio serviciosList[4];
    eTrabajo trabajosList[100];
    eCliente clientesList[5];
    float rodados[4];

    rodados[0] = 20;
    rodados[1] = 26;
    rodados[2] = 27.5;
    rodados[3] = 29;

    tiposList[0] = (eTipo) {1000, "Rutera"};
    tiposList[1] = (eTipo) {1001, "Carrera"};
    tiposList[2] = (eTipo) {1002, "Mountain"};
    tiposList[3] = (eTipo) {1003, "BMX"};

    coloresList[0] = (eColor) {5000, "Gris"};
    coloresList[1] = (eColor) {5001, "Negro"};
    coloresList[2] = (eColor) {5002, "Blanco"};
    coloresList[3] = (eColor) {5003, "Azul"};
    coloresList[4] = (eColor) {5004, "Rojo"};

    serviciosList[0] = (eServicio) {20000, 250, "Limpieza"};
    serviciosList[1] = (eServicio) {20001, 300, "Parche"};
    serviciosList[2] = (eServicio) {20002, 400, "Centrado"};
    serviciosList[3] = (eServicio) {20003, 350, "Cadena"};

    clientesList[0] = (eCliente) {1000, "Nicolas", 'm'};
    clientesList[1] = (eCliente) {1001, "Tamara", 'f'};
    clientesList[2] = (eCliente) {1002, "Gustavo", 'm'};
    clientesList[3] = (eCliente) {1003, "Sergio", 'm'};
    clientesList[4] = (eCliente) {1004, "Micaela", 'f'};

    int sizeBicis = 0;
    int sizeTipos = 4;
    int sizeRodados = 4;
    int sizeColores = 5;
    int sizeServicios = 4;
    int sizeTrabajos = 0;
    int sizeClientes = 5;

    int idTrabajos = 1000;
    int idBicicletas = 10000;

    int opcion = -1;

    while (opcion != 75)
    {
        opcion = pedirOpcion();
        switch(opcion)
        {
            case 65:
                printf("\n Procesando...");
                eBici nuevaBici = pedirNuevaBici(tiposList, sizeTipos, rodados, sizeRodados, coloresList, sizeColores, idBicicletas, clientesList, sizeClientes);
                altaBicicleta(bicicletasList, nuevaBici, sizeBicis);
                sizeBicis++;
                idBicicletas++;
                break;

            case 66:
                if (sizeBicis > 0)
                {
                    printf("\n Procesando...");
                    int idModificar;
                    idModificar = pedirIndexPorIdBici(bicicletasList, sizeBicis, clientesList, sizeClientes);
                    pedirModificacionBici(bicicletasList, sizeBicis, idModificar, tiposList, sizeTipos, rodados, sizeRodados);
                }
                else
                {
                    printf("\nERROR. No hay bicicletas para modificar.");
                }

                break;

            case 67:
                if (sizeBicis > 0)
                {
                    printf("\n Procesando...");
                    int idBaja;
                    idBaja = pedirIndexPorIdBici(bicicletasList, sizeBicis, clientesList, sizeClientes);
                    bajaBicicleta(bicicletasList, idBaja, sizeBicis);
                    sizeBicis--;
                }
                else
                {
                    printf("\nERROR. No hay bicicletas para dar de baja.");
                }

                break;

            case 68:
                listarBicicletas(bicicletasList, sizeBicis, clientesList, sizeClientes);
                break;

            case 69:
                listarTipos(tiposList, sizeTipos);
                break;

            case 70:
                listarColores(coloresList, sizeColores);
                break;

            case 71:
                listarServicios(serviciosList, sizeServicios);
                break;

            case 72:
                printf("Procesando...");
                if (sizeBicis > 0)
                {
                    eTrabajo nuevoTrabajo;
                    nuevoTrabajo = pedirNuevoTrabajo(trabajosList, sizeTrabajos, idTrabajos, bicicletasList, sizeBicis, serviciosList, sizeServicios, clientesList, sizeClientes);
                    altaTrabajo(trabajosList, nuevoTrabajo, sizeTrabajos);
                    sizeTrabajos++;
                    idTrabajos++;
                }
                else
                {
                    printf("\nERROR. No se puede asignar un trabajo si no hay ninguna bicicleta cargada.");
                }
                break;

            case 73:
                listarTrabajos(trabajosList, sizeTrabajos);
                break;
            case 74:
                printf("\nProcesando...");
                int opcionComplementaria;
                opcionComplementaria = pedirOpcionComplementaria();
                ejecutarTareaComplementaria(opcionComplementaria, bicicletasList, sizeBicis, coloresList, sizeColores, rodados, sizeRodados, tiposList, sizeTipos, trabajosList, sizeTrabajos, serviciosList, sizeServicios, clientesList, sizeClientes);

                break;

        }
        printf("\n\n");
        system("pause");
    }
}

void ejecutarTareaComplementaria(int opcion, eBici bicisList[100], int sizeBicis, eColor coloresList[5], int sizeColores, float rodados[3], int sizeRodados, eTipo tiposList[4], int sizeTipos, eTrabajo trabajosList[100], int sizeTrabajos, eServicio serviciosList[4], int sizeServicios, eCliente clientesList[5], int sizeClientes)
{
    switch(opcion)
    {
        if (sizeBicis > 0)
        {
        case 1:
            printf("\nProcesando...");
            int idColor;
            idColor = pedirColor(coloresList, sizeColores);
            listarBicicletasMismoColor(bicisList, sizeBicis, idColor, clientesList, sizeClientes);
            break;

        case 2:
            printf("\nProcesando...");
            int idTipo;
            idTipo = pedirTipo(tiposList, sizeTipos);
            listarBicicletasMismoTipo(bicisList, sizeBicis, idTipo, clientesList, sizeClientes);
            break;

        case 3:
            listarBicicletasMenorRodado(bicisList, sizeBicis, rodados, clientesList, sizeClientes);
            break;

        case 4:
            listarBicicletasSeparadasTipo(bicisList, sizeBicis, clientesList, sizeClientes);
            break;
        case 5:
            printf("\nProcesando...");
            int color;
            int tipo;

            color = pedirColor(coloresList, sizeColores);
            tipo = pedirTipo(tiposList, sizeTipos);
            ContarBicicletasMismoColorYTipo(bicisList, sizeBicis, tipo, color);
            break;
        case 6:
            printf("\nProcesando...");
            int colorMaximoId = obtenerColorMasElegido(bicisList, sizeBicis, coloresList, sizeColores);
            int indexColorMaximo = obtenerColorIndex(sizeColores, colorMaximoId);
            printf("\nEl color mas elegido es: %s", coloresList[indexColorMaximo].nombreColor);
            break;
        case 7:
            printf("\nProcesando...");
            int bici;
            bici = pedirIndexPorIdBici(bicisList, sizeBicis, clientesList, sizeClientes);
            listarTrabajosBici(trabajosList, sizeTrabajos, bici);
            break;
        case 8:
            printf("\nProcesando...");
            int idBici;
            int sumaTotal;
            idBici = pedirIndexPorIdBici(bicisList, sizeBicis, clientesList, sizeClientes);
            sumaTotal = sumaImportes(trabajosList, sizeTrabajos, serviciosList, sizeServicios, idBici);
            printf("\nLa suma total de importes para esa bicicleta es: %d", sumaTotal);
            break;
        case 9:
            printf("\nProcesando...");
            int idServicio;
            idServicio = pedirServicios(serviciosList, sizeServicios);
            mostrarBiciPorServicio(trabajosList, sizeTrabajos, bicisList, sizeBicis, idServicio, clientesList, sizeClientes);
            break;
        case 10:
            printf("\nProcesando...");
            eFecha fechaElegida = pedirFecha();
            listarServiciosPorFecha(trabajosList, sizeTrabajos, fechaElegida, serviciosList, sizeServicios);
            break;
        }
        else
        {
            printf("\nERROR. No hay bicicletas.");
        }
    }
}


