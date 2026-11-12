# 09 · Dynamic Programming & Greedy (Programação Dinâmica e Algoritmos Gulosos)

## Qual é o nome correto desse conceito?

Tanto **Dynamic Programming (Programação Dinâmica)** quanto **Greedy (Algoritmos Gulosos)** são **Paradigmas de Projeto de Algoritmos (*Algorithm Design Paradigms*)**:

1. **Programação Dinâmica (*Dynamic Programming — DP*):**
   - Aplica-se quando um problema possui duas propriedades simultâneas:
     1. **Subestrutura Ótima (*Optimal Substructure*):** A solução ótima do problema maior pode ser construída a partir das soluções ótimas de subproblemas menores.
     2. **Subproblemas Sobrepostos (*Overlapping Subproblems*):** Uma recursão ingênua recalcularia os mesmos estados repetidas vezes em tempo exponencial $O(2^n)$.
   - Ao armazenar os resultados intermediários em uma tabela (**Tabulação *Bottom-Up***) ou variáveis de estado comprimidas, reduzimos a complexidade de exponencial $O(2^n)$ para polinomial $O(n)$ ou $O(n \cdot W)$.
2. **Algoritmos Gulosos (*Greedy Algorithms*):**
   - Aplica-se quando fazer a escolha localmente ótima a cada etapa (como no **Algoritmo de Kadane** ou após ordenar intervalos em **Merge Intervals**) leva garantidamente ao ótimo global.

---

## Problemas nesta pasta

| Problema | Dificuldade | Paradigma / Padrão Principal |
|---|---|---|
| [0070 - Climbing Stairs](./0070-climbing-stairs/README.md) | Fácil | Programação Dinâmica 1D com Otimização de Espaço $O(1)$ |
| [0053 - Maximum Subarray](./0053-maximum-subarray/README.md) | Intermediário | Algoritmo de Kadane (DP 1D / Reinício Guloso de Prefixo) |
| [0322 - Coin Change](./0322-coin-change/README.md) | Intermediário | Programação Dinâmica *Bottom-Up* (*Unbounded Knapsack*) |
| [0056 - Merge Intervals](./0056-merge-intervals/README.md) | Intermediário | Algoritmo Guloso com Ordenação de Intervalos (*Interval Sweep*) |
