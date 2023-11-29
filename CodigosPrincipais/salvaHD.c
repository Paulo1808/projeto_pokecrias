#include <stdio.h>
#include <stdlib.h>
#include "principal.h"

/**
 * @brief //salvar pokemons da mochila e da coleção em um arquivo binario
 * 
 * @param pokemons6 //pokemons da mochila
 * @param pokemonsColecao //pokemons da colecao
 * @param quant_pokemons_colecao //quantidade de pokemons salvos na colecao
 */
void salvamentoNoHD(mochila* pokemons6, Colecao* pokemonsColecao, int* quant_pokemons_colecao)
{
    FILE * salvaHD = fopen("salvamento.dat", "wb");
    
    fwrite(pokemons6, sizeof(mochila), 6, salvaHD);//escreve os pokemons da mochila no arquivo
    fwrite(pokemonsColecao, sizeof(Colecao), (*quant_pokemons_colecao), salvaHD);//escreve os pokemons da colecao

    printf("Mochila e Colecao salvos. Até o proximo jogo!!");
    fclose(salvaHD);
}//salvamentoNoHD