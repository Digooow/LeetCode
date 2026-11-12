# 322. Coin Change

- **Nível:** Intermediário ([LeetCode #322](https://leetcode.com/problems/coin-change/))
- **Classificação do Conceito:**
  - **Paradigma:** *Bottom-Up Dynamic Programming (Tabulation)* (Programação Dinâmica por Tabulação)
  - **Modelo Clássico:** *Unbounded Knapsack Variant* (Problema da Mochila Ilimitada)

---

## 1. O que é esse conceito e por que um Algoritmo Guloso falha aqui?

Muitos candidatos tentam resolver o troco mínimo escolhendo sempre a maior moeda possível (*Greedy*). Isso falha em sistemas de moedas não canônicos: por exemplo, para `coins = [1, 3, 4]` e `amount = 6`, o guloso escolheria `4 + 1 + 1` (3 moedas), enquanto o ótimo é `3 + 3` (2 moedas)!

Com **Programação Dinâmica *Bottom-Up***, definimos o estado:
- `dp[x]` = número mínimo de moedas necessárias para formar o valor exato `x`.
- Caso base: `dp[0] = 0`, e inicializamos `dp[1..amount] = amount + 1` (sentinela de infinito).
- Equação de transição (Equação de Bellman):

$$dp[x] = \min_{c \in \text{coins},\ c \le x} \big(1 + dp[x - c]\big)$$

---

## 2. Complexidade

- **Tempo:** $O(\text{amount} \times |\text{coins}|)$.
- **Espaço:** $O(\text{amount})$ para o vetor de tabulação `dp`.
