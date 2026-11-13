# 0543 · Diameter of Binary Tree

**Dificuldade:** Fácil | **Categoria:** Trees (DFS & BFS) | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada a raiz `root` de uma árvore binária, retornar o comprimento do diâmetro da árvore — definido como o maior caminho (medido em **número de arestas**) entre quaisquer dois nós, passando ou não pela raiz principal.

## Abordagem

O maior caminho cujo nó mais alto é `node` possui comprimento `leftHeight + rightHeight`. Calcular a altura separadamente para cada nó resultaria em custo quadrático $O(n^2)$; para evitar chamadas redundantes, `diameterOfBinaryTree` delega o cálculo para `heightAndUpdate(node, maxDiameter)` em uma única travessia DFS pós-ordem (*bottom-up*):

1. Calcula recursivamente `leftHeight` e `rightHeight`.
2. Atualiza o estado compartilhado `maxDiameter = std::max(maxDiameter, leftHeight + rightHeight)`.
3. Retorna `1 + std::max(leftHeight, rightHeight)` ao nó pai como altura da subárvore atual.

## Complexidade

- **Tempo:** $O(n)$ — altura e diâmetro são computados em passagem única sobre os $n$ nós.
- **Espaço:** $O(h)$ — pilha de chamadas recursivas limitada pela altura $h$ da árvore.
