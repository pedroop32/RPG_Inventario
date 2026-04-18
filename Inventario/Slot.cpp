#include "Slot.h"

Slot::Slot() {}

// retorna true quando vazio, false quando possui item
bool Slot::estaVazio() {
    return this->item == nullptr;
}

void Slot::setItem(ItemAbstrato* item) {
    if(estaVazio()) {
        this->item = item;
        //se não for empilhavel a quantidade será 1 por padrão
        if (this->item->getEmpilhavel()==0){
            this->setQuantidade(1);
        }
    } else printf("Slot já possui item\n");
}

ItemAbstrato* Slot::getItem() {
    if(!estaVazio()) {
        return this->item;
    }
    printf("Slot vazio\n");
    return nullptr;
}

//Se é empilhavel adiciona
bool Slot::setQuantidade(int quantidade) {
    if(this->item->getEmpilhavel()) {
        if(getQuantidade() + quantidade <= capacidade) {
            this->itemQuant += quantidade;
            return true;
        } else return false;
    }
    return false; // não empilhável/ responsabilidade do Inventário
}

int Slot::getQuantidade() {
    return this->itemQuant;
}