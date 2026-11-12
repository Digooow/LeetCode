# 1. Two Sum

- **Nível:** Fácil ([LeetCode #1](https://leetcode.com/problems/two-sum/))
- **Classificação do Conceito:**
  - **Estrutura de Dados:** Tabela Hash (*Hash Map* — `std::unordered_map`)
  - **Padrão Algorítmico:** *Single-Pass Complement Lookup* (Busca de Complemento em Passagem Única)

---

## 1. O que é esse conceito e por que ele tem esse nome?

Em entrevistas, quando um problema pede para encontrar um par $(i, j)$ que satisfaça uma equação como $\text{nums}[i] + \text{nums}[j] = \text{target}$, a abordagem ingênua (*Brute Force*) testa todos os pares possíveis com dois laços `for` aninhados, custando $O(n^2)$.

O padrão **Complement Lookup com Hash Map** reescreve a equação algebricamente isolando a incógnita:

$$\text{complemento} = \text{target} - \text{nums}[i]$$

Como uma **Tabela Hash** (`std::unordered_map`) oferece busca em tempo médio constante $O(1)$, trocamos tempo por espaço (*Time-Space Trade-off*): enquanto percorremos o vetor uma única vez, consultamos se o `complemento` já foi visto antes.

---

## 2. Explicação do Algoritmo Passo a Passo

1. Criamos um `unordered_map<int, int> visto` onde a **chave** é o número do vetor (`nums[i]`) e o **valor** é o seu índice `i`.
2. Iteramos `i` de `0` até `nums.size() - 1`:
   - Calculamos `complemento = target - nums[i]`.
   - Verificamos `visto.find(complemento) != visto.end()`:
     - Se **encontrou**, retornamos `{visto[complemento], i}` imediatamente.
     - Se **não encontrou**, registramos `visto[nums[i]] = i` e avançamos.

### Rastreamento (*Trace*) com `nums = [2, 7, 11, 15], target = 9`

| Iteração `i` | `nums[i]` | `complemento = 9 - nums[i]` | `visto` antes da inserção | Ação |
|---|---|---|---|---|
| `0` | `2` | `7` | `{}` | `7` não está no mapa $\rightarrow$ insere `visto[2] = 0` |
| `1` | `7` | `2` | `{2: 0}` | `2` está no mapa no índice `0` $\rightarrow$ retorna `[0, 1]` |

---

## 3. Complexidade

- **Tempo:** $O(n)$ — percorremos o array uma única vez e cada busca/inserção em `std::unordered_map` custa $O(1)$ amortizado.
- **Espaço:** $O(n)$ — no pior caso, armazenamos até $n - 1$ elementos na tabela hash.
