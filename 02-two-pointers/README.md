# 02 · Two Pointers (Dois Ponteiros)

## Visão Geral

**Two Pointers** é um padrão algorítmico que mantém dois índices coordenados sobre uma estrutura sequencial (array ou string), reduzindo soluções quadráticas $O(n^2)$ para tempo linear **$O(n)$** e espaço auxiliar **$O(1)$**.

As implementações desta pasta dividem-se em duas variantes:

1. **Dois Ponteiros Convergentes (*Opposite-Ends / Converging*):**
   - Inicia com `left = 0` e `right = n - 1`, avançando um dos ponteiros em direção ao centro conforme uma propriedade monotônica do domínio (ordenação prévia ou eliminação do menor limitante).
   - Aplicado em *Valid Palindrome*, *3Sum*, *Container With Most Water* e *Trapping Rain Water*.
2. **Dois Ponteiros na Mesma Direção (*Reader/Writer*):**
   - Ambos iniciam à esquerda; o ponteiro de leitura percorre todos os elementos enquanto o ponteiro de escrita mantém a fronteira da partição válida *in-place*.
   - Aplicado em *Remove Duplicates from Sorted Array* e *Move Zeroes*.

---

## Problemas

| Problema | Dificuldade | Variante |
|---|---|---|
| [0125 - Valid Palindrome](./0125-valid-palindrome/README.md) | Fácil | Ponteiros Convergentes com Filtro Alfanumérico |
| [0026 - Remove Duplicates from Sorted Array](./0026-remove-duplicates-from-sorted-array/README.md) | Fácil | *Reader/Writer* para Compactação *In-Place* |
| [0283 - Move Zeroes](./0283-move-zeroes/README.md) | Fácil | Particionamento Estável *In-Place* |
| [0015 - 3Sum](./0015-3sum/README.md) | Intermediário | Ordenação + Pivô Fixo + Ponteiros Convergentes |
| [0011 - Container With Most Water](./0011-container-with-most-water/README.md) | Intermediário | Redução Gulosa pelo Menor Limitante |
| [0042 - Trapping Rain Water](./0042-trapping-rain-water/README.md) | Difícil (Hard) | Ponteiros Convergentes com Invariante de Máximo Bilateral |
