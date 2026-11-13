# 0053 · Maximum Subarray

**Dificuldade:** Intermediário | **Categoria:** Dynamic Programming & Greedy | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros `nums` (contendo ao menos um elemento, podendo incluir valores negativos), encontrar o subarray contíguo não vazio com a maior soma possível e retornar essa soma.

## Abordagem

`maxSubArray` aplica o **Algoritmo de Kadane**, que mantém em passagem única a melhor soma terminando exatamente no índice atual (`currentSum`) e o máximo global observado (`maxSum`):

- Inicializa `currentSum = nums[0]` e `maxSum = nums[0]`.
- Para cada `i` de `1` até `nums.size() - 1`:
  - `currentSum = std::max(nums[i], currentSum + nums[i])` — caso a soma acumulada anterior seja negativa, estendê-la apenas reduziria o resultado; reinicia-se a subcadeia em `nums[i]`.
  - `maxSum = std::max(maxSum, currentSum)`.

## Complexidade

- **Tempo:** $O(n)$ — uma única travessia linear por `nums`.
- **Espaço:** $O(1)$ — apenas as variáveis `currentSum` e `maxSum`.
