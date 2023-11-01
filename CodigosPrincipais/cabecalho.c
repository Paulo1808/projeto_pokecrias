#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exibeMenu()
{
    char* nickname = NULL;
    int tam = 21;

    nickname = (char*) malloc (tam * sizeof(char));
    int opcao;

        printf("Bem vindo ao Menu inicial!!!\n");
        printf("Primeiramente, me diga seu nickname para que possamos continuar:\n");
        setbuf(stdin, NULL);
        fgets(nickname, 20, stdin);
        nickname[strcspn(nickname, "\n")] = '\0';
        setbuf(stdin, NULL);

        printf("Bom, vamos lá %s!\n", nickname);
        printf("Escolha uma opção para iniciar:\n");
        printf("1 - Novo Jogo\n");
        printf("2 - Carregar Jogo\n");
        printf("3 - Mecanicas do Jogo\n");

        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Envia para a funçao de inicio de jogo\n");

            break;
        case 2:
            printf("Carrega um arquivo do jogo ja existente\n");

            CriaVetorPokedex();

            break;
        case 3:
            printf("Exibe as mecanicas utilizadas no jogo\n");

            break;
        case 4:
            printf("Fecha o jogo\n");

            break;
        
        default:
            printf("Opção invalida...");

            break;
        }
}//fim funçao do menu