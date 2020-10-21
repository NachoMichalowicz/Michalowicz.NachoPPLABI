#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{

    int id;
    char nombreColor[20];

}eColor;

void listarColores(eColor coloresList[5], int size);
/** brief Lista los colores.
* \param eColor coloresList Lista de colores.
* \param int size Tamaño de dicha lista.
*
*/

int obtenerColorIndex(int size, int id);
/** brief Obtiene el index de un color por id.
* \param int size Tamaño de la lista de colores.
* \param int id Id de referencia.
*\return int retorna e
*/

#endif // COLOR_H_INCLUDED
