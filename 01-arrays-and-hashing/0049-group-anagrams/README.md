# 0049 · Group Anagrams

**Dificuldade:** Intermediário | **Categoria:** Arrays & Hashing | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de strings `strs`, agrupar todas as strings que são anagramas entre si em subgrupos distintos.

## Abordagem

Dois anagramas diferem apenas na permutação de seus caracteres; quando ordenados lexicograficamente, produzem a mesma representação canônica (ex.: `"eat"`, `"tea"` e `"ate"` mapeiam para `"aet"`).

Em `groupAnagrams`:
1. Para cada string `s` em `strs`, cria-se uma cópia `canonicalKey` e ordenam-se seus caracteres com `std::sort`.
2. A string original `s` é inserida no balde `groups[canonicalKey]`.
3. Ao término do laço, os vetores acumulados em `groups` são transferidos via `std::move` para `result` (pré-alocado com `result.reserve(groups.size())`), evitando cópias desnecessárias dos baldes.

## Complexidade

- **Tempo:** $O(n \cdot k \log k)$ — onde $n$ é a quantidade de strings e $k$ é o comprimento máximo de uma string, devido à ordenação de cada `canonicalKey`.
- **Espaço:** $O(n \cdot k)$ — armazenamento das chaves canônicas e de todas as strings nos grupos de saída.
