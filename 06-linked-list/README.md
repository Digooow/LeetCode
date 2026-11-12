# 06 · Linked List & Fast/Slow Pointers (Listas Encadeadas e Tartaruga e Lebre)

## Qual é o nome correto desse conceito?

1. **Estrutura de Dados: Lista Encadeada (*Singly Linked List*)**
   - Uma estrutura linear dinâmica composta por nós alocados individualmente, onde cada nó guarda um valor (`val`) e um ponteiro (`next`) para o próximo nó. Diferente do array, não há acesso indexado $O(1)$, mas inserções e religações de ponteiros locais custam $O(1)$.
2. **Padrões Algorítmicos para Listas Encadeadas:**
   - **Inversão de Ponteiros com 3 Variáveis (*Three-Pointer In-Place Reversal*):** Manter `prev`, `curr` e `nextTemp` para inverter as setas da lista em $O(n)$ tempo e $O(1)$ espaço.
   - **Nó Sentinela (*Dummy Head / Sentinel Node*):** Criar um nó artificial na *stack* antes da cabeça da lista de saída para eliminar `if/else` especiais de lista vazia.
   - **Ponteiros Rápido e Lento (*Fast & Slow Pointers* / Algoritmo de Detecção de Ciclo de Floyd — *Tortoise and Hare*):** Avançar `slow` de 1 em 1 e `fast` de 2 em 2. Se houver um ciclo, eles obrigatoriamente se encontram dentro do ciclo em $O(n)$ tempo e $O(1)$ espaço; se não houver ciclo, `fast` chega a `nullptr` (e `slow` estará exatamente no meio da lista!).
   - **Fusão de $k$ Sequências Ordenadas (*K-Way Merge via Min-Heap*):** Usar uma fila de prioridade mínima (`std::priority_queue`) contendo o menor nó disponível de cada uma das $k$ listas para extrair o mínimo global em $O(\log k)$.

---

## Problemas nesta pasta

| Problema | Dificuldade | Conceito / Padrão Principal |
|---|---|---|
| [0206 - Reverse Linked List](./0206-reverse-linked-list/README.md) | Fácil | Inversão Iterativa de Ponteiros *In-Place* |
| [0021 - Merge Two Sorted Lists](./0021-merge-two-sorted-lists/README.md) | Fácil | Mesclagem Ordenada com Nó Sentinela (*Dummy Node*) |
| [0141 - Linked List Cycle](./0141-linked-list-cycle/README.md) | Fácil | Algoritmo de Floyd (*Fast & Slow Pointers*) |
| [0023 - Merge k Sorted Lists](./0023-merge-k-sorted-lists/README.md) | Difícil (Hard) | *K-Way Merge* com *Min-Heap* (`std::priority_queue`) |
