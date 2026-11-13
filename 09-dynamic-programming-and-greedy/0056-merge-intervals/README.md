# 0056 · Merge Intervals

**Dificuldade:** Intermediário | **Categoria:** Dynamic Programming & Greedy | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de intervalos `intervals` no formato `[start, end]`, mesclar todos os intervalos sobrepostos (inclusive adjacentes em ponto extremo, como `[1, 4]` e `[4, 5]`) e retornar a lista resultante de intervalos disjuntos.

## Abordagem

Ordenar `intervals` pelo ponto inicial garante que potenciais sobreposições apareçam contíguas em sequência linear.

Em `merge`:
1. Trata `intervals.empty()` retornando `{}`.
2. Ordena `intervals` com `std::sort` e insere `intervals[0]` em `merged`.
3. Para cada intervalo subsequente `intervals[i]`:
   - Se `intervals[i][0] <= merged.back()[1]`, há sobreposição com o último intervalo consolidado; estende-se o término com `std::max(merged.back()[1], intervals[i][1])` para cobrir também intervalos totalmente contidos (ex.: `[1, 10]` seguido de `[2, 5]`).
   - Caso contrário, adiciona `intervals[i]` como novo bloco em `merged`.

## Complexidade

- **Tempo:** $O(n \log n)$ — dominado por `std::sort`; a varredura linear seguinte custa $O(n)$.
- **Espaço:** $O(\log n)$ a $O(n)$ — conforme a pilha da ordenação e a cópia do vetor de entrada (desconsiderando `merged`).
