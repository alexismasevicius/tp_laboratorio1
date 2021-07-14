#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int i;
    int cont;
    int len;
    char id[50];
    char nombre[50];
    char horas[50];
    char sueldo[50];
    Employee* miEmpleado;


    i=0;

    cont = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",id,nombre,horas,sueldo);
    while(!feof(pFile))
    {
        cont = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horas,sueldo);

        if(cont==4)
        {
            miEmpleado=employee_newParametros(id,nombre,horas,sueldo);

            ll_add(pArrayListEmployee, miEmpleado);

            i++;
        }

    }
    fclose(pFile);

    len = ll_len(pArrayListEmployee);

    employee_list(pArrayListEmployee,len);

    printf("cantidad de elementos cargados es de: %d \n", len);

    return 1;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* miEmpleado;


    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            miEmpleado=(Employee*)malloc(sizeof(Employee));
            fread(miEmpleado,sizeof(Employee),1,pFile);
            if(feof(pFile))
            {
               break;
            }
            ll_add(pArrayListEmployee,miEmpleado);

        }
        return 1;
    }

    return 0;
}
