# 76. Minimum Window Substring

- **Nível:** Difícil / Hard ([LeetCode #76](https://leetcode.com/problems/minimum-window-substring/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Expand-and-Contract Sliding Window with Frequency Deficit Counter* (Janela Deslizante de Expansão e Contração com Contador de Déficit)

---

## 1. O que é esse conceito?

Este é o problema canônico de **Sliding Window de Nível Hard**. Precisamos encontrar a menor substring de `s` que contenha todos os caracteres de `t` (incluindo suas multiplicidades).

Para evitar comparar dois mapas de 128 posições a cada passo, usamos um **Contador de Déficit (`missing`)**:
- Inicializamos `need[c]` com a frequência de cada caractere de `t`, e `missing = t.size()`.
- **Fase de Expansão (`right++`):** Ao incluir `s[right]`, se `need[s[right]] > 0`, significa que esse caractere era necessário $\rightarrow$ decrementamos `--missing`. De qualquer forma, fazemos `--need[s[right]]` (valores negativos em `need` indicam excesso daquele caractere na janela).
- **Fase de Contração (`while (missing == 0)`):** Enquanto a janela for válida (`missing == 0`), tentamos atualizar a menor janela vista e encolher `left++` devolvendo `++need[s[left]]`. Se `need[s[left]] > 0`, perdemos um caractere essencial e incrementamos `++missing`.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Contamos as frequências de `t` em `std::array<int, 128> need{}` e definimos `missing = t.size()`.
2. Mantemos `left = 0`, `bestStart = 0` e `bestLen = INT_MAX`.
3. Avançamos `right` de `0` a `s.size() - 1`:
   - Se `need[s[right]] > 0`, decrementamos `--missing`.
   - Decrementamos `--need[s[right]]`.
   - Enquanto `missing == 0`:
     - Se `right - left + 1 < bestLen`, atualizamos `bestLen` e `bestStart = left`.
     - Incrementamos `++need[s[left]]`.
     - Se `need[s[left]] > 0`, incrementamos `++missing`.
     - Avançamos `++left`.
4. Se `bestLen == INT_MAX`, retornamos `""`; senão, `s.substr(bestStart, bestLen)`.

---

## 3. Complexidade

- **Tempo:** $O(|s| + |t|)$ — tanto `right` quanto `left` avançam no máximo $|s|$ vezes (análise amortizada).
- **Espaço:** $O(1)$ — array fixo de 128 inteiros para a tabela ASCII.
