# 3. Longest Substring Without Repeating Characters

- **Nível:** Intermediário ([LeetCode #3](https://leetcode.com/problems/longest-substring-without-repeating-characters/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Variable-Size Sliding Window with Direct-Index Jump* (Janela Deslizante de Tamanho Variável com Salto por Última Ocorrência)

---

## 1. O que é esse conceito?

Queremos encontrar a maior janela contígua `s[left .. right]` que **não contenha caracteres repetidos**.

Em vez de encolher `left` de 1 em 1 com um `unordered_set`, mantemos uma tabela `lastSeen[256]` (inicializada com `-1`) que guarda o **último índice** em que cada caractere ASCII apareceu:
- Quando `right` lê um caractere `c = s[right]` que já apareceu dentro da janela atual (`lastSeen[c] >= left`), significa que houve repetição.
- Saltamos `left` diretamente para `lastSeen[c] + 1`, eliminando a duplicata em $O(1)$!

---

## 2. Explicação do Algoritmo Passo a Passo

1. Criamos `std::array<int, 256> lastSeen` preenchido com `-1`.
2. Inicializamos `left = 0` e `maxLen = 0`.
3. Para `right` de `0` até `s.size() - 1`:
   - Seja `c = static_cast<unsigned char>(s[right])`.
   - Se `lastSeen[c] >= left`, movemos `left = lastSeen[c] + 1`.
   - Registramos `lastSeen[c] = right`.
   - Atualizamos `maxLen = std::max(maxLen, right - left + 1)`.
4. Retornamos `maxLen`.

---

## 3. Complexidade

- **Tempo:** $O(n)$ — passagem única sem retrocesso.
- **Espaço:** $O(1)$ — tabela estática de 256 inteiros para a tabela ASCII.
