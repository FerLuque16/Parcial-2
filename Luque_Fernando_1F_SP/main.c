#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Computer.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int option;
    char fileName[50];

    LinkedList* listaComputers;
    LinkedList* filtradoLaptops;

    listaComputers=ll_newLinkedList();
    do
    {
        system("cls");
        getInt(&option,"----------------------------------MENU------------------------------------\n\n1. Cargar datos de archivo.csv.\n2. Ordenar segun id.\n"
                   "3. Imprimir\n4. Realizar aumento de precio\n5. Filtrar laptops \n6. Guardar archivo\n7. Salir\nIngrese la accion a realizar: ","\n\nOpcion no valida\n",1,7,100000);

        switch(option)
        {
            case 1:
                if(!getStringNumeros(fileName,"Ingrese el nombre del archivo a cargar: ","Datos no validos",1,50,3))
                {
                    if(controller_loadFromText(listaComputers,fileName))
                    {
                        printf("Se ha cargado con exito\n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("El archivo no existe\n\n");
                        system("pause");
                        break;
                    }
                }

                break;

            case 2:
                if(!ll_sort(listaComputers,computer_compareId,1))
                   {
                       system("cls");
                       printf("Se ha ordenado correctamente\n");
                       system("pause");
                   }
                else
                    {
                        system("cls");
                        printf("No se ha podido ordenar\n");
                        system("pause");
                    }

                break;

            case 3:
                computer_printComputer(listaComputers);
                system("pause");
                break;

            case 4:
                ll_map(listaComputers,computer_mapPrecio);
                break;

            case 5:
                filtradoLaptops=NULL;
                filtradoLaptops=ll_filter(listaComputers,computer_filtrarLaptops);

                break;

            case 6:
                if(!saveAsText(filtradoLaptops))
                {
                    system("cls");
                    printf("Se ha guardado correctamente\n\n");
                    system("pause");
                    break;
                }

                system("cls");
                printf("No se ha guardado\n\n");
                system("pause");

                break;

            case 7:
                break;



        }

    }while(option!=7);
    return 0;
}


