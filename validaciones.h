#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "trabajo.h"
#include "servicio.h"


int pedirOpcion();
/** brief Pide opción de menú al usuario y valida la misma.
*
*\return int opcion Devuelve la opción validada en formato entero.
*/

int pedirOpcionComplementaria();
/** brief Pide opción de menú complementario al usuario y valida la misma.
*
*\return int opcion Devuelve la opción validada en formato entero.
*/

void printMenu();
/** brief Imprime el menú.
*/

void printMenuComplementario();
/** brief Imprime el menú complementario.
*/

eBici pedirNuevaBici(eTipo tiposList[4], int sizeTipos, float rodadosList[3], int sizeRodados, eColor coloresList[5], int sizeColor, int idBici, eCliente clientesList[5], int sizeClientes);
/** brief Pide una nueva bicicleta al usuario, validando todos los campos.
* \param eTipo tiposList Lista de tipos de bicicletas.
* \param int sizeTipos Tamaño del array de tipos de biciletas.
* \param float rodadosList Lista de rodados.
* \param int sizeRodados Tamaño del array de rodados.
* \param eColor coloresList Lista de colores.
* \param int sizeColor Tamaño del array de colores.
* \param int idBici Id actual de las bicicletas.
*
*\return eBici nuevaBici Devuelve un elemento bici con los datos ingresados.
*/

eTrabajo pedirNuevoTrabajo(eTrabajo trabajoList[100], int sizeTrabajo, int idTrabajo, eBici bicisList[100], int sizeBicis, eServicio serviciosList[4], int sizeServicios, eCliente clientesList[5], int sizeClientes);
/** brief Pide un nuevo trabajo.
* \param eTrabajo trabajoList Lista de trabajos.
* \param int sizeTrabajo Tamaño del array de trabajos.
* \param int idTrabajo Id actual de los trabajos.
* \param eBici bicisList Lista de bicicletas.
* \param int sizeBicis Tamaño de bicicletas.
* \param eServicio serviciosList Lista de servicios.
* \param int sizeServicios Tamaño de servicios.
* \param eCliente clientesList Lista de clientes.
* \param int sizeClientes Tamaño de clientes.
*
*\return eTrabajo Devuelve un elemento trabajo con los datos ingresados.
*/

eFecha pedirFecha();
/** brief Pide un nuevo trabajo.
*\return eFecha Devuelve un elemento fecha con los datos ingresados.
*/

void pedirModificacionBici(eBici *bicisList, int size, int index, eTipo tiposList[4], int sizeTipos, float rodadosList[3], int sizeRodados);
/** brief Abre un submenú para modificación de bicicletas. Mediante éste, el usuario puede modificar una bicicleta a elección.
* \param eBici *bicisList Puntero de lista de bicicletas.
* \param int size Tamaño del puntero de biciletas.
* \param eTipo tiposList Lista de tipos de bicicletas.
* \param int sizeTipos Tamaño del array de tipos de biciletas.
* \param float rodadosList Lista de rodados.
* \param int sizeRodados Tamaño del array de rodados.
*
*/

int pedirIndexPorIdBici(eBici bicisList[100], int size, eCliente clientesList[5], int sizeClientes);
/** brief Imprime el menú de bicis, pide un id y lo valida.
* \param eBici bicisList  Lista de bicicletas.
* \param int size  Tamaño del array de Lista de bicicletas.
* \param eCliente clientesList Lista de clientes.
* \param int sizeClientes Tamaño de clientes.
*
*\return int Devuelve el index en el array del elemento con dicho ID.
*/

int pedirServicios(eServicio serviciosList[4], int size);
/** brief Pide un servicio y lo valida.
* \param eServicio serviciosList Lista de servicios
* \param int size Tamaño del array de servicios.
*\return int Devuelve el id validado.
*/

int pedirIndexPorIdBici(eBici bicisList[100], int size, eCliente clientesList[5], int sizeClientes);
/** brief Pide el id de una bici y lo valida.
* \param eBici bicisList Lista de bicicletas.
* \param int size Tamaño del array de bicicletas.
* \param eCliente clientesList Lista de clientes.
* \param int sizeClientes Tamaño de clientes.
*
*\return int Devuelve el id validado.
*/

int pedirServicios(eServicio serviciosList[4], int size);
/** brief Pide el id de un servicio y lo valida.
* \param eServicio serviciosList Lista de servicios.
* \param int size Tamaño del array de servicios.
*
*\return int Devuelve el id validado.
*/


int pedirTipo(eTipo tiposList[4], int size);
/** brief Pide un tipo de bicicleta y lo valida.
* \param eTipo tiposList  Lista de tipos.
* \param int size  Tamaño del array de Lista de tipos.
*\return int Devuelve el tipo validado.
*/

int pedirColor(eColor coloresList[5], int sizeColor);
/** brief Pide un color de bicicleta y lo valida.
* \param eColor coloresList  Lista de colores.
* \param int sizeColor  Tamaño del array de colores.
*\return int Devuelve el color validado.
*/

float pedirRodado(float rodadosList[3], int sizeRodados);
/** brief Pide un rodado de bicicleta.
* \param float rodadosList Lista de rodados.
* \param int size  Tamaño del array de Lista de rodados.
*\return float Devuelve el rodado validado.
*/

int validarRodado(float rodado, float rodadosList[3], int sizeRodados);
/** brief Comprueba si un rodado existe.
* \param float rodado Rodado a comprobar.
* \param float rodadosList  Array de rodados.
* \param int sizeRodados  Tamaño del array de los rodados.
*\return int Devuelve 0 si existe y -1 si no existe.
*/

void pedirCadenaCaracteres(char *cadena);
/** brief Pide una cadena de caracteres y la almacena en un puntero específico.
* \param char *cadena Puntero donde se almacena la cadena pedida.
*/

char pedirCaracter();
/** brief Pide un caracter.
*\return char Devuelve el caracter pedido.
*/

int pedirInt();
/** brief Pide un int.
*\return int Devuelve el int pedido.
*/

float pedirFloat();
/** brief Pide un float.
*\return float Devuelve el float pedido.
*/

#endif // VALIDACIONES_H_INCLUDED
