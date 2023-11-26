#include <stdio.h>
#include <stdlib.h>
#ifndef CABECALHO_H
#define CABECALHO_H

/**
 * @brief 
 * 
 * @param nmrPokemon 
 */
void AllocJogo(int* nmrPokemon)
{
    Colecao* reservaMemoria = (Colecao*) malloc (1 * sizeof(Colecao));
    reservaMemoria->contadorPokemons = (*nmrPokemon);

}//AllocJogo
#endif