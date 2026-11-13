# 0141 · Linked List Cycle

**Dificuldade:** Fácil | **Categoria:** Linked List | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada a cabeça `head` de uma lista simplesmente encadeada, determinar se existe algum ciclo na estrutura de ponteiros.

## Abordagem

Armazenar nós visitados em um `std::unordered_set<ListNode*>` resolveria em $O(n)$ de memória. Para manter espaço constante $O(1)$, `hasCycle` aplica o algoritmo de detecção de ciclo de Floyd (*Tortoise and Hare*):

- Inicializa `slow = head` e `fast = head`.
- Em cada iteração de `while (fast != nullptr && fast->next != nullptr)`:
  - `slow` avança 1 nó (`slow = slow->next`);
  - `fast` avança 2 nós (`fast = fast->next->next`).
- Se `slow == fast`, há interseção dentro do ciclo e retorna `true`.
- Se `fast` alcançar `nullptr`, a lista termina de forma linear e retorna `false`.

## Complexidade

- **Tempo:** $O(n)$ — se não houver ciclo, `fast` percorre a lista na metade dos passos; se houver ciclo, a distância relativa entre `fast` e `slow` diminui em 1 nó por iteração até a colisão.
- **Espaço:** $O(1)$ — apenas os dois ponteiros `slow` e `fast`.
