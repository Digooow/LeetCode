# 26. Remove Duplicates from Sorted Array

- **Nível:** Fácil ([LeetCode #26](https://leetcode.com/problems/remove-duplicates-from-sorted-array/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Reader/Writer Two Pointers* (Dois Ponteiros Leitor/Escritor para Desduplicação *In-Place*)

---

## 1. O que é esse conceito?

Como o array já está **ordenado**, todos os elementos duplicados aparecem em posições adjacentes. Remover elementos do meio de um `std::vector` com `.erase()` deslocaria todos os elementos seguintes a cada remoção, custando $O(n^2)$.

O padrão **Reader/Writer Two Pointers** mantém um invariante de partição no próprio array:
- O ponteiro `write` aponta para a próxima posição onde o próximo valor único deve ser gravado (tudo em `nums[0 .. write - 1]` já é único e ordenado).
- O ponteiro `read` varre o array procurando um elemento diferente do último único gravado (`nums[read] != nums[write - 1]`).

---

## 2. Explicação do Algoritmo Passo a Passo

1. Se `nums` estiver vazio, retornamos `0`.
2. Inicializamos `write = 1` (pois `nums[0]` é sempre o primeiro único).
3. Para `read` de `1` até `n - 1`:
   - Se `nums[read] != nums[write - 1]`, encontramos um novo valor distinto:
     - Copiamos `nums[write] = nums[read]`.
     - Incrementamos `++write`.
4. Retornamos `write` (quantidade de elementos únicos).

---

## 3. Complexidade

- **Tempo:** $O(n)$ — uma única passagem pelo vetor.
- **Espaço:** $O(1)$ — modificação 100% *in-place*.
