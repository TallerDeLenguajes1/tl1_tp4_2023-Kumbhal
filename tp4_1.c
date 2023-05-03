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
void estadoTareas(Tarea **tareas, int cantidad, Tarea ** tareasRealizadas);
void mostrarTareas(Tarea ** tareasPendientes, Tarea ** tareasRealizadas, int cantidad);
void liberarMemoria(Tarea ** tareasPendientes, Tarea ** tareasRealizadas, int cantidad);
void mostrarMenu();

void main (){
    int cantidad = 0, opcion = 0;
    Tarea ** tareasPendientes;
    Tarea ** tareasRealizadas;
    printf("Ingrese la cantidad de tareas a realizar: ");
    scanf("%d", &cantidad);
    fflush(stdin);
    tareasPendientes = crearTareas(cantidad);
    tareasRealizadas = crearTareas(cantidad);
    cargarTareas(tareasPendientes, cantidad);
    while (opcion != 3){
        mostrarMenu();
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion == 1){
            estadoTareas(tareasPendientes, cantidad, tareasRealizadas);
        }else if (opcion == 2){
            mostrarTareas(tareasPendientes, tareasRealizadas, cantidad);
        }
    }
    liberarMemoria(tareasPendientes, tareasRealizadas, cantidad);
}

void mostrarMenu(){
    printf("\n==============MENU PRINCIPAL==============\n");
    printf("\nIngrese una opcion: \n1- Modificar estado\n2- Mostrar tareas\n3- Salir");
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
        printf("\n==========Tarea [%d]==========\n", tareas[i]->tareaId);
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
void estadoTareas(Tarea **tareas, int cantidad, Tarea ** tareasRealizadas){
    for (int i = 0; i < cantidad; i++){
        int confirmacion = 0;
        printf("\n-----Tarea [%d]-----\n", tareas[i]->tareaId);
        printf("\nDescripcion de tarea:");
        puts(tareas[i]->descripcion);
        printf("\nDuracion de tarea: %d\n", tareas[i]->duracion);
        fflush(stdin);
        printf("\nLa tarea esta realizada?(1/0)");
        scanf("%d", &confirmacion);
        if (confirmacion == 1){
            tareasRealizadas[i] = malloc(sizeof(Tarea));
            tareasRealizadas[i]->tareaId = tareas[i]->tareaId;
            tareasRealizadas[i]->descripcion = malloc(sizeof(char) * (strlen(tareas[i]->descripcion)));
            strcpy(tareasRealizadas[i]->descripcion, tareas[i]->descripcion);
            tareasRealizadas[i]->duracion = tareas[i]->duracion;
            free(tareas[i]->descripcion);
            free(tareas[i]);
            tareas[i] = NULL;
        }
    }
}

void mostrarTareas(Tarea ** tareasPendientes, Tarea ** tareasRealizadas, int cantidad){
        printf("\n==========Tareas Pendientes==========\n");
    for (int i = 0; i < cantidad; i++){
        if (tareasPendientes[i] != NULL){
            printf("\n-----Tarea [%d]-----\n", tareasPendientes[i]->tareaId);
            printf("\nDescripcion de tarea: %s", tareasPendientes[i]->descripcion);
            printf("\nDuracion de tarea: %d\n", tareasPendientes[i]->duracion);
        }
    }
        printf("\n==========Tareas Realizadas==========\n");
    for (int j = 0; j < cantidad; j++){
        if (tareasRealizadas[j] != NULL){
            printf("\n-----Tarea [%d]-----\n", tareasRealizadas[j]->tareaId);
            printf("\nDescripcion de tarea: %s", tareasRealizadas[j]->descripcion);
            printf("\nDuracion de tarea: %d\n", tareasRealizadas[j]->duracion);
        }
    }
}

void liberarMemoria(Tarea ** tareasPendientes, Tarea ** tareasRealizadas, int cantidad){
    for (int i = 0; i < cantidad; i++){
        if (tareasPendientes[i] != NULL){
            free(tareasPendientes[i]->descripcion);
            free(tareasPendientes[i]);
        }
        if (tareasRealizadas[i] != NULL){
            free(tareasRealizadas[i]->descripcion);
            free(tareasRealizadas[i]);
        }
    }
}