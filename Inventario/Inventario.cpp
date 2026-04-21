#include "Inventario.h"

Inventario::Inventario(){}

// Retorna um slot com um item empilhavel que ainda não foi preenchido
Slot* Inventario::buscarSlotParcial(int itemId) {
    for(int i = 0; i < INV_TAMANHO; i++) {
        //Se o slot não está vazio, se possui o mesmo item e se ainda possui espaço retorna seu endereço
        if(!inventario[i].estaVazio() && 
            inventario[i].getItem()->getId() == itemId &&
            inventario[i].getQuantidade() < CAPACIDADE_SLOT) {
            return &inventario[i];
        }
    }
    return nullptr;
}

// Retorna o primeiro slot vazio que encontrar
Slot* Inventario::slotVazio(){
   for(int i = 0; i < INV_TAMANHO; i++) {
        if(inventario[i].estaVazio()) {
            return &inventario[i];
        }
    }
    return nullptr;
}

// Adiciona itens ao inventário respeitando empilhamento e limite de slot
void Inventario::adicionarItem(ItemAbstrato* item, int quantidade){
    if(item == nullptr) {
        std::cout<<"\nPonteiro de item não é válido\n"<< std::endl;
        return;
    }
    if(quantidade <= 0){
        std::cout<<"\nQuantiade de itens deve ser maior que zero\n"<< std::endl;
        return;
    }

    Slot* slot = nullptr;

    if(item->getEmpilhavel()){
        slot = buscarSlotParcial(item->getId());
    } else {
        //se não for empilhavel 
        slot = slotVazio();
        if(slot == nullptr) {
            std::cout<<"\nInventário não possui espaço\n"<< std::endl;
            return;
        }

        slot->setItem(item);
        slot->setQuantidade(1);

        adicionarItem(item, quantidade - 1);
        return; 
    }
    //se não for encontrado slot parcialmente preenchido vai para o proximo vazio
    if(slot == nullptr) {
        slot = slotVazio();
        if(slot == nullptr) {
            std::cout<<"\nInventário não possui espaço\n"<< std::endl;
            return;
        }

        slot->setItem(item);
    }

    int quantidadeTotal = quantidade + slot->getQuantidade();

    if(quantidadeTotal <= CAPACIDADE_SLOT){
        slot->setQuantidade(quantidadeTotal);
    } else {
        slot->setQuantidade(CAPACIDADE_SLOT);
        adicionarItem(item, quantidadeTotal - CAPACIDADE_SLOT);
    }
}

// Remove quantidade de um slot específico
void Inventario::removerItem(int index, int quantidade){
    if(index >= INV_TAMANHO || index < 0) {
        std::cout<<"\nIndex invalido\n"<< std::endl;
        return;
    }

    if(inventario[index].estaVazio()) return;

    if(quantidade < 0) quantidade *= -1; //modulo da quantidade

    int resultado = inventario[index].getQuantidade() - quantidade;

    if (resultado <= 0){
        inventario[index].limparSlot();
    } else{
        inventario[index].setQuantidade(resultado);
    }
}

Slot* Inventario::getInventario(){
    return this->inventario;
}