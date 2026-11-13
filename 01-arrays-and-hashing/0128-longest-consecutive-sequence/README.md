# 0128 · Longest Consecutive Sequence

**Dificuldade:** Intermediário | **Categoria:** Arrays & Hashing | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor não ordenado de inteiros `nums`, retornar o comprimento da maior sequência de valores inteiros consecutivos em tempo $O(n)$.

## Abordagem

Ordenar o vetor custaria $O(n \log n)$. Para manter complexidade linear média, `longestConsecutive` insere todos os valores em um `std::unordered_set<int>` (`numSet`) e identifica apenas os **inícios reais** de cada sequência:

1. Iterando sobre cada `num` em `numSet`, verifica-se se `num - 1` está ausente do conjunto (`numSet.find(num - 1) == numSet.end()`).
2. Apenas quando `num - 1` não existe (ou seja, `num` é o menor elemento de uma cadeia consecutiva) inicia-se um laço `while` incrementando `currentNum` e `currentStreak` enquanto `currentNum + 1` existir em `numSet`.
3. O maior comprimento observado é mantido em `longest`.

Como cada elemento do conjunto é visitado pelo `while` interno no máximo uma vez durante toda a execução, evita-se o retrabalho quadrático sobre subcadeias já percorridas.

## Complexidade

- **Tempo:** $O(n)$ médio — inserção em `numSet` e avanço de cada elemento por no máximo uma cadeia consecutiva.
- **Espaço:** $O(n)$ — armazenamento dos elementos únicos em `numSet`.
