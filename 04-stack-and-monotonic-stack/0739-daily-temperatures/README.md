# 739. Daily Temperatures

- **Nível:** Intermediário ([LeetCode #739](https://leetcode.com/problems/daily-temperatures/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Monotonic Decreasing Stack* (Pilha Monotônica Decrescente / *Next Greater Element*)

---

## 1. O que é esse conceito?

Para cada dia `i`, queremos saber quantos dias precisamos esperar até encontrar uma temperatura **estritamente maior** que `temperatures[i]`.

Com uma **Pilha Monotônica Decrescente**, guardamos na pilha os **índices** dos dias que ainda aguardam um dia mais quente. As temperaturas correspondentes aos índices na pilha permanecem sempre em ordem decrescente:
- Quando chega o dia `i` com `temperatures[i]` maior que a temperatura do índice no topo da pilha (`prevDay = st.top()`), descobrimos que `i` é o **primeiro dia mais quente** para `prevDay`!
- Calculamos a distância `answer[prevDay] = i - prevDay`, desempilhamos `prevDay` e repetimos enquanto o topo for menor que `temperatures[i]`.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Inicializamos `answer(n, 0)` e uma pilha de índices `std::stack<int> st`.
2. Para `i` de `0` até `n - 1`:
   - Enquanto `!st.empty() && temperatures[i] > temperatures[st.top()]`:
     - `int prevIndex = st.top(); st.pop();`
     - `answer[prevIndex] = i - prevIndex;`
   - `st.push(i);`
3. Retornamos `answer`.

---

## 3. Complexidade

- **Tempo:** $O(n)$ amortizado — cada índice é empilhado exatamente uma vez e desempilhado no máximo uma vez.
- **Espaço:** $O(n)$ — para a pilha de índices no pior caso (temperaturas estritamente decrescentes).
