# 238. Product of Array Except Self

- **Nível:** Intermediário ([LeetCode #238](https://leetcode.com/problems/product-of-array-except-self/))
- **Classificação do Conceito:**
  - **Padrão Algorítmico:** *Prefix & Suffix Decomposition* (Decomposição em Produto de Prefixo e Sufixo)
  - **Técnica de Otimização:** *In-Place Output Accumulation* ($O(1)$ espaço auxiliar)

---

## 1. O que é esse conceito?

O problema exige calcular, para cada posição $i$, o produto de todos os elementos do array exceto `nums[i]`, **em tempo $O(n)$ e sem usar o operador de divisão** (que falharia quando há zeros no vetor).

O padrão **Prefix & Suffix Decomposition** divide o problema em duas metades independentes em torno do índice $i$:

$$\text{answer}[i] = \underbrace{\left(\prod_{j=0}^{i-1} \text{nums}[j]\right)}_{\text{Produto do Prefixo à esquerda de } i} \times \underbrace{\left(\prod_{j=i+1}^{n-1} \text{nums}[j]\right)}_{\text{Produto do Sufixo à direita de } i}$$

Em vez de alocar dois vetores auxiliares (`left[]` e `right[]`), fazemos duas passagens sobre o próprio vetor `answer`:
1. **Da esquerda para a direita:** gravamos em `answer[i]` o produto acumulado de todos os elementos antes de `i`.
2. **Da direita para a esquerda:** mantemos uma variável escalar `suffixProduct` e multiplicamos `answer[i] *= suffixProduct`.

---

## 2. Explicação do Algoritmo Passo a Passo

Para `nums = [1, 2, 3, 4]`:
1. **1ª Passagem (Prefixos):**
   - `i = 0`: `answer[0] = 1`, `prefix = 1 * 1 = 1`
   - `i = 1`: `answer[1] = 1`, `prefix = 1 * 2 = 2`
   - `i = 2`: `answer[2] = 2`, `prefix = 2 * 3 = 6`
   - `i = 3`: `answer[3] = 6`, `prefix = 6 * 4 = 24`
   - Estado parcial de `answer`: `[1, 1, 2, 6]`
2. **2ª Passagem (Sufixos):**
   - `i = 3`: `answer[3] *= 1` $\rightarrow 6$, `suffix = 1 * 4 = 4`
   - `i = 2`: `answer[2] *= 4` $\rightarrow 8$, `suffix = 4 * 3 = 12`
   - `i = 1`: `answer[1] *= 12` $\rightarrow 12$, `suffix = 12 * 2 = 24`
   - `i = 0`: `answer[0] *= 24` $\rightarrow 24$, `suffix = 24 * 1 = 24`
   - Resultado final: `[24, 12, 8, 6]`

---

## 3. Complexidade

- **Tempo:** $O(n)$ — duas passagens lineares simples.
- **Espaço Auxiliar:** $O(1)$ — além do vetor de saída exigido pela assinatura da função, usamos apenas duas variáveis inteiras (`prefix` e `suffix`).
