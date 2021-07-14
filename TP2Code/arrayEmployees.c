#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"
///initEmployees

int initEmployees(sEmployee list[], int len)
{

    for(int i=0; i<len; i++)
    {
           list[i].isEmpty=1;
    }

    return 0;

}

int buscarLibre(sEmployee list[], int len)
{
    int index=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)//si es 1
            {
                index=i;
                break;
            }
        }

    }

    return index;
}
///addEmployees
int addEmployee(sEmployee list[], int len, int* id)
{
    int todoOk=0;
    int index;


    sEmployee newEmployee;


    if(list!=NULL && len>0)
    {

        printf("Alta empleado\n\n");
        printf("ID: %d\n", *id);
        index=buscarLibre(list, len);
        if(index==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {

            newEmployee.id= *id;

            utn_getStringNombre(newEmployee.name, "Ingrese el nombre del empleado: ", "Error, ingrese un nombre valido\n",51, 3);

            utn_getStringNombre(newEmployee.lastName, "Ingrese el apellido del empleado: ", "Error, ingrese un apellido valido\n",51, 3);

            utn_getNumeroFloat(&newEmployee.salary, "Ingrese el sueldo: ", "Error.\n", 1, 10000000, 3);

            mostrarSectores();
            utn_getNumero(&newEmployee.sector, "Ingrese el sector: ", "Error. Sector invalido.\n", 1, 4, 3);

            newEmployee.isEmpty=0;

            list[index]=newEmployee;


            *id=(*id)+1;


             todoOk=1;
        }

    }

    return todoOk;
}

void mostrarSectores()
{
    printf("***Sectores***\n");
    printf("1. RRHH\n");
    printf("2. Sistemas\n");
    printf("3. Legales\n");
    printf("4. Ventas\n");

}

///findEmployeeById
int findEmployeeById(sEmployee list[], int len, int id)
{
    int index=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty && list[i].id == id)
            {
                index=i;
                break;
            }
        }
    }

    return index;

}

///removeEmployee
int removeEmployee(sEmployee list[], int len, int id)
{
    int todoOk=0;
    int index;
    char confirma;

    index=findEmployeeById(list, len, id);


    if(index==-1)
    {
        printf("No existe un empleado con el id %d", id);
    }
    else
    {

        printf("Confirma la baja del empleado %d?: ", id);
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s')
        {
            list[index].isEmpty=1;
            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }
    return todoOk;
}

///printEmployees

int printEmployee(sEmployee employee, int len)
{
    printf("%d          %10s            %10s            %.2f      %d\n",
           employee.id,
           employee.name,
           employee.lastName,
           employee.salary,
           employee.sector);

           return 0;
}

int printEmployees(sEmployee list[], int len)
{
    int flag=1;
    int todoOk=0;

    if(list!=NULL && len>0)
    {
        printf("\n                      ******Nomina de empleados******\n");
        printf("ID           Nombre               Apellido              Sueldo       Sector \n");

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)///muestra los que estan en el indice que estan ocupados
            {
                printEmployee(list[i], len);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay empleados en la lista");
        }
        printf("\n\n");
        todoOk=1;
    }


    return todoOk;
}
///modifyEmployee
int modifyEmployee(sEmployee list[], int len)
{
    int todoOk=0;
    int index;
    int id;
    int opcion;
    char nuevoNombre[51];
    char nuevoApellido[51];
    float nuevoSueldo;
    int nuevoSector;
    //char confirma;

    system("cls");
    printf("       Modificacion de empleados\n");

    printEmployees(list, len);
    utn_getNumero(&id, "Ingrese el ID del empleado que desea modificar: ", "Error, ID invalido. \n", 1, 1000, 3);

    index=findEmployeeById(list, len, id);

    if(index==-1)
    {
        printf("No existe un empleado con el ID %d", id);
    }
    else
    {
        printEmployee(list[index], len);

        printf("1. Modificar nombre\n");
        printf("2. Modificar apellido\n");
        printf("3. Modificar salario\n");
        printf("4. Modificar sector\n");
        utn_getNumero(&opcion, "Ingrese el campo que desea modificar: ", "Error.\n", 1, 4, 3);
        switch(opcion)
        {
            case 1:
                utn_getStringNombre(nuevoNombre, "Ingrese el nuevo nombre: ", "Error.\n", 51, 3);
                strcpy(list[index].name,nuevoNombre);
                printf("Nombre actualizado\n");
                break;
            case 2:
                utn_getStringNombre(nuevoApellido, "Ingrese el nuevo apellido: ", "Error.\n", 51, 3);
                strcpy(list[index].lastName,nuevoApellido);
                printf("Apellido actualizado\n");
                break;
            case 3:
                utn_getNumeroFloat(&nuevoSueldo, "Ingrese el nuevo sueldo: ", "Error, sueldo incorrecto\n", 1, 10000000, 3);
                list[index].salary=nuevoSueldo;
                printf("Sueldo actualizado\n");
                break;
            case 4:
                mostrarSectores();
                printf("ingrese el nuevo sector: ");
                scanf("%d", &nuevoSector);
                list[index].sector=nuevoSector;
                printf("Sector actualizado\n");
                break;
        }
        todoOk=1;
    }
    return todoOk;
}


///sortEmployees
int sortEmployees(sEmployee list[], int len, int order)
{
    int todoOk=0;
    sEmployee auxEmpleado;

    if(list!=NULL && len>0 && order>=1 && order <=2)
    {
       if(order==1)
       {
           printf("Listado de los empleados ordenados alfabeticamente por Apellido  A-Z y Sector de manera ascendente\n");
            for(int i=0; i<len-1; i++)
                {
                    for(int j=i+1; j<len; j++)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName)>0 || (strcmp(list[i].lastName, list[j].lastName)==0  && list[i].sector>list[j].sector ) )
                        {
                            auxEmpleado=list[i];
                            list[i]=list[j];
                            list[j]=auxEmpleado;
                        }
                    }
                }
       }
       else
       {
           printf("Listado de los empleados ordenados alfabeticamente por Apellido  Z-A y Sector de manera descendente\n");
           for(int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if(strcmp(list[i].lastName, list[j].lastName)<0 || (strcmp(list[i].lastName, list[j].lastName)==0  && list[i].sector>list[j].sector ) )
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                }
            }

       }

       todoOk=1;
    }

    return todoOk;
}

int sueldosTotalesYPromedio(sEmployee list[], int len)
{
    int todoOk=0;
    float total=0;
    int contador=0;
    float promedio;


    if(list!=NULL && len>0)
    {

        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty)
            {
                total+=list[i].salary;
                contador++;
            }


        }
        promedio=total/contador;
        printf("\nEl total de los salarios es $%f. El salario promedio es $%f\n\n", total, promedio);


        printf("Empleados que cobran mas que el promedio:\n");
        for(int i=0; i<len; i++)
        {
            if(list[i].salary>=promedio)
            {
                printf("%s %s \n", list[i].name, list[i].lastName);
            }
        }



        todoOk=1;
    }
    return todoOk;

}

void menu()
{



    printf("Gestion de empleados\n");
    printf("1. Alta empleado\n");
    printf("2. Modificar empleado\n");
    printf("3. Baja empleado\n");
    printf("4. Listar empleados\n");
    printf("5. Informes\n");
    printf("6. Salir\n");



}

void menuInformes()
{


    printf("\n****Informes****\n");
    printf("1. Listado de los empleados ordenados alfabeticamente por Apellido  A-Z y Sector de manera ascendente\n");
    printf("2. Listado de los empleados ordenados alfabeticamente por Apellido  Z-A y Sector de manera descendente\n");
    printf("3. Total y promedio de los salarios. Cantidad de empleados que superan el salario promedio\n");


}



