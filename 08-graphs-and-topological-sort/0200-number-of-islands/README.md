# 200. Number of Islands

- **Nível:** Intermediário ([LeetCode #200](https://leetcode.com/problems/number-of-islands/))
- **Classificação do Conceito:**
  - **Conceito de Teoria dos Grafos:** *Connected Components Counting* (Contagem de Componentes Conexos)
  - **Algoritmo:** *In-Place Grid DFS Sink* (Busca em Profundidade com Marcação *In-Place*)

---

## 1. O que é esse conceito?

Cada "ilha" nada mais é do que um **Componente Conexo (*Connected Component*)** de vértices `'1'` em um grafo em grade 2D.

Para contar quantos componentes conexos existem sem gastar memória extra com matriz `visited[][]`:
1. Varremos todas as coordenadas `(r, c)` da matriz.
2. Sempre que encontramos `'1'`, descobrimos uma **nova ilha** (`++islands`) e disparamos uma DFS/BFS que "afunda" toda a ilha trocando cada `'1'` alcançável por `'0'`. Assim, nenhuma parte daquela mesma ilha será contada duas vezes.

---

## 2. Complexidade

- **Tempo:** $O(R \times C)$ — cada célula é visitada um número constante de vezes.
- **Espaço Auxiliar:** $O(R \times C)$ no pior caso na pilha de recursão (quando a grade inteira é terra em formato de espiral).
