# 0011 · Container With Most Water

**Dificuldade:** Intermediário | **Categoria:** Two Pointers | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um vetor `height` de $n$ alturas verticais, escolher duas linhas $(i, j)$ que formem, junto ao eixo horizontal, um recipiente com a maior área possível de água: $(j - i) \cdot \min(\text{height}[i], \text{height}[j])$.

## Abordagem

`maxArea` inicializa dois ponteiros nos extremos (`left = 0` e `right = n - 1`), maximizando a largura inicial `width = right - left`.

A cada passo no laço `while (left < right)`:
1. Calcula a área corrente `width * std::min(height[left], height[right])` e atualiza `best`.
2. Desloca o ponteiro cuja barra é **menor**: se `height[left] < height[right]`, avança `++left`; caso contrário, recua `--right`.

**Justificativa da escolha gulosa:** mover a barra mais alta nunca aumenta a área em relação à largura já reduzida, pois a altura do recipiente continua limitada pela menor barra (`minHeight`). Descartar o menor limitante é a única transição capaz de alcançar uma altura mínima superior.

## Complexidade

- **Tempo:** $O(n)$ — cada elemento é examinado por no máximo um dos ponteiros convergentes.
- **Espaço:** $O(1)$ — apenas variáveis escalares para os índices e máximo acumulado.
