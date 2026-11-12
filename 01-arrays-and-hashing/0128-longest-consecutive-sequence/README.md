# 128. Longest Consecutive Sequence

- **Nível:** Intermediário ([LeetCode #128](https://leetcode.com/problems/longest-consecutive-sequence/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** Conjunto Hash (*Hash Set* — `std::unordered_set`)
  - **Padrão Algorítmico:** *Sequence Start Detection* (Início de Sequência em Conjunto Hash para Varredura Amortizada $O(n)$)

---

## 1. O que é esse conceito?

Ordenar o vetor resolveria o problema em $O(n \log n)$, mas o enunciado exige **$O(n)$ estrito**.

Se colocarmos todos os números em um `std::unordered_set<int> numSet` e tentarmos contar a sequência a partir de **qualquer** número $x$, gastaríamos $O(n^2)$ recontando sufixos da mesma sequência várias vezes (ex.: contando `1,2,3,4`, depois `2,3,4`, depois `3,4`).

O truque do padrão **Sequence Start Detection** é uma única linha de filtro:
> Um número $x$ só é o **início** de uma sequência consecutiva se **$x - 1$ NÃO existir no conjunto** (`!numSet.count(x - 1)`).

Ao disparar o laço `while (numSet.count(curr + 1))` **apenas** para inícios de sequência, cada número do conjunto é visitado pelo `while` interno **no máximo uma única vez** em toda a execução!

---

## 2. Complexidade

- **Tempo:** $O(n)$ amortizado — cada elemento é inspecionado um número constante de vezes.
- **Espaço:** $O(n)$ para armazenar os elementos únicos no `unordered_set`.
