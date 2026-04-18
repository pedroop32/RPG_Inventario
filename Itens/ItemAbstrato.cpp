#include "ItemAbstrato.h"

ItemAbstrato::ItemAbstrato(int id, Tipo tipo, bool empilhavel) {
    this->id = id;
    this->tipoItem = tipo;
    this->empilhavel = empilhavel;
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