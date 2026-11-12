# 643. Maximum Average Subarray I

- **Nível:** Fácil ([LeetCode #643](https://leetcode.com/problems/maximum-average-subarray-i/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Fixed-Size Sliding Window* (Janela Deslizante de Tamanho Fixo $k$)

---

## 1. O que é esse conceito?

Calcular a soma de cada subarray de tamanho $k$ do zero exigiria somar $k$ elementos para cada posição inicial, levando a $O(n \cdot k)$.

Na **Janela Deslizante de Tamanho Fixo**, observamos que duas janelas consecutivas `[i - k .. i - 1]` e `[i - k + 1 .. i]` compartilham $k - 1$ elementos em comum! Portanto, a transição de uma janela para a próxima custa apenas duas operações aritméticas ($O(1)$):

$$\text{windowSum}_{\text{nova}} = \text{windowSum}_{\text{anterior}} + \underbrace{\text{nums}[i]}_{\text{entrou}} - \underbrace{\text{nums}[i - k]}_{\text{saiu}}$$

---

## 2. Explicação do Algoritmo Passo a Passo

1. Somamos os primeiros $k$ elementos em `windowSum` e inicializamos `maxSum = windowSum`.
2. Para `i` de `k` até `n - 1`:
   - Atualizamos `windowSum += nums[i] - nums[i - k]`.
   - Atualizamos `maxSum = std::max(maxSum, windowSum)`.
3. Retornamos `static_cast<double>(maxSum) / k`.

---

## 3. Complexidade

- **Tempo:** $O(n)$ — cada elemento entra na janela uma vez e sai no máximo uma vez.
- **Espaço:** $O(1)$ — apenas variáveis acumuladoras escalares.
