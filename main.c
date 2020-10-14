#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "tipos.h"
#include "color.h"
#include "trabajo.h"
#include "servicio.h"
#include "bici.h"

float inputRodado(float rodadosList[3], int size); //para que el compilador reconozca que devuelve un float

void hardcodearTipos(Tipo *tiposList, int *sizeTipos);
void hardcodearColores(Color *coloresList, int *sizeColores);
void hardcodearServicios(Servicio *serviciosList, int *sizeServicio);
void mostrarMenu();
void DarAltaBici(Bici *bicisLista, int *bicisSize, Tipo *tiposLista, int *tiposSize, Color *coloresLista, int *coloresSize, float rodados[3], int rodadosSize, int *idBicicleta);

int main()
{
    float rodados[3] = {20, 26, 27.5, 29};
    int sizeRodados = 3;

    Tipo tiposList[4];
    int sizeTipos = 0;

    Color coloresList[5];
    int sizeColores = 0;

    Servicio serviciosList[4];
    int sizeServicios = 0;

    Bici bicisList[100];
    int sizeBicis = 0;
    int idBicicleta = 100;

    Trabajo trabajosList[100];
    int sizeTrabajos = 0;
    int idTrabajo = 100;

    hardcodearTipos(&tiposList,&sizeTipos);
    hardcodearColores(&coloresList, &sizeColores);
    hardcodearServicios(&serviciosList, &sizeServicios);

    int opcion = -1;

    while (opcion != 9)
    {
        mostrarMenu();
        opcion = menuIndex();

        switch (opcion)
        {
            case 0:
                DarAltaBici(&bicisList, &sizeBicis, &tiposList, &sizeTipos, &coloresList, &sizeColores, rodados, sizeRodados, &idBicicleta);
                break;
            case 1:
                if (sizeBicis > 0)
                {
                    DarModificarBici(&bicisList, &sizeBicis, &tiposList, &sizeTipos, &coloresList, &sizeColores, rodados, sizeRodados, &idBicicleta);
                }
                break;
            case 2:
                if (sizeBicis > 0)
                {
                    DarBajaBici(&bicisList, &sizeBicis, &tiposList, &sizeTipos, &coloresList, &sizeColores, rodados, sizeRodados, &idBicicleta);
                }
                break;
            case 3:
                listarBici(&bicisList, sizeBicis, &tiposList, &coloresList, sizeTipos, sizeColores);
                system("pause");
                break;
            case 4:
                listarTipo(&tiposList, sizeTipos);
                system("pause");
                break;
            case 5:
                listarColor(&coloresList, sizeColores);
                system("pause");
                break;
            case 6:
                listarServicios(&serviciosList, sizeServicios);
                system("pause");
                break;
            case 8:
                listarTrabajo(&trabajosList, sizeTrabajos);
                system("pause");
                break;
        }
    }
}

void hardcodearTipos(Tipo *tiposList, int *sizeTipos)
{
    int idTipo = 1000;

    Tipo Rutera;
    strcpy(Rutera.descripcion, "Rutera");
    altaTipo(tiposList, sizeTipos, Rutera, &idTipo);

    Tipo Carrera;
    strcpy(Carrera.descripcion, "Carrera");
    altaTipo(tiposList, sizeTipos, Carrera, &idTipo);

    Tipo Mountain;
    strcpy(Mountain.descripcion, "Mountain");
    altaTipo(tiposList, sizeTipos, Mountain, &idTipo);

    Tipo BMX;
    strcpy(BMX.descripcion, "BMX");
    altaTipo(tiposList, sizeTipos, BMX, &idTipo);

}

void hardcodearColores(Color *coloresList, int *sizeColores)
{
    int idColor = 5000;

    Color Gris;
    strcpy(Gris.nombre, "Gris");
    altaColor(coloresList, sizeColores, Gris, &idColor);

    Color Negro;
    strcpy(Negro.nombre, "Negro");
    altaColor(coloresList, sizeColores, Negro, &idColor);

    Color Blanco;
    strcpy(Blanco.nombre, "Blanco");
    altaColor(coloresList, sizeColores, Blanco, &idColor);

    Color Azul;
    strcpy(Azul.nombre, "Azul");
    altaColor(coloresList, sizeColores, Azul, &idColor);

    Color Rojo;
    strcpy(Rojo.nombre, "Rojo");
    altaColor(coloresList, sizeColores, Rojo, &idColor);
}

void hardcodearServicios(Servicio *serviciosList, int *sizeServicio)
{

    int idServicio = 20000;

    Servicio Limpieza;
    Limpieza.precio = 250;
    strcpy(Limpieza.descripcion, "Limpieza");
    altaServicio(serviciosList, sizeServicio, Limpieza, &idServicio);

    Servicio Parche;
    Parche.precio = 300;
    strcpy(Parche.descripcion, "Parche");
    altaServicio(serviciosList, sizeServicio, Parche, &idServicio);

    Servicio Centrado;
    Centrado.precio = 400;
    strcpy(Centrado.descripcion, "Centrado");
    altaServicio(serviciosList, sizeServicio, Centrado, &idServicio);

    Servicio Cadena;
    Cadena.precio = 350;
    strcpy(Centrado.descripcion, "Cadena");
    altaServicio(serviciosList, sizeServicio, Cadena, &idServicio);
}

void mostrarMenu()
{
    system("cls");
    printf("\n --------------Menu de opciones--------------");
    printf("\n|A: Dar de alta una nueva bicicleta          |");
    printf("\n|B: Modificar una bicicleta                  |");
    printf("\n|C: Dar de baja una bicicleta                |");
    printf("\n|D: Listar las bicicletas                    |");
    printf("\n|E: Listar los tipos                         |");
    printf("\n|F: Listar los colores                       |");
    printf("\n|G: Listar los servicios                     |");
    printf("\n|H: Dar de alta un nuevo trabajo             |");
    printf("\n|I: Listar los trabajos                      |");
    printf("\n|J: Salir del programa                       |");
    printf("\n --------------------------------------------");
    printf("\n");
}

void DarAltaBici(Bici *bicisLista, int *bicisSize, Tipo *tiposLista, int *tiposSize, Color *coloresLista, int *coloresSize, float rodados[3], int rodadosSize, int *idBicicleta)
{
    Bici biciNueva;
    int idTipo;
    int idColor;
    float rodado;
    char marca[21];

    printf("\n --------------Dando de alta a una bici--------------");
    idTipo = inputIdTipo(tiposLista, *tiposSize);
    system("cls");

    idColor = inputIdColor(coloresLista, *coloresSize);
    system("cls");

    rodado = inputRodado(rodados, rodadosSize);
    system("cls");

    inputMarca(&marca);

    biciNueva.idColor = idColor;
    biciNueva.idTipo = idTipo;
    biciNueva.Rodado = rodado;
    strcpy(biciNueva.marca, marca);

    altaBici(bicisLista, bicisSize, biciNueva, idBicicleta);
}

void DarModificarBici(Bici *bicisLista, int *bicisSize, Tipo *tiposLista, int *tiposSize, Color *coloresLista, int *coloresSize, float rodados[3], int rodadosSize, int *idBicicleta)
{
    printf("\n --------------Modificando una bici--------------");
    int idBicy = inputIdBici(bicisLista, *bicisSize, tiposLista, coloresLista, *tiposSize, *coloresSize);
    system("cls");

    printf("\n1 para modificar tipo");
    printf("\n2 para modificar rodado");

    int opcion;
    opcion = inputInt();

    Bici BiciModificada;
    int indexBici = searchBiciById(bicisLista, idBicy, *bicisSize);

    BiciModificada = bicisLista[indexBici];

    while (opcion < 1 || opcion > 2)
    {
        int opcion;
        opcion = inputInt();
    }

    switch(opcion)
    {
        case 1:
            printf("\nIngrese nuevo id de tipo");
            int tipoID = inputIdTipo(tiposLista, *tiposSize);
            BiciModificada.idTipo = tipoID;
            break;

        case 2:
            printf("\nIngrese nuevo rodado");
            float rodado = inputRodado(rodados, rodadosSize);
            BiciModificada.Rodado = rodado;
            break;
    }
    modificarBici(bicisLista, *bicisSize, BiciModificada, indexBici);

}

void DarBajaBici(Bici *bicisLista, int *bicisSize, Tipo *tiposLista, int *tiposSize, Color *coloresLista, int *coloresSize, float rodados[3], int rodadosSize, int *idBicicleta)
{
    printf("\nDando de baja a una bici");
    int idBici = inputIdBici(bicisLista, *bicisSize, tiposLista, coloresLista, *tiposSize, *coloresSize);
    bajaBici(bicisLista, *bicisSize, idBici);
}

