#include <stdio.h>
#include <stdlib.h>
#ifndef CABECALHO_H
#define CABECALHO_H

void NovoJogo() //abre um arquivo novo 
{
    //declara��o de vari�veis
    int opcao_geracao;
    int opcao_pokemon;
    int PokemonEscolhidoFinal;
    
    //coment�rios iniciais para auxiliar o usu�rio
    printf("Bem vindo! O jogo esta sendo inicializado...\n");

    printf("Eu sou F.R.I.D.A.Y e te ajudarei sempre que necessario nessa jornada...\nPara começarmos você deve escolher um pokemon inicial.\nEssa é a lista de pokemons iniciais: \n");
    
    //apresenta as op��es de pokemons iniciais disponiveis de acordo com sua respectiva gera��o
    printf("1° Geração: 1 - Bulbasaur 2 - Charmander 3 - Squirtle\n");

    printf("2º Geração: 1 - Chicorita  2 - Cyndaquil 3 - Totododile\n");

    printf("3° Geração: 1 - Treecko 2 - Torchic 3- Mudkip\n");

    printf("4º Geração: 1 - Turtwig 2 - Chimchar 3 - Piplup\n");

    printf("5º Geração: 1 - Snivy 2 - Tepig 3 - Oshawott\n");

    printf("6º Geração: 1 - Chespin  2 - Fennekin 3 - Froakie\n");

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
            printf("1 - Bulbasaur 2 - Charmander 3 - Squirtle\n");
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
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Chikorita 2 - Totododile 3 - Cyndaquil\n");
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
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Treecko 2 - Torchic 3- Mudkip\n");
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
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Turtwig 2 - Chimchar 3 - Piplup\n");
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
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Snivy 2 - Tepig 3 - Oshawott\n");
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
            printf("QUEM VOCÊ ESCOLHE?\n 1 - Chespin 2 - Fennekin 3 - Froakie\n");
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

#endif