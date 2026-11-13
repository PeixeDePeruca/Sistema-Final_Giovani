#include "ListaProdutos.h"
#include <iostream>
#include <iomanip>




void inicializarLista(ListaProdutos& lista) {
    lista.inicio = nullptr;
    lista.tamanho = 0;
}

//aloca dinamicamente um nó e insere um produto no fim da lista
void inserirProdutoLista(ListaProdutos& lista, Produto prod) {
    NoLista* novo = new NoLista{prod, nullptr};
    if (lista.inicio == nullptr) {
        lista.inicio = novo;
    } else {
        NoLista* atual = lista.inicio;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    lista.tamanho++;
}

//remove o produto da lista buscando pelo código
bool removerProdutoLista(ListaProdutos& lista, int codigo) {
    NoLista* atual = lista.inicio;
    NoLista* anterior = nullptr;

    while (atual != nullptr && atual->dado.codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == nullptr) return false;

    if (anterior == nullptr) lista.inicio = atual->proximo;
    else anterior->proximo = atual->proximo;

    delete atual;
    atual = nullptr;
    lista.tamanho--;
    return true;
}


//passa por tds os itens da lista e imprime no terminal
void exibirListaProdutos(const ListaProdutos& lista) {
    if (lista.inicio == nullptr) {
        std::cout << "Catalogo vazio!\n";
        return;
    }
    NoLista* atual = lista.inicio;
    while (atual != nullptr) {
        std::cout << "Cod: " << atual->dado.codigo << " | " << atual->dado.nome
                  << " | R$ " << std::fixed << std::setprecision(2) << atual->dado.preco << "\n";
        atual = atual->proximo;
    }
}


//calcula recursivamente o total de produtos na lista
int contarRecursivo(NoLista* atual) {
    if (atual == nullptr) return 0;
    return 1 + contarRecursivo(atual->proximo);
}


//libera tds os nós alocados dinamicamente para evitar memory leak
void liberarLista(ListaProdutos& lista) {
    NoLista* atual = lista.inicio;
    while (atual != nullptr) {
        NoLista* temp = atual;
        atual = atual->proximo;
        delete temp;
        temp = nullptr;
    }
    lista.inicio = nullptr;
    lista.tamanho = 0;
}