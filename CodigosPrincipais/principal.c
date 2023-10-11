#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int numero;
    char nome[31], tipo1[31], tipo2[31];
    int total, ataque, defesa, ataque_especial, defesa_especial;
    int velocidade, geracao;
    bool lendario;
    char cor;
    int taxa_de_captura, prox_evolucao, pre_evolucao;
    float altura, peso;
}Pokedex; //definindo struct

typedef struct
{
    int pokemon1;
    int pokemon2; 
    int pokemon3;
    int pokemon4;
    int pokemon5;
    int pokemon6;

} mochila;// mochila com os pokemons

int main(){
printf("Hello World\n");

}