# 08 · Graphs, Grid Traversal & Topological Sort (Grafos)

## Estruturas e Algoritmos

1. **Representações de Grafos ($G = (V, E)$):**
   - **Grafo Implícito em Matriz 2D (*Grid Graph*):** cada célula `(r, c)` atua como vértice conectado aos até quatro vizinhos ortogonais.
   - **Lista de Adjacência (`std::vector<std::vector<int>>`):** cada vértice $u$ armazena a lista de destinos alcançáveis por arestas direcionadas ou não direcionadas $u \to v$.
2. **Algoritmos Principais:**
   - **Flood Fill & Componentes Conexos (DFS/BFS):** explora regiões conectadas marcando vértices visitados para garantir tempo linear $O(|V| + |E|)$ sem revisitas cíclicas.
   - **Ordenação Topológica de Kahn (*In-Degree BFS*):** resolve grafos de dependência mantendo o grau de entrada (`inDegree`) de cada vértice e processando em fila aqueles com `inDegree == 0`. Caso o total de nós processados ao término seja menor que $|V|$, o grafo contém ao menos um ciclo direcionado.

---

## Problemas

| Problema | Dificuldade | Algoritmo / Padrão Principal |
|---|---|---|
| [0733 - Flood Fill](./0733-flood-fill/README.md) | Fácil | DFS em Grafo Implícito 2D (*Grid*) |
| [0200 - Number of Islands](./0200-number-of-islands/README.md) | Intermediário | Contagem de Componentes Conexos via *Grid DFS* |
| [0207 - Course Schedule](./0207-course-schedule/README.md) | Intermediário | Ordenação Topológica (Kahn BFS) e Detecção de Ciclo |
