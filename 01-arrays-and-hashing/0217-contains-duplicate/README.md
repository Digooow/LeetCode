# 217. Contains Duplicate

- **Nível:** Fácil ([LeetCode #217](https://leetcode.com/problems/contains-duplicate/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** Conjunto Hash (*Hash Set* — `std::unordered_set`)
  - **Padrão Algorítmico:** *Early-Exit Set Membership Check* (Verificação de Pertinência com Saída Antecipada)

---

## 1. O que é esse conceito?

Um **Conjunto Hash (`std::unordered_set`)** modela a noção matemática de conjunto: uma coleção não ordenada de elementos únicos. Sob o capô, ele utiliza uma tabela de dispersão (*hash table*) onde cada valor inserido passa por uma função de hash para determinar seu *bucket*.

Existem três abordagens clássicas para detectar duplicatas, e saber compará-las em entrevistas mostra maturidade:
1. **Força Bruta:** Comparar todos os pares $\rightarrow$ Tempo $O(n^2)$, Espaço $O(1)$.
2. **Ordenação (*Sorting*):** Ordenar o array e comparar elementos adjacentes `nums[i] == nums[i - 1]` $\rightarrow$ Tempo $O(n \log n)$, Espaço $O(1)$.
3. **Hash Set (Ótima em Tempo):** Inserir cada elemento em um `unordered_set` e abortar assim que `insert()` indicar que o elemento já existia $\rightarrow$ Tempo $O(n)$, Espaço $O(n)$.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Instanciamos `std::unordered_set<int> seen` e reservamos capacidade (`seen.reserve(nums.size())`) para evitar *rehashes*.
2. Para cada número `x` em `nums`:
   - Em C++, `seen.insert(x)` retorna um `std::pair<iterator, bool>` onde `.second` é `false` se o elemento já estava presente no conjunto.
   - Se `!seen.insert(x).second`, retornamos `true` imediatamente (*early exit*).
3. Se o laço terminar sem colisão, retornamos `false`.

---

## 3. Complexidade

- **Tempo:** $O(n)$ no caso médio (cada `insert` em tabela hash é $O(1)$ amortizado).
- **Espaço:** $O(n)$ no pior caso (quando todos os elementos são distintos).
