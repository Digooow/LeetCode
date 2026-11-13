# 0125 · Valid Palindrome

**Dificuldade:** Fácil | **Categoria:** Two Pointers | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada uma string `s`, verificar se ela é um palíndromo considerando apenas caracteres alfanuméricos e ignorando diferenças entre maiúsculas e minúsculas.

## Abordagem

Em vez de construir uma nova string filtrada em $O(n)$ de memória, `isPalindrome` verifica simetricamente *in-place* usando dois ponteiros convergentes (`left` e `right`):

1. Laços internos avançam `++left` e recuam `--right` enquanto o caractere corrente não for alfanumérico.
2. Os caracteres válidos nas duas extremidades são convertidos para minúsculo e comparados; na primeira divergência, retorna `false`.
3. Se todos os pares válidos coincidirem até `left >= right`, retorna `true`.

**Nota de segurança em C++:** todos os argumentos de `std::isalnum` e `std::tolower` recebem `static_cast<unsigned char>(...)`, evitando comportamento indefinido caso um `char` com sinal seja negativo em entradas fora da faixa ASCII básica.

## Complexidade

- **Tempo:** $O(n)$ — cada caractere da string é inspecionado no máximo uma vez.
- **Espaço:** $O(1)$ — comparação direta sobre a string de entrada, sem alocações adicionais.
