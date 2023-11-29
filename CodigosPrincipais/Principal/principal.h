#ifndef STRUCT_H
#define STRUCT_H
#include "captura.h"
#include "cadastroPokemon.h"
#include "novoJogo.h"

typedef struct
{
    int numero;
    char nome[31], tipo1[31], tipo2[31];
    int total, hp,ataque, defesa, ataque_especial, defesa_especial;
    int velocidade, geracao;
    int lendario;
    char cor[16];
    int taxa_de_captura;
    float altura, peso;
}Pokemon; //definindo struct com as infos de cada pokemon

typedef struct
{
    Pokemon pokemons_mochila;
}mochila;// mochila com os pokemons

typedef struct
{
    int *pokemonCapturado;
    int *contadorPokemons;
}Colecao; //struct cole��o

typedef struct
{
    char a[15], b[15], c[15], d[15], e[15], f[15], g[15], h[15], i[15], j[15], k[15], l[15], m[15], n[15], o[15], p[15], q[15];
}Lixo;//lixo par armazenar a primeira linha do pokedex que n�o cont�m nenhum pokem�n

void verificaWinOuLinux();

#endif