#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"



int main()
{
    LinkedList* miLista;

    miLista = ll_newLinkedList();

    int respuesta;
    char aux[50];


    do
    {
        printf("\n");
        menu();
        printf("Ingrese una opcion:\n");
        fflush(stdin);
        gets(aux);
        respuesta=atoi(aux);
        while(esNumerico(aux)==0 || respuesta<1 || respuesta>10)
        {
            printf("Ingrese una opcion valida:\n");
            fflush(stdin);
            gets(aux);
            respuesta=atoi(aux);
        }

        switch(respuesta)
        {
            case 1:
                controller_loadFromText("data.csv", miLista);
            break;
            case 2:
                controller_loadFromBinary("data.bin", miLista);
            break;
            case 3:
                controller_addEmployee(miLista);
            break;
            case 4:
                controller_editEmployee(miLista);
            break;
            case 5:
                controller_removeEmployee(miLista);
            break;
            case 6:
                controller_ListEmployee(miLista);
            break;
            case 7:
                controller_sortEmployee(miLista);
            break;
            case 8:
                controller_saveAsText("data.csv", miLista);
            break;
            case 9:
                controller_saveAsBinary("data.bin", miLista);
            break;

        }

       }while(respuesta!=10);



    return 0;
}
