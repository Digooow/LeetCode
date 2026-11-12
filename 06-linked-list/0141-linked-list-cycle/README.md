# 141. Linked List Cycle

- **Nível:** Fácil ([LeetCode #141](https://leetcode.com/problems/linked-list-cycle/))
- **Classificação do Conceito:**
  - **Algoritmo Clássico:** *Floyd's Tortoise and Hare Cycle-Finding Algorithm* (Algoritmo da Tartaruga e da Lebre de Floyd)
  - **Padrão Algorítmico:** *Fast & Slow Pointers* (Ponteiros Rápido e Lento)

---

## 1. O que é esse conceito?

Guardar todos os endereços de memória visitados em um `std::unordered_set<ListNode*>` resolveria o problema em $O(n)$ tempo, mas custaria $O(n)$ de memória.

O **Algoritmo de Floyd (*Fast & Slow Pointers*)** detecta ciclos em **$O(1)$ de memória**:
- O ponteiro lento (`slow`) avança **1 passo** por iteração.
- O ponteiro rápido (`fast`) avança **2 passos** por iteração.
- Se a lista possui um ciclo de comprimento $C$, assim que ambos entram no ciclo, a distância entre `fast` e `slow` diminui exatamente em **1 nó por iteração**, garantindo matematicamente que eles colidirão (`slow == fast`) em menos de $C$ passos!

---

## 2. Explicação do Algoritmo Passo a Passo

1. Inicializamos `slow = head` e `fast = head`.
2. Enquanto `fast != nullptr && fast->next != nullptr`:
   - `slow = slow->next;`
   - `fast = fast->next->next;`
   - Se `slow == fast`, retornamos `true`.
3. Se `fast` alcançou o final (`nullptr`), não há ciclo (`return false`).

---

## 3. Complexidade

- **Tempo:** $O(n)$.
- **Espaço:** $O(1)$ — apenas dois ponteiros.
