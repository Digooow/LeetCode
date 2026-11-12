# 02 · Two Pointers (Padrão Algorítmico de Dois Ponteiros)

## Qual é o nome correto desse conceito?

**Two Pointers (Dois Ponteiros)** não é uma estrutura de dados nem um Design Pattern de Orientação a Objetos (GoF): o termo técnico exato é **Padrão Algorítmico (*Algorithmic Pattern* / *Problem-Solving Technique*)**.

Ele consiste em manter dois índices (ou iteradores) que percorrem uma estrutura sequencial (geralmente um array ou string) de forma coordenada para reduzir a complexidade temporal de $O(n^2)$ para **$O(n)$** e a complexidade de espaço para **$O(1)$**.

Existem duas variantes fundamentais desse padrão:

1. **Dois Ponteiros Convergentes (*Opposite-Ends / Converging Two Pointers*):**
   - Um ponteiro começa no início (`left = 0`) e outro no final (`right = n - 1`).
   - A cada passo, decidimos qual ponteiro avançar em direção ao centro (`++left` ou `--right`) com base em uma **propriedade monotônica** (por exemplo, array ordenado ou eliminação do gargalo de altura).
   - Exemplos: *Valid Palindrome*, *3Sum*, *Container With Most Water*, *Trapping Rain Water*.
2. **Dois Ponteiros na Mesma Direção (*Reader/Writer* ou *Slow/Fast Index*):**
   - Ambos começam no início (`write = 0`, `read = 0`).
   - O ponteiro `read` explora todos os elementos, enquanto o ponteiro `write` mantém a fronteira dos elementos válidos já compactados *in-place*.
   - Exemplos: *Remove Duplicates from Sorted Array*, *Move Zeroes*.

---

## Problemas nesta pasta

| Problema | Dificuldade | Variante do Padrão Two Pointers |
|---|---|---|
| [0125 - Valid Palindrome](./0125-valid-palindrome/README.md) | Fácil | Dois Ponteiros Convergentes com Filtro Alfanumérico |
| [0026 - Remove Duplicates from Sorted Array](./0026-remove-duplicates-from-sorted-array/README.md) | Fácil | Ponteiros *Reader/Writer* para Compactação *In-Place* |
| [0283 - Move Zeroes](./0283-move-zeroes/README.md) | Fácil | Particionamento Estável *In-Place* (*Slow/Fast*) |
| [0015 - 3Sum](./0015-3sum/README.md) | Intermediário | Ordenação + Fixação de Pivô + Dois Ponteiros Convergentes |
| [0011 - Container With Most Water](./0011-container-with-most-water/README.md) | Intermediário | Eliminação Gulosa do Gargalo (*Greedy Two Pointers*) |
| [0042 - Trapping Rain Water](./0042-trapping-rain-water/README.md) | Difícil (Hard) | Dois Ponteiros com Invariante de Máximo de Prefixo/Sufixo |
