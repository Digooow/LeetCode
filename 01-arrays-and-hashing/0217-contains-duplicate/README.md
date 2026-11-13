# 0217 · Contains Duplicate

**Dificuldade:** Fácil | **Categoria:** Arrays & Hashing | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros `nums`, retornar `true` caso algum valor apareça pelo menos duas vezes, ou `false` se todos os elementos forem distintos.

## Abordagem

`containsDuplicate` utiliza um `std::unordered_set<int>` (`seen`) com capacidade pré-alocada via `seen.reserve(nums.size())` para reduzir realocações de tabela hash.

Para cada `num` em `nums`, executa-se `seen.insert(num)`. O método `insert` retorna um `std::pair<iterator, bool>` cujo campo `.second` indica se uma nova chave foi inserida: se `.second` for `false`, o elemento já estava presente em `seen`, permitindo retorno imediato `true`.

## Complexidade

- **Tempo:** $O(n)$ médio — até $n$ inserções com custo médio constante $O(1)$ e saída antecipada na primeira colisão de valor.
- **Espaço:** $O(n)$ — armazenamento de até $n$ elementos distintos em `seen`.
