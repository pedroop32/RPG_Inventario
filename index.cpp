#include "Personagem/Personagem.h"
#include "Itens/ItemGlock.h"
#include "Itens/ItemLivro.h"
#include "Itens/ItemPipBoy.h"
#include "Itens/ItemPocao.h"
#include <iostream>

void atualizarInventario(Personagem* pers) {
    int slotsCheios = 0;
    std::cout << "\n=== Inventario de " << pers->getNome() << " ===\n";
    for (int i = 0; i < INV_TAMANHO; i++) {
        if (pers->getInventario().getInventario()[i].estaVazio()) {
        } else {
            slotsCheios++;
            std::cout << "[" << i << "] "
                      << pers->getInventario().getInventario()[i].getItem()->getNome()
                      << " ^" << pers->getInventario().getInventario()[i].getQuantidade() << " | ";
        }
        if((i+1)%7 == 0) std::cout << "\n";
    }
    std::cout << "\n Slots livres: " << INV_TAMANHO - slotsCheios << "\n ====================\n\n";
}

void exibirMenu() {
    std::cout << "1. Adicionar item\n";
    std::cout << "2. Remover item por index\n";
    std::cout << "0. Sair\n";
    std::cout << "> ";
}

void exibirItens(ItemAbstrato* itens[], int total) {
    std::cout << "\nItens disponiveis:\n";
    for (int i = 0; i < total; i++) {
        std::cout << "[" << itens[i]->getId() << "] " << itens[i]->getNome();
        if (itens[i]->getEmpilhavel()) {
            std::cout << " (empilhavel)";
        } else {
            std::cout << " (nao empilhavel)";
        }
        std::cout << "\n";
    }
    std::cout << "> ";
}

int main() {
    Personagem carinha;
    carinha.setNome("Mano brown");

    ItemAbstrato* pocao  = new ItemPocao(0, CONSUMIVEL, true,  "Pocao vida");
    ItemAbstrato* glock  = new ItemGlock(1, ARMA,       false, "Glock 0.1");
    ItemAbstrato* livro  = new ItemLivro(2, ACESSORIO,  true,  "Livro arcano");
    ItemAbstrato* pipboy = new ItemPipBoy(3, ACESSORIO, false, "Pip-Boy");

    ItemAbstrato* itens[] = {pocao, glock, livro, pipboy};
    int totalItens = 4;

    int opcao = -1;
    while (opcao != 0) {
        atualizarInventario(&carinha);
        exibirMenu();
        std::cin >> opcao;

        if (opcao == 1) {
            exibirItens(itens, totalItens);
            int id, qtd;
            std::cin >> id;
            if (id < 0 || id >= totalItens) {
                std::cout << "Id invalido.\n";
                continue;
            }
            std::cout << "Quantidade: ";
            std::cin >> qtd;
            carinha.getInventario().adicionarItem(itens[id], qtd);

        } else if (opcao == 2) {
            int index, qtd;
            std::cout << "Index do slot: ";
            std::cin >> index;
            std::cout << "Quantidade: ";
            std::cin >> qtd;
            carinha.getInventario().removerItem(index, qtd);

        } else if (opcao != 0) {
            std::cout << "Opcao invalida.\n";
        }
    }

    delete pocao;
    delete glock;
    delete livro;
    delete pipboy;

    return 0;
}