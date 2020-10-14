#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include "tipos.h"
#include "color.h"

int menuIndex();
int inputIdTipo(Tipo *tiposList, int size);
int inputIdColor(Color *colorsList, int size);
float inputRodado(float rodadosList[3], int size);
void inputMarca(char *marca);
void mostrarRodados(float rodados[3], int size);
int validarOpcion(character);
char inputChar();
float inputFloat();

#endif // INPUT_H_INCLUDED
