#ifndef FILA_CAIXA_H
#define FILA_CAIXA_H

#include <string>

//estrutura q representa um cliente aguardando no caixa
struct Cliente {
    int senha;
    std::string nome;
    double valorCompra;
};

//nó da fila encadeada
struct NoFila {
    Cliente dado;
    NoFila* proximo;
};

//estrutura de controle da fila FIFO
struct FilaCaixa {
    NoFila* inicio;
    NoFila* fim;
    int tamanho;
};

//inicializa uma fila de caixa vazio
void inicializarFila(FilaCaixa& fila);

//enfileira (enqueue) um cliente no final da fila
void enfileirarCliente(FilaCaixa& fila, Cliente cliente);

//desenfileira (dequeue) o primeiro cliente da fila; retorna true se der sucesso
bool desenfileirarCliente(FilaCaixa& fila, Cliente& atendido);

//exibe todos os clientes aguardando na fila
void exibirFilaCaixa(const FilaCaixa& fila);
void liberarFila(FilaCaixa& fila);




#endif