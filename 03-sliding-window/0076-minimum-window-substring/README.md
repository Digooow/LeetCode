# 0076 · Minimum Window Substring

**Dificuldade:** Difícil (Hard) | **Categoria:** Sliding Window | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dadas duas strings `s` e `t`, retornar a menor substring contígua de `s` que contenha todos os caracteres de `t` (incluindo multiplicidade). Caso não exista tal janela, retornar `""`.

## Abordagem

`minWindow` trata primeiro o caso trivial `t.empty() || s.size() < t.size()` e constrói uma tabela `std::array<int, 128> need{}` com a frequência exigida de cada caractere ASCII de `t`, além do contador agregado `missing = t.size()`.

O algoritmo alterna expansão e contração da janela `[left, right]`:
1. **Expansão (`right`):** se `need[rChar] > 0`, o caractere reduz o déficit restante (`--missing`). Em seguida decrementa-se `need[rChar]` (caracteres em excesso assumem valores negativos para rastrear sobra).
2. **Contração (`while (missing == 0)`):** enquanto a janela cobre todo `t`:
   - Atualiza `bestLen` e `bestStart` se `right - left + 1 < bestLen`.
   - Devolve `lChar` incrementando `need[lChar]`; se `need[lChar]` passar a ser $> 0$, o caractere removido era essencial (não havia excedente), logo `++missing` e o laço de contração encerra.
   - Avança `++left`.

Por fim, retorna `""` se `bestLen == INT_MAX`, ou `s.substr(bestStart, bestLen)`.

## Complexidade

- **Tempo:** $O(|s| + |t|)$ — cada caractere de `s` é processado no máximo uma vez por `right` e uma vez por `left`.
- **Espaço:** $O(1)$ auxiliar — vetor fixo `std::array<int, 128>` para frequências ASCII.
