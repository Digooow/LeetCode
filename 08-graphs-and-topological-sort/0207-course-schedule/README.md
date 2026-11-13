# 0207 · Course Schedule

**Dificuldade:** Intermediário | **Categoria:** Graphs & Topological Sort | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um total `numCourses` de disciplinas (`0` a `numCourses - 1`) e uma lista de pares `prerequisites` onde `[course, prereq]` indica que `prereq` deve preceder `course`, determinar se é possível concluir todas as disciplinas.

## Abordagem

O problema modela a detecção de ciclo em um grafo direcionado: é possível concluir todos os cursos se e somente se o grafo for um **DAG** (*Directed Acyclic Graph*). Em `canFinish`, aplica-se a **Ordenação Topológica via Algoritmo de Kahn (BFS por grau de entrada)**:

1. Constrói-se a lista de adjacência `adj[prereq].push_back(course)` e contabiliza-se o grau de entrada `inDegree[course]` para cada vértice.
2. Todos os cursos sem dependências pendentes (`inDegree[i] == 0`) entram na fila `ready`.
3. Enquanto `ready` não estiver vazia:
   - Extrai `curr` e incrementa `completed`.
   - Para cada dependente `nextCourse` em `adj[curr]`, decrementa `--inDegree[nextCourse]`; ao atingir `0`, enfileira `nextCourse`.
4. Retorna `completed == numCourses`. Caso haja dependências cíclicas, os vértices do ciclo nunca atingem grau zero e `completed` permanece estritamente menor que `numCourses`.

## Complexidade

- **Tempo:** $O(V + E)$ — onde $V = \text{numCourses}$ e $E = |\text{prerequisites}|$; cada vértice e cada aresta direcionada são processados uma única vez.
- **Espaço:** $O(V + E)$ — armazenamento da lista de adjacência `adj`, do vetor `inDegree` e da fila `ready`.
