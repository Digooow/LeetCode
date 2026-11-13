# 0322 · Coin Change

**Dificuldade:** Intermediário | **Categoria:** Dynamic Programming & Greedy | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de denominações de moedas `coins` (com estoque ilimitado de cada tipo) e um valor alvo `amount`, retornar a quantidade mínima de moedas necessária para compor `amount`, ou `-1` se a composição for impossível.

## Abordagem

Uma estratégia gulosa falharia para sistemas de moedas arbitrários (por exemplo, `coins = {1, 3, 4}` e `amount = 6` exige `2` moedas `{3, 3}`, enquanto a escolha gulosa `4 + 1 + 1` usaria `3`).

`coinChange` resolve o problema como variação de *Unbounded Knapsack* via **Programação Dinâmica *Bottom-Up***:

1. Inicializa `dp` de tamanho `amount + 1` com sentinela `inf = amount + 1` (um limite seguro superior ao máximo possível de moedas unitárias e pequeno o bastante para que `1 + dp[curr - coin]` nunca cause *overflow* em `int`), definindo `dp[0] = 0`.
2. Para cada subvalor `curr` de `1` até `amount` e cada `coin` em `coins`:
   - Se `coin <= curr`, atualiza `dp[curr] = std::min(dp[curr], 1 + dp[curr - coin])`.
3. Se `dp[amount] > amount`, nenhum conjunto válido atingiu o valor alvo e retorna `-1`; caso contrário, retorna `dp[amount]`.

## Complexidade

- **Tempo:** $O(\text{amount} \cdot |\text{coins}|)$ — preenchimento iterativo de `amount` estados testando todas as denominações.
- **Espaço:** $O(\text{amount})$ — armazenamento da tabela unidimensional `dp`.
