# 0226 · Invert Binary Tree

**Dificuldade:** Fácil | **Categoria:** Trees (DFS & BFS) | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada a raiz `root` de uma árvore binária, espelhar a árvore trocando os filhos esquerdo e direito em toda a estrutura e retornar a raiz.

## Abordagem

`invertTree` realiza um percurso DFS recursivo em pré-ordem:

1. Caso base: `root == nullptr` retorna `nullptr`.
2. Troca os ponteiros dos filhos diretos da raiz atual com `std::swap(root->left, root->right)`.
3. Aplica a inversão recursivamente sobre `root->left` e `root->right` e devolve `root`.

## Complexidade

- **Tempo:** $O(n)$ — exatamente uma visita e uma troca de ponteiros por nó.
- **Espaço:** $O(h)$ — profundidade máxima da pilha de recursão igual à altura $h$ da árvore ($O(n)$ no pior caso degenerado).
