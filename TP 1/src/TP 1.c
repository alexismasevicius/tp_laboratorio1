/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "funciones.h"
#include "utn.h"


int main()
{

    int primerOperando;
    int segundoOperando;
    int seleccionador=1;
    int flagUno=0;
    int flagDos=0;
    float resultadoDivision;
    int resultadoFactorizarUno;
    int resultadoFactorizarDos;
    int okDivision=-1;

	setbuf(stdout, NULL);


    do
    {
        menuPrincipal(flagUno,flagDos,primerOperando,segundoOperando);
        utn_getNumero(&seleccionador,"Ingrese una opcion: \n","Error. Ingrese una opcion de menu valida.\n\n",1,5,10);
        printf("Usted ha seleccionado la opcion: %d.\n", seleccionador);

        switch(seleccionador)
        {
            case 1:
                flagUno=utn_getNumero(&primerOperando,"Ingrese el primer numero: \n","Error. Ingrese un numero correcto\n",-32000,32000,10);
                if(flagUno==1)
                {
                    printf("Usted ha seleccionado el numero: %d.\n", primerOperando);
                }
                break;
            case 2:
                flagDos=utn_getNumero(&segundoOperando,"Ingrese el segundo numero: \n","Error. Ingrese un numero correcto\n",-32000,32000,10);

                if(flagDos==1)
                {
                    printf("Usted ha seleccionado el numero: %d.\n", segundoOperando);
                }
                break;
            case 3:
            	if(flagDos==1 && flagUno==1)
            	{
            		okDivision=dividir(primerOperando,segundoOperando,&resultadoDivision);
            		if(primerOperando>0 && primerOperando<11 && segundoOperando>0 && segundoOperando<11)
            		{
            			resultadoFactorizar=factorizar(primerOperando);
            		}
            		else
            		{
            			printf("Para calcular el factorial ingrese un numero del 1 y 10\n");
            		}
            	}
            	else
            	{
            		printf("Debe ingresar los dos numeros para calcular.\n");
            	}
                break;
            case 4:
                if(flagDos==1 && flagUno==1)
                {
                    if(okDivision==1)
                    {
                        printf("El resultado de A/B es: %f. \n", resultadoDivision);
                    }
                    else
                    {
                        printf("Error en la division.\n");
                    }
                }
                else
                {
                    printf("Primero ingrese ambos numeros.\n");
                }
                break;
            case 5:
                break;
        }
    }while(seleccionador!=5);


    return 0;
}
