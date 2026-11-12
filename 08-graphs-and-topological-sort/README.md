# 08 · Graphs, Grid Traversal & Topological Sort (Grafos, Componentes Conexos e Ordenação Topológica)

## Qual é o nome correto desse conceito?

1. **Estrutura de Dados: Grafo (*Graph* — $G = (V, E)$)**
   - Conjunto de vértices $V$ conectados por arestas $E$ (direcionadas ou não direcionadas).
   - Em entrevistas, grafos aparecem sob duas representações principais:
     - **Grafo Implícito em Matriz 2D (*Grid Graph*):** Cada célula `(r, c)` é um vértice conectado aos seus 4 vizinhos ortogonais (`(r+1,c)`, `(r-1,c)`, `(r,c+1)`, `(r,c-1)`).
     - **Lista de Adjacência (*Adjacency List* — `std::vector<std::vector<int>>`):** Cada vértice $u$ guarda a lista de vértices $v$ para os quais há uma aresta $u \to v$.
2. **Algoritmos Clássicos em Grafos:**
   - **Flood Fill & Contagem de Componentes Conexos (*Connected Components via DFS/BFS*):** Explorar todas as células alcançáveis de mesma cor/valor marcando-as como visitadas para não entrar em loop infinito.
   - **Ordenação Topológica — Algoritmo de Kahn (*Kahn's Topological Sort via In-Degree BFS*):** Resolve problemas de **dependência de tarefas** (*Course Schedule*, *Build Systems*, *DAG Schedulers*). Mantém o grau de entrada (`inDegree`) de cada vértice e processa em fila todos os vértices com `inDegree == 0`. Se ao final nem todos os vértices foram processados, existe um **ciclo direcionado (*Deadlock*)**!

---

## Problemas nesta pasta

| Problema | Dificuldade | Conceito / Algoritmo Principal |
|---|---|---|
| [0733 - Flood Fill](./0733-flood-fill/README.md) | Fácil | Busca em Profundidade (DFS) em Grafo Implícito 2D (*Grid*) |
| [0200 - Number of Islands](./0200-number-of-islands/README.md) | Intermediário | Contagem de Componentes Conexos via *Grid DFS* |
| [0207 - Course Schedule](./0207-course-schedule/README.md) | Intermediário | Ordenação Topológica (Algoritmo de Kahn) / Detecção de Ciclo em DAG |
