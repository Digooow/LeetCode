# 23. Merge k Sorted Lists

- **Nível:** Difícil / Hard ([LeetCode #23](https://leetcode.com/problems/merge-k-sorted-lists/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** Fila de Prioridade Mínima (*Min-Heap* — `std::priority_queue`)
  - **Padrão Algorítmico:** *K-Way Merge* (Intercalação de $k$ Sequências Ordenadas)

---

## 1. O que é esse conceito e onde ele aparece em Backend / Sistemas Distribuídos?

Em engenharia de software real (como **LSM-Trees** no RocksDB/Cassandra, **External Merge Sort** no PostgreSQL ou agregação de resultados paginados vindos de $k$ *shards*), frequentemente temos $k$ fluxos que já estão individualmente ordenados e precisamos unificá-los em um único fluxo globalmente ordenado.

Se compararmos as $k$ cabeças linearmente a cada passo, gastamos $O(N \cdot k)$ (onde $N$ é o total de nós). Ao manter as $k$ cabeças ativas dentro de uma **Min-Heap (`std::priority_queue` com comparador `>`)**:
- Consultar e extrair o menor elemento entre as $k$ listas custa apenas **$O(\log k)$**!
- Assim que extraímos o nó `smallest` da *Min-Heap*, se `smallest->next != nullptr`, inserimos `smallest->next` na *Min-Heap* em $O(\log k)$.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Definimos um functor `Compare` que ordena ponteiros `ListNode*` pelo maior `val` (para que o topo da `priority_queue` do C++ seja o **menor** `val`, funcionando como *Min-Heap*).
2. Inserimos na *Min-Heap* o primeiro nó de cada lista não vazia ($O(k \log k)$).
3. Criamos um nó sentinela `ListNode dummy(0)` e `tail = &dummy`.
4. Enquanto a *Min-Heap* não estiver vazia:
   - Extraímos `curr = pq.top(); pq.pop();`
   - Anexamos `tail->next = curr; tail = tail->next;`
   - Se `curr->next != nullptr`, fazemos `pq.push(curr->next)`.
5. Retornamos `dummy.next`.

---

## 3. Complexidade

- **Tempo:** $O(N \log k)$, onde $N$ é o número total de nós somando todas as listas e $k$ é o número de listas.
- **Espaço Auxiliar:** $O(k)$ — a *Min-Heap* armazena no máximo $k$ ponteiros simultaneamente.
