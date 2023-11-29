#ifndef CAPTURA_H
#define CAPTURA_H
#include "mochila.h"
#include "colecao.h"
#include "pokedex.h"

void gerenciamentoPokemons(int* quant_pokemons_capturados, Colecao* gerenciamento);
void salvamentoNoHD(mochila* pokemons6, Colecao* pokemonsColecao, int *quant_pokemons_colecao);
void LugarDeCaptura(int opcao);

#endif