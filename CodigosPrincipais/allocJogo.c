#include <stdio.h>
#include <stdlib.h>
#include "principal.h"

/**
 * @brief //aloca memoria para o pokemon da primeira posicao do vetor determinada pela geracao escolhida pelo usuario
 * 
 * @param nmrPokemon //numero do pokemon escolhido
 */
void AllocJogo(int nmrPokemon)
{
    Colecao* reservaMemoria = malloc (1 * sizeof(Colecao));//aloca uma posicao do vetor
    reservaMemoria[0].contadorPokemons = nmrPokemon;//salva o numero do pokemon escolhido

}//AllocJogo