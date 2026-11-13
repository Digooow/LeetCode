# 0001 · Two Sum

**Dificuldade:** Fácil | **Categoria:** Arrays & Hashing | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor de inteiros `nums` e um inteiro `target`, retornar os índices `[i, j]` ($i \neq j$) tais que $\text{nums}[i] + \text{nums}[j] = \text{target}$. Assume-se exatamente uma solução válida e o mesmo índice não pode ser reutilizado.

## Abordagem

Uma busca por força bruta comparando todos os pares $(i, j)$ custaria $O(n^2)$. Em `twoSum`, o problema é reduzido a uma passagem única utilizando `std::unordered_map<int, int>` (`seen`), mapeando `valor -> índice`.

Para cada elemento `nums[i]`:
1. Calcula-se `complement = target - nums[i]`.
2. Consulta-se `seen.find(complement)`: se encontrado, `{it->second, i}` é retornado imediatamente.
3. Caso contrário, `nums[i]` e seu índice `i` são registrados em `seen`.

**Detalhes de implementação:**
- `seen.reserve(nums.size())` evita *rehashings* intermediários durante a inserção.
- A inserção após a consulta garante que o mesmo elemento não seja pareado consigo mesmo (ex.: `nums = [3, 3]`, `target = 6` funciona corretamente no segundo índice).

## Complexidade

- **Tempo:** $O(n)$ — passagem única com consultas e inserções médias em $O(1)$ na tabela hash.
- **Espaço:** $O(n)$ — armazenamento de até $n$ pares chave-valor em `seen`.
