#include <stdio.h>
#include <stdlib.h>
#ifndef CABECALHO_H
#define CABECALHO_H

/**
 * @brief 
 *
 * @param quant_pokemons_capturados 
 * @param gerenciamento 
 */
void gerenciamentoPokemons(int* quant_pokemons_capturados, Colecao* gerenciamento)
{
    //realoca a cole��o de pokemons
    gerenciamento = realloc(gerenciamento, *quant_pokemons_capturados * sizeof(Colecao));

}//gerenciamentoPokemons

#endif