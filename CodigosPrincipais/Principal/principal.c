/**
 * @file principal.c
 * @author millena sartori, maria eduarda mafra e paulo vinicius 
 * @brief 
 * @version 0.1
 * @date 2023-11-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <time.h>
#include "principal.h"

int main()
{
    //declaracao de variaveis
    char nickname[21];
    int opcao;

    verificaWinOuLinux();//verifica se esta no windows ou linux

    printf("Bem vindo ao Menu inicial!!!\n");
    printf("Primeiramente, me diga seu nickname para que possamos continuar:\n");
    setbuf(stdin, NULL);
    fgets(nickname, 20, stdin);
    nickname[strcspn(nickname, "\n")] = '\0';
    setbuf(stdin, NULL); //recebe o nome inserido pelo usuario

    printf("Bom, vamos lá %s!\n", nickname);
    
    do
    {
        printf("Escolha uma opcao para iniciar:\n");
        printf("1 - Novo Jogo\n");
        printf("2 - Carregar Jogo\n");
        printf("3 - Mecanicas do Jogo\n"); 
        printf("4 - Fechar o jogo\n");

        scanf("%i", &opcao);

        switch (opcao) //executa a opçao escolhida
        {
            case 1:
                printf("Envia para a funçao de inicio de jogo\n");
                NovoJogo();
                PesquisaTipoGen();
                LugarDeCaptura(1);

            break;
            
            case 2:
                printf("Carrega um arquivo do jogo ja existente\n");
                LugarDeCaptura(2);

            break;
            case 3:
                printf("Cadastro de um novo pokemon\n");
                CadastroColecao();

            break;

            case 4: 
                printf("Mecanicas do jogo:");
                MecanicasDeJogo();
            
            case 5:
                printf("Fechando o jogo...\n");
                LugarDeCaptura(5);

            break;
            
            default:
                printf("Opcao invalida...");

            break;
        }//switch
    }while(opcao != 5);//menu do jogo, para voltar sempre nele

    return 0;
}//main