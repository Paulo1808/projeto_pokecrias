#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int numero;
    char nome[31], tipo1[31], tipo2[31];
    int total, hp,ataque, defesa, ataque_especial, defesa_especial;
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
void CriaVetorPokedex()
{
    FILE *ArquivoPokedex = fopen("pokedex.csv", "r");
    Pokedex pokemons[721];

    while (!(feof(ArquivoPokedex)))
    {
        for (int i = 0; i < 721; i++)
        {
            fscanf(ArquivoPokedex, "%i , %s , %s , %s , %i , %i , %i , %i , %i , %i , %i , %i , %i , %s , %lf , %lf , %i \n", pokemons[i].nome, pokemons[i].tipo1, pokemons[i].tipo2, pokemons[i].total, pokemons[i].hp, pokemons[i].ataque, pokemons[i].defesa, pokemons[i].ataque_especial, pokemons[i].defesa_especial, pokemons[i].velocidade, pokemons[i].geracao, pokemons[i].velocidade, pokemons[i].cor, pokemons[i].altura, pokemons[i].peso, pokemons[i].taxa_de_captura);
            printf("%i , %s , %s , %s , %i , %i , %i , %i , %i , %i , %i , %i , %i , %s , %lf , %lf , %i \n", pokemons[i].nome, pokemons[i].tipo1, pokemons[i].tipo2, pokemons[i].total, pokemons[i].hp, pokemons[i].ataque, pokemons[i].defesa, pokemons[i].ataque_especial, pokemons[i].defesa_especial, pokemons[i].velocidade, pokemons[i].geracao, pokemons[i].velocidade, pokemons[i].cor, pokemons[i].altura, pokemons[i].peso, pokemons[i].taxa_de_captura);
        
        }//for
        
    }//while
    
}//criaVetorPokedex


//funçao pesquisa de pokemons
void PesquisaTipoGen(){

    FILE *ArquivoPokedex = fopen("pokedex.csv", "r");
    char numero[50];

    if(ArquivoPokedex == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }//msg de erro


    while (fgets(numero, sizeof(numero), ArquivoPokedex))
    {

    }
    
    fclose(ArquivoPokedex);
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