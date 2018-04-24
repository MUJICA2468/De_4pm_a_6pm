#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 0)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}

int getFloat(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,float* resultado)
{
    int retorno = -1;
    char buffer[4096];
    double auxiliarDouble;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(contadorPuntos(buffer) == 0)
        {
            auxiliarDouble = atof(buffer);
            if(auxiliarDouble >= minimo && auxiliarDouble <= maximo)
            {
                *resultado = (float)auxiliarDouble;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}

int esEntero(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return -1;
       i++;
   }
   return 0;

}

int contadorPuntos(char str[])
{
    int i = 0, contador = 0;

    while(str[i]!= '\0')
    {

        if(str[i] == '.')
        {
             contador++;
        }
        i++;
    }
    if(contador > 0 || contador < 2)
    {
    return 0;
    }
    else{
    return -1;
    }
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 1;
       i++;
   }
   return 0;

}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}
int getStringLetras(char mensaje[],int cant,char input[])
{
    char aux[cant];
    getString(mensaje,aux);
    if(esSoloLetras(aux)==0)
    {
        strcpy(input,aux);
        return 0;
    }
    return -1;
}
