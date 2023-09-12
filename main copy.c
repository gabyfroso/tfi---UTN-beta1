#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>

int SizeConsole();
void Logo_ChanelLogo();
void *Funcion_A(void *arg);
void *Funcion_B(void *arg);

const int SizeLogoFila = 13;
const int SizeLogoColumna = 30;

int Program_in_Curse = 1;
int ConsoleSizeInt = 0;

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


struct FuncionAData
{
    char *Intro;
};

int main()
{
    char *xLogo = "*********************\nNombre:\n Frosoni, Hugo Gabriel\nCorreo:\n Gabyfroso@gmail.com\n\nNumero:\n +5493816164351\n\n*********************";
    pthread_t threadA;

    struct FuncionAData dataA;
    dataA.Intro = xLogo;

    system("color 2");
    // Crea el hilo para Funcion_A
    if (pthread_create(&threadA, NULL, Funcion_A, &dataA) != 0)
    {
        perror("Error al crear el hilo para Funcion_A");
        exit(EXIT_FAILURE);
    }

    // Espera a que los hilos terminen
    pthread_join(threadA, NULL);

    return 0;
}

// Función para Funcion_A
void *Funcion_A(void *arg)
{
    pthread_t threadB;

    int PosiCharIntro = 0, salteoN = 0;
    struct FuncionAData *data = (struct FuncionAData *)arg;
    char *Intro = data->Intro;

    while (1)
    {
        if (ConsoleSizeInt == 0 || ConsoleSizeInt != SizeConsole())
        {
            ConsoleSizeInt = SizeConsole();

            system("cls");
            for (int FilaConsole = 0; FilaConsole < 13; FilaConsole++)
            {
                // Logo ajustado izquierda
                for (int space = 0; space < SizeConsole() - SizeLogoColumna; space++)
                {
                    if (Intro[PosiCharIntro] != '\0')
                    {
                        if (Intro[PosiCharIntro] == '\n')
                        {
                            printf(" ");
                            salteoN++;
                        }

                        if (salteoN == 0)
                        {
                            printf("%c", Intro[PosiCharIntro]);
                            PosiCharIntro++;
                        }
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("  %s\n", LogoGatoMio[FilaConsole]);
                if (salteoN != 0)
                {
                    salteoN = 0;
                    PosiCharIntro++;
                }
            }
            PosiCharIntro = 0;

            
        }
        usleep(200); // Espera 0,2 segundos antes de verificar nuevamente

        if (Program_in_Curse == 0)
        {
            pthread_join(threadB, NULL);
            break;
        }
    }
    return NULL;
}

/*


**********

*******************

**********


*/

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