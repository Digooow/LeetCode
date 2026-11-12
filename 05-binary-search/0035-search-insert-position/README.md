# 35. Search Insert Position

- **Nível:** Fácil ([LeetCode #35](https://leetcode.com/problems/search-insert-position/))
- **Classificação do Conceito:**
  - **Algoritmo:** *Lower Bound Binary Search* (Busca Binária de Limite Inferior)

---

## 1. O que é esse conceito?

Na Ciência da Computação (e na STL do C++ via `std::lower_bound`), o **Lower Bound** de um valor `target` em um array ordenado é o **menor índice $i$ tal que $\text{nums}[i] \ge \text{target}$** (ou `n`, caso todos os elementos sejam menores que `target`).

Essa definição unifica os dois casos do problema:
- Se `target` existe no array, o primeiro índice com `nums[i] >= target` é o próprio índice de `target`.
- Se `target` não existe, o primeiro índice com `nums[i] >= target` é exatamente a posição onde `target` deve ser inserido para manter a ordenação!

---

## 2. Explicação do Algoritmo Passo a Passo

1. Inicializamos `left = 0` e `right = n - 1`.
2. Enquanto `left <= right`:
   - `mid = left + (right - left) / 2`.
   - Se `nums[mid] == target`, retornamos `mid`.
   - Se `nums[mid] < target`, a posição de inserção está estritamente à direita $\rightarrow$ `left = mid + 1`.
   - Se `nums[mid] > target`, `mid` pode ser a resposta ou algo à esquerda $\rightarrow$ `right = mid - 1`.
3. Quando o laço termina (`left > right`), `left` aponta exatamente para o *Lower Bound*.

---

## 3. Complexidade

- **Tempo:** $O(\log n)$.
- **Espaço:** $O(1)$.
