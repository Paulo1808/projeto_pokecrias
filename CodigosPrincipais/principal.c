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

    printf("Bom, vamos la %s!\n", nickname);
    
    do
    {
        printf("------- MENU --------\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Novo Jogo\n");
        printf("2 - Carregar Jogo\n");
        printf("3 - Cadastro\n");
        printf("4 - Pesquisa rapida\n"); 
        printf("5 - Mecanicas do Jogo\n");
        printf("6 - Fechar o jogo\n");

        scanf("%i", &opcao);

        switch (opcao) //executa a opçao escolhida
        {
            case 1://comeca um novo jogo
                printf("Envia para a funcao de inicio de jogo\n");
                NovoJogo();
                printf("Capturas\n");
                LugarDeCaptura(opcao);

            break;
            
            case 2://carrega um ja existente
                printf("Carrega um arquivo do jogo ja existente\n");
                LugarDeCaptura(opcao);

            break;
            
            case 3://sistema de cadastro
                printf("Cadastro de um novo pokemon\n");
                CadastroColecao();

            break;

            case 4://pesquisa de tipo geracao e nome
                printf("Envia para a funcao de pesquisa por tipo e genero");
                PesquisaTipoGen();
            
            break;

            case 5://instrucoes do jogo
                printf("Mecanicas do jogo:");
                MecanicasDeJogo();

            break;

            case 6://sair do jogo
                printf("Fechando o jogo...\n");
                LugarDeCaptura(opcao);

            break;
            
            default:
                printf("Opcao invalida...");

            break;
        }//switch
    }while(opcao != 6);//menu do jogo, para voltar sempre nele

    return 0;
}//main