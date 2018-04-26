#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"


/** \brief Recibe una cadena de caracteres y valida que sean solo letras.
 *
 * \param str[] char Es la cadena de caracteres a analizar.
 * \return int 0= Ok. 1 Error.
 *
 */
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

/** \brief Toma una cadena de caracteres y la devuelve.
 *
 * \param mensaje[] char mensaje a mostrar.
 * \param input[] char cadena de string devuelta.
 * \return void
 *
 */
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
/** \brief Toma una cadena de chars y devuel
 *
 * \param str[] char
 * \return int
 *
 */
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
/** \brief
 *
 * \param mensaje char*
 * \param mensajeError char*
 * \param reIntentos int
 * \param minimo int
 * \param maximo int
 * \param resultado int*
 * \return int
 *
 */
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

/** \brief
 *
 * \param str[] char
 * \return int
 *
 */
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
    if(contador >= 0 || contador < 2)
    {
    return 0;
    }
    else{
    return -1;
    }
}

/** \brief
 *
 * \param mensaje char*
 * \param mensajeError char*
 * \param reIntentos int
 * \param minimo int
 * \param maximo int
 * \param resultado float*
 * \return int
 *
 */
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

/** \brief
 *
 * \param arrayUsuarios Usuario*
 * \param sizeArray int
 * \return int
 *
 */
int usu_init(Usuario* arrayUsuarios,int sizeArray)
{
    int i, retorno=-1;
    for(i=0;i < sizeArray; i++)
    {
        arrayUsuarios[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int usu_alta(Usuario* arrayUsuarios,int sizeArray,int id)
{
    int i,retorno=-1;
    for (i=0;i<sizeArray;i++)
    {
        if(arrayUsuarios[i].isEmpty==1)
        {
            getStringLetras("Ingrese el nombre\n", 50, arrayUsuarios[i].nombre);
            getStringLetras("Ingrese el apellido", 50, arrayUsuarios[i].apellido);
            getStringLetras("Ingrese usuario (solo letras) \n", 10, arrayUsuarios[i].user);
            //getInt("Ingrese password (solo 4 digitos) \n","Incorrecto", 3, 0, 9999, &arrayUsuarios[i].password);
            arrayUsuarios[i].idUsuario=i;
            arrayUsuarios[i].isEmpty=0;
            retorno=0;
            break;
        }
    } return retorno;
}

int usu_listar(Usuario* arrayUsuarios,int sizeArray)
{
    int i, retorno=-1;
    for (i=0; i< sizeArray;i++)
        if (arrayUsuarios[i].isEmpty== 0)
        {
            printf("Nombre: %s, Apellido: %s, id: %d\n", arrayUsuarios[i].nombre,arrayUsuarios[i].apellido, arrayUsuarios[i].idUsuario);
            retorno=0;
        }
        return retorno;
}

/** \brief Solicita el Id de un Usuario y lo da de baja.
 *
 * \param arrayUsuarios Usuario* struct de datos de los Usuarios.
 * \param sizeArray int cantidad maxima de Usuarios.
 * \param id int id del Usuario a dar de baja
 * \return int 0=Ok, -1 error.
 *
 */
int usu_baja(Usuario* arrayUsuarios,int sizeArray,int id)
{
    int retorno=-1;

        if (arrayUsuarios[id].isEmpty==0)
        {
            arrayUsuarios[id].isEmpty=1;
            retorno=0;
        } else
            {
                printf("Error. id de Usuario inexistente");
            }

    return retorno;
}

int usu_modificar(Usuario* arrayUsuarios, int sizeArray, int id)
{
    int retorno=-1;
    int opcion;
    int aux;
        if (arrayUsuarios[id].isEmpty==0)
        {

            getInt("Que desea modificar. \n1- nombre \n2-apellido\n3-usuario\n4-password.","ESA OPCION NO EXISTE!!", 2, 0, 4, &opcion);
            switch(opcion)
            {
                case 1:
                    getInt("Seguro que desea modificar? 1=si - 2=nop", "Opcion incorrecta", 0, 0, 2, &aux);
                    if(aux == 1)
                    {
                      getStringLetras("Ingrese el nombre\n", 50, arrayUsuarios[id].nombre);
                    }
                    break;
                case 2:
                    getInt("Seguro que desea modificar? 1=si - 2=nop", "Opcion incorrecta", 0, 0, 2, &aux);
                    if(aux == 1)
                    {
                      getStringLetras("Ingrese el apellido\n", 50, arrayUsuarios[id].apellido);
                    }
                    break;
                case 3:
                    getInt("Seguro que desea modificar? 1=si - 2=nop", "Opcion incorrecta", 0, 0, 2, &aux);
                    if(aux == 1)
                    {
                      getStringLetras("Ingrese el usuario\n", 50, arrayUsuarios[id].user);
                    }
                    break;
                /*
                case 4:getInt("Seguro que desea modificar? 1=si - 2=nop", "Opcion incorrecta", 0, 0, 2, &aux);
                    if(aux == 1)
                    {
                      getStringLetras("Ingrese el password\n", 50, arrayUsuarios[id].password);
                    }
                    break;
                */
            }
            retorno=0;


        } else
            {
                printf("Error. id de Usuario inexistente");
            }

    return retorno;

}
