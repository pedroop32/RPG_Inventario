#include "ItemLivro.h"

ItemLivro::ItemLivro(int id, Tipo tipo, bool empilhavel) : ItemAbstrato(id, tipo, empilhavel){
    //construtor vazio, pois os parametros são gerenciados pelo pai(ItemAbstrato)
}

void ItemAbstrato::usar(){
    //Vazio, para alguma implementação futura
}