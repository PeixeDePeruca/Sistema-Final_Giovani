#include "FilaCaixa.h"
#include <iostream>
#include <iomanip>

//inicializa os ponteiros e o tamanho da fila
void inicializarFila(FilaCaixa& fila) {
    fila.inicio = nullptr;
    fila.fim = nullptr;
    fila.tamanho = 0;
}

//insere um novo cliente no final da fila (FIFO)
void enfileirarCliente(FilaCaixa& fila, Cliente cliente) {
    NoFila* novo = new NoFila{cliente, nullptr};
    if (fila.fim == nullptr) {
        fila.inicio = novo;
        fila.fim = novo;
    } else {
        fila.fim->proximo = novo;
        fila.fim = novo;
    }
    fila.tamanho++;
}



//remove o primeiro cliente da fila para atendimento
bool desenfileirarCliente(FilaCaixa& fila, Cliente& atendido) {
    if (fila.inicio == nullptr) return false;

    NoFila* temp = fila.inicio;
    atendido = temp->dado;
    fila.inicio = temp->proximo;

    if (fila.inicio == nullptr) {
        fila.fim = nullptr;
    }

    delete temp;
    temp = nullptr;
    fila.tamanho--;
    return true;
}

//mostra tds os clientes na ORDEM DE CHEGADA
void exibirFilaCaixa(const FilaCaixa& fila) {
    if (fila.inicio == nullptr) {
        std::cout << "Nenhum cliente na fila do caixa.\n";
        return;
    }
    NoFila* atual = fila.inicio;
    while (atual != nullptr) {
        std::cout << "Senha #" << atual->dado.senha << " | " << atual->dado.nome
                  << " | Total: R$ " << std::fixed << std::setprecision(2)
                  << atual->dado.valorCompra << "\n";
        atual = atual->proximo;
    }
}

//libera tds os nós alocados na fila para evitar memory leak
void liberarFila(FilaCaixa& fila) {
    Cliente descartado;
    while (desenfileirarCliente(fila, descartado)) {}
}