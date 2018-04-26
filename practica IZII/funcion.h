#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
typedef struct
{
    char nombre [50];
    char apellido [50];
    int idUsuario;
    int isEmpty;
    char user[10];
    //int password[4];
}Usuario;
#endif // FUNCION_H_INCLUDED




int esSoloLetras(char []);
void getString(char[],char[]);
int getStringLetras(char[],int,char[]);
int esEntero(char[]);
int getInt(char*,char*,int,int,int,int*);
int getFloat(char*, char*, int, int, int, float*);
int usu_init(Usuario* arrayUsuarios,int sizeArray);
int usu_alta(Usuario* arrayUsuario,int sizeArray,int id);
int usu_listar(Usuario* arrayUsuarios,int sizeArray);
int usu_baja(Usuario* arrayUsuarios,int sizeArray,int id);
int usu_modificar(Usuario* arrayUsuarios, int sizeArray, int id);
