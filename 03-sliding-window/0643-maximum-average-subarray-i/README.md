# 0643 · Maximum Average Subarray I

**Dificuldade:** Fácil | **Categoria:** Sliding Window | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros `nums` e um inteiro `k`, encontrar o subarray contíguo de comprimento exato `k` cujo valor médio seja máximo e retornar essa média em ponto flutuante (`double`).

## Abordagem

Como `k` é constante durante toda a execução, maximizar a média $\frac{\text{soma}}{k}$ equivale a maximizar a soma da janela de tamanho fixo `k`.

Em `findMaxAverage`:
1. Calcula-se a soma inicial dos primeiros `k` elementos em `windowSum` (tipado como `long long` para prevenir *overflow* caso $k \cdot \max(|\text{nums}[i]|)$ exceda 32 bits).
2. De `i = k` até `nums.size() - 1`, a janela desliza em $O(1)$ somando o novo elemento e subtraindo o elemento que saiu da extremidade esquerda: `windowSum += nums[i] - nums[i - k]`.
3. Mantém-se o máximo em `maxSum` e a divisão por `k` ocorre apenas uma vez no retorno (`static_cast<double>(maxSum) / k`).

## Complexidade

- **Tempo:** $O(n)$ — cada elemento entra e sai da janela no máximo uma vez.
- **Espaço:** $O(1)$ — apenas os acumuladores `windowSum` e `maxSum`.
