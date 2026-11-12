# 07 · Binary Trees, DFS & BFS (Árvores Binárias e Buscas em Profundidade/Largura)

## Qual é o nome correto desse conceito?

1. **Estrutura de Dados: Árvore Binária (*Binary Tree*)**
   - Uma estrutura de dados hierárquica recursiva onde cada nó possui um valor e no máximo duas subárvores filhas (`left` e `right`).
2. **Algoritmos de Travessia (*Tree Traversal Algorithms*):**
   - **DFS (*Depth-First Search* / Busca em Profundidade):** Explora um ramo até as folhas antes de retroceder (*Backtrack*), utilizando a pilha de chamadas da recursão (ou uma `std::stack` explícita). Subdivide-se em:
     - **Pré-Ordem (*Pre-order*):** `Raiz -> Esquerda -> Direita` (ideal para clonar/serializar ou propagar informações de cima para baixo, *Top-Down*).
     - **Em-Ordem (*In-order*):** `Esquerda -> Raiz -> Direita` (em uma *Binary Search Tree - BST*, visita os elementos em ordem crescente).
     - **Pós-Ordem (*Post-order*):** `Esquerda -> Direita -> Raiz` (ideal quando o pai precisa combinar as respostas já calculadas dos filhos, *Bottom-Up*, como altura e diâmetro).
   - **BFS (*Breadth-First Search* / Busca em Largura / Travessia por Nível):** Visita a árvore andar por andar usando uma fila FIFO (`std::queue`).

---

## Problemas nesta pasta

| Problema | Dificuldade | Conceito / Algoritmo Principal |
|---|---|---|
| [0226 - Invert Binary Tree](./0226-invert-binary-tree/README.md) | Fácil | Recursão Estrutural (DFS Pré/Pós-Ordem) |
| [0104 - Maximum Depth of Binary Tree](./0104-maximum-depth-of-binary-tree/README.md) | Fácil | Divisão e Conquista *Bottom-Up* em Árvore |
| [0543 - Diameter of Binary Tree](./0543-diameter-of-binary-tree/README.md) | Fácil | DFS *Post-Order* com Acumulador Global de Caminho |
