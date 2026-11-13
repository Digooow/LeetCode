# 0136 · Single Number

**Dificuldade:** Fácil | **Categoria:** Bit Manipulation | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor não vazio de inteiros `nums` em que todos os elementos aparecem exatamente duas vezes exceto um único elemento isolado, encontrá-lo em tempo $O(n)$ e espaço auxiliar $O(1)$.

## Abordagem

`singleNumber` acumula o operador ou-exclusivo (`^`) sobre todos os elementos em `xorSum`:

- Identidade: $x \oplus 0 = x$
- Auto-inversão: $x \oplus x = 0$
- Comutatividade e associatividade: a ordem dos elementos não altera o resultado final.

Todos os pares idênticos anulam-se mutuamente para zero, restando em `xorSum` apenas o inteiro de frequência ímpar.

## Complexidade

- **Tempo:** $O(n)$ — travessia linear única aplicando uma operação bit a bit por elemento.
- **Espaço:** $O(1)$ — apenas o acumulador inteiro `xorSum`.
