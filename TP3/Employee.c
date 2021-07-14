#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
    Employee* miEmpleado;

    miEmpleado=(Employee*) malloc (sizeof(Employee));

    return miEmpleado;

}


Employee* nuevoEmpleado()
{
    Employee* miEmpleado;
    char auxNom[50];
    char auxId[50];
    char auxHoras[50];
    int auxHorasInt;
    char auxSueldo[50];
    int auxSueldoInt;

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", auxNom);
    while(esSoloLetras(auxNom)==0 || strlen(auxNom)>20)
    {
        printf("Error. Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", auxNom);
    }

    printf("Ingrese horas trabajadas: ");
    fflush(stdin);
    gets(auxHoras);
    auxHorasInt=atoi(auxHoras);
    while(esNumerico(auxHoras)==0 || auxHorasInt<0 || auxHorasInt>100000)
    {
        printf("Error. Ingrese horas trabajadas: ");
        fflush(stdin);
        gets(auxHoras);
        auxHorasInt=atoi(auxHoras);
    }

    printf("Ingrese sueldo: ");
    fflush(stdin);
    gets(auxSueldo);
    auxSueldoInt=atoi(auxSueldo);
    while(esNumerico(auxSueldo)==0 || auxSueldoInt<0 || auxSueldoInt>100000)
    {
        printf("Error. Ingrese sueldo: ");
        fflush(stdin);
        gets(auxSueldo);
        auxSueldoInt=atoi(auxSueldo);
    }

    strcpy(auxId,"error");
    miEmpleado=employee_newParametros(auxId,auxNom,auxHoras,auxSueldo);


    return miEmpleado;

}
int employee_NewId(LinkedList* pArrayListEmployee)
{
    int len;
    Employee* aux;
    int auxId;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        len--;
        aux=(Employee*)ll_get(pArrayListEmployee, len);
        if(aux!=NULL)
        {
            employee_getId(aux,&auxId);
            auxId++;
            printf("\n El ID del nuevo empleado es: %d\n", auxId);
        }
        else
        {
            auxId=-1;
            printf("No hay lista cargada.\n");
        }
    }
    else
    {
        printf("Error./n");
    }


    return auxId;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* miEmpleado;
    int auxInt;
    int auxNom;
    int auxHoras;
    int auxSueldo;

    miEmpleado=employee_new();


    auxInt=employee_setId(miEmpleado,atoi(idStr)); // todo esto dentro del IF
    auxNom=employee_setNombre(miEmpleado,nombreStr);
    auxHoras=employee_setHorasTrabajadas(miEmpleado,atoi(horasTrabajadasStr));
    auxSueldo=employee_setSueldo(miEmpleado,atoi(sueldoStr));

    if(auxInt==1 && auxNom==1 && auxHoras==1 && auxSueldo==1)
    {
        employee_setId(miEmpleado,atoi(idStr));
        employee_setNombre(miEmpleado,nombreStr);
        employee_setHorasTrabajadas(miEmpleado,atoi(horasTrabajadasStr));
        employee_setSueldo(miEmpleado,atoi(sueldoStr));
    }

    return miEmpleado;// retornar mieEmpleado // si no miEmpleado=NULL

}

int employee_list(LinkedList* pArrayListEmployee, int len)
{
    int i;
    Employee* aux;


    for(i=0; i<len; i++)
   {
        aux=(Employee*)ll_get(pArrayListEmployee, i);
        mostrarEmpleado(aux);
        ///TODOS LOS GET Y PRINTF VAN DENTRO DE LA FUNCION MOSTRAREMPLEADO
        ///ESTA FUNCION SOLO LLAMA A LA FUNCION MOSTRAR
    }

    return 0;
}

int mostrarEmpleado(Employee* aux)
{
    int id;
    int horas;
    char nombre[50];
    int sueldo;
    int auxInt;
    int auxNom;
    int auxHoras;
    int auxSueldo;


    auxInt=employee_getId(aux, &id); //PONER LA VALIDACION DENTRO IF
    auxNom=employee_getNombre(aux, nombre);
    auxHoras=employee_getHorasTrabajadas(aux, &horas);
    auxSueldo=employee_getSueldo(aux,&sueldo);

    if(auxInt==1 && auxNom==1 && auxHoras==1 && auxSueldo==1)
    {   employee_getId(aux, &id);
        employee_getNombre(aux, nombre);
        employee_getHorasTrabajadas(aux, &horas);
        employee_getSueldo(aux,&sueldo);
        printf("%4d |%15s |%8d | %4d\n",id,nombre,horas,sueldo);
    }
    else
    {
        printf("No se encontro.\n");
    }

    return 0;
}

int employee_setId(Employee* this,int id)
{
    if(id>0 && this!=NULL)
    {
        this -> id = id;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_getId(Employee* this,int* id)
{
    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}
int employee_getNombre(Employee* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this!=NULL)
    {
        this -> horasTrabajadas = horasTrabajadas;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 1;
    }
    else
    {
        return 0;
    }

}

int employee_setSueldo(Employee* this,int sueldo)
{
    if(this!=NULL)
    {
        this -> sueldo = sueldo;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        return 1;
    }
    else
    {
        return 0;
    }
}


int employee_CompareByName(void* e1, void* e2)
{
    Employee* auxEmpleado;
    Employee* auxEmpleadoDos;
    char nombreUno[50];
    char nombreDos[50];


    int resultado;
    auxEmpleado=e1;
    auxEmpleadoDos=e2;

    if(e1!=NULL && e2!=NULL)
    {
        employee_getNombre(auxEmpleado,nombreUno);
        employee_getNombre(auxEmpleadoDos,nombreDos);
        resultado=strcmp(nombreUno,nombreDos);
    }

    return resultado;
}

int employee_CompareById(void* e1, void* e2)
{
    int comp = 0;

    Employee* auxEmpleado;
    Employee* auxEmpleadoDos;
    auxEmpleado=e1;
    auxEmpleadoDos=e2;
    int idUno;
    int idDos;

    if(e1!=NULL && e2!=NULL)
    {
        employee_getId(auxEmpleado, &idUno);
        employee_getId(auxEmpleadoDos, &idDos);
        comp=idUno-idDos;
        //va a retornar mayor o menor segun este antes o despues
    }
    return comp;

}

int employee_IndexById(LinkedList* pArrayListEmployee,int id)
{
    Employee* miEmpleado;
    int len;
    int index;
    int i;
    int auxId;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            miEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(miEmpleado,&auxId);
            if(id==auxId)
            {
                index=i;
            }

        }
        return index;
    }
    else
    {
        return -1;
    }

}
