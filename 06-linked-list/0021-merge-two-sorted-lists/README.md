# 0021 · Merge Two Sorted Lists

**Dificuldade:** Fácil | **Categoria:** Linked List | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dadas as cabeças de duas listas simplesmente encadeadas ordenadas `list1` e `list2`, mesclá-las em uma única lista ordenada religando seus nós existentes e retornar a nova cabeça.

## Abordagem

`mergeTwoLists` utiliza um nó sentinela `ListNode dummy(0)` alocado na *stack* com ponteiro cursor `tail = &dummy` para evitar lógica condicional especial ao definir o primeiro nó da lista de saída:

1. Enquanto `list1 != nullptr && list2 != nullptr`, compara `list1->val <= list2->val`: conecta o menor nó em `tail->next` e avança o ponteiro da lista escolhida junto com `tail`.
2. Quando uma das listas termina, conecta o restante não vazio diretamente em `tail->next = (list1 != nullptr) ? list1 : list2`, aproveitando que os nós remanescentes já estão encadeados e ordenados.
3. Retorna `dummy.next`.

## Complexidade

- **Tempo:** $O(n + m)$ — onde $n$ e $m$ são os comprimentos de `list1` e `list2` (e $O(\min(n, m))$ na prática quando uma lista acaba antes da outra).
- **Espaço:** $O(1)$ — religação *in-place* dos nós existentes usando apenas `dummy` na *stack*.
