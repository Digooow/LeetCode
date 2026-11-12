# 53. Maximum Subarray

- **Nível:** Intermediário ([LeetCode #53](https://leetcode.com/problems/maximum-subarray/))
- **Classificação do Conceito:**
  - **Algoritmo Clássico:** *Kadane's Algorithm* (Algoritmo de Kadane)
  - **Paradigma:** *1D Dynamic Programming / Greedy Prefix Reset*

---

## 1. O que é esse conceito?

O **Algoritmo de Kadane** responde em $O(n)$ tempo e $O(1)$ espaço qual é a maior soma possível de um subarray contíguo.

A decisão de Programação Dinâmica no índice $i$ responde à pergunta:
> *"Para formar o melhor subarray que termina exatamente em `nums[i]`, vale a pena continuar somando a `currentSum` anterior ou começar um subarray novo a partir de `nums[i]`?"*

Se `currentSum < 0`, carregar um prefixo negativo só diminuiria qualquer soma futura; logo, descartamos o passado e recomeçamos em `nums[i]`:

$$\text{currentSum} = \max(\text{nums}[i],\ \text{currentSum} + \text{nums}[i])$$

---

## 2. Complexidade

- **Tempo:** $O(n)$ — varredura única.
- **Espaço:** $O(1)$ — apenas duas variáveis inteiras (`currentSum` e `maxSum`).
