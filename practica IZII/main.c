#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"
#define QTY 100
int main()
{
    Usuario ArrayUsuarios[QTY];


    int opcion;
    int auxId;
    usu_init(ArrayUsuarios, QTY);

    do{

        getInt("Ingrese lo que quiera:\n1- ALTA \n2- BAJA \n3- MODIFICACION \n4- MOSTRAR/LISTAR \n5 -ORDENAR\n6- SALIR", "ERROR", 2,0,9, &opcion);
        switch(opcion)
        {
            case 1:
                printf("ALTA: \n");
                usu_alta(ArrayUsuarios, QTY, 0);
            break;
            case 2:
                getInt("Ingrese el numero id a daar de baja : \n", "numero no valido", 2, 0, QTY, &auxId);
                usu_baja(ArrayUsuarios, QTY, auxId);
            break;
            case 3:
                getInt("Ingrese el numero id a modificar: \n", "numero no valido", 2, 0, QTY, &auxId);
                usu_modificar(ArrayUsuarios, QTY, auxId);
            break;
            case 4:
                usu_listar(ArrayUsuarios, QTY);
            break;
            case 5:
                printf("YA!!");
                break;

       system("pause");
       //system("cls");
       }


    }while(opcion != 6);

    return 0;
}
