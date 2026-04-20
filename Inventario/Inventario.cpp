#include "Inventario.h"

Inventario::Inventario(){};

//retorna o endereço do slot que ainda não está cheio
Slot* Inventario::buscarSlotParcial(int itemId) {
    for(int i = 0; i < INV_TAMANHO; i++) {
        //se não está vazio
        if(inventario[i].estaVazio()) {
            //não faz nada pq ta vazio
        } else if((inventario[i].getItem()->getId() == itemId) && inventario[i].getQuantidade()<CAPACIDADE_SLOT) {
            return &inventario[i];
        }
    }
    return nullptr;
}

//retorna endereço do primeiro slot vazio que achar
Slot* Inventario::slotVazio(){
   for(int i = 0; i < INV_TAMANHO; i++) {
        if(inventario[i].estaVazio()) {
            return &inventario[i];
        }
    }
    std::cout << "Inventario cheio\n" << std::endl;
    return nullptr;
}

//Adiciona uma quantidade positiva ao item, se atingir o limite do slot
//É adicionado ao slot livre mais próximo
//ponteiro para referenciar o slot existente no array e modificá-lo diretamente
//Se não for empilhavel o item preenche varios slots
void Inventario::adicionarItem(ItemAbstrato* item, int quantidade){
    //se digitar algum valor negativo sem querer na soma
    if(quantidade<0){
        std::cout <<"Não é possivel somar quantidades negativos\n" <<std::endl;
        return;
    } else if(quantidade==0){
        //fim da recursão
        return;
    }
    //Primeiro verificar se é empilhavel, se for faz busca parcial
    // se não busca um slot novo
    Slot *slot =nullptr;//inicializo
    if(item->getEmpilhavel()){
        slot = buscarSlotParcial(item->getId());

    } else {
        slot = slotVazio();
        if(slot == nullptr) {
            //caso não encontre slots vazios
            return;
        }

        slot->setItem(item);
        slot->setQuantidade(quantidade);//Se ele for não stakavel será atomaticamente atribuido 1
        adicionarItem(item, quantidade-1);
        return; // para aqui
    }

    //caso não exista adicionar em um slot vazio
    if(slot == nullptr) {
        slot = slotVazio();
        if(slot == nullptr) {
            return;
        }
        slot->setItem(item);
    }
    if (slot!=nullptr){
        int quantidadeTotal = quantidade+slot->getQuantidade();
        //verifico se tem espaço(overflow do slot);
        if(quantidadeTotal<=CAPACIDADE_SLOT){
            slot->setQuantidade(quantidadeTotal);
        } else {
            //preencho totalmente o slot e recursivamente é adicionado em um novo slot
            slot->setQuantidade(CAPACIDADE_SLOT);
            adicionarItem(item, quantidadeTotal-CAPACIDADE_SLOT);
        }
    }
}

//A remoção do item é por index
//Como eu removo por slot se for removido uma quantidade maior que CAPACIDADE_SLOT 
//o item será automaticamente removido
//Será removido o modulo da quantidade
void Inventario::removerItem(int index, int quantidade){
    if(index>=INV_TAMANHO){
        std::cout<<"\nDigite um index valido\n" << std::endl;
        return;
    }
    if(inventario[index].estaVazio()){
        std::cout<<"\nSlot vazio\n" << std::endl;
        return;
    } 
    if(quantidade<0) quantidade *= -1;

    int resultado =inventario[index].getQuantidade()-quantidade;
    if (resultado<=0){
        inventario[index].limparSlot();
    } else{
        inventario[index].setQuantidade(resultado);
    }
}

Slot* Inventario::getInventario(){
    return this->inventario;
}