# RPG_Inventario

## Estrutura do Projeto

```
RPG_Inventario/
│
├── Itens/
│   ├── ItemAbstrato.h
│   ├── ItemAbstrato.cpp
│   ├── ItemPocao.h
│   ├── ItemPocao.cpp
│   ├── ItemGlock.h
│   ├── ItemGlock.cpp
│   ├── ItemLivro.h
│   ├── ItemLivro.cpp
│   ├── ItemPipBoy.h
│   └── ItemPipBoy.cpp
│
├── Inventario/
│   ├── Slot.h
│   ├── Slot.cpp
│   ├── Inventario.h
│   └── Inventario.cpp
│
├── Personagem/
│   ├── Personagem.h
│   └── Personagem.cpp
│
└── main.cpp
```

---

### Organização do Sistema

### Itens/

A hierarquia de itens segue o padrão de herança com a classe abstrata. `ItemAbstrato` define um padrão para os outros itens, e cada subclasse representa um item concreto com seu próprio comportamento de empilhamento.

Cada item possui: identificador único (`id`) que os diferencia, enum que categoriza o item (`tipo`) que especifica se um item é material, arma, consumível etc., e uma flag que define o comportamento no inventário (se é `empilhável` ou item não empilhável).

---

### Inventário/

### Inventario/Slot.cpp

É a unidade básica do inventário. Cada slot possui uma regra de armazenamento:
- Até **64 unidades** de um item empilhável, ou
- **1 unidade** de um item não empilhável

`Slot` referencia `ItemAbstrato`, aceitando qualquer item concreto.

### Inventario/Inventario.cpp

Gerencia um array de `Slot` com capacidade definida como uma constante na classe. As funções que tornam o inventário funcional são:

- `adicionarItem(ItemId, int quantidade)` — empilha em slots existentes; se o slot atingir o seu máximo (sendo item empilhável ou não), ocupa um novo slot
- `removerItem(ItemId, int quantidade)` — remove a quantidade informada, atualizando os slots afetados
- `buscarSlot(ItemId)` — procura um slot com o mesmo item

---

### Personagem/Personagem.cpp

`Personagem` compõe um `Inventario` — um depende do outro para existir. Possui:
- `nome` — identificação do personagem
- `inventario` — instância com capacidade definida na criação

---

### Personagem/Main.cpp
Demonstração de como o sistema funciona com
- Criação de um personagem
- Criação do inventário
- Inserção de itens empilháveis e não empilháveis
- Remoção de itens
- `atualizarInventario()` — printa uma representação visual do inventário em ASCII toda vez que um item é atualizado (removido/adicionado), para que fique fácil acompanhar as alterações
---
### Relações entre Classes
```
Personagem [composição]→  Inventario[composição]→  Slot[associação]→  ItemAbstrato; 
```

---

### Observações:
#### Melhorias além do sistema mínimo pedido
- Acredito que uma descrição e uma representação visual para os itens deixaria o inventário mais interativo
- Atualmente não é possível mover itens pelo inventário; seria interessante ter a capacidade de o usuário poder organizá-lo/mover itens como quiser

#### Justificativa para modelagem
- Nomes de classes e funções são autoexplicativos, e cada função foi criada com responsabilidade única para facilitar a compreensão.
- O inventário foi pensado como uma estrutura de múltiplos slots que gerencia os itens que o personagem possui. Achei melhor definir seu tamanho na própria classe, como uma constante, já que na maioria dos jogos o jogador não faz essa escolha, a menos que seja uma mecânica do jogo, o que pode ser uma função futura. 
- A classe ItemAbstrato é uma classe abstrata para facilitar a criação e padronização dos itens, além de servir como uma unidade de slot na referenciação (o slot sabe como é um item, mas não precisa saber qual item possui).
- O personagem compõe o inventário, pois não faz sentido os dois existirem independentemente.
- Na main foi implementada uma representação visual simples do inventário, onde foram usados alguns dos itens criados.
---