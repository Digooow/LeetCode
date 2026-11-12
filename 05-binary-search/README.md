# 05 · Binary Search (Algoritmo de Busca Binária e Redução Logarítmica)

## Qual é o nome correto desse conceito?

**Binary Search (Busca Binária)** é um **Algoritmo Clássico (*Search Algorithm*)** baseado no paradigma de **Divisão e Conquista (*Divide and Conquer*)** (mais especificamente *Decrease and Conquer*).

Ele opera sobre qualquer espaço de busca que possua uma **propriedade monotônica**: se conseguimos descartar metade do espaço de busca a cada comparação, reduzimos o número de operações de $O(n)$ para **$O(\log_2 n)$** (para $n = 1.000.000.000$, $\log_2 n \approx 30$ passos!).

Três detalhes que diferenciam candidatos seniores ao implementar Busca Binária:
1. **Prevenção de *Integer Overflow* no cálculo do meio:** Sempre calcule `mid = left + (right - left) / 2` em vez de `(left + right) / 2`.
2. **Busca de Limite Inferior (*Lower Bound*):** Encontrar o primeiro índice $i$ tal que $\text{nums}[i] \ge \text{target}$ (equivalente a `std::lower_bound`).
3. **Busca Binária em Array Parcialmente Ordenado (Rotacionado):** Mesmo quando um array ordenado sofreu rotação, **pelo menos uma das duas metades (`[left..mid]` ou `[mid..right]`) continua estritamente ordenada**, permitindo decidir qual metade descartar em $O(1)$.

---

## Problemas nesta pasta

| Problema | Dificuldade | Variante de Busca Binária |
|---|---|---|
| [0704 - Binary Search](./0704-binary-search/README.md) | Fácil | Busca Binária Exata Clássica |
| [0035 - Search Insert Position](./0035-search-insert-position/README.md) | Fácil | Busca Binária *Lower Bound* |
| [0033 - Search in Rotated Sorted Array](./0033-search-in-rotated-sorted-array/README.md) | Intermediário | Busca Binária por Identificação de Metade Ordenada |
