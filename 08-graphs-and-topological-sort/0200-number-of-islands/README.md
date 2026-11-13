# 0200 · Number of Islands

**Dificuldade:** Intermediário | **Categoria:** Graphs & Topological Sort | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada uma matriz binária `grid` de dimensões $M \times N$ onde `'1'` representa terra e `'0'` representa água, retornar a quantidade de ilhas (componentes conexos de `'1'` conectados ortogonalmente nas 4 direções).

## Abordagem

O algoritmo trata `grid` como um grafo implícito não direcionado e contabiliza seus componentes conexos em `numIslands`:

1. Valida entrada vazia (`grid.empty() || grid[0].empty()`).
2. Percorre cada célula `(r, c)`. Sempre que encontra `grid[r][c] == '1'`, incrementa `islands` e dispara `sinkIsland(grid, r, c)`.
3. O DFS `sinkIsland` verifica limites e se a célula contém `'1'`, marca `grid[r][c] = '0'` e propaga recursivamente aos 4 vizinhos ortogonais.

Como `numIslands` recebe `grid` por valor, a marcação *in-place* evita alocar uma matriz booleana `visited` adicional sem modificar o vetor original do chamador caso reutilizado externamente.

## Complexidade

- **Tempo:** $O(M \cdot N)$ — cada célula é visitada uma vez na varredura externa e marcada como `'0'` no máximo uma vez pelo DFS.
- **Espaço:** $O(M \cdot N)$ — considerando a cópia local do parâmetro `grid` e o pior caso de profundidade da pilha de recursão quando toda a grade forma uma única ilha.
