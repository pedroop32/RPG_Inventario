#ifndef ITEM_PIPBOY_H
#define ITEM_PIPBOY_H

#include "ItemAbstrato.h"

class ItemPipBoy : public ItemAbstrato {
public:
    ItemPipBoy(int id, Tipo tipo, bool empilhavel);
    void usar() override;
};

#endif