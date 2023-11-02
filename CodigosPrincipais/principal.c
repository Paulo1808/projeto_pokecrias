#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cabecalho.h"

typedef struct{
    int numero;
    char nome[31], tipo1[31], tipo2[31];
    int total, hp,ataque, defesa, ataque_especial, defesa_especial;
    int velocidade, geracao;
    bool lendario;
    char cor;
    int taxa_de_captura, prox_evolucao, pre_evolucao;
    float altura, peso;
}Pokemon; //definindo struct com as infos de cada pokemon

typedef struct
{
    int pokemon1;
    int pokemon2;  
    int pokemon3;
    int pokemon4;
    int pokemon5;
    int pokemon6;

}mochila;// mochila com os pokemons

typedef struct{
    int *pokemonCapturado;
}Colecao; //struct coleçao

//funçao do menu inicial
void exibeMenu()
{
    char* nickname = NULL;
    int tam = 21;

    nickname = (char*) malloc (tam * sizeof(char)); //aloca dinamicamente o tamanho do nome inserido
    int opcao;

        printf("Bem vindo ao Menu inicial!!!\n");
        printf("Primeiramente, me diga seu nickname para que possamos continuar:\n");
        setbuf(stdin, NULL);
        fgets(nickname, 20, stdin);
        nickname[strcspn(nickname, "\n")] = '\0';
        setbuf(stdin, NULL); //recebe o nome inserido

        printf("Bom, vamos lá %s!\n", nickname);
        printf("Escolha uma opção para iniciar:\n");
        printf("1 - Novo Jogo\n");
        printf("2 - Carregar Jogo\n");
        printf("3 - Mecanicas do Jogo\n"); //menu do jogo
        printf("4 - Fechar o jogo\n");

        scanf("%i", &opcao);

        switch (opcao) //executa a opçao escolhida
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
            printf("Fechando o jogo...\n");

            break;
        
        default:
            printf("Opção invalida...");

            break;
        }


}//fim funçao do menu

void CriaVetorPokedex()
{
    FILE *ArquivoPokedex = fopen("pokedex .csv", "r"); //abre o arquivo da pokedex
    Pokemon pokedexGeral[722];

    while (!(feof(ArquivoPokedex)))
    {
        for (int i = 1; i < 722; i++) //lê as informaçoes de cada pokemon
        {
            fscanf(ArquivoPokedex, "%i , %s , %s , %s , %i , %i , %i , %i , %i , %i , %i , %i , %i , %s , %lf , %lf , %i \n", 
            pokedexGeral[i].nome, 
            pokedexGeral[i].tipo1, 
            pokedexGeral[i].tipo2, 
            pokedexGeral[i].total, 
            pokedexGeral[i].hp, 
            pokedexGeral[i].ataque, 
            pokedexGeral[i].defesa, 
            pokedexGeral[i].ataque_especial, 
            pokedexGeral[i].defesa_especial, 
            pokedexGeral[i].velocidade, 
            pokedexGeral[i].geracao, 
            pokedexGeral[i].velocidade, 
            pokedexGeral[i].cor, 
            pokedexGeral[i].altura, 
            pokedexGeral[i].peso, 
            pokedexGeral[i].taxa_de_captura);

            //exibe as informaçoes de cada pokemon
            printf("%i , %s , %s , %s , %i , %i , %i , %i , %i , %i , %i , %i , %i , %s , %lf , %lf , %i \n", 
            pokedexGeral[i].nome, 
            pokedexGeral[i].tipo1, 
            pokedexGeral[i].tipo2, 
            pokedexGeral[i].total, 
            pokedexGeral[i].hp, 
            pokedexGeral[i].ataque, 
            pokedexGeral[i].defesa, 
            pokedexGeral[i].ataque_especial, 
            pokedexGeral[i].defesa_especial, 
            pokedexGeral[i].velocidade, 
            pokedexGeral[i].geracao, 
            pokedexGeral[i].velocidade, 
            pokedexGeral[i].cor, 
            pokedexGeral[i].altura, 
            pokedexGeral[i].peso, 
            pokedexGeral[i].taxa_de_captura);
        }//for
        
    }//while
    
    fclose(ArquivoPokedex); //fecha o arquivo
}//criaVetorPokedex


void PesquisaTipoGen(){
    FILE *ArquivoPokedex = fopen("pokedex .csv", "r"); //abre o arquivo com as informaçoes dos pokemons
    char numero[50];



    FILE *arquivoPokedex = fopen("pokedex.csv", "r");
    
    

    if (arquivoPokedex == NULL) 
    {

        fprintf(stderr, "Erro ao abrir o arquivo\n");

        exit(1);
    }
    
    fclose(ArquivoPokedex); //fecha o arquivo
}//fim funçao de pesquisa

//funçao de salvamento
void salvamentoNoHD()
{

}//fim funçao de salvamento

//funçao de gerenciamento de pokemons
void gerenciamentoPokemons()
{

}//fim funçao de gerenciamento

//funçoes necessarias
//-------------------
/*
1- Menus e submenus ----------- (menu já está feito)
2- pesquisa por tipo e geração
3- salvamento em binario 
4- gerenciamento dos pokemons obtidos
*/

int main(){
        exibeMenu();
        
    return 0;
}//main

