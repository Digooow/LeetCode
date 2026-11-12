# 206. Reverse Linked List

- **Nível:** Fácil ([LeetCode #206](https://leetcode.com/problems/reverse-linked-list/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** Lista Simplesmente Encadeada (*Singly Linked List*)
  - **Padrão Algorítmico:** *Three-Pointer In-Place Reversal* (Inversão *In-Place* com Três Ponteiros)

---

## 1. O que é esse conceito?

Ao inverter `curr->next` para apontar para o nó anterior (`prev`), perderíamos a referência para o restante da lista se não salvarmos `curr->next` antes. Por isso usamos o invariante de **três ponteiros** (`prev`, `curr`, `nextTemp`):
1. `nextTemp = curr->next` (salva o futuro)
2. `curr->next = prev` (inverte a seta atual)
3. `prev = curr` e `curr = nextTemp` (avança a janela de inversão)

---

## 2. Explicação do Algoritmo Passo a Passo

Para `1 -> 2 -> 3 -> nullptr`:
- Início: `prev = nullptr`, `curr = 1`.
- Iteração 1: `1->next = nullptr`, `prev = 1`, `curr = 2`.
- Iteração 2: `2->next = 1`, `prev = 2`, `curr = 3`.
- Iteração 3: `3->next = 2`, `prev = 3`, `curr = nullptr`.
- Retorna `prev` (`3 -> 2 -> 1 -> nullptr`).

---

## 3. Complexidade

- **Tempo:** $O(n)$ — visita cada nó exatamente uma vez.
- **Espaço:** $O(1)$ — três ponteiros locais, sem alocação de novos nós.
