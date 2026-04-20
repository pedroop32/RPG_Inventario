#include "Slot.h"

Slot::Slot() {}

// retorna true quando vazio, false quando possui item
bool Slot::estaVazio() {
    return this->item == nullptr;
}

void Slot::setItem(ItemAbstrato* item) {
    if(estaVazio()) {
        this->item = item;
    } else std::cout << "Slot já possui item\n"<< std::endl;
}

ItemAbstrato* Slot::getItem() {
    if(!estaVazio()) {
        return this->item;
    }
    std::cout<<"Slot vazio\n" << std::endl;
    return nullptr;
}


bool Slot::setQuantidade(int quantidade) {
    if(item==nullptr) return false;
    if(item->getEmpilhavel()) {
        this->itemQuant = quantidade;
        return true;
    } else {
        this->itemQuant =1;
    }
    return false;  
}

int Slot::getQuantidade() {
    return this->itemQuant;
}

void Slot::limparSlot(){
    this->itemQuant = 0;
    this->item = nullptr;
}