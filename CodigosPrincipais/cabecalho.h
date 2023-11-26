#ifndef CABECALHO_H
#define CABECALHO_H
#include "structs.h"

//cabeçalho funçoes do codigo principal
void verificaWinOuLinux();
void CriaVetorPokedex(Pokemon pokedexGeral[]);
void CadastroColecao();
void PesquisaTipoGen();
void LugarDeCaptura();
void AllocJogo(int* nmrPokemon);
void NovoJogo();
void MecanicasDeJogo();
void salvamentoNoHD();
void gerenciamentoPokemons(int* quant_pokemons_capturados, Colecao* gerenciamento);

#endif