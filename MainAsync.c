#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>

// Función para Funcion_A
void* Funcion_A(void* arg) {
    while (1) {
        // Realiza alguna tarea en Funcion_A
        // Aquí puedes verificar si el tamaño de la consola ha cambiado y actualizarla si es necesario
        printf("Funcion_A está ejecutándose...\n");
        sleep(2);  // Espera 2 segundos antes de verificar nuevamente
    }
    return NULL;
}

// Función para Funcion_B
void* Funcion_B(void* arg) {
    char input;
    printf("Funcion_B está esperando la entrada de 'a' del usuario...\n");
    
    while (1) {
        // Lee la entrada del usuario
        scanf(" %c", &input);
        
        if (input == 'a') {
            printf("Funcion_B ha recibido 'a' del usuario.\n");
            break;  // Sale del bucle si se ingresa 'a'
        }
    }
    return NULL;
}

int main() {
    pthread_t threadA, threadB;

    // Crea el hilo para Funcion_A
    if (pthread_create(&threadA, NULL, Funcion_A, NULL) != 0) {
        perror("Error al crear el hilo para Funcion_A");
        exit(EXIT_FAILURE);
    }

    // Crea el hilo para Funcion_B
    if (pthread_create(&threadB, NULL, Funcion_B, NULL) != 0) {
        perror("Error al crear el hilo para Funcion_B");
        exit(EXIT_FAILURE);
    }

    // Espera a que los hilos terminen
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    return 0;
}


/*


**********

*******************

**********


*/
const int SizeLogoFila = 13;
const int SizeLogoColumna = 30;

const char *LogoGatoMio[13] = {
    "@@@@@/@@@@@@@@@@@@@@@@@/@@@",
    "@@@//////@@@@@@@@@@@&////@@",
    "@@/////////@@@@@@@@///////&",
    "@/////////////////////////&",
    "&////////////////////////&@", //
    "@&///////////////////////Y@",
    "&////////////////////////6@",
    "a////////////////////////@@",
    "v///////////////////////-@@",
    "@@/////////////////////@@@@", // 28 char - 13 filas
    "v@@///@@@//////////@///@@@@",
    "  @@@@@/////////////@@@@@@ ",
    "    @@@@@@@@@@@@@@@@@@@@  "};

int SizeConsole()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return columns;
}

void Logo_ChanelLogo()
{
    int SizeConsoleAnterior = SizeConsole();

    for (int i = 0; i < 13; i++)
    {
        for (int space = 0; space < SizeConsole() - SizeLogoFila; space++)
        {
            printf(" ");
        }
        printf("%s\n", LogoGatoMio[i]);
    }

    do
    {
        if (SizeConsoleAnterior != SizeConsole())
        {
            system("cls");
            Sleep(20);
            SizeConsoleAnterior = SizeConsole();
            for (int i = 0; i < 13; i++)
            {
                for (int space = 0; space < SizeConsole() - 30; space++)
                {
                    printf(" ");
                }
                printf("%s\n", LogoGatoMio[i]);
            }

            Sleep(90);
        }

    } while ('d' == 'd');
}