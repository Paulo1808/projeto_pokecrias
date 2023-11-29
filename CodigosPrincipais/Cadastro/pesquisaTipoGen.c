#include <stdio.h>
#include <stdlib.h>
#include "cadastroPokemon.h"

/**
 * @brief pesquisa os pokemons já existentes por tipo (tipo 1 ou 2), geracao ou nome
 * 
 */
void PesquisaTipoGen()
{    
    //declaracao de variaveis 
    int opcao;
    int numeroGeracao;
    char nomePokemon[21];
    char tipoPokemon[21];
    Pokemon *pokedex; 
    pokedex = (Pokemon*) malloc (722 * sizeof(Pokemon));
    //cria o vetor de todos os pokemons
    CriaVetorPokedex(pokedex);

    printf("Qual parametro deseja pesquisar:\n");
    printf("1 - Tipo dos pokemons(sendo tipo primário e secundário)\n");
    printf("2 - Geraçao dos pokemons\n");
    printf("3 - Nome do pokemon\n");
    scanf("%i", &opcao); //recebe a opcao

    switch (opcao)
    {
        case 1: //tipo do pokemon
        
            printf("Digite o Tipo em que deseja ver os pokemons:\n");
            setbuf(stdin, NULL);
            fgets(tipoPokemon, 20, stdin);
            tipoPokemon[strcspn(tipoPokemon, "\n")] = '\0';
            setbuf(stdin, NULL); //recebe o tipo

            printf("| Numero |    Nome    |   Tipo 1   |   Tipo 2   | total |  HP  | Ataque | Defesa | Sp. Ataque | Sp. Defesa | Speed  | Gen | Lendario |   Cor   |Altura |  Peso | Taxa Cap. |\n");
            for (int i = 1; i < 722; i++)
            {
                if (strcasecmp(tipoPokemon, pokedex[i].tipo1) == 0 || strcasecmp(tipoPokemon, pokedex[i].tipo2) == 0)
                {
                    printf("|%-8i|%-12s|%-12s|%-12s|%-7i|%-6i|%-8i|%-8i|%-12i|%-12i|%-8i|%-5i|%-10i|%-9s|%-7.2f|%-7.2f|%-11i|\n", 
                    pokedex[i].numero,
                    pokedex[i].nome,                         //exibe as infos dos pokemons que tem esse tipo
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
        
        case 2:  //geracao dos pokemons

            do
            {
                printf("Digite o número da geração a ser exibida\n:");
                scanf("%i", &numeroGeracao);
            } while(numeroGeracao < 0 || numeroGeracao > 6);

            printf("| Numero |    Nome    |   Tipo 1   |   Tipo 2   | total |  HP  | Ataque | Defesa | Sp. Ataque | Sp. Defesa | Speed  | Gen | Lendario |   Cor   |Altura |  Peso | Taxa Cap. |\n");
            for (int i = 1; i < 722; i++)
            {
                if (numeroGeracao == pokedex[i].geracao)
                {
                    printf("|%8i|%-12s|%-12s|%-12s|%-7i|%-6i|%-8i|%-8i|%-12i|%-12i|%-8i|%-5i|%-10i|%-9s|%-6.2f|%-4.2f|%-11i|\n", 
                    pokedex[i].numero,
                    pokedex[i].nome,                         //exibe as infos dos pokemons que s�o dessa gera��o
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
        
        case 3: //nome do pokemon
            printf("Digite o nome do pokemon:\n");
            setbuf(stdin, NULL);
            fgets(nomePokemon, 20, stdin);
            nomePokemon[strcspn(nomePokemon, "\n")] = '\0';
            setbuf(stdin, NULL);//recebe o nome do pokemon

            for (int i = 1; i < 722; i++)
            {
                if (strcasecmp(nomePokemon, pokedex[i].nome) == 0)
                {
                    printf("Numero: %3i\nNome: %-12s\nTipo 1: %-12s\nTipo 2: %-12s\nTotal: %3i\nHP: %3i\nAtaque: %3i\nDefesa: %3i\nAt. Especial: %3i\nDf. Especial: %3i\n Velocidade: %3i\nGeração: %i\nLendário: %i\nCor: %-8sAltura: %5.2f\nPeso: %6.2f\nTaxa Captura: %3i\n", 
                    pokedex[i].numero,
                    pokedex[i].nome,                         //exibe as infos do pokemon recebido
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

        default://caso nao queira nenhum
        break;//sai da funcao
    }//switch
}//PesquisaTipoGen