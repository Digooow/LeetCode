# 100. Same Tree

- **Nível:** Fácil ([LeetCode #100](https://leetcode.com/problems/same-tree/))
- **Classificação do Conceito:**
  - **Algoritmo:** *Simultaneous Pre-Order DFS* (Travessia Simultânea de Árvores em Profundidade)

---

## 1. O que é esse conceito?

Para verificar isomorfismo estrutural e igualdade de valores entre duas árvores binárias `p` e `q`, percorremos **ambas simultaneamente** em Pré-Ordem:
1. Se `p == nullptr && q == nullptr`, ambas terminaram juntas neste ramo (`true`).
2. Se apenas uma for `nullptr` ou `p->val != q->val`, encontramos uma diferença (`false`).
3. Caso contrário, exigimos recursivamente `isSameTree(p->left, q->left) && isSameTree(p->right, q->right)`.

---

## 2. Complexidade

- **Tempo:** $O(\min(n, m))$ — para no primeiro nó divergente.
- **Espaço:** $O(\min(h_p, h_q))$ na pilha de chamadas.
