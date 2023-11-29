#include <stdio.h>
#include <stdlib.h>
#include "cadastroPokemon.h"

/**
 * @brief 
 * cadastra as informações dos pokemons
 */
void CadastroColecao()
{
    //declaracao de variaveis
    Pokemon *pokedexGeral;
    int opcao_cadastro_colecao, opcao, posicaoNovoPokemon, numeroPokemon = 1, i = 1, contador, fimPokedex = 1;
    char nome_pokemon_inserir[21];
    char nome_pokemon_alterar[21];
    char nome_pokemon_excluir[21];
    char nome_pokemon_pesquisar[21];

    pokedexGeral = (Pokemon*) calloc(1000, sizeof(Pokemon));//aloca o vetor de pokemons dinamicamente com todas as posicoes zeradas
    CriaVetorPokedex(pokedexGeral);//envia para a funcao que recebe a pokedex
    
    numeroPokemon = pokedexGeral[1].numero;//assume um primeiro valor para o numero novo
    //enquanto for uma linha ocupada por um pokemon ou uma linha de vetor excluido, para encontrar o fim da pokedex
    while(pokedexGeral[i].numero != 0 || strcmp(pokedexGeral[i].nome, "excluido") == 0)
    {
        //qual sera o numero do pokemon novo
        if(pokedexGeral[i].numero > numeroPokemon)
        {
            numeroPokemon = pokedexGeral[i].numero;
        }//if
        fimPokedex++;//incrementa ate encontrar o fim da pokedex
        i++;
    }//while

    do
    {
        printf("O que deseja fazer?\n"); //opcoes de cadastro na pokedex
        printf("1 - INSERIR\n");
        printf("2 - LISTAR\n");
        printf("3 - PESQUISAR\n");
        printf("4 - ALTERAR\n");
        printf("5 - EXCLUIR\n");
        scanf("%i", &opcao_cadastro_colecao);

        if(opcao_cadastro_colecao < 1 || opcao_cadastro_colecao > 5)//caso estiver fora do intervalo permitido
            printf("opcao invalida!!! insira novamente:\n");
    }while(opcao_cadastro_colecao < 1 || opcao_cadastro_colecao > 5);
    
    switch(opcao_cadastro_colecao)//casos de cadastro
    {
        case 1://inserir um novo pokemon
            i = 1;
            while(contador == 0)
            {
                //onde sera armazenado o pokemon novo
                if(pokedexGeral[i].numero == '0' && strcmp(pokedexGeral[i].nome, "excluido") == 0)//se no numero estiver zerado e o nome for algum pokemon excluido
                {
                    posicaoNovoPokemon = i;
                    contador++;
                }//if
                if(pokedexGeral[i].numero == '0' && strcmp(pokedexGeral[i].nome, "0") == 0)//se no numero e no nome estiver zerados
                {
                    posicaoNovoPokemon = i;
                    contador++;
                    fimPokedex++;//se estiver a linha zerada, deve incrementar o tamanho do vetor final
                }//if
                i++;
            }//while
            
            do
            {
                setbuf(stdin, NULL);//recebe o nome de um pokemon
                printf("digite o nome do pokemon que deseja adicionar:\n");
                fgets(nome_pokemon_inserir, 20, stdin);
                nome_pokemon_inserir[strcspn(nome_pokemon_inserir, "\n")] ='\0';
                setbuf(stdin, NULL);

                contador = 0;//variavel de localizacao para verificar se nao tem repetido
                for(int i = 1; i < fimPokedex; i++)
                {
                    if(strcasecmp(nome_pokemon_inserir, pokedexGeral[i].nome) == 0)//caso forem nomes iguais
                    {
                        printf("esse pokemon j� existe\n");
                        contador++;//incrementa o contador para entrar no loop
                    }//if
                }//for
            }while(contador > 0);
            strcpy(pokedexGeral[posicaoNovoPokemon].nome, nome_pokemon_inserir);//copia o nome recebido para a posicao do nome no vetor

            printf("Digite o tipo 1 do %s:\n", pokedexGeral[posicaoNovoPokemon].nome);//recebe o tipo principal 
            fgets(pokedexGeral[posicaoNovoPokemon].tipo1, 30, stdin);
            pokedexGeral[posicaoNovoPokemon].tipo1[strcspn(pokedexGeral[posicaoNovoPokemon].tipo1, "\n")] = '\0';
            setbuf(stdin, NULL);

            printf("digite o tipo 2 do %s (caso não quiser, digite \"NULL\"):\n", pokedexGeral[posicaoNovoPokemon].nome);//recebe o tipo secundario
            fgets(pokedexGeral[posicaoNovoPokemon].tipo2, 30, stdin);
            pokedexGeral[posicaoNovoPokemon].tipo2[strcspn(pokedexGeral[posicaoNovoPokemon].tipo2, "\n")] = '\0';
            setbuf(stdin, NULL);

            do//recebe o valor de ataque
            {
                printf("digite o valor de ataque do %s:\n", pokedexGeral[posicaoNovoPokemon].nome); 
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].ataque);
            }while(pokedexGeral[i].ataque > 300 || pokedexGeral[i].ataque < 0);

            do//recebe o valor de defesa
            {
                printf("digite o valor de defesa do %s:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].defesa);
            }while(pokedexGeral[i].ataque > 300 || pokedexGeral[i].defesa < 0);

            do//recebe o valor de ataque especial
            {
                printf("digite o valor de ataque especial do %s:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].ataque_especial);
            }while(pokedexGeral[i].ataque > 300 || pokedexGeral[i].ataque_especial < 0);
                
            do//recebe o valor de defesa especial
            {
                printf("digite o valor de defesa especial do %s:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].defesa_especial);
            }while(pokedexGeral[i].ataque > 300 || pokedexGeral[i].defesa_especial < 0);
                
            do//recebe o valor de velocidade
            {
                printf("digite a velocidade de %s:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].velocidade);
            }while(pokedexGeral[i].ataque > 300 || pokedexGeral[i].velocidade < 0);

            do//recebe o valor de maximo dano
            {
                printf("digite o hp de %s:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].hp);
            }while(pokedexGeral[i].ataque > 300 || pokedexGeral[i].hp < 0);
            
            //valor total: a soma dos ataques, defesas, velocidade e hp
            pokedexGeral[posicaoNovoPokemon].total = pokedexGeral[posicaoNovoPokemon].ataque + 
                                                    pokedexGeral[posicaoNovoPokemon].defesa + 
                                                    pokedexGeral[posicaoNovoPokemon].ataque_especial + 
                                                    pokedexGeral[posicaoNovoPokemon].defesa_especial + 
                                                    pokedexGeral[posicaoNovoPokemon].velocidade + 
                                                    pokedexGeral[posicaoNovoPokemon].hp;

            do//recebe o valor de geracao
            {
                printf("qual a geracao deseja colocar %s:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].geracao);
            }while(pokedexGeral[posicaoNovoPokemon].geracao < 0 || pokedexGeral[posicaoNovoPokemon].geracao > 6);

            do//se o pokemon pode ser lendario ou nao
            {
                printf("%s: lendario?\n1 - sim\n2 - nao:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].lendario);
            }while(pokedexGeral[posicaoNovoPokemon].lendario != 0 && pokedexGeral[posicaoNovoPokemon].lendario != 1);

            setbuf(stdin, NULL);//recebe a cor do pokemon
            printf("qual a cor de %s:\n", pokedexGeral[posicaoNovoPokemon].nome);
            fgets(pokedexGeral[posicaoNovoPokemon].cor, 30, stdin);
            pokedexGeral[posicaoNovoPokemon].cor[strcspn(pokedexGeral[posicaoNovoPokemon].cor, "\n")] = '\0';
            setbuf(stdin, NULL);

            do//recebe o valor de altura
            {
                printf("qual a altura de %s em metros:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%f", &pokedexGeral[posicaoNovoPokemon].altura);
            }while(pokedexGeral[posicaoNovoPokemon].altura < 0);

            do//recebe o valor de peso
            {
                printf("qual o peso de %s em kg:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%f", &pokedexGeral[posicaoNovoPokemon].peso);
            }while(pokedexGeral[posicaoNovoPokemon].peso < 0);

            do//recebe o valor de taxa de captura
            {
                printf("qual a taxa de captura de %s:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].taxa_de_captura);
            }while(pokedexGeral[posicaoNovoPokemon].taxa_de_captura > 255 || pokedexGeral[posicaoNovoPokemon].taxa_de_captura < 0);

            pokedexGeral = realloc(pokedexGeral, fimPokedex * sizeof(Pokemon));
        break;

        case 2://listar pokemons
            printf("listar os pokemons\n");

            for(i = 1; i < fimPokedex; i++)
            {
                if(strcmp(pokedexGeral[i].nome, "excluido") != 0)
                {
                    printf("Numero: %3i\nNome: %-12s\nTipo 1: %-12s\nTipo 2: %-12s\nTotal: %3i\nHP: %3i\nAtaque: %3i\nDefesa: %3i\nAt. Especial: %3i\nDf. Especial: %3i\n Velocidade: %3i\nGeração: %i\nLendário: %i\nCor: %-8sAltura: %5.2f\nPeso: %6.2f\nTaxa Captura: %3i\n", 
                        pokedexGeral[i].numero,
                        pokedexGeral[i].nome,                         //exibe as infos do pokemon
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
                        pokedexGeral[i].lendario, 
                        pokedexGeral[i].cor, 
                        pokedexGeral[i].altura, 
                        pokedexGeral[i].peso, 
                        pokedexGeral[i].taxa_de_captura);
                }//if
            }//for
        break;

        case 3://pesquisar pokemons
            do
            {
                //recebe o nome do pokemon para busca
                printf("insira o nome do pokemon que deseja pesquisar:\n");
                fgets(nome_pokemon_pesquisar, 20, stdin);
                nome_pokemon_pesquisar[strcspn(nome_pokemon_pesquisar, "\n")] = '\0';
                setbuf(stdin, NULL);

                contador = 0;//variavel de localizacao
                for(i = 1; i < fimPokedex; i++)
                {
                    if(strcasecmp(nome_pokemon_pesquisar, pokedexGeral[i].nome) == 0)//compara com o nome recebido
                    {
                        //exibe os dados do pokemon encontrado
                        printf("---POKEMON ENCONTRADO---\n");
                        printf("NOME: %s\n", pokedexGeral[i].nome);
                        printf("NUMERO: %i\n", pokedexGeral[i].numero);
                        printf("TIPO 1: %s\n", pokedexGeral[i].tipo1);
                        printf("TIPO 2: %s\n", pokedexGeral[i].tipo2);
                        printf("HP: %i\n", pokedexGeral[i].hp);
                        printf("ATAQUE: %i\n", pokedexGeral[i].ataque);
                        printf("DEFESA: %i\n", pokedexGeral[i].defesa);
                        printf("ATAQUE ESPECIAL: %i\n", pokedexGeral[i].ataque_especial);
                        printf("DEFESA ESPECIAL: %i\n", pokedexGeral[i].defesa_especial);
                        printf("VELOCIDADE: %i\n", pokedexGeral[i].velocidade);
                        printf("TOTAL: %i\n", pokedexGeral[i].total);
                        printf("GERAÇÃO: %i\n", pokedexGeral[i].geracao);
                        printf("LENDARIO: %i\n", pokedexGeral[i].lendario);
                        printf("COR: %s\n", pokedexGeral[i].cor);
                        printf("ALTURA: %.2f\n", pokedexGeral[i].altura);
                        printf("PESO: %.2f\n", pokedexGeral[i].peso);
                        printf("TAXA DE CAPTURA: %i\n", pokedexGeral[i].taxa_de_captura);
                        contador++;//caso for encontrado

                        printf("\npesquisar outro pokemon?\n1- sim\n2- nao\n");//caso deseja realizar mais uma pesquisa
                        scanf("%i", &opcao);
                    }//if
                }//for

                if(contador == 0)//caso nao encontre o pokemon
                {
                    printf("Não encontramos nenhum pokemon com esse nome. ");
                    printf("Tentar novamente?\n1- sim\n2- nao\n");//caso queira tentar uma nova pesquisa
                    scanf("%i", &opcao);
                }//if
            }while(opcao == 1);//enquanto for a opcao de querer pesquisar novamnete
        break;

        case 4://alterar pokemons
            do
            {
                //recebe o nome do pokemon que tera suas informações alteradas
                printf("insira o nome do pokemon que deseja alterar:\n");
                fgets(nome_pokemon_alterar, 20, stdin);
                nome_pokemon_alterar[strcspn(nome_pokemon_alterar, "\n")] = '\0';
                setbuf(stdin, NULL);

                contador = 0;//variavel de localizacao
                for(i = 1; i < fimPokedex; i++)
                {
                    if(strcasecmp(nome_pokemon_alterar, pokedexGeral[i].nome) == 0)//compara com o nome de todos os pokemons
                    {
                        printf("---POKEMON ENCONTRADO---\n");
                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira a quantidade de HP:\n");
                            scanf("%i", &pokedexGeral[i].hp);

                            if(pokedexGeral[i].hp > 300)
                                printf("HP alto demais! o numero deve ser abaixo de 300. Insira novamente:\n");
                            else
                            {
                                if(pokedexGeral[i].hp < 0)
                                    printf("o numero deve ser positivo. Insira novamente:\n");
                            }//else
                        }while(pokedexGeral[i].hp > 300 || pokedexGeral[i].hp < 0);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira a quantidade de ataque:\n");
                            scanf("%i", &pokedexGeral[i].ataque);

                            if(pokedexGeral[i].ataque > 300)
                                printf("ataque alto demais! o numero deve ser abaixo de 300. Insira novamente:\n");
                            else
                            {
                                if(pokedexGeral[i].ataque < 0)
                                    printf("o numero deve ser positivo. Insira novamente:\n");
                            }//else
                        }while(pokedexGeral[i].ataque > 300 || pokedexGeral[i].ataque < 0);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira a quantidade de defesa:\n");
                            scanf("%i", &pokedexGeral[i].defesa);

                            if(pokedexGeral[i].defesa > 300)
                                printf("defesa alta demais! o numero deve ser abaixo de 300. Insira novamente:\n");
                            else
                            {
                                if(pokedexGeral[i].defesa < 0)
                                    printf("o numero deve ser positivo. Insira novamente:\n");
                            }//else
                        }while(pokedexGeral[i].defesa > 300 || pokedexGeral[i].defesa < 0);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira a quantidade de ataque especial:\n");
                            scanf("%i", &pokedexGeral[i].ataque_especial);

                            if(pokedexGeral[i].ataque_especial > 300)
                                printf("ataque especial alto demais! o numero deve ser abaixo de 300. Insira novamente:\n");
                            else
                            {
                                if(pokedexGeral[i].ataque_especial < 0)
                                    printf("o numero deve ser positivo. Insira novamente:\n");
                            }//else
                        }while(pokedexGeral[i].ataque_especial > 300 || pokedexGeral[i].ataque_especial < 0);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira a quantidade de defesa especial:\n");
                            scanf("%i", &pokedexGeral[i].defesa_especial);

                            if(pokedexGeral[i].defesa > 300)
                                printf("defesa especial alta demais! o numero deve ser abaixo de 300. Insira novamente:\n");
                            else
                            {
                                if(pokedexGeral[i].defesa_especial < 0)
                                    printf("o numero deve ser positivo. Insira novamente:\n");
                            }//else
                        }while(pokedexGeral[i].defesa_especial > 300 || pokedexGeral[i].defesa_especial < 0);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira a quantidade de velocidade:\n");
                            scanf("%i", &pokedexGeral[i].velocidade);
                            
                            if(pokedexGeral[i].velocidade > 150)
                                printf("velocidade alta demais! o numero deve ser abaixo de 150. Insira novamente:\n");
                            else
                            {
                                if(pokedexGeral[i].velocidade < 0)
                                    printf("o numero deve ser positivo. Insira novamente:\n");
                            }//else
                        }while(pokedexGeral[i].velocidade > 300 || pokedexGeral[i].velocidade < 0);

                        //refaz a soma dos novos valores para alterar no total
                        pokedexGeral[i].total = pokedexGeral[i].ataque + 
                                                pokedexGeral[i].defesa + 
                                                pokedexGeral[i].ataque_especial + 
                                                pokedexGeral[i].defesa_especial + 
                                                pokedexGeral[i].velocidade + 
                                                pokedexGeral[i].hp;

                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira a geracao:\n");
                            scanf("%i", &pokedexGeral[i].geracao);

                            if(pokedexGeral[i].geracao < 0 || pokedexGeral[i].geracao > 6){
                                printf("Geração invalida! Deve ser entre 1 e 6...\n");
                            }
                        }while(pokedexGeral[i].geracao < 0 || pokedexGeral[i].geracao > 6);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            if(pokedexGeral[i].lendario == 1)
                            {
                                printf("continuar sendo lendario - 1\ndeixar de ser lendario - 0");
                                scanf("%i", &pokedexGeral[i].lendario);
                            }//if
                            else
                            {
                                printf("se tornar lendario - 1\ncontinuar normal - 0");
                                scanf("%i", &pokedexGeral[i].lendario);
                            }//else
                        }while(pokedexGeral[i].lendario != 0 && pokedexGeral[i].lendario != 1);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira a altura:\n");
                            scanf("%f", &pokedexGeral[i].altura);

                            if(pokedexGeral[i].altura < 0)
                                printf("Altura invalida: deve ser positiva. Insira novamente:\n");
                        }while(pokedexGeral[i].altura < 0);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira o peso:\n");
                            scanf("%f", &pokedexGeral[i].peso);

                            if(pokedexGeral[i].peso < 0)
                                printf("Peso invalido: deve ser positivo. Insira novamente:\n");
                        }while(pokedexGeral[i].peso < 0);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            printf("insira a taxa de captura:\n");
                            scanf("%i", &pokedexGeral[i].taxa_de_captura);
                            if(pokedexGeral[i].taxa_de_captura > 255)
                                printf("Taxa invalida. O numero deve ser abaixo de 255. Insira novamente:\n");
                            else
                            {
                                if(pokedexGeral[i].taxa_de_captura < 0)
                                    printf("o numero deve ser positivo. Insira novamente:\n");
                            }//else
                        }while(pokedexGeral[i].taxa_de_captura > 255 || pokedexGeral[i].taxa_de_captura < 0);

                        contador++;//caso o pokemon foi encontrado
                        printf("alterar outro pokemon?\n1- sim\n2- nao\n");//caso queira alterar outro
                        scanf("%i", &opcao);
                    }//if
                }//for

                if(contador == 0)//caso nao encontrou o pokemon
                {
                    printf("pokemon nao encontrado para alterar\n");
                    printf("tentar novamente?\n1- sim\n2- nao\n");
                    scanf("%i", &opcao);
                }//if
            }while(opcao == 1);//enquanto for a opcao de alterar novamente

        break;

        case 5://excluir pokemons
            printf("excluir algum pokemon cadastradon\n");

            do
            {
                printf("insira o nome do pokemon que deseja excluir:\n");
                fgets(nome_pokemon_excluir, 20, stdin);
                nome_pokemon_excluir[strcspn(nome_pokemon_excluir, "\n")] = '\0';
                setbuf(stdin, NULL);

                contador = 0;//variavel de localizacao
                for(i = 1; i < fimPokedex; i++)
                {
                    if (strcasecmp(nome_pokemon_excluir, pokedexGeral[i].nome) == 0)
                    {
                        printf("---POKEMON ENCONTRADO---\n");
                        pokedexGeral[i].numero = 0;
                        strcpy(pokedexGeral[i].nome,"excluido");
                        strcpy(pokedexGeral[i].tipo1, "0");
                        strcpy(pokedexGeral[i].tipo2, "0");
                        pokedexGeral[i].total = 0;
                        pokedexGeral[i].hp = 0;
                        pokedexGeral[i].ataque = 0;
                        pokedexGeral[i].defesa = 0;
                        pokedexGeral[i].ataque_especial = 0;
                        pokedexGeral[i].defesa_especial = 0;
                        pokedexGeral[i].velocidade = 0;
                        pokedexGeral[i].geracao = 0;
                        pokedexGeral[i].lendario = 0;
                        strcpy(pokedexGeral[i].cor, "0");
                        pokedexGeral[i].altura = 0;
                        pokedexGeral[i].peso = 0;
                        pokedexGeral[i].taxa_de_captura = 0;
                        contador++;//caso o pokemon foi encontrado

                        printf("excluir outro pokemon?\n1- sim\n2- nao\n");//caso queira excluir outro pokemon
                        scanf("%i", &opcao);
                    }//if
                }//for

                if(contador == 0)
                {
                    printf("pokemon nao encontrado\n");
                    printf("tentar novamente?\n1- sim\n2- nao\n");
                    scanf("%i", &opcao);
                }//if
            }while(opcao == 1);
        break;

        default://caso nao queira nenhum
        break;//sai da funcao
    }//switch
}//CadastroColecao