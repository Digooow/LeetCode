# 0023 · Merge k Sorted Lists

**Dificuldade:** Difícil (Hard) | **Categoria:** Linked List | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor contendo $k$ listas simplesmente encadeadas já ordenadas em ordem crescente, mesclar todas em uma única lista ordenada.

## Abordagem

Combinar as $k$ listas sequencialmente uma a uma degradaria para $O(N \cdot k)$, onde $N$ é o número total de nós. Para reduzir esse fator de $k$ para $\log k$, `mergeKLists` executa um *K-Way Merge* apoiado por uma *min-heap*:

1. Define o comparador `MinNodeCompare` (`a->val > b->val`) para inverter o comportamento padrão de *max-heap* de `std::priority_queue`.
2. Insere em `minHeap` apenas os ponteiros iniciais não nulos de `lists`.
3. Mantém um nó sentinela `ListNode dummy(0)` e `tail = &dummy`. Enquanto `minHeap` não estiver vazia:
   - Extrai o nó de menor valor global `smallest = minHeap.top()` e o conecta em `tail->next`.
   - Se `smallest->next != nullptr`, insere o sucessor de volta na *heap*, mantendo no máximo $k$ elementos simultaneamente na fila de prioridade.

## Complexidade

- **Tempo:** $O(N \log k)$ — onde $N$ é o total de nós somados entre todas as $k$ listas; cada nó entra e sai de uma *heap* de tamanho máximo $k$ exatamente uma vez.
- **Espaço:** $O(k)$ — espaço ocupado por `minHeap` ao manter no máximo um representante ativo por lista.
