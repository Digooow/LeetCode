# 04 · Stack & Monotonic Stack (Pilhas LIFO e Pilha Monotônica)

## Estruturas e Padrões

1. **Pilha (*Stack* — LIFO: *Last-In, First-Out*):**
   - Coleção linear em que inserções (`push`) e remoções (`pop`) ocorrem exclusivamente no topo em tempo constante $O(1)$.
   - Adequada para validação de estruturas aninhadas (parênteses, delimitadores, expressões), pois o último bloco aberto deve ser o primeiro fechado.
2. **Pilha Monotônica (*Monotonic Stack*):**
   - Mantém os elementos armazenados (ou seus índices) em ordem monotonicamente crescente ou decrescente da base ao topo.
   - Sempre que um novo valor viola a ordem monotônica, os elementos anteriores pendentes no topo são desempilhados e resolvidos em tempo amortizado $O(1)$ por item, garantindo complexidade total **$O(n)$** para consultas do tipo *Next Greater / Smaller Element*.

---

## Problemas

| Problema | Dificuldade | Padrão Principal |
|---|---|---|
| [0020 - Valid Parentheses](./0020-valid-parentheses/README.md) | Fácil | Pilha LIFO para Validação de Delimitadores Aninhados |
| [0739 - Daily Temperatures](./0739-daily-temperatures/README.md) | Intermediário | Pilha Monotônica Decrescente (*Next Greater Element*) |
