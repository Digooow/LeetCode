# 04 · Stack & Monotonic Stack (Pilhas LIFO e Pilha Monotônica)

## Qual é o nome correto desse conceito?

Aqui temos uma **Estrutura de Dados** clássica e um **Padrão Algorítmico** derivado dela:

1. **Estrutura de Dados: Pilha (*Stack* — LIFO: *Last-In, First-Out*)**
   - Uma coleção linear onde inserções (`push`) e remoções (`pop`) ocorrem exclusivamente no topo, em $O(1)$.
   - É a estrutura natural para validar **gramáticas aninhadas** (parênteses, tags HTML/XML, expressões aritméticas) porque o último símbolo aberto precisa ser obrigatoriamente o primeiro a ser fechado.
2. **Padrão Algorítmico: Pilha Monotônica (*Monotonic Stack*)**
   - Uma pilha que mantém seus elementos sempre ordenados (estritamente crescentes ou decrescentes da base ao topo).
   - Quando um novo elemento quebra a monotonicidade, desempilhamos todos os elementos menores (ou maiores) que estavam aguardando uma resposta.
   - É o padrão padrão-ouro para resolver qualquer variação de **Next Greater Element (Próximo Elemento Maior)** ou **Next Smaller Element** em **$O(n)$** (em vez de $O(n^2)$).

---

## Problemas nesta pasta

| Problema | Dificuldade | Conceito / Padrão Principal |
|---|---|---|
| [0020 - Valid Parentheses](./0020-valid-parentheses/README.md) | Fácil | Pilha LIFO para Validação de Delimitadores Aninhados |
| [0739 - Daily Temperatures](./0739-daily-temperatures/README.md) | Intermediário | Pilha Monotônica Decrescente (*Next Greater Element*) |
