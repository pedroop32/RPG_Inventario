#ifndef ITEM_GLOCK_H
#define ITEM_GLOCK_H

#include "ItemAbstrato.h"

class ItemGlock : public ItemAbstrato {
public:
    ItemGlock(int id, Tipo tipo, bool empilhavel, std::string nome);
    void usar() override;
};

#endif