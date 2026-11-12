# 49. Group Anagrams

- **Nível:** Intermediário ([LeetCode #49](https://leetcode.com/problems/group-anagrams/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** Tabela Hash Multivalorada (`std::unordered_map<std::string, std::vector<std::string>>`)
  - **Padrão Algorítmico:** *Canonical Key Hashing* (Agrupamento por Representação Canônica / Classe de Equivalência)

---

## 1. O que é esse conceito?

Na Matemática e na Ciência da Computação, uma **Forma Canônica (*Canonical Form*)** é uma representação única escolhida para identificar todos os membros de uma mesma **classe de equivalência**.

Duas strings $A$ e $B$ são anagramas se e somente se suas versões ordenadas alfabeticamente são idênticas:
- `"eat"` $\xrightarrow{\text{sort}}$ `"aet"`
- `"tea"` $\xrightarrow{\text{sort}}$ `"aet"`
- `"ate"` $\xrightarrow{\text{sort}}$ `"aet"`

Ao usar a forma canônica (`"aet"`) como **chave** de um `std::unordered_map`, todas as palavras que são anagramas entre si caem exatamente no mesmo *bucket* em $O(1)$.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Criamos `std::unordered_map<std::string, std::vector<std::string>> groups`.
2. Para cada palavra `word` em `strs`:
   - Criamos uma cópia `key = word` e aplicamos `std::sort(key.begin(), key.end())`.
   - Adicionamos `word` ao vetor `groups[key]`.
3. Percorremos todos os pares de `groups` e movemos cada vetor de anagramas para a matriz de resposta.

---

## 3. Complexidade

Seja $n$ o número de strings e $k$ o tamanho máximo de uma string:
- **Tempo:** $O(n \cdot k \log k)$ — ordenar cada string de tamanho $k$ custa $O(k \log k)$, repetido $n$ vezes.
- **Espaço:** $O(n \cdot k)$ — para armazenar todas as strings agrupadas na tabela hash.
