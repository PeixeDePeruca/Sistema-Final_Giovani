#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>



//estrutura q representa um produto no catálogo do supermercado
struct Produto {
    int codigo;
    std::string nome;
    double preco;
};


#endif