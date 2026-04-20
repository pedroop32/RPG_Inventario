#ifndef SLOT_H
#define SLOT_H

#include "../Itens/ItemAbstrato.h"
#include <iostream>

const int CAPACIDADE_SLOT = 64; //Constante para validação

class Slot {
private:
    ItemAbstrato* item = nullptr;
    int itemQuant = 0;
public:
    Slot();

    void setItem(ItemAbstrato* item);
    ItemAbstrato* getItem();
    
    bool setQuantidade(int quantidade); //true se foi possivel adicionar, false se não
    int getQuantidade();

    void limparSlot();
    bool estaVazio(); // retorna true quando vazio, false quando possui item
};

#endif