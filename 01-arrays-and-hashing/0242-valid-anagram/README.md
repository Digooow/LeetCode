# 242. Valid Anagram

- **Nível:** Fácil ([LeetCode #242](https://leetcode.com/problems/valid-anagram/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** *Fixed-Size Frequency Array* (Vetor de Frequências de Tamanho Fixo / *Direct Addressing Table*)
  - **Padrão Algorítmico:** *Frequency Balance Counting* (Balanço de Frequências)

---

## 1. O que é esse conceito?

Quando o domínio das chaves é pequeno e contíguo (por exemplo, letras minúsculas de `'a'` a `'z'`, totalizando 26 símbolos), usar `std::unordered_map<char, int>` adiciona custo desnecessário de alocação dinâmica e cálculo de hash.

Na Ciência da Computação, substituir um Hash Map por um array indexado diretamente pelo código do caractere (`c - 'a'`) chama-se **Tabela de Endereçamento Direto (*Direct Addressing Table*)** ou **Vetor de Frequências (*Frequency Bucket Array*)**. Ele garante acesso $O(1)$ estrito (sem colisões de hash) e complexidade espacial $O(1)$ ($26 \text{ inteiros}$ na *stack*).

---

## 2. Explicação do Algoritmo Passo a Passo

1. **Poda por tamanho:** Se `s.size() != t.size()`, é impossível serem anagramas $\rightarrow$ retorna `false` em $O(1)$.
2. Criamos um array `std::array<int, 26> freq{}` inicializado com zeros.
3. Percorremos o índice `i` de `0` até `s.size() - 1`:
   - Incrementamos `freq[s[i] - 'a']++` (letra fornecida por `s`).
   - Decrementamos `freq[t[i] - 'a']--` (letra consumida por `t`).
4. Ao final, se `s` e `t` possuem exatamente a mesma multiconjunto de caracteres, todas as 26 posições de `freq` devem ser `0`.

---

## 3. Complexidade

- **Tempo:** $O(n)$, onde $n$ é o comprimento das strings.
- **Espaço:** $O(1)$ (ou $O(|\Sigma|)$ onde $|\Sigma| = 26$ é o tamanho do alfabeto, alocado estaticamente na pilha).
