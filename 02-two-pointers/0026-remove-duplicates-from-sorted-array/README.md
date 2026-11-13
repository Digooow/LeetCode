# 0026 · Remove Duplicates from Sorted Array

**Dificuldade:** Fácil | **Categoria:** Two Pointers | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor `nums` ordenado em ordem não decrescente, remover as duplicatas *in-place* preservando a ordem relativa dos valores únicos e retornar a quantidade `k` de elementos distintos nas primeiras `k` posições.

## Abordagem

Após tratar o caso de entrada vazia (`if (nums.empty()) return 0;`), `removeDuplicates` utiliza o padrão *Reader/Writer* na mesma direção:

- `write = 1` marca a próxima posição livre da partição compactada (o índice `0` é sempre único por definição).
- `read` percorre os índices de `1` até `nums.size() - 1`.
- Sempre que `nums[read] != nums[write - 1]`, trata-se de um novo valor distinto em um vetor ordenado; ele é gravado em `nums[write]` e `write` avança.

## Complexidade

- **Tempo:** $O(n)$ — leitura linear única sobre `nums`.
- **Espaço:** $O(1)$ — compactação realizada *in-place*, sem alocação auxiliar.
