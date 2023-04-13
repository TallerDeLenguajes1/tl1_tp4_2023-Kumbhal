#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 200

struct Tarea{
    int tareaId;
    char *descripcion;
    int duracion;
}typedef Tarea;

Tarea** crearTareas (int cantidad);
void cargarTareas(Tarea **tareas, int cantidad);
void mostrarTareas(Tarea **tareas, int cantidad);

int main (){
    int cantidad = 0;
    Tarea ** tareasPendientes/* , tareasRealizadas */;
    printf("Ingrese la cantidad de tareas a realizar: ");
    scanf("%d", &cantidad);
    fflush(stdin);
    tareasPendientes = crearTareas(cantidad);
    /* tareasRealizadas = crearTareas(cantidad); */
    cargarTareas(tareasPendientes, cantidad);
    mostrarTareas(tareasPendientes, cantidad);
    return 1;
}

Tarea ** crearTareas (int cantidad){
    Tarea **tareas;
    tareas = (Tarea**) malloc(cantidad * sizeof(Tarea*));
    for (int  i = 0; i < cantidad; i++){
        tareas[i] = NULL;
    }
    return tareas;
}
void cargarTareas(Tarea **tareas, int cantidad){
    char descPrincipal[CANT];
    for (int i = 0; i < cantidad; i++){
        tareas[i] = malloc(sizeof(Tarea));
        tareas[i]->tareaId = i+1;
        printf("Ingresar la descripcion de la tarea: ");
        gets(descPrincipal);
        fflush(stdin);
        tareas[i]->descripcion = malloc(sizeof(char) * (strlen(descPrincipal)+1));
        strcpy(tareas[i]->descripcion, descPrincipal);

        printf("Ingrese la duracion de la tarea (Entre 10 - 100): ");
        scanf("%d", &(tareas[i]->duracion));
        fflush(stdin);
    }
}
void mostrarTareas(Tarea **tareas, int cantidad){
    for (int i = 0; i < cantidad; i++){
        printf("\n----------Tarea N %d---------\n", tareas[i]->tareaId);
        printf("\nDescripcion de tarea: %s", tareas[i]->descripcion);
        printf("\nDuracion de tarea: %d\n", tareas[i]->duracion);
    }
}