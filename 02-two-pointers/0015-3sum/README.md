# 0015 · 3Sum

**Dificuldade:** Intermediário | **Categoria:** Two Pointers | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros `nums`, retornar todas as trincas únicas `[nums[i], nums[j], nums[k]]` com índices distintos tais que $\text{nums}[i] + \text{nums}[j] + \text{nums}[k] = 0$, sem duplicatas na saída.

## Abordagem

`threeSum` recebe uma cópia de `nums`, ordena-a com `std::sort` e fixa um pivô `nums[i]` da esquerda para a direita reduzindo o restante do subproblema ao par ordenado com soma `-nums[i]`:

1. **Poda antecipada:** se `nums[i] > 0`, encerra-se o laço, pois todos os valores seguintes à direita também são positivos.
2. **Deduplicação do pivô:** se `i > 0 && nums[i] == nums[i - 1]`, ignora-se o pivô repetido.
3. **Dois ponteiros convergentes:** para `left = i + 1` e `right = n - 1`:
   - `sum < 0` avança `++left`;
   - `sum > 0` recua `--right`;
   - `sum == 0` registra `{nums[i], nums[left], nums[right]}` em `triplets`, move ambos os ponteiros e pula valores adjacentes repetidos em `left` e `right`.

## Complexidade

- **Tempo:** $O(n^2)$ — $O(n \log n)$ da ordenação seguido por laço externo $O(n)$ e varredura linear interna de dois ponteiros $O(n)$.
- **Espaço:** $O(\log n)$ a $O(n)$ dependendo da pilha da ordenação e da cópia local de `nums`, desconsiderando o vetor `triplets` de resposta.
