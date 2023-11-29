#ifndef CAPTURA_H
#define CAPTURA_H

typedef struct
{
    int *pokemonCapturado;
    int *contadorPokemons;
}Colecao; //struct coleção

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

void gerenciamentoPokemons(int* quant_pokemons_capturados, Colecao* gerenciamento);
void salvamentoNoHD(mochila* pokemons6, Colecao* pokemonsColecao, int quant_pokemons_colecao);
void LugarDeCaptura(int opcao);

#endif