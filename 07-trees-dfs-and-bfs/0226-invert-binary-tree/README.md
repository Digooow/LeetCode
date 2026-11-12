# 226. Invert Binary Tree

- **Nível:** Fácil ([LeetCode #226](https://leetcode.com/problems/invert-binary-tree/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** Árvore Binária (*Binary Tree*)
  - **Algoritmo:** *Recursive Depth-First Search (DFS)* (Busca em Profundidade Recursiva)

---

## 1. O que é esse conceito?

Inverter (espelhar) uma árvore binária significa trocar as subárvores esquerda e direita de **todos** os nós da árvore. Como uma árvore binária possui definição indutiva/recursiva, aplicamos **Recursão Estrutural**:
- **Caso base:** Se `root == nullptr`, retornamos `nullptr`.
- **Passo indutivo:** Trocamos `std::swap(root->left, root->right)` e invertemos recursivamente `root->left` e `root->right`.

---

## 2. Complexidade

- **Tempo:** $O(n)$, onde $n$ é o número de nós da árvore (cada nó é visitado uma única vez).
- **Espaço:** $O(h)$, onde $h$ é a altura da árvore (profundidade máxima da pilha de recursão: $O(\log n)$ em árvore balanceada e $O(n)$ em árvore degenerada).
