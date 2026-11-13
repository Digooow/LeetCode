# 0191 · Number of 1 Bits

**Dificuldade:** Fácil | **Categoria:** Bit Manipulation | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um inteiro positivo sem sinal `n` de 32 bits (`std::uint32_t`), retornar o número de bits iguais a `1` presentes em sua representação binária (*Hamming Weight*).

## Abordagem

Em vez de deslocar todos os 32 bits com máscara fixa, `hammingWeight` utiliza o algoritmo de Brian Kernighan:

- A expressão `n & (n - 1)` limpa especificamente o bit `1` menos significativo de `n`.
- Em um laço `while (n != 0)`, aplica-se `n &= (n - 1)` e incrementa-se `count`.

Dessa forma, o número de iterações coincide exatamente com a quantidade de bits `1` ativos no inteiro de entrada.

## Complexidade

- **Tempo:** $O(k)$ — onde $k$ é o número de bits `1` em `n` ($k \le 32$, portanto $O(1)$ para inteiros de largura fixa).
- **Espaço:** $O(1)$ — apenas o contador inteiro `count`.
