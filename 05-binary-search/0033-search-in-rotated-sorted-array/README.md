# 33. Search in Rotated Sorted Array

- **Nível:** Intermediário ([LeetCode #33](https://leetcode.com/problems/search-in-rotated-sorted-array/))
- **Classificação do Conceito:**
  - **Algoritmo:** *Modified Binary Search by Sorted Half Invariant* (Busca Binária Modificada por Identificação de Metade Ordenada)

---

## 1. O que é esse conceito?

Quando um array estritamente crescente sofre uma rotação (por exemplo, `[4, 5, 6, 7, 0, 1, 2]`), ele deixa de ser globalmente ordenado, mas preserva um **invariante estrutural poderoso**:

> Ao dividir qualquer subarray rotacionado ao meio (`mid`), **pelo menos uma das duas metades (`[left..mid]` ou `[mid..right]`) estará 100% ordenada de forma contínua**.

Assim, em cada passo da Busca Binária:
1. Descobrimos qual metade está ordenada comparando `nums[left] <= nums[mid]`.
2. Verificamos se `target` está dentro dos limites da metade ordenada (`nums[left] <= target && target < nums[mid]`). Se estiver, buscamos nela; caso contrário, buscamos na outra metade!

---

## 2. Explicação do Algoritmo Passo a Passo

1. Inicializamos `left = 0`, `right = n - 1`.
2. Enquanto `left <= right`:
   - `mid = left + (right - left) / 2`.
   - Se `nums[mid] == target`, retornamos `mid`.
   - **Caso A — Metade esquerda `[left..mid]` está ordenada (`nums[left] <= nums[mid]`):**
     - Se `nums[left] <= target && target < nums[mid]`, fazemos `right = mid - 1`; senão `left = mid + 1`.
   - **Caso B — Metade direita `[mid..right]` está ordenada:**
     - Se `nums[mid] < target && target <= nums[right]`, fazemos `left = mid + 1`; senão `right = mid - 1`.
3. Se não encontrar, retornamos `-1`.

---

## 3. Complexidade

- **Tempo:** $O(\log n)$ — descarta metade do array a cada passo.
- **Espaço:** $O(1)$.
