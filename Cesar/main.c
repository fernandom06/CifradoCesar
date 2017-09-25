#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para la funcion strlen

#define LONGITUD 50
//Variables
int opcion;
char mensaje[LONGITUD];
char alfabeto[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',};


//Subprogramas
int Menu();
void limpiarPantalla();
void limpiarBuffer();
void Pausa();
void Cifrar();
void Descifrar();


int main()
{
    do{
        Menu();//Menu principal
        switch(opcion){
            case 1://Cifrar
                Cifrar();
                break;
            case 2://Descifrar
                Descifrar();
                break;
            case 0://Salir del programa
                limpiarPantalla();
        }
    }while(opcion!=0);
    return 0;
}

/*Subprograma para limpiar pantalla*/
void limpiarPantalla()
{
    system("cls");
}


/*Subprograma para limpiar el buffer del teclado*/
void limpiarBuffer()
{
    fflush(stdin);
}


/*Subprograma para realizar una pausa en el programa*/
void Pausa()
{
    getchar();
}

/*Subprograma que muestra el menu principal*/
int Menu()
   {
            limpiarPantalla();
            printf("\t------------------------------------------------\n");
            printf("\t\t\t\t CIFRADO CESAR \n");
            printf("\t------------------------------------------------\n\n");
            printf("1.- Cifrar\n");
            printf("2.- Descifrar\n");
            printf("0.- Salir \n");
            printf("\n Elija una opci%cn: ",162);
            limpiarBuffer();
            scanf("%d", &opcion);
    return opcion;
   }

void Cifrar()
{
    int i,j,numero;
    char criptograma[LONGITUD];

    limpiarPantalla();
    printf("Introduzca mensaje a cifrar: ");
    limpiarBuffer();
    gets(mensaje);//pedir frase al usuario
    limpiarBuffer();
    numero=strlen(mensaje);
    printf("Pulse intro para continuar");
    Pausa();
    for(i=0;i<numero;i++){
        for(j=0;j<strlen(alfabeto);j++){
            if(mensaje[i]==alfabeto[j] && mensaje[i]!=alfabeto[24] && mensaje[i]!=alfabeto[25] && mensaje[i]!=alfabeto[26]){
                criptograma[i]=alfabeto[j+3];
            }
            else if(mensaje[i]==alfabeto[24]){
                criptograma[i]=alfabeto[0];
            }
        }
    }
    printf("Su criptograma es: ");
    for(i=0;i<numero;i++){
        printf("%c",criptograma[i]);
    }
    Pausa();
}


void Descifrar()
{
    int i,j,numero;
    char criptograma[LONGITUD];

    limpiarPantalla();
    printf("Introduzca mensaje a cifrar: ");
    limpiarBuffer();
    gets(mensaje);//pedir frase al usuario
    limpiarBuffer();
    numero=strlen(mensaje);
    printf("Pulse intro para continuar");
    Pausa();
    for(i=0;i<numero;i++){
        for(j=0;j<strlen(alfabeto);j++){
            if(mensaje[i]==alfabeto[j]){
                if(mensaje[i]==alfabeto[24]){
                    criptograma[i]=alfabeto[0];
                }
                else if(mensaje[i]==alfabeto[25]){
                    criptograma[i]=alfabeto[1];
                }
                 else if(mensaje[i]==alfabeto[26]){
                    criptograma[i]=alfabeto[2];
                }
                criptograma[i]=alfabeto[j+3];
            }
        }
    }
    printf("Su criptograma es: ");
    for(i=0;i<numero;i++){
        printf("%c",criptograma[i]);
    }
    Pausa();
}
