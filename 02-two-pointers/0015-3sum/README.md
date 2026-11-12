# 15. 3Sum

- **Nível:** Intermediário ([LeetCode #15](https://leetcode.com/problems/3sum/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Sorting + Fixed Pivot + Convergent Two Pointers* (Redução de $k$-Sum para 2-Sum Ordenado)

---

## 1. O que é esse conceito?

Encontrar todas as triplas únicas $(a, b, c)$ tais que $a + b + c = 0$ por força bruta exigiria três laços aninhados ($O(n^3)$) mais um conjunto de hash para eliminar triplas duplicadas.

A técnica de **Redução por Ordenação + Two Pointers** resolve dois problemas de uma vez:
1. Ao ordenar o vetor ($O(n \log n)$), valores iguais ficam adjacentes, permitindo **pular duplicatas** em $O(1)$ apenas comparando `nums[i] == nums[i - 1]`.
2. Para cada índice `i` fixado como primeiro elemento da tripla, o subproblema restante é encontrar dois números em `nums[i + 1 .. n - 1]` que somem `-nums[i]`. Como o subarray está ordenado, aplicamos **Dois Ponteiros Convergentes** (`left` e `right`) em $O(n)$, reduzindo o custo total de $O(n^3)$ para **$O(n^2)$**.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Ordenamos `nums` em ordem crescente.
2. Iteramos `i` de `0` até `n - 3`:
   - **Poda monotônica:** se `nums[i] > 0`, como o vetor está ordenado, a soma de três números a partir de `i` nunca será `0` $\rightarrow$ `break`.
   - **Desduplicação do pivô:** se `i > 0 && nums[i] == nums[i - 1]`, pulamos (`continue`).
   - Definimos `left = i + 1` e `right = n - 1`.
   - Enquanto `left < right`:
     - Calculamos `sum = nums[i] + nums[left] + nums[right]`.
     - Se `sum < 0`: precisamos de uma soma maior $\rightarrow$ `++left`.
     - Se `sum > 0`: precisamos de uma soma menor $\rightarrow$ `--right`.
     - Se `sum == 0`:
       - Registramos `{nums[i], nums[left], nums[right]}`.
       - Avançamos `++left` e `--right` pulando valores repetidos adjacentes.

---

## 3. Complexidade

- **Tempo:** $O(n^2)$ — ordenação $O(n \log n)$ + laço externo $O(n)$ multiplicado pela varredura linear `left`/`right` $O(n)$.
- **Espaço Auxiliar:** $O(1)$ (ou $O(\log n)$ da pilha de recursão do `std::sort`), desconsiderando o vetor de saída.
