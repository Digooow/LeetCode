# 03 · Sliding Window (Padrão Algorítmico de Janela Deslizante)

## Qual é o nome correto desse conceito?

**Sliding Window (Janela Deslizante)** é um **Padrão Algorítmico (*Algorithmic Pattern*)** especializado em problemas sobre **subarrays contíguos** ou **substrings contíguas**.

Em vez de recalcular uma propriedade (soma, média, conjunto de caracteres únicos) do zero para cada subarray `[left..right]` em $O(n^2)$ ou $O(n \cdot k)$, mantemos uma "janela" ativa delimitada por `[left, right]` e atualizamos seu estado incrementalmente em $O(1)$:
- Quando `right` avança, **adicionamos** o elemento que entrou na janela.
- Quando `left` avança, **removemos** o elemento que saiu da janela.

Existem duas subcategorias clássicas:
1. **Janela Deslizante de Tamanho Fixo ($k$):** A largura `right - left + 1` é sempre igual a $k$.
2. **Janela Deslizante Dinâmica (Expansão e Contração):** `right` expande a janela para buscar ou manter uma condição; quando uma restrição é violada (ou satisfeita, no caso de janela mínima), `left` contrai a janela em um laço `while`.
   - Embora haja um `while` dentro de um `for`, tanto `left` quanto `right` só avançam para a direita no máximo $n$ vezes, resultando em **Complexidade Amortizada (*Amortized Time Complexity*) $O(n)$**.

---

## Problemas nesta pasta

| Problema | Dificuldade | Variante de Sliding Window |
|---|---|---|
| [0121 - Best Time to Buy and Sell Stock](./0121-best-time-to-buy-and-sell-stock/README.md) | Fácil | Janela Dinâmica com Mínimo Histórico Acumulado |
| [0643 - Maximum Average Subarray I](./0643-maximum-average-subarray-i/README.md) | Fácil | Janela Deslizante de Tamanho Fixo $k$ |
| [0003 - Longest Substring Without Repeating Characters](./0003-longest-substring-without-repeating-characters/README.md) | Intermediário | Janela Dinâmica com Último Índice Visto |
| [0076 - Minimum Window Substring](./0076-minimum-window-substring/README.md) | Difícil (Hard) | Janela Dinâmica de Expansão/Contração com Contador de Déficit |
