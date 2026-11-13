#ifndef ARVORE_PRODUTOS_H
#define ARVORE_PRODUTOS_H
#include "Produto.h"


//nó da árvore binária de busca
struct NoArvore {
    Produto dado;
    NoArvore* esquerda;
    NoArvore* direita;
};

//inicializa a raiz da árvore como null
void inicializarArvore(NoArvore*& raiz);

//insere um produto na árvore ordenado pelo código
void inserirProdutoArvore(NoArvore*& raiz, Produto prod);

//busca um produto pelo código e então retorna o ponteiro do nó (ou nullptr se não achar)
NoArvore* buscarProdutoArvore(NoArvore* raiz, int codigo);

//percorre a árvore em ordem (in-order) imprimindo os produtos ordenados pelo código
void exibirEmOrdem(NoArvore* raiz);

void liberarArvore(NoArvore*& raiz);

#endif