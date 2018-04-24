#include <stdio.h>
#include <stdlib.h>
#include "practica.h"
#define CANT 20

int main()
{
    int resultado;
    float resultadoF;
    char texto[CANT];
    char prueba[20];

    /*
    getInt("Ingrese numero","ERROR \n",2,0,5,&resultado);
    printf("ESO:  %d \n", resultado);


    getFloat("Ingrese numero float \n","ERROR",2,0,5,&resultadoF);
    printf("THAT: %.2f \n", resultadoF);


    prueba = esSoloLetras("Ingrese n");
    printf("%d \n", prueba);
    */
    getStringLetras("ingrese text \n", CANT, prueba);
    printf("%s", prueba);
    return 0;

}
