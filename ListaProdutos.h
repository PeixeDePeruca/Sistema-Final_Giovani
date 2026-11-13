#ifndef LISTA_PRODUTOS_H
#define LISTA_PRODUTOS_H
#include "Produto.h"



//nó da lista simplesmente encadeada de produtos (só aponta para frente)
struct NoLista {
    Produto dado;
    NoLista* proximo;
};

//estrutura de controle da lista encadeada
struct ListaProdutos {
    NoLista* inicio;
    int tamanho;
};

//inicia uma lista vazia
void inicializarLista(ListaProdutos& lista);

//insere um novo produto no final da lista encadeada
void inserirProdutoLista(ListaProdutos& lista, Produto prod);


//remove um produto da lista pelo código; retorna true se removido
bool removerProdutoLista(ListaProdutos& lista, int codigo);

//exibe tds os produtos cadastrados na lista
void exibirListaProdutos(const ListaProdutos& lista);

//conta recursivamente a quantidade de nós a partir de um ponteiro
int contarRecursivo(NoLista* atual);

//libera td a memória alocada dinamicamente pela lista, para n ter memory leak
void liberarLista(ListaProdutos& lista);

#endif