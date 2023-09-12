#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>

int SizeConsole();
void Logo_ChanelLogo();
int RecompletarDatos_y_Logo(const char *Intro);
void *Funcion_A(void *args);
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
    void (*F_b)();
};

void Bienvenida()
{
    printf("Bienvenido\n");

    char IntSalida[10] = "a";
    do
    {
        printf("\nSalir: -5");
        printf("\n\t>");
        scanf(" %s", IntSalida);

        if (atoi(IntSalida) == -5)
        {
            Program_in_Curse = 0;
        }

    } while (atoi(IntSalida) != -5);
}

int main()
{
    char *xLogo = "*********************\nNombre:\n Frosoni, Hugo Gabriel\nCorreo:\n Gabyfroso@gmail.com\n\nNumero:\n +5493816164351\n\n*********************";
    pthread_t threadA;
    struct FuncionAData args;

    args.Intro = xLogo;
    args.F_b = Bienvenida;

    system("color 2");
    // Crea el hilo para Funcion_A
    if (pthread_create(&threadA, NULL, Funcion_A, &args) != 0)
    {
        perror("Error al crear el hilo para Funcion_A");
        exit(EXIT_FAILURE);
    }

    // Espera a que los hilos terminen
    pthread_join(threadA, NULL);

    return 0;
}

// Función para Funcion_A
void *Funcion_A(void *args)
{
    struct FuncionAData *thread_args = (struct FuncionAData *)args;
    const char *Intro = thread_args->Intro;
    void (*F_b)() = thread_args->F_b;

    // Crear un hilo para ejecutar F_b de forma asíncrona
    pthread_t thread_b;

    while (1)
    {
        if (ConsoleSizeInt == 0 || ConsoleSizeInt != SizeConsole())
        {
            ConsoleSizeInt = SizeConsole();

            system("cls");
            RecompletarDatos_y_Logo(Intro);

            if (thread_b != 0)
            {
                pthread_detach(thread_b);
            }

            if (pthread_create(&thread_b, NULL, (void *)F_b, NULL) != 0)
            {
                perror("Error al crear el hilo para F_b");
                pthread_exit(NULL);
            }
        }
        usleep(200); // Espera 0,2 segundos antes de verificar nuevamente

        if (Program_in_Curse == 0)
        {
            pthread_detach(thread_b);

            pthread_exit(NULL);
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

int RecompletarDatos_y_Logo(const char *Intro)
{
    int salteoN = 0;
    int PosiCharIntro = 0;
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