# 0206 · Reverse Linked List

**Dificuldade:** Fácil | **Categoria:** Linked List | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada a cabeça `head` de uma lista simplesmente encadeada, inverter a direção de todos os ponteiros e retornar a nova cabeça da lista invertida.

## Abordagem

`reverseList` inverte a lista iterativamente *in-place* mantendo três referências locais (`prev`, `curr` e `nextTemp`), evitando o custo $O(n)$ de pilha da abordagem recursiva:

1. Inicializa `prev = nullptr` e `curr = head`.
2. Enquanto `curr != nullptr`:
   - Salva o próximo nó da ordem original em `nextTemp = curr->next` antes de alterar a ligação;
   - Redireciona `curr->next = prev`;
   - Avança `prev = curr` e `curr = nextTemp`.
3. Ao término do laço (`curr == nullptr`), `prev` aponta para o antigo último nó, agora a nova cabeça.

## Complexidade

- **Tempo:** $O(n)$ — visita exatamente uma vez cada um dos $n$ nós da lista.
- **Espaço:** $O(1)$ — inversão iterativa sem alocação de nós extras nem uso de pilha de recursão.
