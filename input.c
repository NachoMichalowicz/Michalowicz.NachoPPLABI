#include "input.h"
#include "tipos.h"
#include "color.h"
#include "bici.h"

#include <stdio.h>

int menuIndex()
{
    char character;
    character = inputChar();

    int indexError;
    indexError = validarOpcion(character);

    while (indexError ==-1)
    {
        printf("\nERROR. Ingrese una letra valida");
        character = inputChar();
        indexError = validarOpcion(character);
    }

    return indexError;
}

int inputIdTipo(Tipo *tiposList, int size)
{
    int index = -1;
    int idTipo;

    listarTipo(tiposList, size);
    printf("\nIngrese un tipo por ID.");
    idTipo = inputInt();
    index = searchTipoById(tiposList, idTipo, size);

    while (index ==-1)
    {
        printf("\nERROR. Ingrese un tipo por ID valido.");
        idTipo = inputInt();
        index = searchTipoById(tiposList, idTipo, size);
    }

    return idTipo;

}

int inputIdColor(Color *colorsList, int size)
{
    int index = -1;
    int idColor;

    listarColor(colorsList, size);
    printf("\nIngrese un color por ID.");
    idColor = inputInt();
    index = searchColorById(colorsList, idColor, size);

    while (index ==-1)
    {
        printf("\nERROR. Ingrese un color por ID valido.");
        idColor = inputInt();
        index = searchColorById(colorsList, idColor, size);
    }

    return idColor;
}

int inputIdBici(Bici *bicisList, int size, Tipo *tiposList, Color *colorsList, int sizeTipos, int sizeColor)
{
    int index = -1;
    int idBicy;

    listarBici(bicisList, size, tiposList, colorsList, sizeTipos, sizeColor);
    printf("\nIngrese una bici por ID.");
    idBicy = inputInt();
    index = searchBiciById(bicisList, idBicy, size);

    while (index ==-1)
    {
        printf("\nERROR. Ingrese una bici por ID valida.");
        idBicy = inputInt();
        index = searchBiciById(bicisList, idBicy, size);
    }

    return idBicy;
}

float inputRodado(float rodadosList[3], int size)
{
    int indexError;

    mostrarRodados(rodadosList, size);
    printf("\n\nIngrese un rodado en numero. (No ingrese su posicion)");
    float rodado = inputFloat();
    indexError = -1;

    for (int i = 0; i < size; i++)
    {
        if (rodadosList[i] == rodado)
        {
            indexError = 0;
        }
    }

    while (indexError == -1)
    {
        printf("\nERROR. Tiene que ser un rodado valido");
        float rodado = inputFloat();
        for (int i = 0; i < size; i++)
        {
            if (rodadosList[i] == rodado)
            {
                indexError = 0;
            }
        }
    }

    return rodado;
}

void inputMarca(char *marca)
{
    printf("\nIngrese una marca: ");
    scanf("%s", marca);
    fflush(stdin);

}

void mostrarRodados(float rodados[3], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nRodado en posicion %d: %.2f", i, rodados[i]);
    }
}

int validarOpcion(character)
{
    int index = -1;
    switch(character)
    {
        case 'A':
            index = 0;
            break;

        case 'B':
            index = 1;
            break;

        case 'C':
            index = 2;
            break;

        case 'D':
            index = 3;
            break;

        case 'E':
            index = 4;
            break;

        case 'F':
            index = 5;
            break;

        case 'G':
            index = 6;
            break;

        case 'H':
            index = 7;
            break;

        case 'I':
            index = 8;
            break;

        case 'J':
            index = 9;
            break;
    }
    return index;
}

int inputInt()
{
    int num;
    printf("\nIngrese un numero: ");
    scanf("%d", &num);
    fflush(stdin);

    return num;
}

char inputChar()
{
    char character;
    printf("\nIngrese una letra: ");
    scanf("%c", &character);
    fflush(stdin);

    return toupper(character);
}

float inputFloat()
{
    float num;
    printf("\nIngrese un numero (puede contener decimales): ");
    scanf("%f", &num);
    fflush(stdin);

    return num;
}
