#ifndef PILHA_CARRINHO_H
#define PILHA_CARRINHO_H
#include "Produto.h"


//nnó da pilha que representa um item no carrinho de compras
struct NoPilha {
    Produto dado;
    NoPilha* proximo;
};

//estrutura de controle da pilha (LIFO)
struct PilhaCarrinho {
    NoPilha* topo;
    int quantidade;
};



void inicializarPilha(PilhaCarrinho& pilha);

//empilha (push) um produto no topo do carrinho
void empilharProduto(PilhaCarrinho& pilha, Produto prod);

//desempilha (pop) o último produto colocado e retorna true se der sucesso
bool desempilharProduto(PilhaCarrinho& pilha, Produto& removido);

//calcula o valor total dos produtos no carrinho
double calcularTotalCarrinho(const PilhaCarrinho& pilha);

//exibe os itens do carrinho do topo para a base
void exibirCarrinho(const PilhaCarrinho& pilha);

//libera td a memória alocada dinamicamente pelo carrinho
void liberarPilha(PilhaCarrinho& pilha);

#endif