#pragma ONCE
#include <stdio.h>
#include "./GConsole.h"

const char *LogoGatoMio[13] = {
    "@@@@@/@@@@@@@@@@@@@/@@@@@",
    "@@@/////@@@@@@@@@&///&@@@",
    "@@///////@@@@@@@@/////&@@",
    "@//////////////////////&@",
    "&//////////////////////&@", //
    "@&/////////////////////Y@",
    "&//////////////////////6@",
    "a//////////////////////@@",
    "v/////////////////////-@@",
    "@@////////////////////&@@", // 24 char - 13 filas
    "v@@///@@/////////@///$@@@",
    "  @@v@@///////////@@v@@@ ",
    "    @@@@@@@@@@@@@@@@@@  "};

const int SizeLogoFila = 13;
const int SizeLogoColumna = 28;

int RecompletarDatos_y_Logo(const char *Intro)
{
    int salteoN = 0;
    int PosiCharIntro = 0;
    for (int FilaConsole = 0; FilaConsole < SizeLogoFila; FilaConsole++)
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
    printf("\n");
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