# 283. Move Zeroes

- **Nível:** Fácil ([LeetCode #283](https://leetcode.com/problems/move-zeroes/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *In-Place Stable Partitioning via Slow/Fast Pointers* (Particionamento Estável *In-Place* com Dois Ponteiros)

---

## 1. O que é esse conceito?

Mover todos os zeros para o final preservando a ordem relativa dos elementos não nulos é exatamente a operação de **Particionamento Estável (*Stable Partition*)** usada na biblioteca padrão (`std::stable_partition`) e semelhante à etapa de partição de Lomuto do *QuickSort*.

Mantemos um ponteiro `nonZeroPos` (ponteiro lento) que marca a fronteira entre elementos não-zero já processados e os zeros acumulados:
- Sempre que o ponteiro rápido `i` encontra `nums[i] != 0`, fazemos `std::swap(nums[nonZeroPos], nums[i])` e avançamos `++nonZeroPos`.

---

## 2. Explicação do Algoritmo Passo a Passo

Para `nums = [0, 1, 0, 3, 12]`:
1. `i = 0` (`0`): ignorado (`nonZeroPos = 0`).
2. `i = 1` (`1 != 0`): `swap(nums[0], nums[1])` $\rightarrow$ `[1, 0, 0, 3, 12]`, `nonZeroPos = 1`.
3. `i = 2` (`0`): ignorado (`nonZeroPos = 1`).
4. `i = 3` (`3 != 0`): `swap(nums[1], nums[3])` $\rightarrow$ `[1, 3, 0, 0, 12]`, `nonZeroPos = 2`.
5. `i = 4` (`12 != 0`): `swap(nums[2], nums[4])` $\rightarrow$ `[1, 3, 12, 0, 0]`, `nonZeroPos = 3`.

---

## 3. Complexidade

- **Tempo:** $O(n)$ — número mínimo de escritas e uma única varredura.
- **Espaço:** $O(1)$ — executado *in-place*.
