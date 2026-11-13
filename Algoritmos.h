#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include "Produto.h"

//exibe uma copia do catalogo ordenada por preco usando MERGE SORT
void exibirOrdenadoPorPreco(const Produto* catalogo, int tamanho);

//compara BUSCA SEQUENCIAL e a BUSCA BINÁRIA pelo codigo do produto
void compararBuscas(const Produto* catalogo, int tamanho, int codigoBuscado);

#endif