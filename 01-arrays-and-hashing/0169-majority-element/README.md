# 169. Majority Element

- **Nível:** Fácil ([LeetCode #169](https://leetcode.com/problems/majority-element/))
- **Classificação do Conceito:**
  - **Algoritmo Clássico:** *Boyer-Moore Majority Vote Algorithm* (Algoritmo de Votação Majoritária de Boyer-Moore)
  - **Categoria:** *Streaming Algorithm* (Algoritmo de Passagem Única com Memória Constante $O(1)$)

---

## 1. O que é esse conceito?

Contar frequências com `unordered_map` resolve o problema em $O(n)$ tempo, mas gasta $O(n)$ de memória. O **Algoritmo de Votação de Boyer-Moore** (1981) resolve o problema em **$O(n)$ tempo e $O(1)$ espaço** explorando uma propriedade matemática simples:

> Se um elemento aparece **estritamente mais que $\lfloor n / 2 \rfloor$ vezes**, então mesmo que você anule cada ocorrência dele pareando-a com qualquer outro elemento diferente do vetor, ainda sobrará pelo menos uma ocorrência do elemento majoritário no final.

---

## 2. Explicação do Algoritmo Passo a Passo

Mantemos duas variáveis escalares: `candidate` (candidato atual) e `count` (saldo de votos):
1. Para cada número `num` em `nums`:
   - Se `count == 0`, elegemos `candidate = num`.
   - Se `num == candidate`, incrementamos `++count`.
   - Caso contrário (`num != candidate`), cancelamos um voto: `--count`.
2. Ao final do vetor, `candidate` é garantidamente o elemento majoritário.

### Rastreamento com `nums = [2, 2, 1, 1, 1, 2, 2]`

| `num` | `candidate` | `count` | Explicação |
|---|---|---|---|
| `2` | `2` | `1` | `count == 0` $\rightarrow$ novo candidato `2` |
| `2` | `2` | `2` | igual ao candidato $\rightarrow$ `+1` |
| `1` | `2` | `1` | diferente $\rightarrow$ cancela um voto (`-1`) |
| `1` | `2` | `0` | diferente $\rightarrow$ cancela um voto (`0`) |
| `1` | `1` | `1` | `count == 0` $\rightarrow$ novo candidato `1` |
| `2` | `1` | `0` | diferente $\rightarrow$ cancela um voto (`0`) |
| `2` | `2` | `1` | `count == 0` $\rightarrow$ novo candidato `2` (vencedor) |

---

## 3. Complexidade

- **Tempo:** $O(n)$ — uma única passagem pelo vetor.
- **Espaço:** $O(1)$ — apenas duas variáveis inteiras.
