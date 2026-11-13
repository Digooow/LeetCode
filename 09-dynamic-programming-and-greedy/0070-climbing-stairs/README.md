# 0070 · Climbing Stairs

**Dificuldade:** Fácil | **Categoria:** Dynamic Programming & Greedy | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um número `n` de degraus de uma escada, onde é possível subir `1` ou `2` degraus por passo, calcular quantas maneiras distintas existem para alcançar o topo.

## Abordagem

O degrau `step` só pode ser atingido diretamente a partir de `step - 1` ou `step - 2`, resultando na relação de recorrência $f(n) = f(n - 1) + f(n - 2)$ com casos base $f(1) = 1$ e $f(2) = 2$.

Em vez de alocar um vetor DP de tamanho $n + 1$, `climbStairs` trata `n <= 2` diretamente e utiliza compressão de estado para $O(1)$ de memória com duas variáveis deslizantes (`prev2 = 1`, `prev1 = 2`), iterando de `step = 3` até `n`.

## Complexidade

- **Tempo:** $O(n)$ — cálculo iterativo linear sem recomputação exponencial.
- **Espaço:** $O(1)$ — apenas as variáveis escalares `prev2`, `prev1` e `current`.
