# 0035 · Search Insert Position

**Dificuldade:** Fácil | **Categoria:** Binary Search | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor ordenado de inteiros distintos `nums` e um valor `target`, retornar o índice caso `target` seja encontrado ou o índice onde ele deveria ser inserido para preservar a ordenação em tempo $O(\log n)$.

## Abordagem

`searchInsert` implementa uma busca binária de limite inferior (*lower bound*) em intervalo fechado `[left, right]`:

- Calcula `mid = left + (right - left) / 2`.
- Se `nums[mid] == target`, retorna `mid`.
- Se `nums[mid] < target`, avança `left = mid + 1`.
- Caso contrário (`nums[mid] > target`), recua `right = mid - 1`.

**Invariante ao término do laço:** quando `left > right` sem correspondência exata, todos os elementos à esquerda de `left` são estritamente menores que `target` e `nums[left]` (se existir dentro dos limites) é estritamente maior que `target`. Logo, `left` coincide exatamente com o índice de inserção.

## Complexidade

- **Tempo:** $O(\log n)$ — redução binária a cada iteração.
- **Espaço:** $O(1)$ — variáveis escalares apenas.
