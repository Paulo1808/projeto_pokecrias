#include <stdio.h>
#include <stdlib.h>
#include "principal.h"

/**
 * @brief 
 * verifica se o usuario esta no windows ou no linux
*/

void verificaWinOuLinux()
{
    #ifdef _WIN32 //Testa se o SO é Windows
        system("cls");
        printf("Est� no Windows\n");
    #else
        system("clear");
        printf("Est� no Linux\n");
    #endif
}//verificaWinOuLinux