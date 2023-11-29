#include <stdio.h>
#include <stdlib.h>
#include "principal.h"

/**
 * @brief //abre um arquivo novo para um novo jogo
 * 
 */
void NovoJogo() 
{
    //declaracao de variaveis
    int opcao_geracao;
    int opcao_pokemon;
    int PokemonEscolhidoFinal;
    
    //comentarios iniciais para auxiliar o usuario
    printf("Bem vindo! O jogo esta sendo inicializado...\n");

    printf("Eu sou F.R.I.D.A.Y e te ajudarei sempre que necessario nessa jornada...\nPara começarmos você deve escolher um pokemon inicial.\nEssa é a lista de pokemons iniciais: \n");
    
    //apresenta as opcoes de pokemons iniciais disponiveis de acordo com sua respectiva geracao
    printf("Geração 1: 1 - Bulbasaur 2 - Charmander 3 - Squirtle\n");

    printf("Geração 2: 1 - Chicorita 2 - Cyndaquil  3 - Totododile\n");

    printf("Geração 3: 1 - Treecko   2 - Torchic    3- Mudkip\n");

    printf("Geração 4: 1 - Turtwig   2 - Chimchar   3 - Piplup\n");

    printf("Geração 5: 1 - Snivy     2 - Tepig      3 - Oshawott\n");

    printf("Geração 6: 1 - Chespin   2 - Fennekin   3 - Froakie\n");

    printf("insira qual geração deseja escolher:\n");
    scanf("%i", &opcao_geracao);//escolhe a geracao para escolher o primeiro pokemon do jogo

    while(opcao_geracao < 1 || opcao_geracao > 6)
    {
        printf("opção de geracao invalida! Insira novamente...\n");
        scanf("%i", &opcao_geracao);
    }//while

    switch (opcao_geracao)//escolhe o primeiro pokemon de acordo com a geracao que escolher
    {
        case 1://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n");
            printf("1 - Bulbasaur 2 - Charmander 3 - Squirtle\n");
            scanf("%i", &opcao_pokemon);
            
            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 1;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Bulbasaur

            if(opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 4;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Charmander

            if(opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 7;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Squirtle

        break;

        case 2://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Chikorita 2 - Totododile 3 - Cyndaquil\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 152;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Chikorita
                
            if (opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 155;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Totododile
                
            if (opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 158;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Cyndaquil
            
        break;
        
        case 3://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Treecko 2 - Torchic 3- Mudkip\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 252;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Treecko
                
            if (opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 255;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Torchic
                
            if (opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 258;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Mudkip

        break;

        case 4://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Turtwig 2 - Chimchar 3 - Piplup\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 387;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Tortwig
                
            if (opcao_pokemon == 390)
            {
                PokemonEscolhidoFinal = 1;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Chimchar
                
            if (opcao_pokemon == 393)
            {
                PokemonEscolhidoFinal = 1;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Piplup
        
        break;

        case 5://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Snivy 2 - Tepig 3 - Oshawott\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 495;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Snivy
                
            if (opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 498;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Tepig
                
            if (opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 501;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Oshawott
        
        break;

        case 6://escolhe o pokemon dentre os tres abaixo
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Chespin 2 - Fennekin 3 - Froakie\n");
            scanf("%i", &opcao_pokemon);

            if(opcao_pokemon == 1)
            {
                PokemonEscolhidoFinal = 650;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Chespin
                
            if (opcao_pokemon == 2)
            {
                PokemonEscolhidoFinal = 653;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Fennekin
                
            if (opcao_pokemon == 3)
            {
                PokemonEscolhidoFinal = 656;//numero do pokemon escolhido
                AllocJogo(PokemonEscolhidoFinal);//envia para a funcao para fazer a alocacao do pokemon
            }//Froaki
        
        break;            
    }//switch
}//NovoJogo