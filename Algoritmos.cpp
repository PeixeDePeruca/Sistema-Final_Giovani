#include "Algoritmos.h"
#include <iostream>
#include <iomanip>

//função: intercalarPorPreco
//descrição: Mescla dois subvetores ordenados por preco em ordem crescente.
//parametros: vetor (array de produtos), inicio, meio e fim (indices).
//return: void
void intercalarPorPreco(Produto* vetor, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    Produto* esq = new Produto[n1];
    Produto* dir = new Produto[n2];

    for (int i = 0; i < n1; i++) esq[i] = vetor[inicio + i];
    for (int j = 0; j < n2; j++) dir[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (esq[i].preco <= dir[j].preco) vetor[k++] = esq[i++];
        else vetor[k++] = dir[j++];
    }
    while (i < n1) vetor[k++] = esq[i++];
    while (j < n2) vetor[k++] = dir[j++];

    delete[] esq;
    delete[] dir;
    esq = nullptr;
    dir = nullptr;
}

//função: mergeSortPorPreco
//descrição: Ordena recursivamente o vetor de produtos pelo preco (Merge Sort).
//complexidade: Tempo O(n log n) em todos os casos; Espaco auxiliar O(n).
//parametros: vetor (array de produtos), inicio e fim (indices).
//return: void
void mergeSortPorPreco(Produto* vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSortPorPreco(vetor, inicio, meio);
        mergeSortPorPreco(vetor, meio + 1, fim);
        intercalarPorPreco(vetor, inicio, meio, fim);
    }
}

//função: exibirOrdenadoPorPreco
//descrição: Cria copia do catalogo, ordena por preco via Merge Sort e imprime.
//parametros: catalogo (vetor original), tamanho (quantidade de itens).
//return: void
void exibirOrdenadoPorPreco(const Produto* catalogo, int tamanho) {
    if (tamanho <= 0) {
        std::cout << "Catalogo vazio.\n";
        return;
    }
    Produto* copia = new Produto[tamanho];
    for (int i = 0; i < tamanho; i++) copia[i] = catalogo[i];

    mergeSortPorPreco(copia, 0, tamanho - 1);

    std::cout << "\n--- CATALOGO ORDENADO POR PRECO (MERGE SORT - O(n log n)) ---\n";
    for (int i = 0; i < tamanho; i++) {
        std::cout << "[" << copia[i].codigo << "] " << copia[i].nome
                  << " - R$ " << std::fixed << std::setprecision(2) << copia[i].preco << "\n";
    }
    delete[] copia;
    copia = nullptr;
}

//função: buscaSequencial
//descrição: Percorre o vetor linearmente contando comparacoes ate achar o codigo.
//complexidade: O(n) no pior caso.
//parametros: vetor, tamanho, codigoBuscado, comparacoes (referencia).
//return: Indice do produto encontrado ou -1.
int buscaSequencial(const Produto* vetor, int tamanho, int codigoBuscado, int& comparacoes) {
    comparacoes = 0;
    for (int i = 0; i < tamanho; i++) {
        comparacoes++;
        if (vetor[i].codigo == codigoBuscado) return i;
    }
    return -1;
}

//função: ordenarPorCodigo
//descrição: Ordena vetor auxiliar por codigo para permitir a busca binaria.
//parametros: vetor (array de produtos), tamanho (quantidade de itens).
//return: void
void ordenarPorCodigo(Produto* vetor, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        Produto chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j].codigo > chave.codigo) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

//funcão: buscaBinaria
//descricao: Busca um codigo em vetor ordenado dividindo o espaco ao meio.
//complexidade: O(log n) no pior caso.
//parametros: vetor ordenado, tamanho, codigoBuscado, comparacoes (referencia).
//return Indice do produto encontrado ou -1.
int buscaBinaria(const Produto* vetor, int tamanho, int codigoBuscado, int& comparacoes) {
    comparacoes = 0;
    int esq = 0, dir = tamanho - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        comparacoes++;
        if (vetor[meio].codigo == codigoBuscado) return meio;
        if (vetor[meio].codigo < codigoBuscado) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}


//função: compararBuscas
//descricao: Executa busca sequencial e binaria e exibe o comparativo de operacoes.
//parametros: catalogo (vetor original), tamanho, codigoBuscado.
//return: void
void compararBuscas(const Produto* catalogo, int tamanho, int codigoBuscado) {
    int compSeq = 0, compBin = 0;
    int idxSeq = buscaSequencial(catalogo, tamanho, codigoBuscado, compSeq);

    Produto* ordenado = new Produto[tamanho];
    for (int i = 0; i < tamanho; i++) ordenado[i] = catalogo[i];
    ordenarPorCodigo(ordenado, tamanho);
    int idxBin = buscaBinaria(ordenado, tamanho, codigoBuscado, compBin);

    std::cout << "\n--- COMPARATIVO DE BUSCA (CODIGO " << codigoBuscado << ") ---\n";
    if (idxBin != -1) std::cout << "Produto: " << ordenado[idxBin].nome << "\n";
    else std::cout << "Produto nao encontrado.\n";
    std::cout << "Busca Sequencial (O(n))    : " << compSeq << " comparacoes\n";
    std::cout << "Busca Binaria    (O(log n)): " << compBin << " comparacoes\n";

    delete[] ordenado;
    ordenado = nullptr;

}