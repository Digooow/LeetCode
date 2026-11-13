# 07 · Binary Trees, DFS & BFS (Árvores Binárias)

## Estruturas e Algoritmos

1. **Árvore Binária (*Binary Tree*):**
   - Estrutura hierárquica recursiva na qual cada nó armazena um valor (`val`) e referências para até duas subárvores (`left` e `right`).
2. **Estratégias de Travessia:**
   - **DFS (*Depth-First Search* — Busca em Profundidade):** explora cada ramo até os nós folha antes de retroceder, utilizando a pilha de chamadas recursivas ou uma `std::stack` explícita.
     - **Pré-Ordem (*Pre-order*):** `Raiz -> Esquerda -> Direita`, útil quando decisões ocorrem de cima para baixo (*top-down*).
     - **Em-Ordem (*In-order*):** `Esquerda -> Raiz -> Direita`, produzindo sequência crescente em *Binary Search Trees (BST)*.
     - **Pós-Ordem (*Post-order*):** `Esquerda -> Direita -> Raiz`, adequada para agregação de métricas *bottom-up* (altura, diâmetro, balanço).
   - **BFS (*Breadth-First Search* — Busca em Largura):** percorre nível por nível utilizando uma fila FIFO (`std::queue`).

---

## Problemas

| Problema | Dificuldade | Padrão Principal |
|---|---|---|
| [0100 - Same Tree](./0100-same-tree/README.md) | Fácil | Comparação Recursiva Simétrica (DFS) |
| [0104 - Maximum Depth of Binary Tree](./0104-maximum-depth-of-binary-tree/README.md) | Fácil | Divisão e Conquista *Bottom-Up* |
| [0226 - Invert Binary Tree](./0226-invert-binary-tree/README.md) | Fácil | Recursão Estrutural em Árvore (DFS) |
| [0543 - Diameter of Binary Tree](./0543-diameter-of-binary-tree/README.md) | Fácil | DFS *Post-Order* com Acumulador Global |
