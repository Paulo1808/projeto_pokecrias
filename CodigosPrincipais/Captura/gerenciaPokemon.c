#include <stdio.h>
#include <stdlib.h>
#include "captura.h"

/**
 * @brief realoca a estrutura colecao para cada vez que um novo pokemon for capturado
 *
 * @param quant_pokemons_capturados //quantidade de pokemons que foram capturados
 * @param gerenciamento //estrutura colecao que será realocada
 */
void gerenciamentoPokemons(int* quant_pokemons_capturados, Colecao* gerenciamento)
{
    //realoca a colecao de pokemons
    gerenciamento = realloc(gerenciamento, *quant_pokemons_capturados * sizeof(Colecao));

}//gerenciamentoPokemons