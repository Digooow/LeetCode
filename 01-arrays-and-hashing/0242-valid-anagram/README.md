# 0242 · Valid Anagram

**Dificuldade:** Fácil | **Categoria:** Arrays & Hashing | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dadas duas strings `s` e `t` compostas por letras minúsculas ASCII (`'a'` a `'z'`), retornar `true` se `t` for um anagrama de `s`, ou `false` caso contrário.

## Abordagem

Após validar rapidamente se `s.size() != t.size()` (condição eliminatória em $O(1)$), `isAnagram` utiliza um vetor estático `std::array<int, 26> freq{}` alocado na *stack* para contabilizar o saldo líquido de cada caractere.

Em uma única travessia de índice `i`:
- Incrementa-se `freq[s[i] - 'a']`.
- Decrementa-se `freq[t[i] - 'a']`.

Se `s` e `t` possuem exatamente a mesma multiconjunto de caracteres, todas as 26 posições de `freq` encerram com valor `0`.

## Complexidade

- **Tempo:** $O(n)$ — uma passagem sobre as strings de tamanho $n$, seguida por verificação fixa de 26 posições.
- **Espaço:** $O(1)$ — tabela estática de 26 inteiros, independente do comprimento das strings.
