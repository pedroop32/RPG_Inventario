#ifndef ITEM_LIVRO_H
#define ITEM_LIVRO_H

#include "ItemAbstrato.h"

class ItemLivro : public ItemAbstrato {
public:
    ItemLivro(int id, Tipo tipo, bool empilhavel, std::string nome);
    void usar() override;
};

#endif