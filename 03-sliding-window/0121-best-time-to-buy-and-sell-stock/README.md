# 121. Best Time to Buy and Sell Stock

- **Nível:** Fácil ([LeetCode #121](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Dynamic Sliding Window / Running Minimum Tracking* (Janela Deslizante com Rastreamento do Mínimo Histórico)

---

## 1. O que é esse conceito?

Queremos maximizar $\text{prices}[right] - \text{prices}[left]$ sujeito à restrição temporal $left < right$ (você precisa comprar antes de vender).

Em termos de **Sliding Window**:
- `left` representa o dia da compra (o menor preço visto até agora).
- `right` representa o dia da venda que estamos avaliando hoje.
- Se encontramos um dia `right` cujo preço é **menor** que o preço de compra em `left`, deslizamos imediatamente a ponta esquerda da janela para `right` (`minPrice = prices[right]`), pois qualquer venda futura terá lucro estritamente maior comprando nesse novo fundo histórico.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Inicializamos `minPrice = prices[0]` e `maxProfit = 0`.
2. Para cada preço `price` em `prices`:
   - Se `price < minPrice`, atualizamos `minPrice = price`.
   - Caso contrário, calculamos o lucro potencial `price - minPrice` e atualizamos `maxProfit`.
3. Retornamos `maxProfit`.

---

## 3. Complexidade

- **Tempo:** $O(n)$ — uma única passagem pelo vetor de preços.
- **Espaço:** $O(1)$ — apenas duas variáveis inteiras.
