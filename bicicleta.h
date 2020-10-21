#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

#include "color.h"
#include "cliente.h"

typedef struct{

    int id;
    int idTipo;
    int idColor;
    int idCliente;
    float rodado;

    char marca[20];

} eBici;

void altaBicicleta(eBici *bicisList, eBici nuevaBici, int index);
/** brief Agrega una bicicleta a una dirección de punteros.
* \param eBici *bicisList Puntero de lista de bicicletas.
* \param eBici nuevaBici Bicicleta a agregar.
* \param int index Index donde poner la bicicleta.
*
*/

void bajaBicicleta(eBici *bicisList, int index, int size);
/** brief Elimina una bicicleta de un array y luego lo reordena.
* \param eBici *bicisList Puntero de lista de bicicletas.
* \param int index Index donde dar de baja la bicicleta.
* \param int size Tamaño del array de bicicletas.
*/

void modificarBicicleta(eBici *bicisList, eBici biciModificada, int index);
/** brief Dado un determinado array, modifica un elemento teniendo en cuenta un index específico.
* \param eBici *bicisList Puntero de lista de bicicletas.
* \param eBici biciModificada Bicicleta modificada.
* \param int index Index donde modificar la bicicleta.
*/

int obtenerIndexBiciPorId(eBici bicisList[100], int id, int size);
/** brief Dado un determinado id, se obtiene el index de bicicleta en un array.
* \param eBici bicisList Lista de bicicletas.
* \param int id Id a buscar.
* \param int size Tamaño del array de bicicletas.
*\return int Devuelve el index en el array del elemento con dicho ID. En caso de que el elemento no exista, devuelve -1.
*/

void listarBicicletas(eBici bicisList[100], int size, eCliente clientesList[5], int sizeClientes);
/** brief Lista un array de eBicis.
* \param eBici bicisList Array de lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
* \param eCliente clientesList Array de clientes.
* \param int sizeClientes Tamaño del array de clientes.
*/

void listarBicicletasSeparadasTipo(eBici bicisList[100], int size, eCliente clientesList[5], int sizeClientes);
/** brief Lista un array de eBicis separadas por tipo.
* \param eBici bicisList Array de lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
* \param eCliente clientesList Array de clientes.
* \param int sizeClientes Tamaño del array de clientes.
*/

void listarBicicletasMismoColor(eBici bicisList[100], int size, int idColor, eCliente clientesList[5], int sizeClientes);
/** brief Lista un array de bicicletas de un determinado color.
* \param eBici bicisList Array de lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
* \param int idColor Id del color a filtrar.
* \param eCliente clientesList Array de clientes.
* \param int sizeClientes Tamaño del array de clientes.
*/

void listarBicicletasMismoTipo(eBici bicisList[100], int size, int idTipo, eCliente clientesList[5], int sizeClientes);
/** brief Lista un array de bicicletas de un determinado tipo.
* \param eBici bicisList Array de lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
* \param int idTipo Id del tipo a filtrar.
* \param eCliente clientesList Array de clientes.
* \param int sizeClientes Tamaño del array de clientes.
*/

void listarBicicletasMenorRodado(eBici bicisList[100], int size, float rodadosList[4], eCliente clientesList[5], int sizeClientes);
/** brief Lista un array de bicicletas de menor rodado.
* \param eBici bicisList Array de lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
* \param float rodadosList Array de rodados.
* \param eCliente clientesList Array de clientes.
* \param int sizeClientes Tamaño del array de clientes.
*/

int obtenerColorMasElegido(eBici bicisList[100], int size, eColor colorList[5], int sizeColors);
/** brief Obtiene id del color más elegido.
* \param eBici bicisList Array de lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
* \param eColor colorList Array de colores.
* \param int sizeColores Tamaño del array de clientes.
*
* \return int Retorna el id del color más elegido.
*/

void ContarBicicletasMismoColorYTipo(eBici bicisList[100], int size, int idTipo, int idColor);
/** brief Cuenta bicicletas del mismo color y tipo y muestra el resultado en pantalla.
* \param eBici bicisList Array de lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
* \param int idTipo Id del tipo.
* \param int idColor Id del color.
*
*/

void ordenarBicicletas(eBici *bicisList, int size);
/** brief Ordena bicicletas por tipo y rodado.
* \param eBici *bicisList Puntero del array de lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
*
*/

void ordenarBicicletasColor(eBici *bicisList, int size, eColor coloresList[5], int sizeColores);
/** brief Ordena bicicletas por color.
* \param eBici *bicisList Puntero del array de lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
* \param eColor coloresList Array de colores.
* \param int sizeColores Tamaño del array de colores.
*
*/
#endif // BICICLETA_H_INCLUDED
