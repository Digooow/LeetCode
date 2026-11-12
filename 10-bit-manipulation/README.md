# 10 · Bit Manipulation (Manipulação de Bits e Álgebra Booleana)

## Qual é o nome correto desse conceito?

**Bit Manipulation (Manipulação Bit a Bit / *Bitwise Algorithms*)** é uma **Técnica Algorítmica de Baixo Nível** que opera diretamente sobre a representação binária dos inteiros nos registradores da CPU usando operadores lógicos (`^` XOR, `&` AND, `|` OR, `~` NOT, `<<` e `>>` *Bit Shifts*).

Dois padrões clássicos de entrevista baseados em bits:
1. **Cancelamento por XOR (`^` — *Exclusive OR*):**
   - O operador XOR é comutativo ($a \oplus b = b \oplus a$), associativo, possui elemento neutro zero ($a \oplus 0 = a$) e **auto-inverso ($a \oplus a = 0$)**.
   - Portanto, aplicar XOR em todos os elementos de um array onde todos aparecem em pares exceto um cancela todos os pares em $O(n)$ tempo e $O(1)$ espaço!
2. **Truque de Brian Kernighan (`n & (n - 1)`):**
   - Subtrair `1` de um número binário inverte todos os bits desde o bit `1` menos significativo (*Lowest Set Bit*) até a direita. Logo, `n & (n - 1)` **apaga exatamente o bit `1` mais à direita** em $O(1)$.

---

## Problemas nesta pasta

| Problema | Dificuldade | Técnica de Manipulação de Bits |
|---|---|---|
| [0136 - Single Number](./0136-single-number/README.md) | Fácil | Cancelamento Algébrico com XOR (`a ^ a = 0`) |
| [0191 - Number of 1 Bits](./0191-number-of-1-bits/README.md) | Fácil | Algoritmo de Brian Kernighan (`n &= (n - 1)`) — *Hamming Weight* |
