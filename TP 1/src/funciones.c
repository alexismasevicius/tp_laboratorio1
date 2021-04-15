/*
 * funciones.c
 *
 *  Created on: 15 abr. 2021
 *      Author: Alex
 */


#include <stdio.h>
#include <stdlib.h>


int menuPrincipal (int flagUno, int flagDos, int primerOperando, int segundoOperando)
{

    printf("************************************************\n");
    if(flagUno==0)
    {
    printf("*     1-Ingresar primer operando     A=X       *\n");
    }
    else
    {
    printf("*     1-Ingresar primer operando     A=%-8d*\n", primerOperando);
    }
    if(flagDos==0)
    {
    printf("*     2-Ingresar segundo operando    B=X       *\n");
    }
    else
    {
    printf("*     2-Ingresar segundo operando    B=%-8d*\n",segundoOperando);
    }
    printf("*     3-Calcular operaciones                   *\n");
    printf("*        a-Calcular suma                       *\n");
    printf("*        b-Calcular resta                      *\n");
    printf("*        c-Calcular multiplicacion             *\n");
    printf("*        d-Calcular division                   *\n");
    printf("*        e-Calcular factorial                  *\n");
    printf("*     4-Informar resultados                    *\n");
    printf("*     5-Salir                                  *\n");
    printf("************************************************\n");

    return 0;
}



int sumar (int operador1,int operador2)
{
    int resultado;

    resultado = operador1 + operador2;

    return resultado;
}

int restar (int operador1,int operador2)
{
    int resultado;

    resultado = operador1 - operador2;

    return resultado;
}

int multiplicar (int operador1,int operador2)
{
    int resultado;

    resultado = operador1 * operador2;

    return resultado;
}



/** \brief realiza una division entre dos enteros.
 *
 * \param 1: operador1 dividendo.
 * \param 2: operador2 divisor.
 * \param 3: operadorSalida Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \return Retorna  1 si es exitosa, 0 si es ERROR
 *
 */
float dividir (int operador1, int operador2, float* operadorSalida)
{
    int todoOk = 0;

    if(operador2!=0 && operadorSalida!=NULL)
    {
        *operadorSalida=(float)operador1/operador2;
        todoOk=1;
    }
    return todoOk;
}

int factorizar (int operador)
{
    int resultado;

    if(operador==0)
    {
        resultado=1;
    }
    else
    {
        resultado=operador*factorizar(operador-1);
    }
    return resultado;
}
