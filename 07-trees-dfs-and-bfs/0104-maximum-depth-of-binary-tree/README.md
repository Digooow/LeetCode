# 104. Maximum Depth of Binary Tree

- **Nível:** Fácil ([LeetCode #104](https://leetcode.com/problems/maximum-depth-of-binary-tree/))
- **Classificação do Conceito:**
  - **Algoritmo:** *Post-Order DFS (Bottom-Up Tree Recursion)* (Busca em Profundidade Pós-Ordem)

---

## 1. O que é esse conceito?

A profundidade máxima de uma árvore enraizada em `root` obedece à relação de recorrência:

$$\text{depth}(\text{root}) = \begin{cases} 0, & \text{se } \text{root} = \text{nullptr} \\ 1 + \max\big(\text{depth}(\text{root}\to\text{left}),\ \text{depth}(\text{root}\to\text{right})\big), & \text{caso contrário} \end{cases}$$

Essa abordagem é chamada de **DFS Pós-Ordem (*Bottom-Up*)**: primeiro descemos até as folhas, calculamos a altura da subárvore esquerda e da subárvore direita, e só então combinamos os resultados no nó pai somando `1`.

---

## 2. Complexidade

- **Tempo:** $O(n)$ — visita cada nó exatamente uma vez.
- **Espaço:** $O(h)$ — espaço na pilha de chamadas proporcional à altura $h$ da árvore.
