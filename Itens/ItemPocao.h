#ifndef ITEM_POCAO_H
#define ITEM_POCAO_H

#include "ItemAbstrato.h"

class ItemPocao : public ItemAbstrato {
public:
    ItemPocao(int id, Tipo tipo, bool empilhavel, std::string nome);
    void usar() override;
};

#endif