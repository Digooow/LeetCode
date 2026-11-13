# 0121 · Best Time to Buy and Sell Stock

**Dificuldade:** Fácil | **Categoria:** Sliding Window | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor `prices` onde `prices[i]` representa o preço de um ativo no dia `i`, retornar o lucro máximo obtido com uma única compra e uma única venda posterior ($i_{\text{venda}} > i_{\text{compra}}$). Caso nenhum lucro seja possível, retornar `0`.

## Abordagem

Após verificar `prices.empty()`, `maxProfit` mantém o menor preço de compra observado até o dia corrente (`minPrice = prices[0]`) e o maior lucro alcançado (`bestProfit = 0`).

Para cada `price` em `prices`:
1. Atualiza `minPrice = std::min(minPrice, price)`, deslocando implicitamente o ponto esquerdo da janela de compra caso surja uma mínima histórica menor.
2. Atualiza `bestProfit = std::max(bestProfit, price - minPrice)`, avaliando o ganho caso a venda ocorra no dia atual.

## Complexidade

- **Tempo:** $O(n)$ — passagem linear única por `prices`.
- **Espaço:** $O(1)$ — apenas as variáveis escalares `minPrice` e `bestProfit`.
