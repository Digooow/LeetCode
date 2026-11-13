# 0033 · Search in Rotated Sorted Array

**Dificuldade:** Intermediário | **Categoria:** Binary Search | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros distintos `nums` originalmente ordenado de forma crescente e rotacionado em um pivô desconhecido, retornar o índice de `target` em tempo $O(\log n)$, ou `-1` se não existir.

## Abordagem

Ao dividir qualquer intervalo `[left, right]` pelo ponto médio `mid = left + (right - left) / 2`, ao menos uma das duas subfaixas (`[left, mid]` ou `[mid, right]`) permanece estritamente ordenada. `search` utiliza essa invariante para decidir em $O(1)$ qual metade descartar:

1. Se `nums[mid] == target`, retorna `mid`.
2. Se `nums[left] <= nums[mid]`, a metade esquerda está ordenada:
   - Se `nums[left] <= target && target < nums[mid]`, restringe a `right = mid - 1`.
   - Caso contrário, busca à direita (`left = mid + 1`).
3. Senão, a metade direita `[mid, right]` é que está ordenada:
   - Se `nums[mid] < target && target <= nums[right]`, restringe a `left = mid + 1`.
   - Caso contrário, busca à esquerda (`right = mid - 1`).

## Complexidade

- **Tempo:** $O(\log n)$ — o intervalo de busca é reduzido pela metade a cada iteração.
- **Espaço:** $O(1)$ — busca iterativa apenas com ponteiros de índice (`left`, `right`, `mid`).
