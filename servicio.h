#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

    int id;
    int precio;
    char descripcion[25];

}eServicio;

void listarServicios(eServicio serviciosList[4], int size);
/** brief Lista los servicios.
* \param eServicio serviciosList Lista de servicios.
* \param int size Tamaño del array de servicios.
*/

int obtenerServicioIndex(eServicio serviciosList[4], int size, int id);

#endif // SERVICIO_H_INCLUDED
