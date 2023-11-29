#include <stdio.h>
#include <stdlib.h>
#include "cadastroPokemon.h"

/**
 * @brief 
 * cria um vetor com todos os pokemons disponiveis
 * @param pokedexGeral struct com a informacao de cada pokemon
 */
void CriaVetorPokedex(Pokemon *pokedexGeral)
{
    //declaracao de variaveis
    FILE *ArquivoPokedex = fopen("pokedex.csv", "r"); //abre o arquivo da pokedex
    Lixo lixo;
    fseek(ArquivoPokedex, 0, SEEK_SET);//direciona para o inicio do arquivo

    for(int i = 0; i < 722; i++)
    {
        if (i == 0)//caso for a linha de nome das colunas
        {
            fscanf(ArquivoPokedex, "%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s \n", 
            lixo.a,
            lixo.b,
            lixo.c,
            lixo.d,
            lixo.e,
            lixo.f,
            lixo.g,
            lixo.h,
            lixo.i,
            lixo.j,
            lixo.k,
            lixo.l,
            lixo.m,
            lixo.n, 
            lixo.o,
            lixo.p,
            lixo.q);
        }//if
        else//caso for as linhas dos pokemons
        {
            fscanf(ArquivoPokedex, "%3i ,%s ,%s ,%s ,%3i ,%3i ,%3i ,%3i ,%3i ,%3i ,%3i ,%i ,%i ,%s ,%f ,%f ,%3i \n", 
            &pokedexGeral[i].numero,
            pokedexGeral[i].nome, 
            pokedexGeral[i].tipo1, 
            pokedexGeral[i].tipo2, 
            &pokedexGeral[i].total, 
            &pokedexGeral[i].hp, 
            &pokedexGeral[i].ataque, 
            &pokedexGeral[i].defesa, 
            &pokedexGeral[i].ataque_especial, 
            &pokedexGeral[i].defesa_especial, 
            &pokedexGeral[i].velocidade, 
            &pokedexGeral[i].geracao, 
            &pokedexGeral[i].lendario, 
            pokedexGeral[i].cor, 
            &pokedexGeral[i].altura, 
            &pokedexGeral[i].peso, 
            &pokedexGeral[i].taxa_de_captura);
        }//else
    }//while

    fclose(ArquivoPokedex); //fecha o arquivo
}//CriaVetorPokedex