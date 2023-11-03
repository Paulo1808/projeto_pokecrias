#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int numero;
    char nome[31], tipo1[31], tipo2[31];
    int total, hp,ataque, defesa, ataque_especial, defesa_especial;
    int velocidade, geracao;
    int lendario;
    char cor[16];
    int taxa_de_captura;
    float altura, peso;
}Pokemon; //definindo struct com as infos de cada pokemon

typedef struct
{
    int prox_evolucao, pre_evolucao;
}evolucoes;

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

void CriaVetorPokedex(Pokemon pokedexGeral[])
{
    FILE *ArquivoPokedex = fopen("pokedex.csv", "r"); //abre o arquivo da pokedex
    
    fseek(ArquivoPokedex, 0, SEEK_SET);

    for (int i = 0; i < 722; i++)
    {
        if (i == 0)
        {
            do{
            fseek(ArquivoPokedex, 1, SEEK_CUR);
            }while(fgetc(ArquivoPokedex) != '\n');
        }

        fscanf(ArquivoPokedex, "%3i ,%s ,%s ,%s ,%3i ,%3i ,%3i ,%3i ,%3i ,%3i ,%3i ,%i ,%i ,%s ,%f ,%f ,%3i \n", 
        &pokedexGeral[i].numero,
        pokedexGeral[i].nome, 
        pokedexGeral[i].tipo1, 
        pokedexGeral[i].tipo2, 
        &pokedexGeral[i].total, 
        &pokedexGeral[i].hp, 
        &pokedexGeral[i].ataque, 
        &pokedexGeral[i].defesa, 
        &pokedexGeral[i].ataque_especial, 
        &pokedexGeral[i].defesa_especial, 
        &pokedexGeral[i].velocidade, 
        &pokedexGeral[i].geracao, 
        &pokedexGeral[i].lendario, 
        pokedexGeral[i].cor, 
        &pokedexGeral[i].altura, 
        &pokedexGeral[i].peso, 
        &pokedexGeral[i].taxa_de_captura);
    }//for

    fclose(ArquivoPokedex); //fecha o arquivo
}//criaVetorPokedex

void PesquisaTipoGen()
{    
    //variaveis 
    int opcao;
    int numeroGeracao;
    char nomePokemon[21];
    char tipoPokemon[21];
    Pokemon pokedex[722];

    //cria o vetor de todos os pokemons
    CriaVetorPokedex(pokedex);

    printf("Qual parametro deseja pesquisar:\n");
    printf("1 - Tipo dos pokemons(sendo tipo primário e secundário)\n");
    printf("2 - Geraçao dos pokemons\n");
    printf("3 - Nome do pokemon\n");
    scanf("%i", &opcao); //recebe a opçao

    switch (opcao)
    {
        case 1: //tipo do pokemon
        
                printf("Digite o Tipo em que deseja ver os pokemons:\n");
                setbuf(stdin, NULL);
                fgets(tipoPokemon, 20, stdin);
                tipoPokemon[strcspn(tipoPokemon, "\n")] = '\0';
                setbuf(stdin, NULL); //recebe o tipo

                for (int i = 1; i < 722; i++)
                {
                    if (strcasecmp(tipoPokemon, pokedex[i].tipo1) == 0 || strcasecmp(tipoPokemon, pokedex[i].tipo2) == 0)
                    {
                        printf("|%3i|%-12s|%-12s|%-12s|%3i|%3i|%3i|%3i|%3i|%3i|%3i|%i|%i|%-8s|%5.2f|%6.2f|%3i|\n", 
                        pokedex[i].numero,
                        pokedex[i].nome,                         //exibe as infos dos pokemons
                        pokedex[i].tipo1, 
                        pokedex[i].tipo2, 
                        pokedex[i].total, 
                        pokedex[i].hp, 
                        pokedex[i].ataque, 
                        pokedex[i].defesa, 
                        pokedex[i].ataque_especial, 
                        pokedex[i].defesa_especial, 
                        pokedex[i].velocidade, 
                        pokedex[i].geracao, 
                        pokedex[i].lendario, 
                        pokedex[i].cor, 
                        pokedex[i].altura, 
                        pokedex[i].peso, 
                        pokedex[i].taxa_de_captura);
                    }//if

                }//for 
        break;
        
        case 2:  //geraçao dos pokemons

                do
                {
                    printf("Digite o número da geração a ser exibida\n:");
                    scanf("%i", &numeroGeracao);
            
                } while (numeroGeracao < 0 || numeroGeracao > 6);

                for (int i = 1; i < 722; i++)
                {
                    if (numeroGeracao == pokedex[i].geracao)
                    {
                        printf("|%3i|%-12s|%-12s|%-12s|%3i|%3i|%3i|%3i|%3i|%3i|%3i|%i|%i|%-8s|%5.2f|%6.2f|%3i|\n", 
                        pokedex[i].numero,
                        pokedex[i].nome, 
                        pokedex[i].tipo1, 
                        pokedex[i].tipo2, 
                        pokedex[i].total, 
                        pokedex[i].hp, 
                        pokedex[i].ataque, 
                        pokedex[i].defesa, 
                        pokedex[i].ataque_especial, 
                        pokedex[i].defesa_especial, 
                        pokedex[i].velocidade, 
                        pokedex[i].geracao, 
                        pokedex[i].lendario, 
                        pokedex[i].cor, 
                        pokedex[i].altura, 
                        pokedex[i].peso, 
                        pokedex[i].taxa_de_captura);

                    }//if
                }
                
        break;
        
        case 3: //nome do pokemon
                printf("Digite o nome do pokemon:\n");
                setbuf(stdin, NULL);
                fgets(nomePokemon, 20, stdin);
                nomePokemon[strcspn(nomePokemon, "\n")] = '\0';
                setbuf(stdin, NULL);

                for (int i = 1; i < 722; i++)
                {
                    if (strcasecmp(nomePokemon, pokedex[i].nome) == 0)
                    {
                        printf("Numero: %3i\nNome: %-12s\nTipo 1: %-12s\nTipo 2: %-12s\nTotal: %3i\nHP: %3i\nAtaque: %3i\nDefesa: %3i\nAt. Especial: %3i\nDf. Especial: %3i\n Velocidade: %3i\nGeração: %i\nLendário: %i\nCor: %-8sAltura: %5.2f\nPeso: %6.2f\nTaxa Captura: %3i\n", 
                        pokedex[i].numero,
                        pokedex[i].nome,                         /*exibe as infos do pokemon*/
                        pokedex[i].tipo1, 
                        pokedex[i].tipo2, 
                        pokedex[i].total, 
                        pokedex[i].hp, 
                        pokedex[i].ataque, 
                        pokedex[i].defesa, 
                        pokedex[i].ataque_especial, 
                        pokedex[i].defesa_especial, 
                        pokedex[i].velocidade, 
                        pokedex[i].geracao, 
                        pokedex[i].lendario, 
                        pokedex[i].cor, 
                        pokedex[i].altura, 
                        pokedex[i].peso, 
                        pokedex[i].taxa_de_captura);

                        break;
                    }//if
                }//for
            break;

        default:
            break;
    }//switch
}//fim funçao de pesquisa

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
            PesquisaTipoGen();
            break;
        case 2:
            printf("Carrega um arquivo do jogo ja existente\n");

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

//funçao pra pesquisar o tipo


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