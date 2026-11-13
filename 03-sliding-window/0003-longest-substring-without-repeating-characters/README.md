# 0003 · Longest Substring Without Repeating Characters

**Dificuldade:** Intermediário | **Categoria:** Sliding Window | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dada uma string `s`, encontrar o comprimento da maior substring contígua que não contém caracteres repetidos.

## Abordagem

Em `lengthOfLongestSubstring`, uma janela deslizante dinâmica `[left, right]` mantém todos os caracteres do intervalo atual sem repetições:

1. Um array fixo `std::array<int, 256> lastSeen` (inicializado com `-1`) registra o último índice em que cada byte (`static_cast<unsigned char>(s[right])`) foi visto.
2. Quando o caractere `c` em `right` já apareceu dentro da janela ativa (`lastSeen[c] >= left`), o ponteiro `left` salta diretamente para `lastSeen[c] + 1`, descartando o prefixo que causaria colisão em $O(1)$.
3. Atualiza-se `lastSeen[c] = right` e recalcula-se `maxLen = std::max(maxLen, right - left + 1)`.

Saltar `left` diretamente pelo último índice registrado evita ter de avançar `left` caractere por caractere até eliminar a duplicata.

## Complexidade

- **Tempo:** $O(n)$ — passagem única por `s` com indexação direta em `lastSeen`.
- **Espaço:** $O(1)$ — tabela estática de 256 inteiros, independente do tamanho da entrada.
