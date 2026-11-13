# 0739 · Daily Temperatures

**Dificuldade:** Intermediário | **Categoria:** Stack & Monotonic Stack | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros `temperatures` em que `temperatures[i]` representa a temperatura do dia `i`, retornar um vetor `answer` em que `answer[i]` indica quantos dias após `i` ocorre a primeira temperatura estritamente maior (ou `0` caso não ocorra).

## Abordagem

`dailyTemperatures` mantém um vetor `answer(n, 0)` e uma pilha monotônica decrescente de índices `std::stack<int> pendingIndices`, armazenando dias que ainda aguardam uma temperatura superior à frente.

Para cada dia `i` de `0` a `n - 1`:
1. Enquanto `pendingIndices` não estiver vazia e `temperatures[i] > temperatures[pendingIndices.top()]`:
   - Retira-se o índice `prevDay` do topo.
   - Registra-se a distância em dias diretamente em `answer[prevDay] = i - prevDay`.
2. Empilha-se `i` em `pendingIndices`.

Índices que restarem na pilha ao final do percurso preservam o valor padrão `0` em `answer`.

## Complexidade

- **Tempo:** $O(n)$ — cada índice é empilhado uma vez e desempilhado no máximo uma vez ao longo de todo o laço.
- **Espaço:** $O(n)$ — no pior caso (temperaturas em ordem não crescente), `pendingIndices` armazena todos os $n$ índices.
