

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
    int flagFactorizar=0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicar;
    float resultadoDivision;
    int resultadoFactorizarUno;
    int resultadoFactorizarDos;
    int okDivision=-1;



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

            		resultadoResta=restar(primerOperando, segundoOperando);

            		resultadoSuma=sumar(primerOperando, segundoOperando);

            		resultadoMultiplicar=multiplicar(primerOperando, segundoOperando);

            		if(primerOperando>0 && primerOperando<11 && segundoOperando>0 && segundoOperando<11)
            		{
            			resultadoFactorizarUno=factorizar(primerOperando);
            			resultadoFactorizarDos=factorizar(segundoOperando);
            			flagFactorizar=1;
            		}
            		else
            		{
            			flagFactorizar=0;
            			printf("\nPara calcular el factorial ingrese numeros del 1 y 10\n\n");
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
                    printf("\n\n");

                    printf("El resultado de A+B es= %d .\n", resultadoSuma);
                    printf("El resultado de A-B es= %d .\n", resultadoResta);
                    printf("El resultado de A*B es= %d .\n", resultadoMultiplicar);


                	if(okDivision==1)
                    {
                        printf("El resultado de A/B es: %f. \n", resultadoDivision);
                    }
                    else
                    {
                        printf("Error en la division.\n");
                    }
                    if(flagFactorizar==1)
                    {
                    	printf("El resultado de la factorizacion de A es : %d .\n", resultadoFactorizarUno);
                    	printf("El resultado de la factorizacion de B es : %d .\n", resultadoFactorizarDos);
                    }
                    printf("\n\n");
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
