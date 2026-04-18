#ifndef ITEM_GLOCK_H
#define ITEM_GLOCK_H

#include "ItemAbstrato.h"

class ItemGlock : public ItemAbstrato {
public:
    ItemGlock(int id, Tipo tipo, bool empilhavel);
    void usar() override;
};

#endif