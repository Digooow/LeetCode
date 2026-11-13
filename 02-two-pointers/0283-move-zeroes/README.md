# 0283 · Move Zeroes

**Dificuldade:** Fácil | **Categoria:** Two Pointers | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros `nums`, mover todos os `0` para o final *in-place*, mantendo a ordem relativa dos elementos não nulos.

## Abordagem

`moveZeroes` implementa um particionamento estável *in-place* usando dois ponteiros na mesma direção:

- `nonZeroPos` marca o fim da partição de elementos não nulos já posicionados corretamente.
- O índice `i` percorre todo o vetor `nums`.
- Quando `nums[i] != 0`, executa-se `std::swap(nums[nonZeroPos], nums[i])` e incrementa-se `nonZeroPos`.

Ao término do laço, todos os elementos não nulos ocupam `nums[0 .. nonZeroPos - 1]` na ordem original e os zeros restantes permanecem contíguos a partir de `nonZeroPos`.

## Complexidade

- **Tempo:** $O(n)$ — uma passagem única pelo vetor com trocas em $O(1)$.
- **Espaço:** $O(1)$ — modificação direta sobre `nums`.
