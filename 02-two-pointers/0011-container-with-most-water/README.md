# 11. Container With Most Water

- **Nível:** Intermediário ([LeetCode #11](https://leetcode.com/problems/container-with-most-water/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Converging Two Pointers* (Dois Ponteiros Convergentes)
  - **Paradigma:** *Greedy Bottleneck Elimination* (Eliminação Gulosa do Gargalo)

---

## 1. O que é esse conceito?

A área formada entre duas paredes nos índices `left` e `right` é dada por:

$$\text{Área}(left, right) = (right - left) \times \min(\text{height}[left], \text{height}[right])$$

Começando com a largura máxima possível (`left = 0`, `right = n - 1`), qualquer movimento para dentro **diminui a largura** $(right - left)$. Portanto, a única chance de encontrar uma área maior é **aumentar a altura limitante** $\min(\text{height}[left], \text{height}[right])$.

A **escolha gulosa (*Greedy Choice*)** consiste em sempre descartar e mover o ponteiro da **parede mais baixa** (o gargalo), pois manter a parede mais baixa e diminuir a largura jamais poderia produzir uma área superior à atual.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Inicializamos `left = 0`, `right = n - 1` e `maxArea = 0`.
2. Enquanto `left < right`:
   - Calculamos `width = right - left` e `h = std::min(height[left], height[right])`.
   - Atualizamos `maxArea = std::max(maxArea, width * h)`.
   - Se `height[left] < height[right]`, avançamos `++left`; caso contrário, recuamos `--right`.
3. Retornamos `maxArea`.

---

## 3. Complexidade

- **Tempo:** $O(n)$ — em cada passo `right - left` diminui em 1, executando exatamente $n - 1$ comparações.
- **Espaço:** $O(1)$ — apenas variáveis escalares.
