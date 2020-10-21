#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "servicio.h"
#include "trabajo.h"
#include "bicicleta.h"

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct{

    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;

}eTrabajo;

void altaTrabajo(eTrabajo *trabajosList, eTrabajo nuevoTrabajo, int index);
/** brief Agrega un trabajo a una dirección de punteros.
* \param eTrabajo *trabajosList Puntero de lista de trabajos.
* \param eTrabajo nuevoTrabajo Trabajo a agregar.
* \param int index Index donde poner el trabajo.
*
*/

void listarTrabajos(eTrabajo trabajosList[100], int size);
/** brief Lista trabajos.
* \param eTrabajo trabajosList Array de lista de trabajos.
* \param int size Tamaño de trabajos.
*
*/

void listarTrabajosBici(eTrabajo trabajosList[100], int size, int id);
/** brief Lista trabajos de determinada bici.
* \param eTrabajo trabajosList Array de lista de trabajos.
* \param int size Tamaño de trabajos.
* \param int id Id de la bici a buscar.
*
*/

void listarServiciosPorFecha(eTrabajo trabajosList[100], int size, eFecha fechaElegida, eServicio serviciosList[4], int sizeServicios);
/** brief Lista servicios de determinada fecha.
* \param eTrabajo trabajosList Array de lista de trabajos.
* \param int size Tamaño de trabajos.
* \param eFecha fechaElegida Fecha a filtrar.
* \param eServicio serviciosList Lista de servicios.
* \param int sizeServicios Tamaño del array de servicios.
*
*/

int sumaImportes(eTrabajo trabajosList[100], int sizeTrabajos, eServicio serviciosLista[4], int sizeServicio, int idBici);
/** brief Suma los importes de determinada bici.
* \param eTrabajo trabajosList Array de lista de trabajos.
* \param int sizeTrabajos Tamaño de trabajos.
* \param eServicio serviciosList Lista de servicios.
* \param int sizeServicios Tamaño del array de servicios.
* \param int idBici Id de la bici a filtrar
*
*/

void mostrarBiciPorServicio(eTrabajo trabajosList[100], int sizeTrabajo, eBici bicisList[100], int sizeBicis, int idServicio, eCliente clientesList[5], int sizeClientes);
/** brief Muestra las bicicletas de determinado servicio.
* \param eTrabajo trabajosList Array de lista de trabajos.
* \param int sizeTrabajos Tamaño de trabajos.
* \param eBici bicisList Lista de bicicletas
* \param int sizeBicis Tamaño del array de bicicletas.
* \param int idServicio Id del servicio a filtrar
*
*/

#endif // TRABAJO_H_INCLUDED
