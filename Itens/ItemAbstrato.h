#ifndef ITEM_ABSTRATO_H
#define ITEM_ABSTRATO_H
#include <string>

enum Tipo{
    CONSUMIVEL, //Itens que desaparecem após o uso
    ARMA, //Armas de fogo e armas brancas
    ACESSORIO //Item decorativo que pode ou não ter utilidade
};

class ItemAbstrato {
  protected:
  Tipo tipoItem;
  int id;
  bool empilhavel;
  std::string nome;

  public:
    //Empilhavel: 1 para empilhavel 0 para não empilhavel
    ItemAbstrato(int id, Tipo tipo, bool empilhavel, std::string nome);

    virtual void usar() = 0; //Função virtual para que cada classe concreta seja obrigada a implementa-la
    
    //getters
    int getId() const;
    Tipo getTipo() const;
    bool getEmpilhavel() const;
    std::string getNome();
};


#endif