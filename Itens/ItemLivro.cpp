#include "ItemLivro.h"

ItemLivro::ItemLivro(int id, Tipo tipo, bool empilhavel, std::string nome) : ItemAbstrato(id, tipo, empilhavel, nome){
    //construtor vazio, pois os parametros são gerenciados pelo pai(ItemAbstrato)
}

void ItemLivro::usar(){
    //Vazio, para alguma implementação futura
}