# 0704 · Binary Search

**Dificuldade:** Fácil | **Categoria:** Binary Search | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros `nums` ordenado em ordem crescente e um inteiro `target`, retornar o índice de `target` em $O(\log n)$, ou `-1` se estiver ausente.

## Abordagem

`search` realiza busca binária clássica em intervalo fechado `[left, right]` (`0` até `nums.size() - 1`):

- A cada iteração de `while (left <= right)`, calcula `mid = left + (right - left) / 2` para evitar *integer overflow* em índices grandes.
- Compara `nums[mid]` com `target`:
  - Igual: retorna `mid`.
  - Menor que `target`: descarta a metade esquerda ajustando `left = mid + 1`.
  - Maior que `target`: descarta a metade direita ajustando `right = mid - 1`.
- Caso o intervalo se esgote sem encontro, retorna `-1`.

## Complexidade

- **Tempo:** $O(\log n)$ — metade do espaço de busca restante é eliminada por iteração.
- **Espaço:** $O(1)$ — execução iterativa sem consumo de pilha de recursão.
