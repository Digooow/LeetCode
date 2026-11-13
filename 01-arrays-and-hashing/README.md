# 01 · Arrays & Hashing (Tabelas Hash, Frequência e Prefixos)

## Estruturas e Padrões

1. **Tabela Hash (`std::unordered_map` e `std::unordered_set`):**
   - Mapeia chaves a valores via função de espalhamento (*hash function*), oferecendo inserção, remoção e busca em tempo médio constante $O(1)$ em troca de espaço $O(n)$.
2. **Padrões Algorítmicos Aplicados:**
   - **Busca por Complemento (*Complement Lookup*):** Substitui um laço aninhado $O(n^2)$ por consultas $O(1)$ em tabela hash sobre elementos já processados.
   - **Contagem de Frequências (*Frequency Counting / Bucket Array*):** Mapeia ocorrências para vetores de tamanho fixo (ex.: 26 posições para ASCII minúsculo) ou mapas hash, reduzindo comparações de permutação à igualdade de contagens.
   - **Chave Canônica (*Canonical Representation*):** Normaliza entradas equivalentes (como ordenar caracteres de `"eat"`, `"tea"` e `"ate"` para `"aet"`) a fim de agrupá-las diretamente por chave.
   - **Acumulação de Prefixo e Sufixo (*Prefix & Suffix Products/Sums*):** Pré-computa acumulados da esquerda para a direita e da direita para a esquerda para resolver consultas de exclusão por índice em $O(n)$ sem divisão.
   - **Votação de Boyer-Moore (*Boyer-Moore Majority Vote*):** Algoritmo de passagem única que identifica o elemento majoritário ($\lfloor n/2 \rfloor + 1$ ocorrências) em $O(n)$ tempo e $O(1)$ espaço por cancelamento de pares distintos.

## Critérios de Aplicação

| Característica do problema | Abordagem | Complexidade |
|---|---|---|
| Busca de par complementar ou detecção de duplicatas | `std::unordered_map` / `std::unordered_set` | Tempo $O(n)$, Espaço $O(n)$ |
| Verificação ou agrupamento de anagramas | Tabela de frequência fixa (`std::array<int, 26>`) ou chave ordenada | Tempo $O(n)$ ou $O(n \cdot k \log k)$, Espaço $O(1)$ ou $O(n \cdot k)$ |
| Produto/soma de todos os elementos exceto o índice $i$ sem divisão | Passe de prefixo seguido de passe de sufixo | Tempo $O(n)$, Espaço auxiliar $O(1)$ |
| Elemento com frequência estritamente maior que $\lfloor n/2 \rfloor$ | Votação de Boyer-Moore | Tempo $O(n)$, Espaço $O(1)$ |

---

## Problemas

| Problema | Dificuldade | Padrão Principal |
|---|---|---|
| [0001 - Two Sum](./0001-two-sum/README.md) | Fácil | Hash Map · Busca de Complemento em Passagem Única |
| [0217 - Contains Duplicate](./0217-contains-duplicate/README.md) | Fácil | Hash Set · Detecção de Colisão por Inserção |
| [0242 - Valid Anagram](./0242-valid-anagram/README.md) | Fácil | Array de Frequência Estático (*Bucket Counting*) |
| [0169 - Majority Element](./0169-majority-element/README.md) | Fácil | Algoritmo de Votação de Boyer-Moore |
| [0049 - Group Anagrams](./0049-group-anagrams/README.md) | Intermediário | Hash Map com Chave Canônica |
| [0238 - Product of Array Except Self](./0238-product-of-array-except-self/README.md) | Intermediário | Acumulação de Prefixo e Sufixo *In-Place* |
| [0128 - Longest Consecutive Sequence](./0128-longest-consecutive-sequence/README.md) | Intermediário | Hash Set com Detecção de Início de Sequência |
