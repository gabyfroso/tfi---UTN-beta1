#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

int SizeConsole();
void Logo_intro(char *Intro);
void Logo_ChanelLogo();

const int SizeLogoFila = 12;
const int SizeLogoColumna = 28;

const char *LogoGatoMio[13] = {
    "@@@@@/@@@@@@@@@@@@@@@/@@@",
    "@@@//////@@@@@@@@@&////@@",
    "@@/////////@@@@@@///////&",
    "@///////////////////////&",
    "&//////////////////////&@", //
    "@&/////////////////////Y@",
    "a//////////////////////@@",
    "v/////////////////////-@@",
    "@@///////////////////@@@@", // 26 char - 12 filas
    "v@@///@@@////////@///@@@@",
    "  @@@@@///////////@@@@@@ ",
    "    @@@@@@@@@@@@@@@@@@  "};

void main()
{
    char IntSalida[10] = "a";
    int LogoAnterior = 0;
    char *xLogo = "*********************\nNombre: Frosoni Hugo Gabriel\nCorreo: Gabyfroso@gmail.com\n\nNumero: +5493816164351\n\n*********************";
    do
    {
        if (LogoAnterior != SizeConsole() || (int)IntSalida[0] == (int)'a')
        {
            system("cls");
            Logo_intro(xLogo);
            LogoAnterior = SizeConsole();
        }

        LogoAnterior = SizeConsole();
        Sleep(90);

        printf("\nSalir: -5");
        printf("\n\t>");
        scanf(" %s", IntSalida);

    } while (atoi(IntSalida) != -5);
}

int SizeConsole()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return columns;
}

void Logo_intro(char *Intro)
{
    int PosiCharIntro = 0, salteoN = 0;

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
}

/*


**********

*******************

**********


*/
void Logo_ChanelLogo()
{
    int SizeConsoleAnterior = SizeConsole();

    for (int i = 0; i < SizeLogoFila; i++)
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