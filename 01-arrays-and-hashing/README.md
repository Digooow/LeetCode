# 01 · Arrays & Hashing (Tabelas Hash, Frequência e Prefixos)

## Qual é o nome correto desse conceito?

Quando resolvemos problemas como **Two Sum**, **Valid Anagram** ou **Product of Array Except Self**, estamos combinando dois conceitos com nomes técnicos precisos na Ciência da Computação:

1. **Estrutura de Dados (*Data Structure*): Tabela Hash (*Hash Table* — `std::unordered_map` e `std::unordered_set`)**
   - Uma estrutura de dados que mapeia chaves a valores usando uma **função de espalhamento (*hash function*)**, permitindo inserção, remoção e busca em tempo médio constante $O(1)$, em vez da busca linear $O(n)$ de um vetor comum.
2. **Padrões Algorítmicos (*Algorithmic Patterns*):**
   - **Busca por Complemento (*Complement Lookup*):** Trocar um segundo laço aninhado $O(n^2)$ por uma consulta $O(1)$ em uma tabela hash perguntando *"o complemento que falta para atingir o alvo já passou por mim?"*.
   - **Contagem de Frequências (*Frequency Counting / Bucket Array*):** Mapear elementos para suas contagens (usando um array fixo de tamanho 26 para letras ASCII ou um `unordered_map`), transformando comparações de permutação/anagrama em igualdade de vetores de frequência.
   - **Chave Canônica (*Canonical Representation*):** Transformar objetos equivalentes (como `"eat"`, `"tea"`, `"ate"`) em uma única assinatura padronizada (`"aet"`) para agrupá-los em $O(1)$ no mapa.
   - **Acumulação de Prefixo e Sufixo (*Prefix & Suffix Products/Sums*):** Pré-computar resultados acumulados da esquerda para a direita e da direita para a esquerda para responder consultas sobre "todos os elementos exceto o índice $i$" em $O(n)$ sem usar divisão.
   - **Votação de Boyer-Moore (*Boyer-Moore Majority Vote Algorithm*):** Um **algoritmo de streaming** que encontra o elemento majoritário ($\lfloor n/2 \rfloor + 1$ ocorrências) em $O(n)$ tempo e $O(1)$ espaço por cancelamento de pares distintos.

---

## Quando reconhecer este padrão na entrevista?

| Sinal no enunciado | Técnica recomendada | Complexidade alvo |
|---|---|---|
| "Encontre dois elementos que somam $X$" / "Existe duplicata?" | `std::unordered_map` / `std::unordered_set` | Tempo $O(n)$, Espaço $O(n)$ |
| "Verifique se duas strings são anagramas" / "Agrupe anagramas" | Contagem de frequência (`int count[26]`) ou Chave Canônica | Tempo $O(n)$, Espaço $O(1)$ ou $O(n)$ |
| "Calcule o produto/soma de todos exceto `nums[i]` sem divisão" | Acumulação de Prefixo + Sufixo | Tempo $O(n)$, Espaço extra $O(1)$ |
| "Elemento que aparece mais de $\lfloor n/2 \rfloor$ vezes em $O(1)$ espaço" | Algoritmo de Votação de Boyer-Moore | Tempo $O(n)$, Espaço $O(1)$ |

---

## Problemas nesta pasta

| Problema | Dificuldade | Conceito / Padrão Principal |
|---|---|---|
| [0001 - Two Sum](./0001-two-sum/README.md) | Fácil | Hash Map · Busca de Complemento em Passagem Única |
| [0217 - Contains Duplicate](./0217-contains-duplicate/README.md) | Fácil | Hash Set · Detecção de Colisão de Cardinalidade |
| [0242 - Valid Anagram](./0242-valid-anagram/README.md) | Fácil | Array de Frequência Estático (*Bucket Counting*) |
| [0169 - Majority Element](./0169-majority-element/README.md) | Fácil | Algoritmo de Votação de Boyer-Moore |
| [0049 - Group Anagrams](./0049-group-anagrams/README.md) | Intermediário | Hash Map com Chave Canônica |
| [0238 - Product of Array Except Self](./0238-product-of-array-except-self/README.md) | Intermediário | Acumulação de Prefixo e Sufixo In-Place |
| [0128 - Longest Consecutive Sequence](./0128-longest-consecutive-sequence/README.md) | Intermediário | Hash Set com Detecção de Início de Sequência ($O(n)$) |
