#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "principal.h"

/**
 * @brief //realiza a captura de determinado pokemon de acordo com a estrategia criada
 * 
 * @param opcao //para caso entrar em uma opcao especifica (opcao == 5), a qual será deslocada para uma outra funcao
 */
void LugarDeCaptura(int opcao)
{
    //declaracao de variaveis
    Pokemon pokedex[722];
    Colecao contadores;
    Colecao* reallocGerenciamento;
    mochila* mochila_de_pokemons = calloc(6, sizeof(mochila));

    //alocação dos pokemos dinamicamente assim que sair do sistema de captura
    int tam = 1000;
    reallocGerenciamento = (Colecao*) malloc (tam * sizeof(Colecao));

    //variaveis de controle
    int *contador_de_pokemons; 
    (*contador_de_pokemons) = 1;//1 pq ja tem o pokemon inicial
    int opcao_local, localizei, salveiMochila;
    int opcao_captura, j, sair = 0;
    int taxa_sorteada_captura[3], capturou;

    //define os tipos que aparecerao
    char tipos_floresta[5][40] = {"Planta", "Venenoso", "Bug", "Normal", "Fada"}; 
    char tipos_lago[3][40] = {"Water", "Voador", "Planta"};
    char tipos_pantano[4][40] = {"Psychic", "Venenoso", "Water", "Bug"};
    char tipos_mansao_assombrada[3][40] = {"Sombrio", "Ghost", "Psychic"};
    char tipos_vulcao[4][40] = {"Fire", "Lutador", "Pedra", "Terra"};
    char tipos_deserto[3][40] = {"Pedra", "Terra", "Fire"};
    char tipos_montanhas[2][40] = {"Dragon", "Voador"};
    char tipos_bosque[2][40] = {"Dragon", "Fada"};
    char tipos_pedreira[3][40] = {"Aço", "Pedra", "Terra"};
    char tipos_usina[1][20] = {"Electric"};
    char tipos_utfpr[7][50] = {"Fire", "Electric", "Pedra", "Terra", "Fada", "Planta", "Aço"};

    //sorteia um valor aleatorio
    srand(time(NULL));
    int pokemon_sorteado = rand() % 722 + 1; //sorteia um pokemon

    switch(opcao)
    {
        case 1:
        case 2:     
            printf("Vamos comecar a capturar alguns pokemons?\n");
            CriaVetorPokedex(pokedex);//recebe o vetor da pokedex
            
            do
            {
                do
                {
                    //escolhe o lugar para capturar pokemons
                    printf("para onde vamos:\n");
                    printf("floresta - 1\nlago - 2\npantano - 3\nmansao assombrada - 4\nencosta do vulcao - 5\ndeserto - 6\nmontanhas - 7\nbosque - 8\npedreira - 9\nusina eletrica - 10\nUTFPR-AP - 11\n");
                    scanf("%i", &opcao_local);

                    if(opcao_local < 1 || opcao_local > 11)//repetir enquanto estiver fora dos parametros
                        printf("opcao invalida... insira novamente\n");
                }while(opcao_local < 1 || opcao_local > 11);

                switch(opcao_local)//entra na opcao escolhida pelo usuario
                {
                    case 1: //floresta
                        localizei = 0;
                        for(int i = 0; i < 5; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se ja foi encontrado um pokemon ou não
                            {
                                if((strcmp(pokedex[pokemon_sorteado].tipo1, tipos_floresta[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_floresta[i]) == 0)) //compara substring
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
                                        capturou = 0;//variavel de localizacao se foi capturado ou nao
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].taxa_de_captura) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar se foi salvo ou nao na mochila
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for

                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("%s fugiu!!!\n", pokedex[pokemon_sorteado].nome);
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel para nao continuar procurando um novo pokemon 
                            }//if
                        }//for
                    break;

                    case 2: //lago
                        localizei = 0;
                        for(int i = 0; i < 3; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se ja foi encontrado um pokemon ou não
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_lago[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_lago[i]) == 0) //compara substring
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
                                        capturou = 0;//variavel de localizacao se foi capturado ou nao
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar se o pokemon foi salvo na mochila 
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu!!!");
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;

                    case 3: //pantano
                        localizei = 0;
                        for(int i = 0; i < 4; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se um pokemon foi encontrado
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_pantano[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_pantano[i]) == 0) //compara substring
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
                                        capturou = 0; //variavel de localizacao para verificar se o pokemon foi capturado
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar se foi salvo na mochila
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu!!!");
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;

                    case 4: //mansao assombrada
                        localizei = 0;
                        for(int i = 0; i < 3; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se um pokemon foi encontrado
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_mansao_assombrada[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_mansao_assombrada[i]) == 0) //compara substring
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
                                        capturou = 0; //variavel de localizacao para verificar se o pokemon foi capturado
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar caso o pokemon foi salvo na mochila
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0) //caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu!!!");
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;

                    case 5: //encosta do vulcao
                        localizei = 0;
                        for(int i = 0; i < 4; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se um pokemon foi encontrado ou nao
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_vulcao[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_vulcao[i]) == 0) //compara substring
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
                                        capturou = 0;//variavel de localizacao para verificar se o pokemon foi capturado
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar caso o pokemon foi salvo na mochila
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu !!!");
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;

                    case 6: //deserto
                        localizei = 0;
                        for(int i = 0; i < 3; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se um pokemon foi encontrado ou nao
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_deserto[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_deserto[i]) == 0)//compara substring
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
                                        capturou = 0;//variavel de localizacao para verificar se o pokemon foi capturado
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar se foi salvo na mochila ou nao
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu!!!");
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;

                    case 7: //montanha
                        localizei = 0;
                        for(int i = 0; i < 2; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se foi encontrado um pokemon ou nao
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_montanhas[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_montanhas[i]) == 0) //compara substring
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
                                        capturou = 0;//variavel de localizacao para verificar se o pokemon foi capturado ou nao
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar se foi salvo na mochila ou nao
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu!!!");
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;

                    case 8: //bosque
                        localizei = 0;
                        for(int i = 0; i < 2; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se foi encontrado um pokemon ou nao
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_bosque[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_bosque[i]) == 0) //compara substring
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
                                        capturou = 0;//variavel de localizacao para verificar se o pokemon foi capturado ou nao
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar se foi salvo na mochila ou nao
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu!!!");
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;

                    case 9: //pedreira
                        localizei = 0;
                        for(int i = 0; i < 3; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se foi encontrado um pokemon ou nao
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_pedreira[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_pedreira[i]) == 0) //compara substring
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
                                        capturou = 0;//variavel de localizacao para verificar se o pokemon foi capturado ou nao
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar se foi salvo na mochila ou nao
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu!!!");
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;

                    case 10: //usina eletrica
                        localizei = 0;
                        for(int i = 0; i < 1; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se foi encontrado um pokemon ou nao
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_usina[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_usina[i]) == 0) //compara substring
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
                                        capturou = 0;//variavel de localizacao para verificar se o pokemon foi capturado ou nao
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar se foi salvo na mochila ou nao
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu!!!");
                                    }//if
                                    else//opcao_captura == 0
                                        printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;

                    case 11: //utfpr
                        localizei = 0;
                        for(int i = 0; i < 7; i++)
                        {
                            if(localizei == 0)//variavel de localizacao para verificar se foi encontrado um pokemon ou nao
                            {
                                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_utfpr[i]) == 0 || strcmp(pokedex[pokemon_sorteado].tipo2, tipos_utfpr[i]) == 0) //compara substring
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
                                        capturou = 0;//variavel de localizacao para verificar se o pokemon foi capturado ou nao
                                        for(int i = 0; i < 3; i++)
                                        {
                                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                            {
                                                capturou++;//incrementa a localizacao caso capturar
                                                salveiMochila = 0;//variavel de localizacao para verificar se foi salvo na mochila ou nao
                                                for(j = 0; j < 6; j++)
                                                {
                                                    if(salveiMochila == 0)//se nao foi salvo na mochila
                                                    {
                                                        if(mochila_de_pokemons[j].pokemons_mochila.numero == 0)//se a linha encontrada estiver zerada
                                                        {
                                                            mochila_de_pokemons[j].pokemons_mochila = pokedex[pokemon_sorteado];//adiciona o pokemon capturado na mochila
                                                            salveiMochila++;//incrementa a variavel mochila para nao salvar na colecao
                                                        }//if
                                                    }//if
                                                }//for
                                                if(salveiMochila == 0)//se nao foi salvo na mochila, salva na colecao
                                                {
                                                    (*contador_de_pokemons)++;
                                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                                }//if
                                                printf("capturado!!!");
                                                break;
                                            }//if
                                            else
                                                printf("não conseguimos captura-lo!\n");
                                        }//for
                                        if(capturou == 0)//caso nao tenha conseguido capturar
                                        printf("o pokemon fugiu!!!");
                                    }//if
                                }//if
                                else
                                {
                                    printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                                }//else
                                localizei++;//incrementa a variavel de localizacao para nao procurar outro pokemon
                            }//if
                        }//for
                    break;
                }//switch
                printf("\ndeseja voltar ao menu?\n1- sim 0- nao\n");//caso queira fazer mais alguma coisa nessa funcao antes de voltar para o menu
                scanf("%i", &sair);
            }while(sair == 0);
        break;

        case 6:
            //manda para a funcao de salvamento no HD para finalizar o programa
            salvamentoNoHD(mochila_de_pokemons, reallocGerenciamento, &contador_de_pokemons);
        break;
    }//switch
}//LugarDeCaptura