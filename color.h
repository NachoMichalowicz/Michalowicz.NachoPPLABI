#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];

}Color;

void altaColor(Color *ColorsList, int *size, Color ColorNuevo, int *id);
int bajaColor(Color *ColorsList, int *size, int id);
int modificarColor(Color *ColorsList, int size, Color ColorSwap, int id);
int listarColor(Color *ColorsList, int size);
int listarColor(Color *ColorsList, int size);
int searchColorById(Color *ColorsList, int id, int size);


#endif // COLOR_H_INCLUDED
