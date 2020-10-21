#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

int pedirOpcion();
void printMenu();
void printMenuComplementario();

eBici pedirNuevaBici(eTipo tiposList[4], int sizeTipos, float rodadosList[3], int sizeRodados, eColor coloresList[5], int sizeColor, int idBici, eCliente clientesList[5], int sizeClientes);
eTrabajo pedirNuevoTrabajo(eTrabajo trabajoList[100], int sizeTrabajo, int idTrabajo, eBici bicisList[100], int sizeBicis, eServicio serviciosList[4], int sizeServicios, eCliente clientesList[5], int sizeClientes);
eFecha pedirFecha();
void pedirModificacionBici(eBici *bicisList, int size, int index, eTipo tiposList[3], int sizeTipos, float rodadosList[3], int sizeRodados);
int pedirIndexPorIdBici(eBici bicisList[100], int size, eCliente clientesList[5], int sizeClientes);
int pedirServicios(eServicio serviciosList[4], int size);

int pedirTipo(eTipo tiposList[4], int size);
int pedirColor(eColor coloresList[4], int sizeColor);
float pedirRodado(float rodadosList[3], int sizeRodados);
int validarRodado(float rodado, float rodadosList[3], int sizeRodados);

void pedirCadenaCaracteres(char *cadena);
char pedirCaracter();
int pedirInt();
float pedirFloat();


int pedirOpcion()
{
    char opcion;

    printMenu();
    printf("\nIngrese una opcion: ");
    opcion = toupper(pedirCaracter());

    while (opcion < 65 || opcion > 75)
    {
        printf("\nERROR. Ingrese una opcion valida: ");
        opcion = toupper(pedirCaracter());
    }

    return opcion;
}

int pedirOpcionComplementaria()
{
    int opcion;

    printMenuComplementario();
    printf("\nIngrese una opcion: ");
    opcion = pedirInt();

    while (opcion < 1 || opcion > 11)
    {
       printf("\nERROR. Ingrese una opcion valida: ");
       opcion = pedirInt();
    }

    return opcion;
}

void printMenu()
{
    system("cls");
    printf("\n----Menu de opciones----");
    printf("\n| A: Alta bicicleta     |");
    printf("\n| B: Modificar bicicleta|");
    printf("\n| C: Baja bicicleta     |");
    printf("\n| D: Listar bicicletas  |");
    printf("\n| E: Listar tipos       |");
    printf("\n| F: Listar colores     |");
    printf("\n| G: Listar servicios   |");
    printf("\n| H: Alta trabajo       |");
    printf("\n| I: Listar trabajos    |");
    printf("\n| J: Menu complementario|");
    printf("\n| K: Salir              |");
    printf("\n------------------------");
}

void printMenuComplementario()
{
    system("cls");
    printf("\n-------------------Menu complementario-------------------");
    printf("\n| 1: Mostrar las bicicletas de un mismo color.            |");
    printf("\n| 2: Mostrar bicicletas de un tipo seleccionado.          |");
    printf("\n| 3: Informar las bicicletas de menor rodado.             |");
    printf("\n| 4: Informar las bicicletas separadas por tipo.          |");
    printf("\n| 5: Cuantas bicicletas hay de determinado tipo y color.  |");
    printf("\n| 6: Colores mas elegidos                                 |");
    printf("\n| 7: Trabajos hechos a una bicicleta especifica.          |");
    printf("\n| 8: Suma importes de determinada bicicleta.              |");
    printf("\n| 9: Listar bicicletas por servicio.                      |");
    printf("\n| 10: Servicios en una fecha especifica.                  |");
    printf("\n| 11: Volver al menu principal.                           |");
    printf("\n---------------------------------------------------------");
}

eBici pedirNuevaBici(eTipo tiposList[4], int sizeTipos, float rodadosList[3], int sizeRodados, eColor coloresList[5], int sizeColor, int idBici, eCliente clientesList[5], int sizeClientes)
{
    eBici nuevaBici;

    char marca[20];
    int tipoId;
    int colorId;
    int clienteId;
    float rodado;

    system("cls");
    printf("\n -----Dando de alta a una bicicleta-----");
    printf("\n|Ingrese la marca de dicha bicicleta:  ");
    pedirCadenaCaracteres(marca);

    system("cls");
    printf("\n ---------------------------------------");
    printf("\n|Ingrese el id del tipo de la bicicleta:  ");
    tipoId = pedirTipo(tiposList, sizeTipos);

    system("cls");
    printf("\n ---------------------------------------");
    printf("\n|Ingrese el id del color de la bicicleta:  ");
    colorId = pedirColor(coloresList, sizeColor);

    system("cls");
    printf("\n ---------------------------------------");
    printf("\n|Ingrese el id del cliente de la bicicleta:  ");
    clienteId = pedirCliente(clientesList, sizeClientes);

    system("cls");
    printf("\n ---------------------------------------\n");
    rodado = pedirRodado(rodadosList, sizeRodados);

    strcpy(nuevaBici.marca, marca);
    nuevaBici.idTipo = tipoId;
    nuevaBici.idColor = colorId;
    nuevaBici.rodado = rodado;
    nuevaBici.id = idBici;
    nuevaBici.idCliente = clienteId;

    return nuevaBici;

}

eTrabajo pedirNuevoTrabajo(eTrabajo trabajoList[100], int sizeTrabajo, int idTrabajo, eBici bicisList[100], int sizeBicis, eServicio serviciosList[4], int sizeServicios, eCliente clientesList[5], int sizeClientes)
{
    eTrabajo nuevoTrabajo;
    eFecha fecha;

    int bicicleta;
    int servicio;

    system("cls");
    printf("\n -----Dando de alta a un trabajo-----");
    bicicleta = pedirIndexPorIdBici(bicisList, sizeBicis, clientesList, sizeClientes);

    system("cls");
    servicio = pedirServicios(serviciosList, sizeServicios);

    system("cls");
    fecha = pedirFecha();

    nuevoTrabajo.fecha = fecha;
    nuevoTrabajo.id = idTrabajo;
    nuevoTrabajo.idBicicleta = bicicleta;
    nuevoTrabajo.idServicio = servicio;

    return nuevoTrabajo;
}

eFecha pedirFecha()
{
    eFecha fechaActual;

    int dia;
    int mes;
    int anio;


    printf("\n-----Asignando una fecha-----");
    printf("\nIngrese un dia: ");
    dia = pedirInt();

    while (dia > 30 || dia < 1)
    {
        printf("\nERROR. Ingrese un dia valido: ");
        dia = pedirInt();
    }
    system("cls");
    printf("\nIngrese un mes: ");
    mes = pedirInt();

    while (mes > 12 || mes < 1)
    {
        printf("\nERROR. Ingrese un mes valido: ");
        mes = pedirInt();
    }

    system("cls");
    printf("\nIngrese un anio: ");
    anio = pedirInt();

    while (anio > 3000 || anio < 2000)
    {
        printf("\nERROR. Ingrese un anio valido (del 2000 a 3000): ");
        anio = pedirInt();
    }

    fechaActual.anio = anio;
    fechaActual.dia = dia;
    fechaActual.mes = mes;

    return fechaActual;
}

void pedirModificacionBici(eBici *bicisList, int size, int index, eTipo tiposList[4], int sizeTipos, float rodadosList[3], int sizeRodados)
{
    int opcion;
    int tipo;
    int indexBici;
    float rodado;

    eBici biciActual;

    indexBici = obtenerIndexBiciPorId(bicisList, index, size);
    biciActual = bicisList[indexBici];
    tipo = biciActual.idTipo;
    rodado = biciActual.rodado;

    system("cls");
    printf("\n -----Modificando una bicicleta-----");
    printf("\n|Ingrese 1 para modificar el rodado (%.2f)", biciActual.rodado);
    printf("\n|Ingrese 2 para modificar el tipo   (%d)", biciActual.idTipo);
    printf("\n Opcion: ");
    opcion = pedirInt();

    while (opcion > 2 || opcion < 1)
    {
        printf("\nERROR. Ingese una opcion valida: ");
        opcion = pedirInt();
    }

    switch(opcion)
    {
        case 1:
           system("cls");
           printf("\n -----Modificando rodado-----\n");
           rodado = pedirRodado(rodadosList, sizeRodados);
           break;

        case 2:
            system("cls");
            printf("\n -----Modificando tipo-----\n");
            tipo = pedirTipo(tiposList, sizeTipos);
            break;
    }

    biciActual.idTipo = tipo;
    biciActual.rodado = rodado;
    modificarBicicleta(bicisList, biciActual, indexBici);
}

int pedirIndexPorIdBici(eBici bicisList[100], int size, eCliente clientesList[5], int sizeClientes)
{
    int num;
    int indexBici;
    listarBicicletas(bicisList, size, clientesList, sizeClientes);

    printf("\n ---------------------------------------");
    printf("\n|Ingrese el id de la bicicleta:  ");

    num = pedirInt();
    indexBici = obtenerIndexBiciPorId(bicisList, num, size);

    while(indexBici == -1)
    {
        printf("\nERROR. Ingrese un id de bicicleta valido:");
        num = pedirInt();
        indexBici = obtenerIndexBiciPorId(bicisList, num, size);
    }

    return num;
}

int pedirServicios(eServicio serviciosList[4], int size)
{
    int id;
    int indexServicio;
    listarServicios(serviciosList, size);

    printf("\n ---------------------------------------");
    printf("\n|Ingrese el id del servicio:  ");

    id = pedirInt();
    indexServicio = obtenerServicioIndex(serviciosList, size, id);

    while (indexServicio == -1)
    {
        printf("\nERROR. Ingrese un id valido:  ");
        id = pedirInt();
        indexServicio = obtenerServicioIndex(serviciosList, size, id);
    }

    return id;
}

int pedirTipo(eTipo tiposList[3], int size)
{
    int tipo;
    int indexTipo;

    listarTipos(tiposList, size);

    printf("\nIngrese un tipo por id: ");
    tipo = pedirInt();
    indexTipo = obtenerTipoIndex(tiposList, size, tipo);

    while (indexTipo == -1)
    {
        printf("\nERROR. Ingrese un tipo por id valido: ");
        tipo = pedirInt();
        indexTipo = obtenerTipoIndex(tiposList, size, tipo);
    }

    return tipo;
}

int pedirColor(eColor coloresList[5], int sizeColor)
{
    int indexColor;
    int id;
    listarColores(coloresList, sizeColor);

    printf("\nIngrese un color por id: ");
    id = pedirInt();
    indexColor = obtenerColorIndex(sizeColor, id);

    while (indexColor == -1)
    {
        printf("\nERROR. Ingrese un color por id valido: ");
        id = pedirInt();
        indexColor = obtenerColorIndex(sizeColor, id);
    }

    return id;
}

int pedirCliente(eCliente clienteList[5], int sizeCliente)
{
    int indexCliente;
    int id;
    listarClientes(clienteList, sizeCliente);

    printf("\nIngrese un cliente por id: ");
    id = pedirInt();
    indexCliente = obtenerIndexClientePorId(clienteList, id, sizeCliente);

    while (indexCliente == -1)
    {
        printf("\nERROR. Ingrese un cliente por id valido: ");
        id = pedirInt();
        indexCliente = obtenerIndexClientePorId(clienteList, id, sizeCliente);
    }
    return id;
}

float pedirRodado(float rodadosList[3], int sizeRodados)
{
    float rodado;
    int validacionRodado;

    printf("\n---Categoria de rodados---\n");
    for (int i = 0; i < sizeRodados; i++)
    {
        printf("\nRodado numero %d:%.2f", i, rodadosList[i]);
        printf("\n----------------------");
    }
    printf("\n\nIngrese un rodado: ");
    rodado = pedirFloat();
    validacionRodado = validarRodado(rodado, rodadosList, sizeRodados);

    while (validacionRodado == -1)
    {
        printf("\nERROR. Ingrese un rodado valido: ");
        rodado = pedirFloat();
        validacionRodado = validarRodado(rodado, rodadosList, sizeRodados);
    }

    return rodado;
}

int validarRodado(float rodado, float rodadosList[3], int sizeRodados)
{
    for (int i = 0; i < sizeRodados; i++)
    {
        if (rodadosList[i] == rodado)
        {
            return 0;
        }
    }
    return -1;
}

void pedirCadenaCaracteres(char *cadena)
{
    char cadenaCaracteres[20];
    gets(cadenaCaracteres);
    fflush(stdin);
    strcpy(cadena, cadenaCaracteres);

}

char pedirCaracter()
{
    char caracter;
    scanf("%c", &caracter);
    fflush(stdin);

    return caracter;
}

int pedirInt()
{
    int num;
    scanf("%d", &num);
    fflush(stdin);

    return num;
}

float pedirFloat()
{
    float num;
    scanf("%f", &num);
    fflush(stdin);

    return num;
}
