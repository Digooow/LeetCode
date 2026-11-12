# 21. Merge Two Sorted Lists

- **Nível:** Fácil ([LeetCode #21](https://leetcode.com/problems/merge-two-sorted-lists/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Two-Way Merge with Dummy Head (Sentinel Node)* (Intercalação com Nó Sentinela)

---

## 1. O que é esse conceito?

Este algoritmo é a etapa de combinação (*Merge Step*) do algoritmo **Merge Sort**, adaptada para listas encadeadas:
- Em vez de escrever código condicional extra para decidir qual nó será o primeiro `head` da lista resultante, declaramos um objeto local `ListNode dummy(0)` na pilha (*Sentinel / Dummy Head*) e um ponteiro `tail = &dummy`.
- A cada passo, comparamos `list1->val` e `list2->val`, costuramos o menor em `tail->next` e avançamos.
- Quando uma das listas acaba, basta apontar `tail->next` para a lista restante em $O(1)$.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Criamos `ListNode dummy(0)` e `ListNode* tail = &dummy`.
2. Enquanto `list1 != nullptr && list2 != nullptr`:
   - Se `list1->val <= list2->val`: `tail->next = list1; list1 = list1->next;`
   - Senão: `tail->next = list2; list2 = list2->next;`
   - Avançamos `tail = tail->next`.
3. Conectamos a sobra: `tail->next = (list1 != nullptr) ? list1 : list2`.
4. Retornamos `dummy.next`.

---

## 3. Complexidade

- **Tempo:** $O(n + m)$, onde $n$ e $m$ são os tamanhos das duas listas.
- **Espaço:** $O(1)$ — reaproveita os próprios nós existentes (*in-place splicing*).
