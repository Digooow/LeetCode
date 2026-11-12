# 704. Binary Search

- **Nível:** Fácil ([LeetCode #704](https://leetcode.com/problems/binary-search/))
- **Classificação do Conceito:**
  - **Algoritmo:** *Binary Search* (Busca Binária Clássica)
  - **Paradigma:** *Decrease and Conquer* (Redução por Fator Constante)

---

## 1. O que é esse conceito?

Dado um vetor ordenado `nums`, comparamos o elemento central `nums[mid]` com `target`:
- Se `nums[mid] == target`, encontramos o índice.
- Se `nums[mid] < target`, todos os elementos à esquerda de `mid` também são menores que `target`, logo descartamos a metade esquerda fazendo `left = mid + 1`.
- Se `nums[mid] > target`, descartamos a metade direita fazendo `right = mid - 1`.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Definimos o intervalo fechado `[left, right] = [0, n - 1]`.
2. Enquanto `left <= right`:
   - Calculamos `mid = left + (right - left) / 2` (evita estouro de inteiro 32-bits se `left + right > INT_MAX`).
   - Comparamos `nums[mid]` com `target` e ajustamos os limites.
3. Se o intervalo esvaziar (`left > right`), retornamos `-1`.

---

## 3. Complexidade

- **Tempo:** $O(\log n)$ — o tamanho do intervalo cai pela metade a cada iteração.
- **Espaço:** $O(1)$ — implementação iterativa sem pilha de recursão.
