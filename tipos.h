#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];

}Tipo;

void altaTipo(Tipo *TiposList, int *size, Tipo TipoNuevo, int *id);
int bajaTipo(Tipo *TiposList, int *size, int id);
int modificarTipo(Tipo *TiposList, int size, Tipo TipoSwap, int id);
int listarTipo(Tipo *TiposList, int size);
void organizarTipos(Tipo *TiposList, int size);
int searchTipoById(Tipo *TiposList, int id, int size);

#endif // TIPOS_H_INCLUDED
