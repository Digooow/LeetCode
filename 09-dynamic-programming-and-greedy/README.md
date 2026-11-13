# 09 · Dynamic Programming & Greedy (Programação Dinâmica e Algoritmos Gulosos)

## Paradigmas

1. **Programação Dinâmica (*Dynamic Programming — DP*):**
   - Aplicada a problemas que combinam **subestrutura ótima** (solução global construída a partir de subproblemas menores ótimos) e **subproblemas sobrepostos** (recomputação repetida em árvore recursiva ingênua).
   - A transição via **tabulação *bottom-up*** ou variáveis de estado comprimidas reduz o custo de exponencial $O(2^n)$ para polinomial ($O(n)$ ou $O(\text{amount} \cdot m)$).
2. **Algoritmos Gulosos (*Greedy*):**
   - Realizam escolhas localmente ótimas em cada passo (como o descarte de prefixo negativo no algoritmo de Kadane ou a varredura após ordenação em intervalos) quando a propriedade de escolha gulosa garante o ótimo global.

---

## Problemas

| Problema | Dificuldade | Paradigma / Padrão Principal |
|---|---|---|
| [0070 - Climbing Stairs](./0070-climbing-stairs/README.md) | Fácil | DP 1D com Compressão de Espaço $O(1)$ |
| [0053 - Maximum Subarray](./0053-maximum-subarray/README.md) | Intermediário | Algoritmo de Kadane (DP 1D / Escolha Gulosa) |
| [0322 - Coin Change](./0322-coin-change/README.md) | Intermediário | DP *Bottom-Up* (*Unbounded Knapsack*) |
| [0056 - Merge Intervals](./0056-merge-intervals/README.md) | Intermediário | Ordenação + Varredura Gulosa de Intervalos |
