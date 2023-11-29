#ifndef NOVOJOGO_H
#define NOVOJOGO_H

typedef struct
{
    int *pokemonCapturado;
    int *contadorPokemons;
}Colecao; //struct coleção

void NovoJogo();
void AllocJogo(int* nmrPokemon);
void MecanicasDeJogo();

#endif