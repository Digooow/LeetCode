# 20. Valid Parentheses

- **Nível:** Fácil ([LeetCode #20](https://leetcode.com/problems/valid-parentheses/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** Pilha (*LIFO Stack* — `std::stack<char>`)
  - **Conceito Teórico:** Reconhecimento de Linguagem Livre de Contexto (Gramática de Dyck)

---

## 1. O que é esse conceito?

Quando abrimos delimitadores aninhados como `({[]})`, o delimitador aberto **mais recentemente** (`[`) deve ser fechado **primeiro** (`]`). Essa propriedade de inversão de ordem (*Last-In, First-Out*) é exatamente a definição de uma **Pilha (*Stack*)**.

Um truque elegante de implementação: ao ler um caractere de abertura (`(`, `[`, `{`), empilhamos diretamente o **caractere de fechamento esperado** (`)`, `]`, `}`). Assim, quando lemos um fechamento, basta verificar se ele é igual a `st.top()`.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Criamos `std::stack<char> expected`.
2. Para cada caractere `c` em `s`:
   - Se `c == '('`, fazemos `expected.push(')')`.
   - Se `c == '['`, fazemos `expected.push(']')`.
   - Se `c == '{'`, fazemos `expected.push('}')`.
   - Caso contrário (é um fechamento):
     - Se `expected.empty()` ou `expected.top() != c`, a string é inválida (`return false`).
     - Fazemos `expected.pop()`.
3. Ao final, retornamos `expected.empty()` (garantindo que nenhum delimitador ficou aberto).

---

## 3. Complexidade

- **Tempo:** $O(n)$ — cada caractere é empilhado e desempilhado no máximo uma vez.
- **Espaço:** $O(n)$ — no pior caso (ex.: `"(((((("`), a pilha armazena $n$ caracteres.
