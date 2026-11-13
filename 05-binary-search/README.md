# 05 · Binary Search (Busca Binária)

## Visão Geral

**Binary Search** aplica redução de espaço de busca (*Decrease and Conquer*) sobre domínios com propriedade monotônica. Ao descartar metade do intervalo válido em cada iteração, reduz a busca de $O(n)$ para **$O(\log_2 n)$**.

## Pontos Críticos de Implementação

1. **Cálculo de ponto médio sem *Integer Overflow*:** utilizar `left + (right - left) / 2` em vez de `(left + right) / 2`.
2. **Busca de Limite Inferior (*Lower Bound*):** retornar o primeiro índice em que $\text{nums}[i] \ge \text{target}$, preservando a invariante de intervalo fechado `[left, right]` para que `left` aponte exatamente para a posição de inserção ao final do laço.
3. **Arrays Rotacionados:** em qualquer partição `[left..right]` de um array ordenado rotacionado sem duplicatas, ao menos uma das metades (`[left..mid]` ou `[mid..right]`) permanece ordenada, permitindo decidir qual lado descartar em $O(1)$.

---

## Problemas

| Problema | Dificuldade | Variante |
|---|---|---|
| [0704 - Binary Search](./0704-binary-search/README.md) | Fácil | Busca Binária Exata em Intervalo Fechado |
| [0035 - Search Insert Position](./0035-search-insert-position/README.md) | Fácil | Busca Binária *Lower Bound* |
| [0033 - Search in Rotated Sorted Array](./0033-search-in-rotated-sorted-array/README.md) | Intermediário | Identificação de Metade Ordenada em Array Rotacionado |
