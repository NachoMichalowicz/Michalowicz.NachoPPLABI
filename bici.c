#include "bici.h"
#include "tipos.h"
#include "color.h"

void altaBici(Bici *BicisList, int *size, Bici BiciNuevo, int *id)
{
    int newSize = *size +1;
    BicisList[*size] = BiciNuevo;
    BicisList[*size].id = *id;
    *id = *id +1;

    *size = newSize;
}

int bajaBici(Bici *BicisList, int *size, int id)
{
    int index = searchBiciById(BicisList, id, *size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        Bici BiciVacio;
        BicisList[index] = BiciVacio;

        for (int i = index+1; i < *size; i++)
        {
            Bici auxBici;
            auxBici = BicisList[i-1];

            BicisList[i-1] = BicisList[i];
            BicisList[i] = auxBici;
        }

        *size = *size -1;
        }
}

int modificarBici(Bici *BicisList, int size, Bici BiciSwap, int id)
{
    int index;
    index = searchBiciById(BicisList, id, size);

    if (index == -1)
    {
        return 0;
    }
    else
    {
        BicisList[index] = BiciSwap;
    }
}

int listarBici(Bici *BicisList, int size, Tipo *tiposList, Color *colorsList, int sizeTipos, int sizeColor)
{
    if (size > 0)
    {
        printf("\n---Bicis---\n");
        organizarBicis(BicisList, size);
        for (int i = 0; i < size; i++)
        {
            Bici BiciActual;
            BiciActual = BicisList[i];

            Tipo tipoActual;
            int indexTipo = searchTipoById(tiposList, BiciActual.idTipo, sizeTipos);
            tipoActual = tiposList[indexTipo];

            Color colorActual;
            int indexColor = searchColorById(colorsList, BiciActual.idColor, sizeColor);
            colorActual = colorsList[indexColor];

            printf("\n\nId de la bici: %d", BiciActual.id);
            printf("\nMarca de la Bici: %s", BiciActual.marca);
            printf("\nId del tipo: %d (%s)", BiciActual.idTipo, tipoActual.descripcion);
            printf("\nId del color: %d (%s)", BiciActual.idColor, colorActual.nombre);
            printf("\nRodado: %.2f", BiciActual.Rodado);
        }
        printf("\n\n");
    }
    else
    {
        return -1;
    }

}

void organizarBicis(Bici *BicisList, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {

            if (BicisList[i].idTipo < BicisList[j].idTipo)
            {
                Bici BiciAux;
                BiciAux = BicisList[i];

                BicisList[i] = BicisList[j];
                BicisList[j] = BiciAux;

                    if (BicisList[i].id < BicisList[j].id)
                    {
                        Bici BiciAux;
                        BiciAux = BicisList[i];

                        BicisList[i] = BicisList[j];
                        BicisList[j] = BiciAux;
                    }
            }
        }
    }
}

int searchBiciById(Bici *BicisList, int id, int size)
{
    for (int i = 0; i < size; i++)
    {
        Bici BiciActual;
        BiciActual = BicisList[i];

        if (BiciActual.id == id)
        {
            return i;
        }
    }
    return -1;
}
