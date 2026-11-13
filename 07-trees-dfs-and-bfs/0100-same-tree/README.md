# 0100 · Same Tree

**Dificuldade:** Fácil | **Categoria:** Trees (DFS & BFS) | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dadas as raízes de duas árvores binárias `p` e `q`, verificar se ambas são estruturalmente idênticas e contêm os mesmos valores em todos os nós correspondentes.

## Abordagem

`isSameTree` aplica recursão estrutural simétrica (DFS) avaliando os pares de nós em três casos:

1. `p == nullptr && q == nullptr`: ambas as subárvores terminaram simultaneamente, portanto coincidem (`return true`).
2. `p == nullptr || q == nullptr || p->val != q->val`: divergência estrutural ou de valor (`return false`).
3. Caso contrário, ambas existem com o mesmo valor; verifica recursivamente `isSameTree(p->left, q->left) && isSameTree(p->right, q->right)`.

## Complexidade

- **Tempo:** $O(n)$ — onde $n$ é o número de nós da menor árvore visitada antes de qualquer divergência.
- **Espaço:** $O(h)$ — profundidade da pilha de recursão correspondente à altura $h$ da árvore ($O(\log n)$ balanceada, $O(n)$ degenerada).
