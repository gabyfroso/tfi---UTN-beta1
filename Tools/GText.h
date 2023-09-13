#pragma ONCE
#include <stdio.h>
#include <windows.h>

/*
Seccion dedicada al texto para simplificar lo que diga
*/
void GOptions_classic(int x);
void GOptions_menu();
void GOptions_Ajustes();

void GOptions_menu()
{
    printf("\nMenu\n");
    printf("\n1_ TFI");
    printf("\n2_ Ajustes");
    printf("\n3_ Mas info creador");
    GOptions_classic(0);
    sleep(1);
}

void GOptions_Ajustes()
{
    printf("\n\tMenu - Ajustes\n");
    printf("\n1_ Activar/Desactivar Logo");
    printf("\n2_ Activar/Desactivar Actualizacion por cambio de consola");
    printf("\n3_ Activar/Desactivar Ambos");
    GOptions_classic(0);
    sleep(1);
}

/*


**********

*******************

**********


*/

void GOptions_classic(int x)
{
    if (x == 0)
    {
        printf("\n\nSalir(Forzado): -5");
        printf("\n\t>");
    }
}