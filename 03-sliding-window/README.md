# 03 · Sliding Window (Janela Deslizante)

## Visão Geral

**Sliding Window** é um padrão algorítmico voltado para **subarrays** ou **substrings contíguas**. Em vez de recalcular uma métrica do zero para cada intervalo `[left..right]` em $O(n^2)$ ou $O(n \cdot k)$, o estado da janela é atualizado incrementalmente em $O(1)$:

- Ao avançar `right`, o elemento recém-incluído entra no estado da janela.
- Ao avançar `left`, o elemento descartado é removido do estado da janela.

Variantes utilizadas nesta seção:

1. **Janela de Tamanho Fixo ($k$):** mantém largura constante `right - left + 1 == k` a cada deslocamento.
2. **Janela Dinâmica (Expansão e Contração):** `right` expande o intervalo enquanto `left` contrai em um laço `while` interno para restaurar ou minimizar uma restrição. Como `left` e `right` avançam no máximo $n$ posições no total, o custo temporal é **amortizado $O(n)$**.

---

## Problemas

| Problema | Dificuldade | Variante |
|---|---|---|
| [0121 - Best Time to Buy and Sell Stock](./0121-best-time-to-buy-and-sell-stock/README.md) | Fácil | Janela Dinâmica com Mínimo Histórico Acumulado |
| [0643 - Maximum Average Subarray I](./0643-maximum-average-subarray-i/README.md) | Fácil | Janela Deslizante de Tamanho Fixo $k$ |
| [0003 - Longest Substring Without Repeating Characters](./0003-longest-substring-without-repeating-characters/README.md) | Intermediário | Janela Dinâmica Indexada por Última Ocorrência |
| [0076 - Minimum Window Substring](./0076-minimum-window-substring/README.md) | Difícil (Hard) | Expansão/Contração com Contador de Déficit |
