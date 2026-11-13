#include "ArvoreProdutos.h"
#include <iostream>
#include <iomanip>

//inicializa a raiz da árvore vazia
void inicializarArvore(NoArvore*& raiz) {
    raiz = nullptr;
}


//insere um produto na árvore ordenado pelo código
void inserirProdutoArvore(NoArvore*& raiz, Produto prod) {
    //se chegou em um espaço vazio, cria o novo nó AQUI
    if (raiz == nullptr) {
        NoArvore* novo = new NoArvore;
        novo->dado = prod;
        novo->esquerda = nullptr;
        novo->direita = nullptr;
        raiz = novo;
        return;
    }

    //se o código for menor vai para a esquerda...se for maior vai para a direita
    if (prod.codigo < raiz->dado.codigo) {
        inserirProdutoArvore(raiz->esquerda, prod);
    } else if (prod.codigo > raiz->dado.codigo) {
        inserirProdutoArvore(raiz->direita, prod);
    }
}

//busca um produto pelo código usando um laço simples
NoArvore* buscarProdutoArvore(NoArvore* raiz, int codigo) {
    NoArvore* atual = raiz;

    while (atual != nullptr) {
        if (codigo == atual->dado.codigo) {
            return atual;
        }
        if (codigo < atual->dado.codigo) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }

    return nullptr;
}
//mostra os produtos do menor código para o maior código
void exibirEmOrdem(NoArvore* raiz) {
    if (raiz == nullptr) return;

    exibirEmOrdem(raiz->esquerda);
    std::cout << "Cod: " << raiz->dado.codigo << " | " << raiz->dado.nome
              << " | R$ " << std::fixed << std::setprecision(2) << raiz->dado.preco << "\n";
    exibirEmOrdem(raiz->direita);
}



void liberarArvore(NoArvore*& raiz) {
    if (raiz == nullptr) return;

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    delete raiz;
    raiz = nullptr;
}