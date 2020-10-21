#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];

} eTipo;

void listarTipos(eTipo tiposList[4], int size);
/** brief Lista los tipos de bicicletas.
* \param eTipo tiposList Lista de tipos de bicicletas.
* \param int size Tamaño de listas de bicicletas.
*/

int obtenerTipoIndex(eTipo tiposList[4], int size, int id);
/** brief Obtiene el index de tipo en un array mediante su id.
* \param eTipo tiposList Lista de tipos de bicicletas.
* \param int size Tamaño de listas de bicicletas.
* \param int id Id de tipo a buscar.
*
*\return int Devuelve el index en el array del elemento con dicho ID. En caso de que el elemento no exista, devuelve -1.
*/

#endif // TIPO_H_INCLUDED
