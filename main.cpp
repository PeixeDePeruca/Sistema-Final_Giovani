//APERTE F6 (ou clique no botão "Play" (compile and run) para rodar o código, se preferir execute no terminal o código:
// g++ main.cpp ListaProdutos.cpp PilhaCarrinho.cpp FilaCaixa.cpp ArvoreProdutos.cpp -o supermercado
//e dps o código
// ./supermercado

//escolha qual dos 2 métodos vc prefere e execute o código! :P



//////////////////////////////////////////////////////////////////////////

//bibliotecas padrao
#include <iostream>
#include <iomanip>
#include <string>

//cabecalhos das estruturas de dados
#include "Produto.h"
#include "ListaProdutos.h"
#include "PilhaCarrinho.h"
#include "FilaCaixa.h"
#include "ArvoreProdutos.h"

//função auxiliar para cadastrar produto na lista e na arvore ao mesmo tempo
void cadastrarProdutoGeral(ListaProdutos& lista, NoArvore*& raiz, int codigo, std::string nome, double preco) {
    Produto novo = {codigo, nome, preco};
    inserirProdutoLista(lista, novo);
    inserirProdutoArvore(raiz, novo);
}

int main() {
    //inicializa as quatro estruturas de dados
    ListaProdutos catalogo;
    inicializarLista(catalogo);

    NoArvore* indiceArvore;
    inicializarArvore(indiceArvore);

    PilhaCarrinho carrinho;
    inicializarPilha(carrinho);

    FilaCaixa filaCaixa;
    inicializarFila(filaCaixa);

    //pre-cadastra alguns produtos iniciais no sistema
    cadastrarProdutoGeral(catalogo, indiceArvore, 102, "ARROZ 5KG", 24.90);
    cadastrarProdutoGeral(catalogo, indiceArvore, 101, "FEIJAO 1KG", 8.50);
    cadastrarProdutoGeral(catalogo, indiceArvore, 105, "CAFE 500G", 16.75);
    cadastrarProdutoGeral(catalogo, indiceArvore, 103, "LEITE INTEGRAL 1L", 4.80);
    cadastrarProdutoGeral(catalogo, indiceArvore, 109, "CAIXA DE CHOCOLATE LACTA", 12.90);
    cadastrarProdutoGeral(catalogo, indiceArvore, 112, "CESTA BASICA", 120.00);
    cadastrarProdutoGeral(catalogo, indiceArvore, 104, "IOGURTE GREGO POTE 500ML", 8.80);
    cadastrarProdutoGeral(catalogo, indiceArvore, 115, "RACAO PARA GATO ELITE", 12.85);
    cadastrarProdutoGeral(catalogo, indiceArvore, 113, "PRESERVATIVO MASCULINO ORIGINAL", 8.50);
    cadastrarProdutoGeral(catalogo, indiceArvore, 114, "PRESERVATIVO MASCULINO MORANGO", 7.99);
    cadastrarProdutoGeral(catalogo, indiceArvore, 106, "CARRINHO HOT WHEELS", 6.99);
    cadastrarProdutoGeral(catalogo, indiceArvore, 110, "LEITE DE COCO 500ML", 16.83);
    cadastrarProdutoGeral(catalogo, indiceArvore, 107, "LARANJA PERA", 18.30);
    cadastrarProdutoGeral(catalogo, indiceArvore, 108, "LARANJA BAHIA", 20.45);
    cadastrarProdutoGeral(catalogo, indiceArvore, 111, "MACA", 12.90);
    cadastrarProdutoGeral(catalogo, indiceArvore, 116, "BANANA", 8.70);
    cadastrarProdutoGeral(catalogo, indiceArvore, 118, "KINDER OVO JOY", 10.00);
    cadastrarProdutoGeral(catalogo, indiceArvore, 124, "FINI BANANA 80G", 5.69);
    cadastrarProdutoGeral(catalogo, indiceArvore, 125, "FINI BANANA 500G", 12.90);
    cadastrarProdutoGeral(catalogo, indiceArvore, 126, "FINI ROSCA DE MORANGO 80G", 5.69);
    cadastrarProdutoGeral(catalogo, indiceArvore, 127, "FINI REGALIZ UVA 80G", 5.69);
    cadastrarProdutoGeral(catalogo, indiceArvore, 128, "FINI DENTADURA 15G", 1.00);
    cadastrarProdutoGeral(catalogo, indiceArvore, 129, "FINI REGALIZ TUTTI FRUTTI 80G", 5.69);
    cadastrarProdutoGeral(catalogo, indiceArvore, 119, "ABACAXI", 15.90);
    cadastrarProdutoGeral(catalogo, indiceArvore, 120, "UVA ROXA", 13.45);
    cadastrarProdutoGeral(catalogo, indiceArvore, 121, "UVA VERDE", 13.45);
    cadastrarProdutoGeral(catalogo, indiceArvore, 122, "ACUCAR 1KG", 9.00);
    cadastrarProdutoGeral(catalogo, indiceArvore, 123, "SAL 1KG", 8.00);
    cadastrarProdutoGeral(catalogo, indiceArvore, 130, "PAO FRANCES", 2.30);
    cadastrarProdutoGeral(catalogo, indiceArvore, 131, "PAO FATIADO", 9.45);
    cadastrarProdutoGeral(catalogo, indiceArvore, 132, "RACAO PARA CACHORRO PEBA", 15.85);
    cadastrarProdutoGeral(catalogo, indiceArvore, 134, "PRESUNTO 200G", 8.65);
    cadastrarProdutoGeral(catalogo, indiceArvore, 135, "QUEIJO 500G", 14.50);
    cadastrarProdutoGeral(catalogo, indiceArvore, 133, "BUBBALOO 5G", 0.85);
    cadastrarProdutoGeral(catalogo, indiceArvore, 117, "CAMISETA CAMPO REAL", 666.69);
    cadastrarProdutoGeral(catalogo, indiceArvore, 140, "PATE PEITO DE PERU", 4.50);
    cadastrarProdutoGeral(catalogo, indiceArvore, 137, "TOALHA DE BANHO", 8.99);
    cadastrarProdutoGeral(catalogo, indiceArvore, 138, "PANO DE PRATO", 1.85);
    cadastrarProdutoGeral(catalogo, indiceArvore, 136, "BATATA 1KG", 10.85);
    cadastrarProdutoGeral(catalogo, indiceArvore, 139, "LEITE EM PO", 6.90);




    //variaveis auxiliares para o menu
    int opcao = -1;
    int proximaSenha = 1;

    while (opcao != 0) {
        std::cout << "\n========================================\n";
        std::cout << "       SISTEMA DE SUPERMERCADO\n";
        std::cout << "========================================\n";
        std::cout << "1. Cadastrar novo produto\n";
        std::cout << "2. Listar catalogo (Lista Encadeada - Misturado)\n";
        std::cout << "3. Listar produtos por codigo (Arvore BST - Organizado por ID)\n";
        std::cout << "4. Buscar produto por codigo (Arvore BST)\n";
        std::cout << "5. Adicionar produto ao carrinho (Pilha)\n";
        std::cout << "6. Remover ultimo item do carrinho (Pilha)\n";
        std::cout << "7. Ver carrinho atual e total (Pilha)\n";
        std::cout << "8. Finalizar compra e entrar na fila (Fila)\n";
        std::cout << "9. Ver fila do caixa (Fila)\n";
        std::cout << "10. Atender proximo cliente no caixa (Fila)\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

if (opcao == 1) {
            int codigo;
            std::string nome;
            double preco;

            std::cout << "Codigo do produto: ";
            std::cin >> codigo;

            //bloqueia letras ou codigos menores ou iguais a zero
            if (std::cin.fail() || codigo <= 0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Erro: digite um codigo numerico maior que zero.\n";
            } else if (buscarProdutoArvore(indiceArvore, codigo) != nullptr) {
                std::cin.ignore();
                std::cout << "Erro: ja existe um produto cadastrado com esse codigo.\n";
            } else {
                std::cin.ignore();
                std::cout << "Nome do produto: ";
                std::getline(std::cin, nome);

                //valida se o nome tem pelo menos 3 caracteres
                if (nome.length() < 3) {
                    std::cout << "Erro: digite um nome valido para o produto.\n";
                } else {
                    std::cout << "Preco (R$): ";
                    std::cin >> preco;

                    //trava o preco entre 0.85 e 666.69 para q o usuário n possa zaralhar e colocar um preço exageradamente alto ou rídiculo de baixo (ou negativo)
                    if (std::cin.fail() || preco < 0.85 || preco > 666.69) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Erro: o preco deve ser entre R$ 0.85 e R$ 666.69.\n";
                    } else {
                        //insere na lista e na arvore
                        cadastrarProdutoGeral(catalogo, indiceArvore, codigo, nome, preco);
                        std::cout << "Produto cadastrado com sucesso!\n";
                    }
                }
            }
        } else if (opcao == 2) {
            //exibe a lista e usa a contagem recursiva
            std::cout << "\n--- CATALOGO DE PRODUTOS (LISTA) ---\n";
            exibirListaProdutos(catalogo);
            std::cout << "Total de produtos cadastrados: " << contarRecursivo(catalogo.inicio) << "\n";
        } else if (opcao == 3) {
            //exibee a arvore em ordem crescente de codigo
            std::cout << "\n--- PRODUTOS ORDENADOS POR CODIGO (ARVORE) ---\n";
            if (indiceArvore == nullptr) {
                std::cout << "Nenhum produto cadastrado na arvore.\n";
            } else {
                exibirEmOrdem(indiceArvore);
            }
        } else if (opcao == 4) {
            //busca rapida na arvore binaria
            int codigo;
            std::cout << "Digite o codigo do produto para buscar: ";
            std::cin >> codigo;

            NoArvore* encontrado = buscarProdutoArvore(indiceArvore, codigo);
            if (encontrado != nullptr) {
                std::cout << "Encontrado -> Cod: " << encontrado->dado.codigo
                          << " | " << encontrado->dado.nome
                          << " | R$ " << std::fixed << std::setprecision(2)
                          << encontrado->dado.preco << "\n";
            } else {
                std::cout << "Produto nao encontrado.\n";
            }
        } else if (opcao == 5) {
            //busca o produto na arvore e empilha no carrinho em loop
            int codigo;
            std::cout << "\n--- ADICIONANDO PRODUTOS AO CARRINHO ---\n";

            while (true) {
                std::cout << "Digite o codigo do produto (ou 0 para finalizar o carrinho): ";
                std::cin >> codigo;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Entrada invalida. Digite um codigo numerico correto ou 0 para finalizar.\n";
                } else if (codigo == 0) {
                    std::cout << "Adicao de itens finalizada!\n";
                    break;
                } else {
                    NoArvore* encontrado = buscarProdutoArvore(indiceArvore, codigo);
                    if (encontrado != nullptr) {
                        empilharProduto(carrinho, encontrado->dado);
                        std::cout << encontrado->dado.nome << " adicionado ao carrinho!\n\n";
                    } else {
                        std::cout << "Codigo invalido. Produto nao encontrado.\n\n";
                    }
                }
            }


        } else if (opcao == 6) {
            //desempilha o ultimo produto colocado no carrinho
            Produto removido;
            if (desempilharProduto(carrinho, removido)) {
                std::cout << "Item removido do topo do carrinho: " << removido.nome << "\n";
            } else {
                std::cout << "O carrinho ja esta vazio.\n";
            }
        } else if (opcao == 7) {
            //mostra os itens da pilha e o valor total
            std::cout << "\n--- SEU CARRINHO (PILHA - TOPO PARA BASE) ---\n";
            exibirCarrinho(carrinho);
            std::cout << "Valor total: R$ " << std::fixed << std::setprecision(2)
                      << calcularTotalCarrinho(carrinho) << "\n";
        } else if (opcao == 8) {
            //calcula o total...esvazia o carrinho e enfileira o cliente no caixa
            if (carrinho.topo == nullptr) {
                std::cout << "Adicione itens ao carrinho antes de ir para o caixa.\n";
            } else {
                std::string nomeCliente;
                std::cin.ignore();
                std::cout << "Nome do cliente: ";
                std::getline(std::cin, nomeCliente);

                double total = calcularTotalCarrinho(carrinho);
                Cliente novoCliente = {proximaSenha, nomeCliente, total};
                proximaSenha++;

                enfileirarCliente(filaCaixa, novoCliente);
                liberarPilha(carrinho);

                std::cout << "Cliente " << novoCliente.nome << " entrou na fila (Senha #"
                          << novoCliente.senha << ") com total de R$ "
                          << std::fixed << std::setprecision(2) << total << ".\n";
            }
        } else if (opcao == 9) {
            //mostra tds os clientes aguardando na fila
            std::cout << "\n--- FILA DO CAIXA (ORDEM DE CHEGADA) ---\n";
            exibirFilaCaixa(filaCaixa);
        } else if (opcao == 10) {
            //atende o primeiro cliente da fila (lógica fifo)
            Cliente atendido;
            if (desenfileirarCliente(filaCaixa, atendido)) {
                std::cout << "Atendendo Senha #" << atendido.senha << " - " << atendido.nome
                          << " | Pagamento: R$ " << std::fixed << std::setprecision(2)
                          << atendido.valorCompra << "\n";
            } else {
                std::cout << "Nao ha clientes na fila do caixa.\n";
            }
        } else if (opcao == 0) {
            std::cout << "Encerrando o sistema e liberando memoria...\n";
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }



    //libera memoria alocada antes de encerrar o programa
    liberarLista(catalogo);
    liberarArvore(indiceArvore);
    liberarPilha(carrinho);
    liberarFila(filaCaixa);

    return 0;
}