# Documentação do Projeto

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
└── index.cpp
```
---

### Organização do Sistema

### Itens/

A hierarquia de itens segue o padrão de herança com a classe abstrata. `ItemAbstrato` define um padrão para os outros itens, e cada subclasse representa um item concreto com seu próprio comportamento de empilhamento.

Cada item possui: identificador único (`id`) que os diferencia, enum que categoriza o item (`tipo`) que especifica se um item é arma, consumível, acessório etc., e uma flag que define o comportamento no inventário (se é `empilhável` ou não).
Possui método virtual `usar()` para definir o comportamento de cada item individualmente.
Foram criados 4 itens como exemplo.

Criei uma variável adicional chamada `nome`, pois precisava para identificar os itens no terminal.

---

### Inventário/

### Inventario/Slot.cpp

É a unidade básica do inventário. Cada slot possui uma regra de armazenamento:
- Até **64 unidades** de um item empilhável (esse valor é uma constante na classe), ou
- **1 unidade** de um item não empilhável

`Slot` referencia `ItemAbstrato`, aceitando qualquer item concreto.

obs: O slot é somente uma unidade de armazenamento; a validação e gerenciamento são responsabilidade do inventário.

### Inventario/Inventario.cpp

Gerencia um array privado de `Slot` com capacidade definida como uma constante na classe. As funções que tornam o inventário funcional são:


- `slotVazio()`: busca slots vazios
- `buscarSlotParcial`: busca por id o primeiro slot com o mesmo item que ainda não foi preenchido
- `adicionarItem`: adiciona item empilhavel a slots existentes; se o slot atingir o seu máximo (sendo item empilhável ou não), ocupa um novo slot
- `removerItem(index, quantidade)`: remove a quantidade informada do slot no index especificado; se a quantidade for maior que a existente, o slot é limpo completamente. (A quantidade pode ser negativa ou positiva pois é feito o modulo da quantiade para não ter confusão)
- `getInventario()`: retorna o array de slots para acesso externo;

---

### Personagem/Personagem.cpp

`Personagem` compõe um `Inventario`, um depende do outro para existir. Possui:
- `nome`: identificação do personagem
- `inventario`: capacidade definida na classe

---

### index.cpp
Demonstração interativa de como o sistema funciona:
- Criação de um personagem
- Criação dos itens disponíveis
- Menu para adicionar e remover itens
- `atualizarInventario()`: imprime uma representação visual do inventário em ASCII a cada atualização, exibindo o index de cada slot ocupado para facilitar a visualização

- Cada item printado no terminal tem o formato `[[index] nome^quantidade]`, ex: [[3]pip-boy^1] (um pip-boy no index 3), [[0]Poção^32](32 poções no primeiro index)
---

### Relações entre Classes
```
Personagem [composição]→  Inventario[composição]→  Slot[associação]→  ItemAbstrato; 
```

---

### Observações:

#### Melhorias além do sistema mínimo pedido

- Uma descrição e representação visual para os itens deixaria o inventário mais interativo
- Atualmente não é possível mover itens pelo inventário; seria interessante o usuário poder organizá-lo como quiser, como organizar por tipo ou juntar todos os itens com o mesmo id, pois com o tempo o inventário tende a ficar bagunçado por conta das próprias funções de adicionar e excluir itens
- Implementar o comportamento de usar() nos itens e adicionar mais parâmetros, se necessário; ex: o item Glock (arma) consumiria munição para funcionar

#### Justificativa para modelagem

- Nomes de classes e funções são autoexplicativos, e cada função foi criada com responsabilidade única para facilitar a compreensão.
- O inventário foi pensado como uma estrutura de múltiplos slots que gerencia os itens que o personagem possui. O tamanho foi definido como uma constante na própria classe, já que na maioria dos jogos o jogador não faz essa escolha (exceto quando é uma mecânica do jogo)
- A classe ItemAbstrato é abstrata para facilitar a criação e padronização dos itens e permitir a adição de novas funcionalidades futuras. O slot referencia ItemAbstrato, aceitando qualquer item concreto sem precisar conhecê-lo diretamente. O método usar() foi definido como virtual para tornar ItemAbstrato não instanciável e garantir que itens futuros implementem seu próprio comportamento. Obs: nenhum item possui comportamento por enquanto.
- Por enquanto, os itens são armazenados por referência no inventário, podendo múltiplos slots apontarem para o mesmo objeto. Isso funciona enquanto nenhum item possui comportamento próprio com alguma alteração de estado. No futuro, seria necessário criar instâncias independentes.
- O personagem compõe o inventário, pois não faz sentido os dois existirem independentemente.
- No index foi implementado um menu onde o usuário adiciona e remove itens, com uma representação visual simples do inventário em ASCII, atualizada a cada ação.


### Rodar o projeto
- Para compilar no linux: `g++ **/*.cpp index.cpp -o inventario.exe`
- rodar: ./inventario.exe