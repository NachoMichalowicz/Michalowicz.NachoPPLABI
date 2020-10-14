#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    Fecha fechaTrabajo;
}Trabajo;

void altaTrabajo(Trabajo *TrabajosList, int *size, Trabajo TrabajoNuevo, int *id);
int bajaTrabajo(Trabajo *TrabajosList, int *size, int id);
int modificarTrabajo(Trabajo *TrabajosList, int size, Trabajo TrabajoSwap, int id);
int listarTrabajo(Trabajo *TrabajosList, int size);
void organizarTrabajos(Trabajo *TrabajosList, int size);
int searchTrabajoById(Trabajo *TrabajosList, int id, int size);

#endif // TRABAJO_H_INCLUDED
