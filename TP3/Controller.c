#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int controlador;

    controlador=ll_isEmpty(pArrayListEmployee);
    pFile = fopen(path, "r");

    if(controlador==1)
    {
        if(pFile!=NULL && pArrayListEmployee!=NULL)
        {
            parser_EmployeeFromText(pFile, pArrayListEmployee);
        }
        else
        {
            printf("Error.\n");
        }
    }
    else
    {
        printf("\nYa hay una lista cargada\n\n");
    }



    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int controlador;

    controlador=ll_isEmpty(pArrayListEmployee);
    pFile = fopen(path, "rb");

    if(controlador==1)
    {
        if(pFile!=NULL && pArrayListEmployee!=NULL)
        {
            parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
        else
        {
            printf("Error.\n");
        }
    }
    else
    {
        printf("\nYa hay una lista cargada\n\n");
    }



    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* miEmpleado;
    int auxId;


    miEmpleado=nuevoEmpleado();

    if(miEmpleado!=NULL)
    {
        auxId=employee_NewId(pArrayListEmployee);
        employee_setId(miEmpleado,auxId);
        if(auxId>0)
        {
            ll_add(pArrayListEmployee,miEmpleado);
        }
        else
        {
            printf("\nNo se agrego, cargue una lista primero.\n");
        }
        return 1;
    }
    else
    {
        printf("Error.");
        return 0;
    }
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    Employee* miEmpleado;
    int controlador;
    int index;

    controlador=ll_isEmpty(pArrayListEmployee);

    controller_ListEmployee(pArrayListEmployee);

    if(controlador==0)
    {
        printf("\nIngrese el numero de ID del empleado que desea modificar: \n");
        scanf("%d", &id);
        miEmpleado=nuevoEmpleado();
        if(miEmpleado!=NULL)
        {
            employee_setId(miEmpleado,id);
            index=employee_IndexById(pArrayListEmployee,id);
            ll_set(pArrayListEmployee,index, miEmpleado);
            return 1;
        }
        else
        {
            printf("Error.\n");
            return 0;
        }
    }
    else
    {
        printf("Error.No hay lista cargada\n");
        return 0;
    }
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int controlador;
    int index;

    if(pArrayListEmployee!=NULL)
    {
        controlador=ll_isEmpty(pArrayListEmployee);

        controller_ListEmployee(pArrayListEmployee);

        if(controlador==0)
        {
            printf("\nIngrese el numero de ID del empleado que desea borrar: \n");
            scanf("%d", &id);
            index=employee_IndexById(pArrayListEmployee,id);

            ll_remove(pArrayListEmployee,index);
            return 1;
        }
        else
        {
            printf("Error. No hay lista cargada.\n");
            return 0;
        }
    }
    else
    {
        printf("Error.\n");
        return 0;
    }
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len;


    if(pArrayListEmployee!=NULL)
    {
            len=ll_len(pArrayListEmployee);
            if(len>0)
            {
                employee_list(pArrayListEmployee,len);
            }
            else
            {
                printf("\nNo hay lista cargada.\n");
            }
    }
    else
    {
        printf("Error!\n");
    }


    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int len;

    len=ll_len(pArrayListEmployee);


    printf("\nIngrese 1 para ordenar por nombre o 2 para ordenar por ID: \n");
    scanf("%d", &opcion);


    if(opcion==1 || opcion==2)
    {
        switch(opcion)
        {
            case 1:
                if(pArrayListEmployee!=NULL && len>0)
                {
                    printf("\nOrdenando...\n");
                    ll_sort(pArrayListEmployee,employee_CompareByName, 1);
                    printf("\nOrdenamiento finalizado...\n");

                }
                else
                {
                    printf("Error.");
                }
            break;
            case 2:
            if(pArrayListEmployee!=NULL && len>0)
            {
                printf("\nOrdenando...\n");
                ll_sort(pArrayListEmployee,employee_CompareById, 1);
                printf("\nOrdenamiento finalizado...\n");

            }
            else
            {
                printf("Error.");
            }
            break;
        }

    }
    else
    {
            printf("No ha seleccionado una opcion valida.");
    }



    return 1;
}




int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* miEmpleado;
    int i;
    int len;
    int auxId;
    char auxNombre[50];
    int auxSueldo;
    int auxHoras;

    len=ll_len(pArrayListEmployee);

    pFile=fopen(path,"w");
    fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
    for(i=0;i<len;i++)
    {
        miEmpleado=ll_get(pArrayListEmployee, i);
        employee_getId(miEmpleado,&auxId);
        employee_getNombre(miEmpleado, auxNombre);
        employee_getHorasTrabajadas(miEmpleado,&auxHoras);
        employee_getSueldo(miEmpleado,&auxSueldo);

        fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);

    }

    fclose(pFile);


    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* miEmpleado;
    int i;
    int len;

    len=ll_len(pArrayListEmployee);

    pFile=fopen(path,"wb");

    for(i=0;i<len;i++)
    {
        miEmpleado=ll_get(pArrayListEmployee, i);
        fwrite(miEmpleado,sizeof(Employee),1,pFile);

    }
    fclose(pFile);

    return 1;
}

void menu ()
{
    printf("*******************************\n");
    printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2-Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3-Alta de empleado\n");
    printf("4-Modificar datos de empleado\n");
    printf("5-Baja de empleado\n");
    printf("6-Listar empleados\n");
    printf("7-Ordenar empleados \n");
    printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9-Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10-Salir\n");
    printf("*******************************\n");

}
