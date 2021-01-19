#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encriptar(){
    
    int i, j, v, t, f=0, r=0;
    int grado, columnas, renglones;
    int c[200], d[200];
    long veces;
    char mensaje[200], ch;
    
    
    //PEDIR EL GRADO DE LA MATRIZ
    printf("\nIndique el grado de la matriz: ");
    scanf("%d", &grado);
       
    
    // PEDIR EL TEXTO A ENCRIPTAR
    printf("\nTeclee el mensaje a cifrar (sin espacios): ");
    scanf("%s", mensaje);
       
    
    //FORMATEAR EL MENSAJE (PASANDO A MAYUSCULAS Y RELLENANDO CON 'X')
       for (i=0; i<=strlen(mensaje); i++) {

           ch = mensaje[i];
               
           //SI EL CARACTER ES ALFANUMERICO LO PASA A MAYUSCULAS
           if(isalpha(ch)){
               mensaje[i]=toupper(ch);
           }
           
           //SI NO ALCANZA A CUBRIR EL GRADO DE LA MATRIZ LE AGREGA UNA X HASTA COMPLETAR
           if(strlen(mensaje) % grado != 0){
               strcat(mensaje, "X");
           }
       }

    
    //CONTRUIR LA MATRIZ
    int a[grado][grado];
    renglones = grado;
    columnas = grado;
    
    printf("\nIngresa la matriz de %d x %d (debe ser reversible): \n", grado, grado);
       
    //LLENAR LA MATRIZ
    for (i=0; i<renglones; i++) {
       for (j=0; j<columnas; j++) {
           printf("\t[%d][%d]: ", i, j);
           scanf("%d", &a[i][j]);
           
       }
    }
       
       
    //IMPRIMIR LA MATRIZ
    printf("\n\tMATRIZ\n");
    for (i=0; i<renglones; i++) {
       for (j=0; j<columnas; j++) {
           printf("\t%d ", a[i][j]);
       }
       printf("\n");
    }
       

    //OBTENER LOS CARACTERES EN NUMEROS RESPECTO A ASCII
    printf("\nMensaje: %s en numeros del 0 al 26 es: ", mensaje);
    for (i=0; i<strlen(mensaje); i++) {
        c[i]= mensaje[i]-65;
        printf("%d ", c[i]);
    }
       

    //MULTIPLICAR LOS NUMEROS OBTENIDOS CON LA MATRIZ
       
    //OBTENER EL NUMERO DE VECES QUE SE HARA, PARTIR EL MENSAJE EN PARTES IGUALES
    veces = strlen(mensaje) / grado;

       for (v=0; v<veces; v++) {
           for (i=0; i<grado; i++) {
                t=0;
                f = grado * v;
               for (j=0; j<grado; j++,f++) {
                   t = t + (a[i][j] * c[f]);
               }
                d[r]=t%26;
                r = r+1;
           }
       }
       
       
       
    //PRESENTAR TEXTO ENCRIPTADO
    printf("\nTexto encriptado: ");
       
    for (i=0; i<strlen(mensaje); i++) {
        printf("%c",d[i] + 65);
    }

    printf("\n");
    
}

void desencriptar(){
    
    int i, j, v, t, f=0, r=0;
    int grado, columnas, renglones;
    int c[200], d[200];
    long veces;
    char mensaje[200], ch;
    
    
    //PEDIR EL GRADO DE LA MATRIZ
    printf("\nIndique el grado de la matriz reversible: ");
    scanf("%d", &grado);
       
    
    // PEDIR EL TEXTO A ENCRIPTAR
    printf("\nTeclee el mensaje a descifrar (sin espacios): ");
    scanf("%s", mensaje);
       
    
    //FORMATEAR EL MENSAJE (PASANDO A MAYUSCULAS Y RELLENANDO CON 'X')
    for (i=0; i<=strlen(mensaje); i++) {

        ch = mensaje[i];

        //SI EL CARACTER ES ALFANUMERICO LO PASA A MAYUSCULAS
        if(isalpha(ch)){
            mensaje[i]=toupper(ch);
        }

        //SI NO ALCANZA A CUBRIR EL GRADO DE LA MATRIZ LE AGREGA UNA X HASTA COMPLETAR
        if(strlen(mensaje) % grado != 0){
            strcat(mensaje, "X");
        }
    }

    
    //CONTRUIR LA MATRIZ
    int a[grado][grado];
    renglones = grado;
    columnas = grado;
    
    printf("\nIngresa la matriz reversible de %d x %d: \n", grado, grado);
       
    //LLENAR LA MATRIZ
    for (i=0; i<renglones; i++) {
       for (j=0; j<columnas; j++) {
           printf("\t[%d][%d]: ", i, j);
           scanf("%d", &a[i][j]);
           
       }
    }
       
       
    //IMPRIMIR LA MATRIZ
    printf("\n\tMATRIZ\n");
    for (i=0; i<renglones; i++) {
       for (j=0; j<columnas; j++) {
           printf("\t%d ", a[i][j]);
       }
       printf("\n");
    }
       

    //OBTENER LOS CARACTERES EN NUMEROS RESPECTO A ASCII
    printf("\nMensaje: %s en numeros del 0 al 26 es: ", mensaje);
    for (i=0; i<strlen(mensaje); i++) {
        c[i]= mensaje[i]-65;
        printf("%d ", c[i]);
    }
       

    //MULTIPLICAR LOS NUMEROS OBTENIDOS CON LA MATRIZ
       
    //OBTENER EL NUMERO DE VECES QUE SE HARA, PARTIR EL MENSAJE EN PARTES IGUALES
    veces = strlen(mensaje) / grado;

       for (v=0; v<veces; v++) {
           for (i=0; i<grado; i++) {
                t=0;
                f = grado * v;
               for (j=0; j<grado; j++,f++) {
                   t = t + (a[i][j] * c[f]);
               }
                d[r]=t%26;
                r = r+1;
           }
       }
    
    
    //PRESENTAR TEXTO ENCRIPTADO
    printf("\nTexto desencriptado: ");
       
    for (i=0; i<strlen(mensaje); i++) {
        printf("%c",d[i] + 65);
    }

    printf("\n");
    
    
}

int main(){

    int opcion;

    do
    {
        printf("\n\n CIFRADO HILL");
        printf( "\n   1. Encriptar.");
        printf( "\n   2. Desencriptar.");
        printf( "\n   3. Salir." );
        printf( "\n\n   Introduzca opcion (1-3): ");

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1: encriptar();
                    break;

            case 2: desencriptar();
                    break;
         }
    } while ( opcion != 3 );

    return 0;
}
