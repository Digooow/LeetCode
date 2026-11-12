# 136. Single Number

- **Nível:** Fácil ([LeetCode #136](https://leetcode.com/problems/single-number/))
- **Classificação do Conceito:**
  - **Técnica Algorítmica:** *Bitwise XOR Cancellation* (Cancelamento Algébrico por OU-Exclusivo Bit a Bit)

---

## 1. O que é esse conceito?

O operador **XOR (`^`)** satisfaz três identidades algébricas fundamentais:
1. $x \oplus 0 = x$ (identidade)
2. $x \oplus x = 0$ (auto-anulação)
3. $x \oplus y = y \oplus x$ e $(x \oplus y) \oplus z = x \oplus (y \oplus z)$ (comutatividade e associatividade)

Se todos os números do vetor aparecem **duas vezes** e apenas um número $u$ aparece **uma única vez**, o XOR acumulado de todos os elementos agrupa e anula todos os pares ($a \oplus a = 0$), restando $0 \oplus u = u$.

---

## 2. Complexidade

- **Tempo:** $O(n)$ — uma única passagem com instrução nativa de CPU.
- **Espaço:** $O(1)$ — uma única variável acumuladora.
