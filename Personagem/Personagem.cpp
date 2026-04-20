#include "Personagem.h"

Personagem::Personagem(){};

void Personagem::setNome(std::string nome){
    this->nome = nome;
}

std::string Personagem::getNome(){
    return this->nome;
}

Inventario& Personagem::getInventario(){
    return this->inventario;
}