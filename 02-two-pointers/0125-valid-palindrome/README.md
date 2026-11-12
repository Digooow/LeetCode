# 125. Valid Palindrome

- **Nível:** Fácil ([LeetCode #125](https://leetcode.com/problems/valid-palindrome/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Converging Two Pointers* (Dois Ponteiros Convergentes / Extremos Opostos)

---

## 1. O que é esse conceito?

Uma abordagem ingênua criaria uma nova string filtrada e outra invertida para compará-las, gastando $O(n)$ de memória extra. Com o padrão **Two Pointers Convergentes**, colocamos `left` no primeiro caractere e `right` no último caractere da string original e caminhamos para o centro em $O(1)$ de memória:

- Enquanto `s[left]` não for alfanumérico, avançamos `++left`.
- Enquanto `s[right]` não for alfanumérico, recuamos `--right`.
- Comparamos `std::tolower(s[left]) == std::tolower(s[right])`.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Inicializamos `left = 0` e `right = s.size() - 1`.
2. Enquanto `left < right`:
   - Ignoramos pontuação e espaços à esquerda com `std::isalnum(static_cast<unsigned char>(s[left]))`.
   - Ignoramos pontuação e espaços à direita da mesma forma.
   - Se os caracteres normalizados em minúsculo divergirem, retornamos `false`.
   - Avançamos ambos (`++left`, `--right`).
3. Se os ponteiros se cruzarem sem divergência, a string é um palíndromo (`true`).

---

## 3. Complexidade

- **Tempo:** $O(n)$ — cada caractere da string é visitado no máximo uma vez.
- **Espaço:** $O(1)$ — nenhuma string auxiliar é alocada.
