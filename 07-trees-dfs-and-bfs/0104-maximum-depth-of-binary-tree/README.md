# 0104 · Maximum Depth of Binary Tree

**Dificuldade:** Fácil | **Categoria:** Trees (DFS & BFS) | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada a raiz `root` de uma árvore binária, retornar a profundidade máxima (número de nós ao longo do caminho mais longo da raiz até a folha mais distante).

## Abordagem

A profundidade de qualquer subárvore segue a definição recursiva: uma árvore vazia possui profundidade `0`, e uma árvore não vazia possui profundidade `1 + std::max(maxDepth(root->left), maxDepth(root->right))`.

`maxDepth` calcula as alturas das subárvores esquerda e direita em pós-ordem (*bottom-up*) e retorna o maior caminho acrescentado da raiz corrente.

## Complexidade

- **Tempo:** $O(n)$ — cada um dos $n$ nós é visitado exatamente uma vez.
- **Espaço:** $O(h)$ — espaço de pilha da recursão proporcional à altura $h$ da árvore ($O(\log n)$ no caso balanceado, $O(n)$ no pior caso linear).
