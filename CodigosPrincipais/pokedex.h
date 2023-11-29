#ifndef POKEDEX_H
#define POKEDEX_H

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

#endif