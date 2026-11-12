# 56. Merge Intervals

- **Nível:** Intermediário ([LeetCode #56](https://leetcode.com/problems/merge-intervals/))
- **Classificação do Conceito:**
  - **Paradigma:** *Greedy Algorithm* (Algoritmo Guloso)
  - **Padrão Algorítmico:** *Interval Sorting & Linear Sweep* (Ordenação de Intervalos e Varredura Linear)

---

## 1. O que é esse conceito?

Problemas de agendamento e sobreposição de horários (como o próprio sistema de reservas de salas que você desenvolveu no `Projeto-Integrador2`!) usam o padrão **Interval Sweep**:
1. Ordenamos todos os intervalos pelo horário de início `interval[0]` ($O(n \log n)$).
2. Graças a essa ordenação, todos os intervalos que podem se sobrepor ao intervalo atual são obrigatoriamente **contíguos** na lista ordenada!
3. Mantemos o último intervalo mesclado em `merged.back()`:
   - Se `curr.start <= merged.back().end`, há sobreposição $\rightarrow$ estendemos o fim de forma gulosa: `merged.back()[1] = std::max(merged.back()[1], curr[1])`.
   - Caso contrário, não há sobreposição $\rightarrow$ iniciamos um novo intervalo em `merged`.

---

## 2. Complexidade

- **Tempo:** $O(n \log n)$ dominado pela ordenação inicial.
- **Espaço Auxiliar:** $O(\log n)$ da ordenação (além do vetor de resposta).
