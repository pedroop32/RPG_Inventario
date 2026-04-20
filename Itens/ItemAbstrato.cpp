#include "ItemAbstrato.h"

ItemAbstrato::ItemAbstrato(int id, Tipo tipo, bool empilhavel, std::string nome) {
    this->id = id;
    this->tipoItem = tipo;
    this->empilhavel = empilhavel;
    this->nome = nome;
}

std::string ItemAbstrato::getNome(){
    return this->nome;
}

int ItemAbstrato::getId() const {
    return this->id;
}

Tipo ItemAbstrato::getTipo() const {
    return this->tipoItem;
}

bool ItemAbstrato::getEmpilhavel() const {
    return this->empilhavel;
}