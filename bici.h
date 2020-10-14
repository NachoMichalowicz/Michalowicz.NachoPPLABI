#ifndef BICI_H_INCLUDED
#define BICI_H_INCLUDED
#include "tipos.h"
#include "color.h"

typedef struct
{
    int id;
    int idTipo;
    int idColor;
    float Rodado;

    char marca[21];

}Bici;

void altaBici(Bici *BicisList, int *size, Bici BiciNuevo, int *id);
int bajaBici(Bici *BicisList, int *size, int id);
int modificarBici(Bici *BicisList, int size, Bici BiciSwap, int id);
int listarBici(Bici *BicisList, int size, Tipo *tiposList, Color *colorsList, int sizeTipos, int sizeColor);
void organizarBicis(Bici *BicisList, int size);
int searchBiciById(Bici *BicisList, int id, int size);

#endif // BICI_H_INCLUDED
