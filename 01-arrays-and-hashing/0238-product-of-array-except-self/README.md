# 0238 · Product of Array Except Self

**Dificuldade:** Intermediário | **Categoria:** Arrays & Hashing | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros `nums`, retornar um vetor `answer` em que `answer[i]` seja igual ao produto de todos os elementos de `nums` exceto `nums[i]`, em tempo $O(n)$ e **sem usar a operação de divisão**.

## Abordagem

A exclusão de divisão é necessária porque `nums` pode conter zeros (impossibilitando dividir o produto total por `nums[i]`). O produto desejado em cada posição $i$ decompõe-se como:

$$\text{answer}[i] = \left(\prod_{j=0}^{i-1} \text{nums}[j]\right) \times \left(\prod_{j=i+1}^{n-1} \text{nums}[j]\right)$$

Em `productExceptSelf`, esse cálculo ocorre diretamente sobre o vetor de retorno `answer`:
1. **Passagem de prefixo (esquerda para direita):** grava o acumulado `prefix` em `answer[i]` antes de multiplicar `prefix *= nums[i]`.
2. **Passagem de sufixo (direita para esquerda):** multiplica `answer[i] *= suffix` e atualiza `suffix *= nums[i]`.

## Complexidade

- **Tempo:** $O(n)$ — duas travessias lineares independentes pelo vetor `nums`.
- **Espaço:** $O(1)$ auxiliar — apenas os acumuladores escalares `prefix` e `suffix`, reutilizando `answer` (alocação exigida pela saída) para armazenar os prefixos parciais.
