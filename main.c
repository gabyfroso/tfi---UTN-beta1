#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include "lib/GGraphs.h"
#include "Tools/GText.h"

struct FuncionAData
{
    char *Intro;
    void (*F_b)();
};
int ConsoleSizeInt = 0;
int Tools[3] = {1, 1, 1}; // Exit[0] Logo[1] SizeConsole[2]

void SuperFunction();
void Menu_Ajustes();

void CentralData(int Graphs_Change_Preferences[3]);
void *Central_ASync(void *args);

void ExitAll();

int main()
{
    char *xLogo = "*********************\nNombre:\n Frosoni, Hugo Gabriel\nCorreo:\n Gabyfroso@gmail.com\n\nNumero:\n +5493816164351\nForced Exit -5\n*********************";
    pthread_t threadA;
    struct FuncionAData args;

    args.Intro = xLogo;
    args.F_b = SuperFunction;

    system("color 2");
    // Crea el hilo para Funcion_A
    if (pthread_create(&threadA, NULL, Central_ASync, &args) != 0)
    {
        perror("Error al crear el menu, consultar a Gabyfroso");
        exit(EXIT_FAILURE);
    }

    // Espera a que los hilos terminen
    pthread_join(threadA, NULL);

    return 0;
}

/*


*******************


*/

void SuperFunction()
{
    char IntSalida[10] = "";
    do
    {
        memset(IntSalida, 0, sizeof(IntSalida));
        GOptions_menu();
        usleep(200);
        scanf(" %s", IntSalida);
        sleep(1);

        switch (atoi(IntSalida))
        {
        case 2:
        {
            Menu_Ajustes();
        }
        break;
        case 5:
            ExitAll();
            break;
        case -5:
        {
            ExitAll();
        }
        break;

        default:
            break;
        }
        system("cls");
    } while (atoi(IntSalida) != -5);
}

void Menu_Ajustes()
{
    char IntSalida[10] = "a";
    do
    {
        GOptions_Ajustes();
        usleep(200);
        scanf(" %s", IntSalida);
        sleep(1);

        switch (atoi(IntSalida))
        {
        case 1:
        {
            int x[3] = {0, 1, 0};
            CentralData(x);
        }
        break;
        case 2:
        {
            int x[3] = {0, 0, 1};
            CentralData(x);
        }
        break;
        case 3:
        {
            int x[3] = {0, 1, 1};
            CentralData(x);
        }
        break;
        case 5:
            goto fin;
            break;
        case -5:
            goto fin;
            break;

        default:
            break;
        }

        system("cls");

    } while (atoi(IntSalida) != -5);
fin:
}

void CentralData(int Graphs_Change_Preferences[3])
{
    // Exit[0] Logo[1] SizeConsole[2]
    /*
        Se recomienda Volver a poner el texto desde el inicio debido a la limpieza.
        Exceptuando que quieras apagarla, claro.
    */
    if (Graphs_Change_Preferences[0] == 1)
    {
        printf("\nForzando cierre");
        for (int i = 0; i < 3; i++)
        {
            printf(".");
            sleep(1);
        }

        usleep(400);
        Tools[0] = 0;
    }
    if (Graphs_Change_Preferences[1] == 1)
    {
        switch (Tools[1])
        {
        case 0:
        {
            printf("\nLogo Activado");
            sleep(2);
            Tools[1] = 1;
        }
        break;
        case 1:
        {
            printf("\nLogo Desactivado");
            sleep(2);
            Tools[1] = 0;
        }
        break;
        }
    }
    if (Graphs_Change_Preferences[2] == 1)
    {
        switch (Tools[2])
        {
        case 0:
        {
            printf("\nActualizacion por consola Activado");
            sleep(2);
            Tools[2] = 1;
        }
        break;
        case 1:
        {
            printf("\nActualizacion por consola Desactivado");
            sleep(2);
            Tools[2] = 0;
        }
        break;
        }
    }

    ConsoleSizeInt = 0;
}

/*


**********




*******************




**********


*/

// Función para Funcion_A
void *Central_ASync(void *args)
{
    struct FuncionAData *thread_args = (struct FuncionAData *)args;
    const char *Intro = thread_args->Intro;
    void (*To_Menu)() = thread_args->F_b;

    // Crear un hilo para ejecutar F_b de forma asíncrona
    pthread_t thread_b;

    while (1)
    {
        if (Tools[2])
        {
            if (ConsoleSizeInt == 0 || ConsoleSizeInt != SizeConsole())
            {
                ConsoleSizeInt = SizeConsole();

                system("cls");

                if (Tools[1] == 1)
                {
                    RecompletarDatos_y_Logo(Intro);
                }

                if (pthread_create(&thread_b, NULL, (void *)To_Menu, NULL) != 0)
                {
                    perror("Error al ir directo al menu");
                    pthread_exit(NULL);
                }
            }
        }
        else
        {
            if (thread_b == 0)
            {
                if (pthread_create(&thread_b, NULL, (void *)To_Menu, NULL) != 0)
                {
                    perror("Error al ir directo al menu");
                    pthread_exit(NULL);
                }
            }
        }

        usleep(200); // Espera 0,2 segundos antes de verificar nuevamente

        if (Tools[0] == 0)
        {
            if (thread_b != 0)
            {
                pthread_detach(thread_b);
            }

            pthread_exit(NULL);
            break;
        }
    }
    return NULL;
}

void ExitAll()
{
    int ExitX[3] = {0, 0, 0};
    CentralData(ExitX);
}