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
    int prox_evolucao, pre_evolucao;
}evolucoes;

typedef struct
{
    Pokemon pokemons_mochila;
}mochila;// mochila com os pokemons

typedef struct{
    int *pokemonCapturado;
}Colecao; //struct coleçao

typedef struct{
    char a[15], b[15], c[15], d[15], e[15], f[15], g[15], h[15], i[15], j[15], k[15], l[15], m[15], n[15], o[15], p[15], q[15];
}Lixo;

void CriaVetorPokedex(Pokemon pokedexGeral[])
{
    FILE *ArquivoPokedex = fopen("pokedex.csv", "r"); //abre o arquivo da pokedex
    Lixo lixo;
    fseek(ArquivoPokedex, 0, SEEK_SET);

    for (int i = 0; i < 722; i++)
    {
        if (i == 0)
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
        }else{
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
        }
    }

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

printf("| Numero |    Nome    |   Tipo 1   |   Tipo 2   | total |  HP  | Ataque | Defesa | Sp. Ataque | Sp. Defesa | Speed  | Gen | Lendario |   Cor   |Altura |  Peso | Taxa Cap. |\n");

                for (int i = 1; i < 722; i++)
                {
                    if (strcasecmp(tipoPokemon, pokedex[i].tipo1) == 0 || strcasecmp(tipoPokemon, pokedex[i].tipo2) == 0)
                    {
                        printf("|%-8i|%-12s|%-12s|%-12s|%-7i|%-6i|%-8i|%-8i|%-12i|%-12i|%-8i|%-5i|%-10i|%-9s|%-7.2f|%-7.2f|%-11i|\n", 
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

                printf("| Numero |    Nome    |   Tipo 1   |   Tipo 2   | total |  HP  | Ataque | Defesa | Sp. Ataque | Sp. Defesa | Speed  | Gen | Lendario |   Cor   |Altura |  Peso | Taxa Cap. |\n");

                for (int i = 1; i < 722; i++)
                {
                    if (numeroGeracao == pokedex[i].geracao)
                    {
                        printf("|%8i|%-12s|%-12s|%-12s|%-7i|%-6i|%-8i|%-8i|%-12i|%-12i|%-8i|%-5i|%-10i|%-9s|%-6.2f|%-4.2f|%-11i|\n", 
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

int MallocColecaoPokemons(){
    //passar a variavel de numero de pokemons por ponteiro e tb tem o struct do gerenciamento
    //pokemon_capturado_gerenciamento.pokemonCapturado = (Colecao*) malloc (numero_de_pokemons * sizeof(Pokemon));
}

int LugarDeCaptura()
{
    Pokemon pokedex[722];
    int numero_de_pokemons; //aqui eu criei uma variavel pra alocar o numero na memoria de acordo com o n. de pokemons que o usuario possuir
    Colecao pokemon_capturado_gerenciamento; //declarando a struct colecao
    CriaVetorPokedex(pokedex);
    int opcao_local;

    //acredito que seja melhor fazer uma funcao apenas pra isso e chama-la td vez que um pokemon for capturado
    pokemon_capturado_gerenciamento.pokemonCapturado = (Colecao*) malloc (numero_de_pokemons * sizeof(Pokemon));
    
    do{
        printf("insira para qual lugar deseja ir:\n");
        printf("floresta - 1\nlago - 2\npantano - 3\nmansao assombrada - 4\nencosta do vulcao - 5\ndeserto - 6\nmontanhas - 7\nbosque - 8\npedreira - 9\nusina eletrica - 10\nUTFPR-AP - 11\n");
        scanf("%i", &opcao_local);
        if(opcao_local < 1 || opcao_local > 11){
            printf("opcao invalida... insira novamente\n");
        }
    }while(opcao_local < 1 || opcao_local > 11);

    switch(opcao_local){

        case 1: //floresta

        int opcao_captura;
        int taxa_sorteada_captura[3];
        char tipos_floresta = {"Planta", "Venenoso", "Bug", "Normal", "Fada"}; //define os tipos que aparecerao

        srand(time(NULL));
        int pokemon_sorteado = rand() % 722 + 1; //sorteia um pokemon

        if(strcasecmp(pokedex[pokemon_sorteado].tipo1, tipos_floresta) == 0 || strcasecmp(pokedex[pokemon_sorteado].tipo2, tipos_floresta) == 0){
            printf("um %s apareceu !!!\n", pokedex[pokemon_sorteado].nome);
            printf("voce deseja captura-lo?\n");
            printf("1 - sim |||| 0 - nao\n");
            scanf("%i", &opcao_captura); //recebe se vai capturar ou nao
            if(opcao_captura != 0 || opcao_captura != 1){ //caso o usuario insira uma opcao invalida
                printf("opcao invalida. insira novamente:\n");
                scanf("%i", opcao_captura);
            }

            if(opcao_captura == 1){
                for(int i = 0; i < 3; i++){
                    taxa_sorteada_captura[i] = rand() % 255 + 1; //gera a probabilidade de captura (3 chances)
                    if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].taxa_de_captura){ //o valor deve ser menor para captura-lo
                        //mandar pra colecao. a mochila deve ser gerenciada depois apenas
                        numero_de_pokemons++;
                        //chama a funcao mallocColecaoPokemons()
                    }
                }
            }
        }

        break;

        case 2: //lago
        break;

        case 3: //pantano
        break;

        case 4: //mansao assombrada
        break;

        case 5: //encosta do vulcao
        break;

        case 6: //deserto
        break;

        case 7: //montanha
        break;

        case 8: //bosque
        break;

        case 9: //pedreira
        break;

        case 10: //usina eletrica
        break;

        case 11: //utfpr
        break;
    }
    

}//Lembarra de recriar para cada lugar

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
1- Menus e submenus ----------- FEITO
2- pesquisa por tipo e geração ------- FEITO
3- salvamento em binario ------ AINDA FALTA
4- gerenciamento dos pokemons obtidos ---- AINDA FALTA (estamos tentando a mochila)
5- sistema de batalha ----- AINDA FALTA
6- identificar se ta no windows ou linux ----- AINDA FALTA
*/

int main(){
        exibeMenu();
        
    return 0;
}//main