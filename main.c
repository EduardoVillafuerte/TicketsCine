#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    char peliculas[10][4][40]={{"1","Avatar            ","10:20","Fantasia"},
                               {"2","Endgame           ","19:45","Accion"},
                               {"3","Star_Wars         ","12:10","Ciencia_Ficcion"},
                               {"4","Intensamente      ","13:15","Infantil"},
                               {"5","Harry_Potter      ","15:15","Ciencia_Ficcion"},
                               {"6","Rapidos_y_Furiosos","14:30","Accion"},
                               {"7","Spiderman         ","18:40","Accion"},
                               {"8","Batman            ","16:00","Accion"},
                               {"9","Bad_Boys          ","20:10","Comedia"},
                               {"10","Gran_Turismo     ","15:20","Aventura"}};
    double precio[3]={7,3.5,3};
    char clientes[5][2][40]={{"",""},
                             {"",""},
                             {"Carolina","1234567891"}, 
                             {"",""},
                             {"",""}};

    int reserva[10][4]={ {1,2,2,1}, 
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1},
                         {-1,-1,-1,-1}};


    int opcion1=0,opcion2=0,opcion3=0;
    do
    {
        printf("Escoja una opcion:\n1.Ingresar Cliente\n2.Ver Peliculas\n3.Buscar Pelicula\n4.Comprar Ticket\n5.Ver Compras\n>>");
        scanf("%d",&opcion2);
        switch (opcion2)
        {
        case 1:
            ingresarCliente(clientes);
            break;
        case 2:
            listarPeliculas(peliculas);
            break;
        case 3:
            printf("1.Por nombre\n2.Por Genero\n>>");
            scanf("%d",&opcion3);
            switch (opcion3)
            {
            case 1:
                buscarporNombre(peliculas);
                break;
            case 2:
                buscarporGenero(peliculas);
                break;
            default:
                break;
            }
            break;
        case 4:
            comprarTicket(peliculas,precio,clientes,reserva);
            break;
        case 5:
            verCompras(peliculas,precio,clientes,reserva); 
            break;
        default: 

            break;
        }
        printf("Desea escoger una nueva opcion: 1.Si/2.No\n>>");
        scanf("%d",&opcion1);
    } while (opcion1==1);

    return 0;
}