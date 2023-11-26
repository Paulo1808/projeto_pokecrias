#include <stdio.h>
#include <stdlib.h>
#ifndef CABECALHO_H
#define CABECALHO_H

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
    int opcao_local, localizei;
    int opcao_captura;
    int taxa_sorteada_captura[3], capturou;

    char tipos_floresta[5][40] = {"Planta", "Venenoso", "Bug", "Normal", "Fada"}; //define os tipos que aparecerao
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
            localizei = 0;
            for(int i = 0; i < 5; i++){
                if(localizei == 0){
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
                            capturou = 0;//variavel de localiza��o
                            for(int i = 0; i < 3; i++)
                            {
                                taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                {
                                    capturou++;//incrementa a localiza��o caso capturar
                                    (*contador_de_pokemons)++;
                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                    printf("capturado!!!");
                                    break;
                                }//if
                                else
                                    printf("não conseguimos captura-lo!\n");
                            }//for
                            if(capturou == 0)//caso n�o tenha conseguido capturar
                            printf("%s fugiu!!!\n", pokedex[pokemon_sorteado].nome);
                        }
                        else
                        {
                            printf("%s fugiu!\n", pokedex[pokemon_sorteado].nome);
                        }
                    }else{
                        printf("Nenhum pokemon foi encontrado neste lugar.\nProcure em outro lugar.");
                    }
                    localizei++;
                }
            }
        break;

        case 2: //lago
            localizei = 0;
            for(int i = 0; i < 3; i++){
                if(localizei == 0){

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
                            capturou = 0;//variavel de localiza��o
                            for(int i = 0; i < 3; i++)
                            {
                                taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                                if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                                {
                                    capturou++;//incrementa a localiza��o caso capturar
                                    (*contador_de_pokemons)++;
                                    gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
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
                    localizei++;
                }
            }
        break;

        case 3: //pantano
        localizei = 0;
        for(int i = 0; i < 4; i++){
            if(localizei == 0){

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
                        capturou = 0; //variavel de localiza��o
                        for(int i = 0; i < 3; i++)
                        {
                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                            {
                                capturou++;//incrementa a localiza��o caso capturar
                                (*contador_de_pokemons)++;
                                gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
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
                localizei++;
            }
        }
        break;

        case 4: //mansao assombrada
        localizei = 0;
        for(int i = 0; i < 3; i++){
            if(localizei == 0){

                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_mansao_assombrada[i]) == 0 || strstr(pokedex[pokemon_sorteado].tipo2, tipos_mansao_assombrada[i]) == 0) //compara substring
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
                                gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
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
                localizei++;
            }
        }
        break;

        case 5: //encosta do vulcao
        localizei = 0;
        for(int i = 0; i < 4; i++){
            if(localizei == 0){

                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_vulcao[i]) == 0 || strstr(pokedex[pokemon_sorteado].tipo2, tipos_vulcao[i]) == 0) //compara substring
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
                                gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
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
                localizei++;
            }
        }
        break;

        case 6: //deserto
        localizei = 0;
        for(int i = 0; i < 3; i++){
            if(localizei == 0){

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
                        capturou = 0;//variavel de localiza��o
                        for(int i = 0; i < 3; i++)
                        {
                            taxa_sorteada_captura[i] = rand() % 255 + 1; //sorteia 3 numeros --> 3 chances de captura
                            if(taxa_sorteada_captura[i] <= pokedex[pokemon_sorteado].numero) //o numero sorteado deve ser menor ou igual a sua taxa para ser capturado
                            {
                                capturou++;//incrementa a localiza��o caso capturar
                                (*contador_de_pokemons)++;
                                gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
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
                localizei++;
            }
        }
        break;

        case 7: //montanha
        localizei = 0;
        for(int i = 0; i < 2; i++){
            if(localizei == 0){
                
                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_montanhas[i]) == 0 || strstr(pokedex[pokemon_sorteado].tipo2, tipos_montanhas[i]) == 0) //compara substring
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
                                gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
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
                localizei++;
            }
        }
        break;

        case 8: //bosque
        localizei = 0;
        for(int i = 0; i < 2; i++){
            if(localizei == 0){
                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_bosque[i]) == 0 || strstr(pokedex[pokemon_sorteado].tipo2, tipos_bosque[i]) == 0) //compara substring
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
                                gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
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
                localizei++;
            }
        }
        break;

        case 9: //pedreira
        localizei = 0;
        for(int i = 0; i < 3; i++){
            if(localizei == 0){
                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_pedreira[i]) == 0 || strstr(pokedex[pokemon_sorteado].tipo2, tipos_pedreira[i]) == 0) //compara substring
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
                                gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
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
                localizei++;
            }
        }
        break;

        case 10: //usina eletrica
        localizei = 0;
        for(int i = 0; i < 1; i++){
            if(localizei == 0){
                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_usina[i]) == 0 || strstr(pokedex[pokemon_sorteado].tipo2, tipos_usina[i]) == 0) //compara substring
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
                                gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                printf("capturado!!!");
                                break;
                            }//if
                            else
                                printf("não conseguimos captura-lo!\n");
                        }//for
                        if(capturou == 0)//caso n�o tenha conseguido capturar
                        printf("o pokemon fugiu!!!");
                    }//if
                    }
                    localizei++;
            }//if
        }
        break;

        case 11: //utfpr
        localizei = 0;
        for(int i = 0; i < 7; i++){
            if(localizei == 0){
                if(strcmp(pokedex[pokemon_sorteado].tipo1, tipos_utfpr[i]) == 0 || strstr(pokedex[pokemon_sorteado].tipo2, tipos_utfpr[i]) == 0) //compara substring
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
                                gerenciamentoPokemons(contador_de_pokemons, reallocGerenciamento); //chama a funcao para reallocar
                                printf("capturado!!!");
                                break;
                            }//if
                            else
                                printf("não conseguimos captura-lo!\n");
                        }//for
                        if(capturou == 0)//caso n�o tenha conseguido capturar
                        printf("o pokemon fugiu!!!");
                    }//if
                    }
                    localizei++;
            }//if
        }
        break;
        /*case 12:
            if (opcao_local == 12)
            {
                contadores.contadorPokemons = (*contador_de_pokemons);
                reallocGerenciamento = realloc(reallocGerenciamento, (*contador_de_pokemons) * sizeof (Colecao));
            }
            
        break;*/
    }//switch
}//LugarDeCaptura

#endif