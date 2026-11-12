# 70. Climbing Stairs

- **Nível:** Fácil ([LeetCode #70](https://leetcode.com/problems/climbing-stairs/))
- **Classificação do Conceito:**
  - **Paradigma:** *Bottom-Up 1D Dynamic Programming with State Compression* (Programação Dinâmica 1D com Compressão de Estado)

---

## 1. O que é esse conceito?

Para chegar ao degrau $n$, o último passo dado só pode ter vindo do degrau $n - 1$ (um passo de 1) ou do degrau $n - 2$ (um passo de 2). Isso define a relação de recorrência de Fibonacci:

$$dp[i] = dp[i - 1] + dp[i - 2]$$

Uma recursão pura recalcularia os mesmos degraus exponencialmente ($O(2^n)$). Com **Programação Dinâmica + Compressão de Estado**, percebemos que `dp[i]` depende apenas dos **dois últimos estados** (`prev1` e `prev2`), reduzindo o tempo para $O(n)$ e o espaço de $O(n)$ para **$O(1)$**.

---

## 2. Complexidade

- **Tempo:** $O(n)$.
- **Espaço:** $O(1)$ — apenas duas variáveis inteiras de estado.
