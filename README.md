# LeetCode Solutions & Algorithmic Patterns (C++17)

Repositório de soluções em **C++17** para os desafios clássicos do [LeetCode](https://leetcode.com/u/digooow/), estruturado por **Padrões Algorítmicos (*Algorithmic Patterns*)** e **Estruturas de Dados (*Data Structures*)**, com explicações teóricas e análise de complexidade em cada pasta.

---

## Glossário Técnico: Qual é o nome certo de cada "conceito"?

Para usar a terminologia exata em entrevistas técnicas:

| Termo Técnico | Nome em Inglês | O que é na prática | Exemplos |
|---|---|---|---|
| **Estrutura de Dados** | *Data Structure* | Forma concreta de organizar dados na memória para otimizar leitura, busca, inserção ou remoção. | *Array*, *Hash Table* (`unordered_map`), *Linked List*, *Stack*, *Queue*, *Min-Heap* (`priority_queue`), *Binary Tree*, *Graph*. |
| **Algoritmo** | *Algorithm* | Sequência finita e determinística de instruções para transformar uma entrada em uma saída. | *Binary Search*, *DFS*, *BFS*, *Algoritmo de Kadane*, *Algoritmo de Floyd*, *Algoritmo de Kahn*, *Boyer-Moore Voting*. |
| **Padrão Algorítmico** (ou Técnica de Resolução) | *Algorithmic Pattern* / *Problem-Solving Pattern* | O "molde" mental recorrente usado para reconhecer e resolver famílias inteiras de problemas sem inventar um algoritmo do zero. | *Two Pointers*, *Sliding Window*, *Fast & Slow Pointers*, *Monotonic Stack*, *Prefix & Suffix Decomposition*, *K-Way Merge*. |
| **Paradigma de Projeto de Algoritmos** | *Algorithm Design Paradigm* | Estratégia macro de construção de algoritmos. | *Divide and Conquer* (Divisão e Conquista), *Dynamic Programming* (Programação Dinâmica), *Greedy* (Algoritmo Guloso), *Backtracking*. |
| **Padrão de Projeto de Software** | *Software Design Pattern (GoF / Arquitetura)* | Soluções de arquitetura e orientação a objetos para desacoplar classes e módulos de sistemas (não são algoritmos matemáticos). | *Strategy*, *Factory*, *Adapter*, *Repository*, *Unit of Work*, *Outbox Pattern*. |

---

## Índice de Pastas por Padrão Algorítmico

1. [**01 · Arrays & Hashing**](./01-arrays-and-hashing/README.md) — *Hash Tables, Bucket Counting, Prefix/Suffix & Boyer-Moore*
2. [**02 · Two Pointers**](./02-two-pointers/README.md) — *Ponteiros Convergentes e Compactação In-Place*
3. [**03 · Sliding Window**](./03-sliding-window/README.md) — *Janela Deslizante Fixa e Dinâmica (Expansão/Contração)*
4. [**04 · Stack & Monotonic Stack**](./04-stack-and-monotonic-stack/README.md) — *Pilha LIFO e Pilha Monotônica (Next Greater Element)*
5. [**05 · Binary Search**](./05-binary-search/README.md) — *Busca Binária Exata, Lower Bound e Arrays Rotacionados*
6. [**06 · Linked List & Fast/Slow Pointers**](./06-linked-list/README.md) — *Inversão de Ponteiros, Dummy Head, Ciclo de Floyd e K-Way Merge*
7. [**07 · Binary Trees (DFS & BFS)**](./07-trees-dfs-and-bfs/README.md) — *Recursão Estrutural Top-Down e Bottom-Up*
8. [**08 · Graphs & Topological Sort**](./08-graphs-and-topological-sort/README.md) — *Flood Fill, Componentes Conexos e Algoritmo de Kahn (DAG)*
9. [**09 · Dynamic Programming & Greedy**](./09-dynamic-programming-and-greedy/README.md) — *Tabulação Bottom-Up, Kadane e Interval Sweep*
10. [**10 · Bit Manipulation**](./10-bit-manipulation/README.md) — *Cancelamento por XOR e Algoritmo de Brian Kernighan*

---

## Catálogo Completo de Desafios Resolvidos (39 Problemas: 23 Fáceis · 13 Intermediários · 3 Hard)

### Nível Fácil (23 Clássicos)

| # | Problema | Pasta / Explicação | Código | Padrão / Algoritmo | Complexidade |
|---|---|---|---|---|---|
| 1 | Two Sum | [README](./01-arrays-and-hashing/0001-two-sum/README.md) | [`solution.cpp`](./01-arrays-and-hashing/0001-two-sum/solution.cpp) | Hash Map (*Complement Lookup*) | $O(n)$ tempo · $O(n)$ espaço |
| 20 | Valid Parentheses | [README](./04-stack-and-monotonic-stack/0020-valid-parentheses/README.md) | [`solution.cpp`](./04-stack-and-monotonic-stack/0020-valid-parentheses/solution.cpp) | Pilha LIFO | $O(n)$ tempo · $O(n)$ espaço |
| 21 | Merge Two Sorted Lists | [README](./06-linked-list/0021-merge-two-sorted-lists/README.md) | [`solution.cpp`](./06-linked-list/0021-merge-two-sorted-lists/solution.cpp) | *Two-Way Merge* com *Dummy Node* | $O(n+m)$ tempo · $O(1)$ espaço |
| 26 | Remove Duplicates from Sorted Array | [README](./02-two-pointers/0026-remove-duplicates-from-sorted-array/README.md) | [`solution.cpp`](./02-two-pointers/0026-remove-duplicates-from-sorted-array/solution.cpp) | Two Pointers (*Reader/Writer*) | $O(n)$ tempo · $O(1)$ espaço |
| 35 | Search Insert Position | [README](./05-binary-search/0035-search-insert-position/README.md) | [`solution.cpp`](./05-binary-search/0035-search-insert-position/solution.cpp) | Binary Search (*Lower Bound*) | $O(\log n)$ tempo · $O(1)$ espaço |
| 70 | Climbing Stairs | [README](./09-dynamic-programming-and-greedy/0070-climbing-stairs/README.md) | [`solution.cpp`](./09-dynamic-programming-and-greedy/0070-climbing-stairs/solution.cpp) | DP 1D com Compressão de Estado | $O(n)$ tempo · $O(1)$ espaço |
| 100 | Same Tree | [README](./07-trees-dfs-and-bfs/0100-same-tree/README.md) | [`solution.cpp`](./07-trees-dfs-and-bfs/0100-same-tree/solution.cpp) | DFS Simultânea Pré-Ordem | $O(n)$ tempo · $O(h)$ espaço |
| 104 | Maximum Depth of Binary Tree | [README](./07-trees-dfs-and-bfs/0104-maximum-depth-of-binary-tree/README.md) | [`solution.cpp`](./07-trees-dfs-and-bfs/0104-maximum-depth-of-binary-tree/solution.cpp) | DFS Pós-Ordem (*Bottom-Up*) | $O(n)$ tempo · $O(h)$ espaço |
| 121 | Best Time to Buy and Sell Stock | [README](./03-sliding-window/0121-best-time-to-buy-and-sell-stock/README.md) | [`solution.cpp`](./03-sliding-window/0121-best-time-to-buy-and-sell-stock/solution.cpp) | Sliding Window / Mínimo Acumulado | $O(n)$ tempo · $O(1)$ espaço |
| 125 | Valid Palindrome | [README](./02-two-pointers/0125-valid-palindrome/README.md) | [`solution.cpp`](./02-two-pointers/0125-valid-palindrome/solution.cpp) | Two Pointers Convergentes | $O(n)$ tempo · $O(1)$ espaço |
| 136 | Single Number | [README](./10-bit-manipulation/0136-single-number/README.md) | [`solution.cpp`](./10-bit-manipulation/0136-single-number/solution.cpp) | Cancelamento Bitwise XOR | $O(n)$ tempo · $O(1)$ espaço |
| 141 | Linked List Cycle | [README](./06-linked-list/0141-linked-list-cycle/README.md) | [`solution.cpp`](./06-linked-list/0141-linked-list-cycle/solution.cpp) | Algoritmo de Floyd (*Fast & Slow*) | $O(n)$ tempo · $O(1)$ espaço |
| 169 | Majority Element | [README](./01-arrays-and-hashing/0169-majority-element/README.md) | [`solution.cpp`](./01-arrays-and-hashing/0169-majority-element/solution.cpp) | Algoritmo de Votação de Boyer-Moore | $O(n)$ tempo · $O(1)$ espaço |
| 191 | Number of 1 Bits | [README](./10-bit-manipulation/0191-number-of-1-bits/README.md) | [`solution.cpp`](./10-bit-manipulation/0191-number-of-1-bits/solution.cpp) | Algoritmo de Brian Kernighan | $O(1)$ tempo · $O(1)$ espaço |
| 206 | Reverse Linked List | [README](./06-linked-list/0206-reverse-linked-list/README.md) | [`solution.cpp`](./06-linked-list/0206-reverse-linked-list/solution.cpp) | Inversão *In-Place* de 3 Ponteiros | $O(n)$ tempo · $O(1)$ espaço |
| 217 | Contains Duplicate | [README](./01-arrays-and-hashing/0217-contains-duplicate/README.md) | [`solution.cpp`](./01-arrays-and-hashing/0217-contains-duplicate/solution.cpp) | Hash Set (*Early Exit*) | $O(n)$ tempo · $O(n)$ espaço |
| 226 | Invert Binary Tree | [README](./07-trees-dfs-and-bfs/0226-invert-binary-tree/README.md) | [`solution.cpp`](./07-trees-dfs-and-bfs/0226-invert-binary-tree/solution.cpp) | Recursão Estrutural (DFS) | $O(n)$ tempo · $O(h)$ espaço |
| 242 | Valid Anagram | [README](./01-arrays-and-hashing/0242-valid-anagram/README.md) | [`solution.cpp`](./01-arrays-and-hashing/0242-valid-anagram/solution.cpp) | Vetor de Frequência Fixo (26) | $O(n)$ tempo · $O(1)$ espaço |
| 283 | Move Zeroes | [README](./02-two-pointers/0283-move-zeroes/README.md) | [`solution.cpp`](./02-two-pointers/0283-move-zeroes/solution.cpp) | Particionamento Estável *In-Place* | $O(n)$ tempo · $O(1)$ espaço |
| 543 | Diameter of Binary Tree | [README](./07-trees-dfs-and-bfs/0543-diameter-of-binary-tree/README.md) | [`solution.cpp`](./07-trees-dfs-and-bfs/0543-diameter-of-binary-tree/solution.cpp) | DFS Pós-Ordem + Estado Global | $O(n)$ tempo · $O(h)$ espaço |
| 643 | Maximum Average Subarray I | [README](./03-sliding-window/0643-maximum-average-subarray-i/README.md) | [`solution.cpp`](./03-sliding-window/0643-maximum-average-subarray-i/solution.cpp) | Sliding Window de Tamanho Fixo $k$ | $O(n)$ tempo · $O(1)$ espaço |
| 704 | Binary Search | [README](./05-binary-search/0704-binary-search/README.md) | [`solution.cpp`](./05-binary-search/0704-binary-search/solution.cpp) | Busca Binária Clássica | $O(\log n)$ tempo · $O(1)$ espaço |
| 733 | Flood Fill | [README](./08-graphs-and-topological-sort/0733-flood-fill/README.md) | [`solution.cpp`](./08-graphs-and-topological-sort/0733-flood-fill/solution.cpp) | *Grid DFS* (Inundação Conexos) | $O(R \cdot C)$ tempo · $O(R \cdot C)$ espaço |

*(Nota: 23 problemas fáceis incluídos para cobrir todos os 10 módulos fundamentais.)*

### Nível Intermediário (13 Clássicos)

| # | Problema | Pasta / Explicação | Código | Padrão / Algoritmo | Complexidade |
|---|---|---|---|---|---|
| 3 | Longest Substring Without Repeating Characters | [README](./03-sliding-window/0003-longest-substring-without-repeating-characters/README.md) | [`solution.cpp`](./03-sliding-window/0003-longest-substring-without-repeating-characters/solution.cpp) | Sliding Window Dinâmica com Salto | $O(n)$ tempo · $O(1)$ espaço |
| 11 | Container With Most Water | [README](./02-two-pointers/0011-container-with-most-water/README.md) | [`solution.cpp`](./02-two-pointers/0011-container-with-most-water/solution.cpp) | Greedy + Two Pointers Convergentes | $O(n)$ tempo · $O(1)$ espaço |
| 15 | 3Sum | [README](./02-two-pointers/0015-3sum/README.md) | [`solution.cpp`](./02-two-pointers/0015-3sum/solution.cpp) | Sorting + Pivô Fixo + Two Pointers | $O(n^2)$ tempo · $O(1)$ espaço aux. |
| 33 | Search in Rotated Sorted Array | [README](./05-binary-search/0033-search-in-rotated-sorted-array/README.md) | [`solution.cpp`](./05-binary-search/0033-search-in-rotated-sorted-array/solution.cpp) | Busca Binária por Metade Ordenada | $O(\log n)$ tempo · $O(1)$ espaço |
| 49 | Group Anagrams | [README](./01-arrays-and-hashing/0049-group-anagrams/README.md) | [`solution.cpp`](./01-arrays-and-hashing/0049-group-anagrams/solution.cpp) | Hash Map com Chave Canônica | $O(n \cdot k \log k)$ tempo · $O(n \cdot k)$ espaço |
| 53 | Maximum Subarray | [README](./09-dynamic-programming-and-greedy/0053-maximum-subarray/README.md) | [`solution.cpp`](./09-dynamic-programming-and-greedy/0053-maximum-subarray/solution.cpp) | Algoritmo de Kadane | $O(n)$ tempo · $O(1)$ espaço |
| 56 | Merge Intervals | [README](./09-dynamic-programming-and-greedy/0056-merge-intervals/README.md) | [`solution.cpp`](./09-dynamic-programming-and-greedy/0056-merge-intervals/solution.cpp) | Greedy Interval Sorting & Sweep | $O(n \log n)$ tempo · $O(n)$ espaço |
| 128 | Longest Consecutive Sequence | [README](./01-arrays-and-hashing/0128-longest-consecutive-sequence/README.md) | [`solution.cpp`](./01-arrays-and-hashing/0128-longest-consecutive-sequence/solution.cpp) | Hash Set (*Sequence Start Filter*) | $O(n)$ tempo · $O(n)$ espaço |
| 200 | Number of Islands | [README](./08-graphs-and-topological-sort/0200-number-of-islands/README.md) | [`solution.cpp`](./08-graphs-and-topological-sort/0200-number-of-islands/solution.cpp) | Contagem de Componentes Conexos (DFS) | $O(R \cdot C)$ tempo · $O(R \cdot C)$ espaço |
| 207 | Course Schedule | [README](./08-graphs-and-topological-sort/0207-course-schedule/README.md) | [`solution.cpp`](./08-graphs-and-topological-sort/0207-course-schedule/solution.cpp) | Ordenação Topológica de Kahn (BFS) | $O(V + E)$ tempo · $O(V + E)$ espaço |
| 238 | Product of Array Except Self | [README](./01-arrays-and-hashing/0238-product-of-array-except-self/README.md) | [`solution.cpp`](./01-arrays-and-hashing/0238-product-of-array-except-self/solution.cpp) | Decomposição Prefixo/Sufixo *In-Place* | $O(n)$ tempo · $O(1)$ espaço aux. |
| 322 | Coin Change | [README](./09-dynamic-programming-and-greedy/0322-coin-change/README.md) | [`solution.cpp`](./09-dynamic-programming-and-greedy/0322-coin-change/solution.cpp) | DP *Bottom-Up* (*Unbounded Knapsack*) | $O(A \cdot |C|)$ tempo · $O(A)$ espaço |
| 739 | Daily Temperatures | [README](./04-stack-and-monotonic-stack/0739-daily-temperatures/README.md) | [`solution.cpp`](./04-stack-and-monotonic-stack/0739-daily-temperatures/solution.cpp) | Pilha Monotônica Decrescente | $O(n)$ tempo · $O(n)$ espaço |

### Nível Difícil / Hard (3 Clássicos de Entrevista)

| # | Problema | Pasta / Explicação | Código | Padrão / Algoritmo | Complexidade |
|---|---|---|---|---|---|
| 23 | Merge k Sorted Lists | [README](./06-linked-list/0023-merge-k-sorted-lists/README.md) | [`solution.cpp`](./06-linked-list/0023-merge-k-sorted-lists/solution.cpp) | *K-Way Merge* via *Min-Heap* | $O(N \log k)$ tempo · $O(k)$ espaço |
| 42 | Trapping Rain Water | [README](./02-two-pointers/0042-trapping-rain-water/README.md) | [`solution.cpp`](./02-two-pointers/0042-trapping-rain-water/solution.cpp) | Two Pointers com Invariante de Máximo | $O(n)$ tempo · $O(1)$ espaço |
| 76 | Minimum Window Substring | [README](./03-sliding-window/0076-minimum-window-substring/README.md) | [`solution.cpp`](./03-sliding-window/0076-minimum-window-substring/solution.cpp) | Sliding Window com Contador de Déficit | $O(|s| + |t|)$ tempo · $O(1)$ espaço |

---

## Como Compilar e Executar Qualquer Solução

Cada arquivo `solution.cpp` é autônomo e inclui assertions (`cassert`) na função `main` para validar os casos de teste localmente:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic 02-two-pointers/0042-trapping-rain-water/solution.cpp -o solution
./solution
```
