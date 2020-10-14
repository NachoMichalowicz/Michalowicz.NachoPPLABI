#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    int precio;

}Servicio;

void altaServicio(Servicio *serviciosList, int *size, Servicio servicioNuevo, int *id);
int bajaServicio(Servicio *serviciosList, int *size, int id);
int modificarServicio(Servicio *serviciosList, int size, Servicio servicioSwap, int id);
int listarServicios(Servicio *serviciosList, int size);
void organizarServicios(Servicio *serviciosList, int size);
int searchServiceById(Servicio *serviciosList, int id, int size);


#endif // SERVICIO_H_INCLUDED
