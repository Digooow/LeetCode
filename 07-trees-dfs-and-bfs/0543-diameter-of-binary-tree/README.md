# 543. Diameter of Binary Tree

- **Nível:** Fácil ([LeetCode #543](https://leetcode.com/problems/diameter-of-binary-tree/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Post-Order DFS with Global State Aggregation* (DFS Pós-Ordem Retornando Altura e Atualizando Caminho Máximo)

---

## 1. O que é esse conceito?

O **diâmetro** de uma árvore binária é o maior número de arestas em qualquer caminho entre dois nós (o caminho **não precisa** passar pela raiz principal da árvore).

No entanto, todo caminho simples em uma árvore tem um único **ponto mais alto** (nó de curvatura $u$) onde o caminho sobe da subárvore esquerda de $u$ e desce para a subárvore direita de $u$. Nesse nó $u$, o comprimento do caminho é exatamente:

$$\text{caminho passando por } u = \text{height}(u\to\text{left}) + \text{height}(u\to\text{right})$$

Logo, em uma única DFS Pós-Ordem:
- Cada chamada recursiva `height(node)` **atualiza** `maxDiameter = std::max(maxDiameter, leftHeight + rightHeight)`;
- E **retorna** para o pai a altura vertical `1 + std::max(leftHeight, rightHeight)`.

---

## 2. Complexidade

- **Tempo:** $O(n)$ — evita recalcular alturas repetidamente (que custaria $O(n^2)$).
- **Espaço:** $O(h)$ — profundidade da pilha de recursão.
