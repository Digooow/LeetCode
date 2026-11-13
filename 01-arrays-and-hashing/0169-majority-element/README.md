# 0169 · Majority Element

**Dificuldade:** Fácil | **Categoria:** Arrays & Hashing | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor `nums` de tamanho $n$, retornar o elemento majoritário (aquele que ocorre estritamente mais de $\lfloor n / 2 \rfloor$ vezes). Assume-se que o elemento majoritário sempre existe.

## Abordagem

Embora uma tabela de frequências resolva em $O(n)$ espaço, `majorityElement` aplica o **Algoritmo de Votação de Boyer-Moore** para operar em espaço constante $O(1)$:

- Mantém-se um `candidate` atual e um saldo `count`.
- Quando `count == 0`, assume-se o elemento corrente `num` como novo `candidate`.
- Em seguida, incrementa-se `count` se `num == candidate` e decrementa-se caso contrário.

**Invariante:** cada ocorrência de um elemento diferente pode cancelar no máximo uma ocorrência do elemento majoritário. Como o majoritário possui mais de $n/2$ ocorrências, seu saldo líquido permanece positivo após todos os cancelamentos em par.

## Complexidade

- **Tempo:** $O(n)$ — passagem única sequencial pelo vetor `nums`.
- **Espaço:** $O(1)$ — apenas duas variáveis escalares (`candidate` e `count`).
