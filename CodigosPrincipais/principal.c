#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <time.h>

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
    Pokemon pokemons_mochila;
}mochila;// mochila com os pokemons

typedef struct
{
    int *pokemonCapturado;
    int *contadorPokemons;
}Colecao; //struct cole��o

typedef struct
{
    char a[15], b[15], c[15], d[15], e[15], f[15], g[15], h[15], i[15], j[15], k[15], l[15], m[15], n[15], o[15], p[15], q[15];
}Lixo;//lixo par armazenar a primeira linha do pokedex que n�o cont�m nenhum pokem�n

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

void CriaVetorPokedex(Pokemon *pokedexGeral)
{
    //declara��o de vari�veis
    FILE *ArquivoPokedex = fopen("pokedex.csv", "r"); //abre o arquivo da pokedex
    Lixo lixo;
    fseek(ArquivoPokedex, 0, SEEK_SET);//direciona para o in�cio do arquivo
    int i;

    while(i = 0; i < 722; i++)
    {
        if (i == 0)//caso for a linha de nome das colunas
        {
            fscanf(ArquivoPokedex, "%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s \n", 
            lixo.a,
            lixo.b,
            lixo.c,
            lixo.d,
            lixo.e,
            lixo.f,
            lixo.g,
            lixo.h,
            lixo.i,
            lixo.j,
            lixo.k,
            lixo.l,
            lixo.m,
            lixo.n, 
            lixo.o,
            lixo.p,
            lixo.q);
        }//if
        else//caso for as linhas dos pokemons
        {
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
        }//else
    }//while

    fclose(ArquivoPokedex); //fecha o arquivo
}//CriaVetorPokedex

void CadastroColecao(){

    //declara��o de vari�veis
    Pokemon *pokedexGeral;
    int opcao_cadastro_colecao, opcao, posicaoNovoPokemon, numeroPokemon = 1, i = 1, contador, fimPokedex = 1;
    char nome_pokemon_inserir[21];
    char nome_pokemon_alterar[21];
    char nome_pokemon_excluir[21];
    char nome_pokemon_pesquisar[21];

    pokedexGeral = (Pokemon*) calloc(1000, sizeof(Pokemon));//aloca o vetor de pokemons dinamicamente com todas as posi��es zeradas
    CriaVetorPokedex(pokedexGeral);//envia para a fun��o que recebe a pokedex
    
    numeroPokemon = pokedexGeral[1].numero;//assume um primeiro valor para o numero novo
    //enquanto for uma linha ocupada por um pokemon ou uma linha de vetor excluido, para encontrar o fim da pokedex
    while(pokedexGeral[i].numero != 0 || strcmp(pokedexGeral[i].nome, "excluido") == 0)
    {
        //qual ser� o numero do pokemon novo
        if(pokedexGeral[i].numero > numeroPokemon)
        {
            numeroPokemon = pokedexGeral[i].numero;
        }//if
        fimPokedex++;//incrementa at� encontrar o fim da pokedex
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
        case 1://inserir um novo pokem�n
            i = 1;
            while(contador == 0)
            {
                //onde ser� armazenado o pokemon novo
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

                contador = 0;//variavel de localiza��o para verificar se n�o tem repetido
                for(int i = 1; i < fimPokedex; i++)
                {
                    if(strcasecmp(nome_pokemon_inserir, pokedexGeral[i].nome) == 0)//caso forem nomes iguais
                    {
                        printf("esse pokemon j� existe\n");
                        contador++;//incrementa o contador para entrar no loop
                    }//if
                }//for
            }while(contador > 0);
            strcpy(pokedexGeral[posicaoNovoPokemon].nome, nome_pokemon_inserir);//copia o nome recebido para a posi��o do nome no vetor

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
            
            //valor total � a soma dos ataques, defesas, velocidade e hp
            pokedexGeral[posicaoNovoPokemon].total = pokedexGeral[posicaoNovoPokemon].ataque + 
                                                    pokedexGeral[posicaoNovoPokemon].defesa + 
                                                    pokedexGeral[posicaoNovoPokemon].ataque_especial + 
                                                    pokedexGeral[posicaoNovoPokemon].defesa_especial + 
                                                    pokedexGeral[posicaoNovoPokemon].velocidade + 
                                                    pokedexGeral[posicaoNovoPokemon].hp;

            do//recebe o valor de gera��o
            {
                printf("qual a gera��o deseja colocar %s:\n", pokedexGeral[posicaoNovoPokemon].nome);
                scanf("%i", &pokedexGeral[posicaoNovoPokemon].geracao);
            }while(pokedexGeral[posicaoNovoPokemon].geracao < 0 || pokedexGeral[posicaoNovoPokemon].geracao > 6);

            do//se o pokemon � lendario ou n�o
            {
                printf("%s � lend�rio?\n1 - sim\n2 - n�o:\n", pokedexGeral[posicaoNovoPokemon].nome);
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

                contador = 0;//variavel de localiza��o
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

                if(contador == 0)//caso n�o encontre o pokemon
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

                contador = 0;//variavel de localiza��o
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

                            if(pokedexGeral[i].geracao < 0 || pokedexGeral[i].geracao > 6);
                            printf("Geração invalida! Deve ser entre 1 e 6...\n");
                        }while(pokedexGeral[i].geracao < 0 || pokedexGeral[i].geracao > 6);

                        do//repetir enquanto sair do intervalo permitido
                        {
                            if(pokedexGeral[i].lendario == 1)
                            {
                                printf("continuar� sendo lendario - 1\ndeixar� de ser lendario - 0");
                                scanf("%i", &pokedexGeral[i].lendario);
                            }//if
                            else
                            {
                                printf("se tornar� lend�rio - 1\ncontinuar� normal - 0");
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
                        printf("alterar outro pokemon?\n1- sim\n2- n�o\n");//caso queira alterar outro
                        scanf("%i", &opcao);
                    }//if
                }//for

                if(contador == 0)//caso n�o encontrou o pokemon
                {
                    printf("pokemon n�o encontrado para alterar\n");
                    printf("tentar novamente?\n1- sim\n2- n�o\n");
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

                contador = 0;//variavel de localiza��o
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

                        printf("excluir outro pokemon?\n1- sim\n2- n�o\n");//caso queira excluir outro pokemon
                        scanf("%i", &opcao);
                    }//if
                }//for

                if(contador == 0)
                {
                    printf("pokemon n�o encontrado\n");
                    printf("tentar novamente?\n1- sim\n2- n�o\n");
                    scanf("%i", &opcao);
                }//if
            }while(opcao == 1);
        break;

        default://caso n�o queira nenhum
        break;
    }//switch
}//CadastroColecao

void PesquisaTipoGen()
{    
    //declara��o de variaveis 
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
    scanf("%i", &opcao); //recebe a op��o

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
                    pokedex[i].nome,                         //exibe as infos dos pokemons que t�m esse tipo
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
        
        case 2:  //gera��o dos pokemons

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
            }
                
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

        default:
        break;
    }//switch
}//PesquisaTipoGen

void gerenciamentoPokemons(int* quant_pokemons_capturados, Colecao* gerenciamento)
{
    //realoca a cole��o de pokemons
    gerenciamento = realloc(gerenciamento, *quant_pokemons_capturados * sizeof(Colecao));

}//gerenciamentoPokemons

void LugarDeCaptura()
{
    //delcara��o de vari�veis
    Pokemon pokedex[722];
    Colecao contadores;
    Colecao* reallocGerenciamento;

    //alocação dos pokemos dinamicamente assim que sair do sistema de captura
    int tam = 1000;
    reallocGerenciamento = (Colecao*) malloc (tam * sizeof(Colecao));

    int *contador_de_pokemons = 1; //1 pq ja tem o pokemon inicial
    int opcao_local;
    int opcao_captura;
    int taxa_sorteada_captura[3], capturou;

    char tipos_floresta[40] = {"Planta, Venenoso, Bug, Normal, Fada"}; //define os tipos que aparecerao
    char tipos_lago[40] = {"Agua, Voador, Planta"};
    char tipos_pantano[40] = {"Psychic, Venenoso, Agua, Inseto"};
    char tipos_mansao_assombrada[40] = {"Dark, Ghost, Psychic"};
    char tipos_vulcao[40] = {"Fogo, Lutador, Pedra, Terra"};
    char tipos_deserto[40] = {"Pedra, Terra, Fogo"};
    char tipos_montanhas[40] = {"Dragao, Voador"};
    char tipos_bosque[40] = {"Dragao, Fada"};
    char tipos_pedreira[40] = {"Aço, Pedra, Terra"};
    char tipos_usina[40] = {"Eletrico"};
    char tipos_utfpr[40] = {"Fogo, Eletrico, Pedra, Terra, Fada, Planta, Aço"};

    //sorteia um valor aleat�rio
    srand(time(NULL));
    int pokemon_sorteado = rand() % 722 + 1; //sorteia um pokemon

    CriaVetorPokedex(pokedex);
    
    do
    {
        //escolhe o lugar para capturar pokemons
        printf("para onde vamos:\n");
        printf("floresta - 1\nlago - 2\npantano - 3\nmansao assombrada - 4\nencosta do vulcao - 5\ndeserto - 6\nmontanhas - 7\nbosque - 8\npedreira - 9\nusina eletrica - 10\nUTFPR-AP - 11\n");
        scanf("%i", &opcao_local);

        if(opcao_local < 1 || opcao_local > 11)
            printf("opcao invalida... insira novamente\n");
    }while(opcao_local < 1 || opcao_local > 11);

    switch(opcao_local)
    {
        case 1: //floresta

            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_floresta) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_floresta) != NULL) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                     //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0;//variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)//caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;

        case 2: //lago
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_lago) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_lago) != NULL) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0;//variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)//caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;

        case 3: //pantano
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_pantano) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_pantano) != NULL) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0; //variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)//caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;

        case 4: //mansao assombrada
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_mansao_assombrada) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_mansao_assombrada) != NULL) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0; //variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0) //caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;

        case 5: //encosta do vulcao
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_vulcao != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_vulcao) != NULL)) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0;//variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)//caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu !!!");
                }//if
            }//if
        break;

        case 6: //deserto
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_deserto) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_deserto) != NULL)//compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0;//variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)//caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;

        case 7: //montanha
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_montanhas) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_montanhas) != NULL) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0;//variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)//caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;

        case 8: //bosque
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_bosque) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_bosque) != NULL) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0;//variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)//caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;

        case 9: //pedreira
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_pedreira) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_pedreira) != NULL) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
        
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0;//variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;

        case 10: //usina eletrica
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_usina) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_usina) != NULL) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0;//variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)//caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;

        case 11: //utfpr
            if(strstr(pokedex[pokemon_sorteado].tipo1, tipos_utfpr) != NULL || strstr(pokedex[pokemon_sorteado].tipo2, tipos_utfpr) != NULL) //compara substring
            {
                //caso o tipo do pokemon sorteado estiver dentre os tipos encontrados nesse lugar
                printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
                printf("voce deseja captura-lo?\n");
                printf("1 - sim |||| 0 - nao\n");
                scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
                
                while(opcao_captura != 0 && opcao_captura != 1)
                {
                    //caso seja inserida uma opcao invalida
                    printf("opcao invalida. insira novamente:\n");
                    scanf("%i", &opcao_captura);
                }//while

                if(opcao_captura == 1)
                {
                    capturou = 0;//variavel de localiza��o
                    for(int i = 0; i < 3; i++)
                    {
                        taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                        if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                        {
                            capturou++;//incrementa a localiza��o caso capturar
                            (*contador_de_pokemons)++;
                            gerenciamentoPokemons(*contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                            printf("capturado!!!");
                            break;
                        }//if
                        else
                            printf("não conseguimos captura-lo!\n");
                    }//for
                    if(capturou == 0)//caso n�o tenha conseguido capturar
                    printf("o pokemon fugiu!!!");
                }//if
            }//if
        break;
        case 12:
            if (opcao_local == 12)
            {
                contadores.contadorPokemons = (*contador_de_pokemons);
                reallocGerenciamento = realloc(reallocGerenciamento, (*contador_de_pokemons) * sizeof (Colecao));
            }

        break;
    }//switch
}//LugarDeCaptura

void AllocJogo(int* nmrPokemon)
{
    Colecao* reservaMemoria = (Colecao*) malloc (1 * sizeof(Colecao));
    reservaMemoria = (*nmrPokemon);

}//AllocJogo

void NovoJogo() //abre um arquivo novo 
{
    //declara��o de vari�veis
    int opcao_geracao;
    int opcao_pokemon;
    int PokemonEscolhidoFinal;
    
    //coment�rios iniciais para auxiliar o usu�rio
    printf("Bem vindo! O jogo esta sendo inicializado...\n");

    printf("Eu sou F.R.I.D.A.Y e te ajudarei sempre que necessario nessa jornada...\n Para começarmos você deve escolher um pokemon inicial.\n Essa é a lista de pokemons iniciais: \n");
    
    //apresenta as op��es de pokemons iniciais disponiveis de acordo com sua respectiva gera��o
    printf("1° Geração:\n 1 - Bulbasaur\n 2 - Charmander\n 3 - Squirtle\n");

    printf("2º Geração:\n 1 - Chicorita\n  2 - Cyndaquil\n3 - Totododile\n");

    printf("3° Geração:\n 1 - Treecko\n 2 - Torchic\n 3- Mudkip\n");

    printf("4º Geração:\n 1 - Turtwig\n 2 - Chimchar\n 3 - Piplup\n");

    printf("5º Geração:\n 1 - Snivy\n 2 - Tepig\n 3 - Oshawott\n");

    printf("6º Geração:\n 1 - Chespin\n  2 - Fennekin\n 3 - Froakie\n");

    printf("insira qual geração deseja escolher:\n");
    scanf("%i", &opcao_geracao);

    while(opcao_geracao < 1 || opcao_geracao > 6)
    {
        printf("opção de geracao invalida! Insira novamente...\n");
        scanf("%i", &opcao_geracao);
    }//while

    switch (opcao_geracao)//escolhe o primeiro pokemon de acordo com a gera��o que escolher
    {
        case 1://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n");
            printf("1 - Bulbasaur\n2 - Charmander\n3 - Squirtle\n");
            scanf("%i", &opcao_pokemon);
            
            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 1;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Bulbasaur

            if(opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 4;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Charmander

            if(opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 7;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Squirtle

        break;

        case 2://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Chikorita\n 2 - Totododile\n 3 - Cyndaquil\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 152;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Chikorita
                
            if (opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 155;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Totododile
                
            if (opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 158;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Cyndaquil
            
        break;
        
        case 3://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Treecko\n 2 - Torchic\n 3- Mudkip\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 252;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Treecko
                
            if (opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 255;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Torchic
                
            if (opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 258;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Mudkip

        break;

        case 4://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Turtwig\n 2 - Chimchar\n 3 - Piplup\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 387;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Tortwig
                
            if (opcao_pokemon == 390)
            {
                PokemonEscolhidoFinal = 1;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Chimchar
                
            if (opcao_pokemon == 393)
            {
                PokemonEscolhidoFinal = 1;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Piplup
        
        break;

        case 5://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Snivy\n 2 - Tepig\n 3 - Oshawott\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 495;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Snivy
                
            if (opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 498;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Tepig
                
            if (opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 501;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Oshawott
        
        break;

        case 6://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Chespin\n  2 - Fennekin\n 3 - Froakie\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 650;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Chespin
                
            if (opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 653;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Fennekin
                
            if (opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 656;
                AllocJogo(&PokemonEscolhidoFinal);//envia para a funcao para fazer a aloca��o dos pokemons
            }//Froaki
        
        break;

        default:

            printf("Opção invalida... Digite novamente...");
        break;
            
    }//switch
}//NovoJogo

void MecanicasDeJogo()
{
    //exibe as instru��es principais do jogo
    printf("Passo 1:\n\n");
    printf("F.R.I.D.A.Y: Escolher seu inicial é uma das partes mais importantes da nossa jornada, ele te acompanhara durante o inicio da jornada e te ajudara futuramente em batalhas,\n assim que iniciar um novo jogo você terá que escolher uma geração e um de seus respectivos iniciais\n sendo tipo água, fogo ou planta...");

    printf("Passo 2:\n\n");
    printf("F.R.I.D.A.Y: Vamos a captura, agora vamos começar a formar seu time, primeiramente vamos começar escolhendo a area em que vamos captura- los\n essas areas são floresta, pantano, fabrica, etc... e cada uma pode aparecer um tipo especifico de pokemon dependendo de seu tipo\n");
    printf("Os tipos de acordo com cada lugar:\nFloreta:\n Planta\nVenenoso\nNormal\nInseto\nFada\n Lago:\nAgua\nVoador\nPlanta\n Plantano:\nPsychic\nVenenoso\nAgua\nInseto\nMansão\n Assombrada:\nDark\nGhost\nPsychic\nEncosta Do Vucão:\nFogo\nLutador\nPedra\nTerra\nDeserto:\nPedra\nTerra\nFogo\nMontanhas:\nDragão\nVoador\nBosque:\nDragão\nFada\nPedreira:\nAço\nPedra\nTerra\nUsina Eletrica:\nEletrico\nUTFPR- AP:\nFogo\nEletrico\nPedra\nTerra\nFada\nPlanta\nAço\n");

    printf("Passo 3:\n\n");
    printf("F.R.I.D.A.Y: Batalha, continua\n\n\n");

}//MecanicasDeJogo

//funçao de salvamento
void salvamentoNoHD() //EM BINARIO
{
    //salvar pokemons da mochila e da coleção
}//salvamentoNoHD

//funçoes necessarias
//-------------------
/*
1- Menus e submenus ----------- FEITO
2- pesquisa por tipo e geração ------- FEITO
3- salvamento em binario ------ AINDA FALTA
4- gerenciamento dos pokemons obtidos ---- MAIS OU MENOS FEITO --> mochila com os 6 bichin
5- sistema de batalha ----- NEM IREMOS FAZER
6- identificar se ta no windows ou linux ----- FEITO
7- cadastro de novos pokemons na pokedex e na cole��o ----- FEITO
*/

int main()
{
    //decalra��o de variaveis
    char* nickname = NULL;
    int tam = 21;
    int opcao;

    nickname = (char*) malloc (tam * sizeof(char)); //aloca dinamicamente o tamanho do nome inserido

    verificaWinOuLinux();//verifica se esta no windows ou linux

    printf("Bem vindo ao Menu inicial!!!\n");
    printf("Primeiramente, me diga seu nickname para que possamos continuar:\n");
    setbuf(stdin, NULL);
    fgets(nickname, tam, stdin);
    nickname[strcspn(nickname, "\n")] = '\0';
    setbuf(stdin, NULL); //recebe o nome inserido pelo usu�rio

    printf("Bom, vamos lá %s!\n", nickname);
    
    do{
        printf("Escolha uma op��o para iniciar:\n");
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
                LugarDeCaptura();

            break;
            
            case 2:
                printf("Carrega um arquivo do jogo ja existente\n");
                LugarDeCaptura();

            break;
            
            case 3:
                printf("Mecanicas do Jogo:\n");
                MecanicasDeJogo();

            break;
            
            case 4:
                printf("Fechando o jogo...\n");
                salvamentoNoHD();

            break;
            
            default:
                printf("Op��o invalida...");

            break;
        }//switch
    }while(opcao != 4);//menu do jogo (do while)

    free(nickname);

    return 0;
}//main