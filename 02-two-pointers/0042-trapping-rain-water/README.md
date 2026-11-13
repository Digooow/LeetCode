# 0042 · Trapping Rain Water

**Dificuldade:** Difícil (Hard) | **Categoria:** Two Pointers | **Arquivo:** [solution.cpp](./solution.cpp)

## Problema

Dado um mapa de elevação representado pelo vetor de inteiros não negativos `height` (barras de largura unitária), calcular o volume total de água que pode ficar retido entre as barras após uma chuva.

## Abordagem

A água retida sobre a posição $i$ é determinada por $\min(\text{maxLeft}[i], \text{maxRight}[i]) - \text{height}[i]$. Em vez de pré-computar dois vetores auxiliares em $O(n)$ de memória, `trap` resolve o cálculo com ponteiros convergentes (`left`, `right`) e rastreadores escalares `leftMax` e `rightMax`:

- Se `height[left] <= height[right]`: sabe-se que existe à direita pelo menos uma parede de altura $\ge \text{height}[\text{left}]$. Portanto, o gargalo efetivo em `left` depende apenas de `leftMax` (já visto até `left`). Atualiza-se `leftMax`, soma-se `leftMax - height[left]` em `totalWater` e avança `++left`.
- Caso contrário (`height[left] > height[right]`): por simetria, o lado esquerdo garante uma barreira maior ou igual; o nível de água em `right` é determinado exclusivamente por `rightMax`. Atualiza-se `rightMax`, acumula-se `rightMax - height[right]` e recua `--right`.

## Complexidade

- **Tempo:** $O(n)$ — cada índice é processado exatamente uma vez pelos ponteiros `left` e `right`.
- **Espaço:** $O(1)$ — apenas cinco variáveis escalares.
