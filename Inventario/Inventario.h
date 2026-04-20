#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include "Slot.h"

const int INV_TAMANHO = 32;

class Inventario{
    private:
       Slot* slotVazio(); //busca slots vazios
       Slot* buscarSlotParcial(int itemId); //busca por id o slot que ainda não foi preenchido
       Slot inventario[INV_TAMANHO];//array de slots
    public:
        Inventario();
        void adicionarItem(ItemAbstrato* item, int quantidade);
        void removerItem(int index, int quantidade);
        
        Slot *getInventario();
};

#endif