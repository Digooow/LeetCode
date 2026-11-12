# 207. Course Schedule

- **Nível:** Intermediário ([LeetCode #207](https://leetcode.com/problems/course-schedule/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** Grafo Direcionado (*Directed Graph* — Lista de Adjacência)
  - **Algoritmo Clássico:** *Kahn's Topological Sort Algorithm* (Ordenação Topológica de Kahn / Detecção de Ciclo via Grau de Entrada)

---

## 1. O que é esse conceito?

Quando cursos (ou pacotes de software, migrations ou tarefas de um *pipeline*) possuem pré-requisitos `[a, b]` ("para cursar `a`, é preciso concluir `b` antes", isto é, uma aresta direcionada $b \to a$), só é possível concluir todos os cursos se o grafo for um **DAG (*Directed Acyclic Graph* — Grafo Direcionado Acíclico)**.

O **Algoritmo de Kahn (1962)** testa se um grafo direcionado é um DAG usando **Busca em Largura (BFS) guiada por Grau de Entrada (`inDegree`)**:
1. Calculamos `inDegree[u]` = quantos pré-requisitos pendentes o curso `u` possui.
2. Enfileiramos todos os cursos com `inDegree[u] == 0` (cursos que já podem ser feitos imediatamente).
3. Enquanto a fila não estiver vazia:
   - Retiramos `u`, incrementamos `++completedCourses` e, para cada curso dependente `v` em `adj[u]`, decrementamos `--inDegree[v]`.
   - Se `inDegree[v]` chegou a `0`, todos os pré-requisitos de `v` foram cumpridos $\rightarrow$ enfileiramos `v`.
4. Ao final, se `completedCourses == numCourses`, não há ciclo (`true`); caso contrário, existe um ciclo de dependência circular (`false`).

---

## 2. Complexidade

- **Tempo:** $O(V + E)$, onde $V = \text{numCourses}$ e $E = \text{prerequisites.size()}$.
- **Espaço:** $O(V + E)$ para armazenar a lista de adjacência e o vetor `inDegree`.
