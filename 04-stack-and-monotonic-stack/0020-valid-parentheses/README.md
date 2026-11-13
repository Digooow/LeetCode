# 0020 · Valid Parentheses

**Dificuldade:** Fácil | **Categoria:** Stack & Monotonic Stack | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada uma string `s` contendo apenas os caracteres `'('`, `')'`, `'{'`, `'}'`, `'['` e `']'`, determinar se a sequência de delimitadores é válida quanto à ordem de abertura e fechamento.

## Abordagem

Em `isValid`, utiliza-se uma `std::stack<char>` (`expected`) para registrar o caractere de fechamento esperado para cada abertura encontrada:

1. Ao ler `'('`, `'['` ou `'{'`, empilha-se respectivamente `')'`, `']'` ou `'}'` em `expected`.
2. Ao ler um delimitador de fechamento `c`, verifica-se se `expected` não está vazia e se `expected.top() == c`; em caso negativo, retorna `false` imediatamente. Caso coincida, executa-se `expected.pop()`.
3. Ao término da string, retorna `expected.empty()` para garantir que nenhum delimitador aberto ficou sem fechamento.

Empilhar diretamente o símbolo de fechamento simplifica o ramo de validação, dispensando um mapa ou tabela auxiliar de pares.

## Complexidade

- **Tempo:** $O(n)$ — cada caractere é empilhado e desempilhado no máximo uma vez.
- **Espaço:** $O(n)$ — profundidade máxima da pilha `expected` quando todos os caracteres iniciais são aberturas.
