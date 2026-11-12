# 733. Flood Fill

- **Nível:** Fácil ([LeetCode #733](https://leetcode.com/problems/flood-fill/))
- **Classificação do Conceito:**
  - **Algoritmo:** *Flood Fill via Grid DFS* (Preenchimento por Inundação em Grafo de Matriz 2D)

---

## 1. O que é esse conceito?

O algoritmo **Flood Fill** (o famoso "balde de tinta" de editores gráficos) modela uma matriz 2D como um **grafo implícito**, onde cada pixel `(r, c)` tem até 4 arestas (cima, baixo, esquerda, direita) conectando-o a pixels adjacentes de mesma cor inicial (`originalColor`).

Um detalhe crucial de borda (*edge case*): se `image[sr][sc] == color` (a nova cor já é idêntica à cor original), devemos retornar imediatamente; caso contrário, a recursão entraria em loop infinito entre dois pixels vizinhos!

---

## 2. Complexidade

- **Tempo:** $O(R \times C)$, onde $R$ é o número de linhas e $C$ o número de colunas (cada célula é pintada no máximo uma vez).
- **Espaço:** $O(R \times C)$ no pior caso na pilha de chamadas da DFS.
