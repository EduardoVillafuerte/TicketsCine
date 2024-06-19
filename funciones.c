#include <stdio.h>
#include "funciones.h"
#include <string.h>

void ingresarCliente(char clientes[][2][40]){
   
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(clientes[i][0],"")==0){
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s",clientes[i][0]);
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s",clientes[i][1]);
            break;
        }
    } 
    imprimirClientes(clientes);
}

void imprimirClientes(char clientes[][2][40]){
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t\t%s\n",clientes[i][0],clientes[i][1]);
    }   
}

void listarPeliculas(char peliculas[][4][40]){
    for (int i = 0; i < 10; i++)
    {
        printf("%s\t\t%s\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
    }   
}

void buscarporNombre(char peliculas[][4][40]){
    char nombrepelicula[30];
    int found = -1;
    printf("Ingrese en nombre de la pelicula\n>>");
    scanf("%s",nombrepelicula);
    for(int k = 0; k < 10;k++){
        if(strcmp(nombrepelicula,peliculas[k][1])==0){
            printf("Las funciones para la pelicula es:\n");
            printf("%s\t\t%s\t\t%s\n",peliculas[k][1],peliculas[k][2],peliculas[k][3]);
            found = 1;
            break;
        }
    }
    if(found == -1){
        printf("No tenenemos funciones en esta pelicula: %s\n",nombrepelicula);
    }
}

void buscarporGenero(char peliculas[][4][40]){
    char generobuscar[30];
    int found = -1;
    printf("Ingrese el genero de la pelicula\n>>");
    scanf("%s",generobuscar);
    printf("Las funciones para la pelicula es:\n");
    for(int k = 0; k < 10;k++){
        if(strcmp(generobuscar,peliculas[k][3])==0){
            printf("%s\t\t%s\t\t%s\n",peliculas[k][1],peliculas[k][2],peliculas[k][3]);
            found = 1;
        }
    }
    if(found == -1){
        printf("No tenenemos funciones en este genero: %s\n",generobuscar);
    }
}

void comprarTicket(char peliculas[][4][40],double precio[], char clientes[][2][40],int reserva[][4]){

    char cedula[40];
    int found = -1;

    for(int k = 0; k<10; k++){
        if(reserva[k][0]==-1){
            printf("Ingrese su cedula: ");
            scanf("%s", cedula);
            getchar();
            for (int i = 0; i < 5; i++) {
                if (strcmp(clientes[i][1], cedula) == 0) {
                    found = i;
                    reserva[k][1] = i;
                    break;
                }
            }

            if (found == -1) {
                printf("Cedula no encontrada.\n");
                return;
            }
            
            listarPeliculas(peliculas);
            printf("Ingrese el numero de la pelicula: ");
            scanf("%d", &reserva[k][0]);
            printf("El valor de peli es : %d\n", reserva[k][0]);

            printf("Tipos de entrada: \n 0  Normal ($7) \n 1  Ninos ($3.5) \n 2  Adulto mayor ($3)\n");
            printf("Ingrese el tipo de entrada: ");
            scanf("%d", &reserva[k][2]);
            
            printf("Ingrese la cantidad de entradas: ");
            scanf("%d", &reserva[k][3]);

            double total = reserva[k][3] * precio[reserva[k][2]];
            printf("Compra realizada exitosamente. Total: $%.2f\n", total);
            break;
        }
    }
}


             


void verCompras(char peliculas[][4][40],double precio[], char clientes[][2][40],int reserva[][4]){
    char cedula[30];
    int indice=-1, found =-1;
    printf("Ingerese la cedula para ver las compras\n");
    scanf("%s", cedula);

    for(int y=0; y < 5; y++){
        if(strcmp(clientes[y][1],cedula)==0){
            indice = y;
            break;
        }
    }
    if(indice == -1){
        printf("La cedula no fue encontrada \n");
    }

    for(int j = 0; j < 10; j++)
    {
        if((reserva[j][1]==indice)&&(reserva[j][1]!=-1)){
            printf("%s\t\t%s\t\t%.2f\t\t%d\n",peliculas[reserva[j][0]-1][1],clientes[reserva[j][1]][0],precio[reserva[j][2]],reserva[j][3]);
            found = 1;
        }
    } 
    if(found == -1){
        printf("El cliente no ha hecho alguna compra\n");
    }
}  
