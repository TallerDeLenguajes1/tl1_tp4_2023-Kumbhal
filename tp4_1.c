#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{
    int tareaId;
    char *descripcion;
    int duracion;
}typedef Tarea;

void cargarTareas (Tarea *tareas, int cantidad);

void main (){
    int cantidad = 0;
    printf("Ingrese la cantidad de tareas a realizar: ");
    scanf("%d", &cantidad);
    Tarea **tareas = malloc(cantidad * sizeof(Tarea));
    cargarTareas(tareas, cantidad);
}

void cargarTareas (Tarea *tareas, int cantidad){
    for (int i = 0; i < cantidad; i++){

    }
}