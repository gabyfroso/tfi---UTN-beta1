#pragma ONCE
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

void Universe_PrintLogo(int width);
int Universe_GetConsoleWidth();
void Universe();

void Universe()
{
    system("color 2");
    int sizeConsoleAnterior = Universe_GetConsoleWidth();

    while (1)
    {
        int currentWidth = Universe_GetConsoleWidth();

        if (currentWidth != sizeConsoleAnterior)
        {
            Universe_PrintLogo(currentWidth);
            sizeConsoleAnterior = currentWidth;
        }

        usleep(100000); // Pausa de 100 ms para evitar una verificación continua
    }
}

void Universe_PrintLogo(int width)
{
    char *Logo2[8] = {
        "@       @@@@@            @@/              @",
        "@@              ///@@@                   &///                        @",
        "@@                /////                   @///////&",
        "@////////////               ///         //&",
        "&/////                    ///////         //&@",
        "  @@@@@/////                ////@@@@@@ ",
        "@&/////                       /////////Y@"};

    int padding = width - 32;
    if (padding < 0)
    {
        padding = 0;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("\r");
        for (int space = 0; space < padding; space++)
        {
            printf(" ");
        }
        printf("%s", Logo2[i]);
        fflush(stdout);
        usleep(1000); // Pausa pequeña para simular una actualización más suave
    }

    for (int i = 0; i < 8; i++)
    {
        printf("\r");
        for (int space = 0; space < padding; space++)
        {
            printf(" ");
        }
        printf("%s", Logo2[i]);
        fflush(stdout);
        usleep(1000); // Pausa pequeña para simular una actualización más suave
    }
}

int Universe_GetConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}
