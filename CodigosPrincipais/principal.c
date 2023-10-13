#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int numero;
    char nome[31], tipo1[31], tipo2[31];
    int total, ataque, defesa, ataque_especial, defesa_especial;
    int velocidade, geracao;
    bool lendario;
    char cor;
    int taxa_de_captura, prox_evolucao, pre_evolucao;
    float altura, peso;
}Pokedex; //definindo struct

typedef struct
{
    int pokemon1;
    int pokemon2;  
    int pokemon3;
    int pokemon4;
    int pokemon5;
    int pokemon6;

} mochila;// mochila com os pokemons

//funçao do menu inicial
void exibeMenu()
{
    char nickname[21];
    int opcao;

        printf("Bem vindo ao Menu inicial!!!\n");
        printf("Primeiramente, me diga seu nickname para que possamos continuar:\n");
        setbuf(stdin, NULL);
        fgets(nickname, 20, stdin);
        nickname[strcspn(nickname, "\n")] = '\0';
        setbuf(stdin, NULL);

        printf("Bom, vamos lá %s!\n");
        printf("Escolha uma opção para iniciar:\n");
        printf("1 - Novo Jogo\n");
        printf("2 - Carregar Jogon\n");
        printf("3 - Mecanicas do Jogo\n");

        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Envia para a funçao de inicio de jogo\n");

            break;
        case 2:
            printf("Carrega um arquivo do jogo ja existente\n");

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

//funçao pesquisa de pokemons
void PesquisaTipoGen()
{

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
1- Menus e submenus
2- pesquisa por tipo e geração
3- salvamento em binario 
4- gerenciamento dos pokemons obtidos
*/

int main(){

        exibeMenu();


    return 0;
}//main