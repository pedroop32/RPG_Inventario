#include "ItemPocao.h"

ItemPocao::ItemPocao(int id, Tipo tipo, bool empilhavel, std::string nome) : ItemAbstrato(id, tipo, empilhavel, nome) {
    //construtor vazio, pois os parametros são gerenciados pelo pai(ItemAbstrato)
}

void ItemPocao::usar(){
    //Vazio, para alguma implementação futura
}