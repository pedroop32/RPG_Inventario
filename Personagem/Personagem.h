#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "../Inventario/Inventario.h"
#include <string>

class Personagem{
    private:
        std::string nome;
        Inventario inventario;
    public:
        Personagem();

        void setNome(std::string nome);
        std::string getNome();

        Inventario &getInventario();//por referencia
};

#endif