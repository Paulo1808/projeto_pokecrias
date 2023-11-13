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

    for (int i = 0; i < 722; i++)
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
        }
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
    }//for

    fclose(ArquivoPokedex); //fecha o arquivo
}//CriaVetorPokedex

void CadastroColecao(){

    //declara��o de vari�veis
    Pokemon *pokedexGeral;
    int opcao_cadastro_colecao, *tamanhoVetor, numeroNovoPokemon;

    pokedexGeral = (Pokemon*) malloc((*tamanhoVetor) * sizeof(Pokemon));//aloca o vetor de pokemons dinamicamente
    CriaVetorPokedex(pokedexGeral);//envia para a fun��o que recebe a pokedex

    numeroNovoPokemon = pokedexGeral[(*tamanhoVetor) - 1].numero;
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
            numeroNovoPokemon++;//novo numero para o novo pokemon
            (*tamanhoVetor)++;//incrementa o tamanho do vetor
            printf("inserir novo pokemon nº %i\n",numeroNovoPokemon);
            
            pokedexGeral = realloc(pokedexGeral, (*tamanhoVetor) * sizeof(Pokemon));//realoca para receber o novo pokemon

            pokedexGeral[numeroNovoPokemon].numero = numeroNovoPokemon;//recebe o numero do pokemon

            setbuf(stdin, NULL);
            printf("digite o nome do pokemon que deseja adicionar:\n");//recebe o nome do pokemon
            fgets(pokedexGeral[numeroNovoPokemon].nome, 30, stdin);
            pokedexGeral[numeroNovoPokemon].nome[strcspn(pokedexGeral[numeroNovoPokemon].nome, "\n")] ='\0';
            setbuf(stdin, NULL);
            
            printf("Digite o tipo 1 do %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o tipo principal 
            fgets(pokedexGeral[numeroNovoPokemon].tipo1, 30, stdin);
            pokedexGeral[numeroNovoPokemon].tipo1[strcspn(pokedexGeral[numeroNovoPokemon].tipo1, "\n")] = '\0';
            setbuf(stdin, NULL);

            printf("digite o tipo 2 do %s (caso não quiser, digite \"NULL\"):\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o tipo secundario
            fgets(pokedexGeral[numeroNovoPokemon].tipo2, 30, stdin);
            pokedexGeral[numeroNovoPokemon].tipo2[strcspn(pokedexGeral[numeroNovoPokemon].tipo2, "\n")] = '\0';
            setbuf(stdin, NULL);

            printf("digite o valor de ataque do %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de ataque 
            scanf("%i", &pokedexGeral[numeroNovoPokemon].ataque);
            
            printf("digite o valor de defesa do %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de defesa
            scanf("%i", &pokedexGeral[numeroNovoPokemon].defesa);
            
            printf("digite o valor de ataque especial do %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de ataque especial
            scanf("%i", &pokedexGeral[numeroNovoPokemon].ataque_especial);
            
            printf("digite o valor de defesa especial do %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de defesa especial
            scanf("%i", &pokedexGeral[numeroNovoPokemon].defesa_especial);
            
            printf("digite a velocidade de %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de velocidade
            scanf("%i", &pokedexGeral[numeroNovoPokemon].velocidade);
            
            printf("digite o hp de %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de maximo dano
            scanf("%i", &pokedexGeral[numeroNovoPokemon].hp);
            
            //valor total � a soma dos ataques, defesas, velocidade e hp
            pokedexGeral[numeroNovoPokemon].total = pokedexGeral[numeroNovoPokemon].ataque + 
                                                    pokedexGeral[numeroNovoPokemon].defesa + 
                                                    pokedexGeral[numeroNovoPokemon].ataque_especial + 
                                                    pokedexGeral[numeroNovoPokemon].defesa_especial + 
                                                    pokedexGeral[numeroNovoPokemon].velocidade + 
                                                    pokedexGeral[numeroNovoPokemon].hp;

            printf("qual a gera��o deseja colocar %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de gera��o
            scanf("%i", &pokedexGeral[numeroNovoPokemon].geracao);
            
            printf("%s � lend�rio?\n1 - sim\n2 - n�o:\n", pokedexGeral[numeroNovoPokemon].nome);//se o pokemon � lendario ou n�o
            scanf("%i", &pokedexGeral[numeroNovoPokemon].lendario);

            printf("qual a cor de %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe a cor do pokemon
            fgets(pokedexGeral[numeroNovoPokemon].cor, 30, stdin);
            pokedexGeral[numeroNovoPokemon].cor[strcspn(pokedexGeral[numeroNovoPokemon].cor, "\n")] = '\0';
            setbuf(stdin, NULL);
            
            printf("qual a altura de %s em metros:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de altura
            scanf("%f", &pokedexGeral[numeroNovoPokemon].altura);

            printf("qual o peso de %s em kg:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de peso
            scanf("%f", &pokedexGeral[numeroNovoPokemon].peso);

            printf("qual a taxa de captura de %s:\n", pokedexGeral[numeroNovoPokemon].nome);//recebe o valor de taxa de captura
            scanf("%i", &pokedexGeral[numeroNovoPokemon].taxa_de_captura);
            
        break;

        case 2://listar pokemons
            printf("listar os pokemons\n");
            
        break;

        case 3://pesquisar pokemons
            printf("pesquisar os pokemons\n");

        break;

        case 4://alterar pokemons
            printf("alterar algum pokemon cadastrado\n");

        break;

        case 5://excluir pokemons
            printf("excluir algum pokemon cadastradon\n");
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
    reallocGerenciamento = malloc (tam * sizeof(Colecao));

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
                376
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

            main();
        break;
    }//switch
}//LugarDeCaptura


void NovoJogo() //abre um arquivo novo 
{
    //declara��o de vari�veis
    FILE* Inicializando_Jogo = fopen("pokemonGame.dat", "wb"); //abre o arquivo do novo jogo
    int opcao_geracao;
    int opcao_pokemon;
    int PokemonEscolhidoFinal;

    if(Inicializando_Jogo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);// 1 significa erro    
    }// if
    
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
    printf("Mecanicas de Jogo:\n"); 

    printf("Passo 1:\n\n");
    printf("F.R.I.D.A.Y: Escolher seu inicial é uma das partes mais importantes da nossa jornada, ele te acompanhara durante o inicio da jornada e te ajudara futuramente em batalhas,\n assim que iniciar um novo jogo você terá que escolher uma geração e um de seus respectivos iniciais\n sendo tipo água, fogo ou planta...");

    printf("Passo 2:\n\n");
    printf("F.R.I.D.A.Y: Vamos a captura, agora vamos começar a formar seu time, primeiramente vamos começar escolhendo a area em que vamos captura- los\n essas areas são floresta, pantano, fabrica, etc... e cada uma pode aparecer um tipo especifico de pokemon dependendo de seu tipo\n");
    printf("Os tipos de acordo com cada lugar:\nFloreta:\n Planta\nVenenoso\nNormal\nInseto\nFada\n Lago:\nAgua\nVoador\nPlanta\n Plantano:\nPsychic\nVenenoso\nAgua\nInseto\nMansão\n Assombrada:\nDark\nGhost\nPsychic\nEncosta Do Vucão:\nFogo\nLutador\nPedra\nTerra\nDeserto:\nPedra\nTerra\nFogo\nMontanhas:\nDragão\nVoador\nBosque:\nDragão\nFada\nPedreira:\nAço\nPedra\nTerra\nUsina Eletrica:\nEletrico\nUTFPR- AP:\nFogo\nEletrico\nPedra\nTerra\nFada\nPlanta\nAço\n");

    printf("Passo 3:\n\n");
    printf("F.R.I.D.A.Y: Batalha, continua\n\n\n");

}//MecanicasDeJogo

//funçao de salvamento
void salvamentoNoHD()
{

}//salvamentoNoHD

//funçoes necessarias
//-------------------
/*
1- Menus e submenus ----------- FEITO
2- pesquisa por tipo e geração ------- FEITO
3- salvamento em binario ------ AINDA FALTA
4- gerenciamento dos pokemons obtidos ---- AINDA FALTA (estamos tentando a mochila)
5- sistema de batalha ----- AINDA FALTA
6- identificar se ta no windows ou linux ----- FEITO
7- cadastro de novos pokemons na pokedex e na cole��o ----- AINDA FALTA (terminar todos os topicos)
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
    
    //menu do jogo
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
            //PesquisaTipoGen();
            LugarDeCaptura();

        break;
        
        case 2:
            printf("Carrega um arquivo do jogo ja existente\n");
            LugarDeCaptura();

        break;
        
        case 3:
            printf("Mecanicas do Jogo\n");
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

    free(nickname);

    return 0;
}//main