# 10 · Bit Manipulation (Manipulação de Bits)

## Técnicas Principais

Operações diretas sobre a representação binária dos inteiros com operadores bit a bit (`^`, `&`, `|`, `~`, `<<`, `>>`):

1. **Cancelamento Algébrico por XOR (`^`):**
   - A operação ou-exclusivo é comutativa ($a \oplus b = b \oplus a$), associativa, tem elemento neutro zero ($a \oplus 0 = a$) e propriedade auto-inversa ($a \oplus a = 0$).
   - Acumular `^` em uma sequência onde apenas um valor possui multiplicidade ímpar elimina todos os pares em $O(n)$ tempo e $O(1)$ espaço.
2. **Algoritmo de Brian Kernighan (`n & (n - 1)`):**
   - Subtrair `1` de um inteiro binário inverte todos os bits do bit `1` menos significativo até a posição `0`. Logo, `n &= (n - 1)` limpa exatamente o bit `1` mais à direita em $O(1)$, fazendo o laço executar apenas $k$ vezes para $k$ bits ativos (*Hamming Weight*).

---

## Problemas

| Problema | Dificuldade | Técnica |
|---|---|---|
| [0136 - Single Number](./0136-single-number/README.md) | Fácil | Cancelamento Algébrico com XOR (`a ^ a = 0`) |
| [0191 - Number of 1 Bits](./0191-number-of-1-bits/README.md) | Fácil | Algoritmo de Brian Kernighan (`n &= (n - 1)`) |
