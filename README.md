# Sistema de Simulação de Caixa de Supermercado (C++)

Sistema modular desenvolvido em C++ para gestão de catálogo de produtos, carrinho de compras, fila de atendimento em caixa e análise comparativa de algoritmos de ordenação e busca.

## ---- Arquitetura do Sistema ----

SISTEMA-FINAL_GIOVANI/
main.cpp               # Menu principal e integração das estruturas
Produto.h              # Struct Produto compartilhada entre os módulos
ListaProdutos.h/.cpp   # Catálogo geral (Lista Encadeada)
ArvoreProdutos.h/.cpp  # Índice por código (Árvore Binária de Busca)
PilhaCarrinho.h/.cpp   # Carrinho do cliente (Pilha LIFO)
FilaCaixa.h/.cpp       # Ordem de atendimento (Fila FIFO)
Algoritmos.h/.cpp      # Merge Sort por preço e comparativo de buscas