# 42. Trapping Rain Water

- **Nível:** Difícil / Hard ([LeetCode #42](https://leetcode.com/problems/trapping-rain-water/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Two Pointers with Prefix/Suffix Max Invariant* (Dois Ponteiros com Invariante de Máximo Acumulado)

---

## 1. O que é esse conceito e por que este problema Hard é tão cobrado?

A quantidade de água acumulada exatamente sobre a barra $i$ depende apenas da maior parede à sua esquerda ($L_{\max}[i]$) e da maior parede à sua direita ($R_{\max}[i]$):

$$\text{água}[i] = \max\Big(0,\ \min(L_{\max}[i], R_{\max}[i]) - \text{height}[i]\Big)$$

Uma solução com Programação Dinâmica pré-calcula dois vetores `leftMax[]` e `rightMax[]` em $O(n)$ tempo e $O(n)$ espaço.

Porém, usando **Two Pointers Convergentes**, conseguimos reduzir o espaço para **$O(1)$**:
- Mantemos `leftMax` (máximo visto em `0..left`) e `rightMax` (máximo visto em `right..n-1`).
- Se `leftMax <= rightMax`, sabemos **com certeza absoluta** que o nível de água em `left` é limitado por `leftMax` (mesmo que exista uma parede ainda maior no meio não explorado, o mínimo entre os dois lados para a posição `left` será exatamente `leftMax`).
- Simetricamente, se `rightMax < leftMax`, o nível em `right` é limitado por `rightMax`.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Inicializamos `left = 0`, `right = n - 1`, `leftMax = 0`, `rightMax = 0` e `trapped = 0`.
2. Enquanto `left < right`:
   - Se `height[left] <= height[right]`:
     - Atualizamos `leftMax = std::max(leftMax, height[left])`.
     - Somamos `trapped += leftMax - height[left]`.
     - Avançamos `++left`.
   - Caso contrário:
     - Atualizamos `rightMax = std::max(rightMax, height[right])`.
     - Somamos `trapped += rightMax - height[right]`.
     - Recuamos `--right`.
3. Retornamos `trapped`.

---

## 3. Complexidade

- **Tempo:** $O(n)$ — uma única passagem convergente pelo array.
- **Espaço:** $O(1)$ — zero alocação auxiliar.
