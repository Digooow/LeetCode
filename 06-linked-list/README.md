# 06 · Linked List & Fast/Slow Pointers (Listas Encadeadas)

## Estruturas e Padrões

1. **Lista Simplesmente Encadeada (*Singly Linked List*):**
   - Estrutura linear dinâmica composta por nós alocados individualmente, contendo um valor (`val`) e um ponteiro (`next`). Não oferece acesso indexado em $O(1)$, mas permite religação local de ponteiros em $O(1)$ sem realocação contígua.
2. **Padrões Utilizados:**
   - **Inversão *In-Place* com Três Ponteiros:** uso de `prev`, `curr` e `nextTemp` para reverter ligações em $O(n)$ tempo e $O(1)$ espaço.
   - **Nó Sentinela (*Dummy Head*):** alocação de um nó auxiliar na *stack* antes da cabeça da lista resultante para eliminar ramificações especiais no primeiro elemento.
   - **Ponteiros Rápido e Lento (*Fast & Slow Pointers* / Algoritmo de Floyd):** `slow` avança 1 nó e `fast` avança 2 nós por iteração. Havendo ciclo, os ponteiros colidem em $O(n)$ tempo e $O(1)$ espaço; caso contrário, `fast` alcança `nullptr`.
   - **Fusão de $k$ Listas Ordenadas (*K-Way Merge* via *Min-Heap*):** fila de prioridade mínima (`std::priority_queue`) mantendo apenas o menor nó ativo de cada lista, com extração em $O(\log k)$.

---

## Problemas

| Problema | Dificuldade | Padrão Principal |
|---|---|---|
| [0206 - Reverse Linked List](./0206-reverse-linked-list/README.md) | Fácil | Inversão Iterativa de Ponteiros *In-Place* |
| [0021 - Merge Two Sorted Lists](./0021-merge-two-sorted-lists/README.md) | Fácil | Mesclagem Ordenada com Nó Sentinela |
| [0141 - Linked List Cycle](./0141-linked-list-cycle/README.md) | Fácil | Detecção de Ciclo de Floyd (*Fast & Slow Pointers*) |
| [0023 - Merge k Sorted Lists](./0023-merge-k-sorted-lists/README.md) | Difícil (Hard) | *K-Way Merge* com *Min-Heap* (`std::priority_queue`) |
