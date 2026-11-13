# 0733 · Flood Fill

**Dificuldade:** Fácil | **Categoria:** Graphs & Topological Sort | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada uma matriz inteira `image` representando pixels, uma coordenada inicial `(sr, sc)` e uma nova cor `color`, substituir a cor de todos os pixels conectados ortogonalmente ao ponto inicial que compartilhem sua cor original.

## Abordagem

Em `floodFill`, registra-se `originalColor = image[sr][sc]` e executa-se o DFS recursivo apenas quando `originalColor != color`:

- **Guarda contra loop infinito:** se `originalColor == color`, nenhuma alteração é necessária e o retorno imediato evita recursão infinita entre pixels já coloridos com o valor alvo.
- O auxiliar `dfs` verifica os limites da matriz e se `image[r][c] == originalColor`, atribui `newColor` e avança nos 4 vizinhos ortogonais.

## Complexidade

- **Tempo:** $O(M \cdot N)$ — no pior caso, todos os pixels da imagem $M \times N$ compartilham `originalColor` e são visitados uma vez.
- **Espaço:** $O(M \cdot N)$ — pilha de recursão no pior caso de preenchimento completo da grade (além da cópia do parâmetro `image`).
