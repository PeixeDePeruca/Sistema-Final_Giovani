#include "PilhaCarrinho.h"
#include <iostream>
#include <iomanip>




void inicializarPilha(PilhaCarrinho& pilha) {
    pilha.topo = nullptr;
    pilha.quantidade = 0;
}

//insere (push) um produto no topo da pilha do carrinho
void empilharProduto(PilhaCarrinho& pilha, Produto prod) {
    NoPilha* novo = new NoPilha{prod, pilha.topo};
    pilha.topo = novo;
    pilha.quantidade++;
}

//remove (pop) o produto do topo da pilha e devolve por referência
bool desempilharProduto(PilhaCarrinho& pilha, Produto& removido) {
    if (pilha.topo == nullptr) return false;

    NoPilha* temp = pilha.topo;
    removido = temp->dado;
    pilha.topo = temp->proximo;

    delete temp;
    temp = nullptr;
    pilha.quantidade--;
    return true;
}

//soma o preço de tds os produtos q estão atualmente na pilha
double calcularTotalCarrinho(const PilhaCarrinho& pilha) {
    double total = 0.0;
    NoPilha* atual = pilha.topo;
    while (atual != nullptr) {
        total += atual->dado.preco;
        atual = atual->proximo;
    }
    return total;
}

//lista tds os itens do carrinho sem removê-los da pilha
void exibirCarrinho(const PilhaCarrinho& pilha) {
    if (pilha.topo == nullptr) {
        std::cout << "Carrinho vazio.\n";
        return;
    }
    NoPilha* atual = pilha.topo;
    while (atual != nullptr) {
        std::cout << "- " << atual->dado.nome << " (R$ "
                  << std::fixed << std::setprecision(2) << atual->dado.preco << ")\n";
        atual = atual->proximo;
    }
}

//libera tds os nós alocados na pilha para evitar vazamento
void liberarPilha(PilhaCarrinho& pilha) {
    Produto descartado;
    while (desempilharProduto(pilha, descartado)) {}
}