# 191. Number of 1 Bits

- **Nível:** Fácil ([LeetCode #191](https://leetcode.com/problems/number-of-1-bits/))
- **Classificação do Conceito:**
  - **Algoritmo Clássico:** *Brian Kernighan's Bit Counting Algorithm* (Contagem de Peso de Hamming via `n & (n - 1)`)

---

## 1. O que é esse conceito?

O número de bits `1` na representação binária de um inteiro é chamado na Teoria da Informação de **Peso de Hamming (*Hamming Weight* / `popcount`)**.

Em vez de deslocar todos os 32 bits um por um, o **Algoritmo de Brian Kernighan** faz `n &= (n - 1)` a cada passo. Essa operação zera diretamente o bit `1` menos significativo de `n`. Assim, o laço `while (n != 0)` executa **exatamente tantas vezes quantos forem os bits `1` presentes em `n`**!

### Exemplo com `n = 12` (`1100` em binário)
1. `12 & 11` = `1100 & 1011` = `1000` (`8`) $\rightarrow$ `count = 1`
2. `8 & 7` = `1000 & 0111` = `0000` (`0`) $\rightarrow$ `count = 2` (termina!)

---

## 2. Complexidade

- **Tempo:** $O(k)$, onde $k \le 32$ é a quantidade de bits `1` ($O(1)$ para inteiros de 32 bits).
- **Espaço:** $O(1)$.
