# LeetCode Solutions

Repositório com minhas soluções para problemas do
[LeetCode](https://leetcode.com/u/digooow/), desenvolvido como parte do estudo
contínuo de algoritmos, estruturas de dados e resolução de problemas.

O objetivo não é apenas armazenar respostas, mas registrar a evolução do
raciocínio: estratégia escolhida, complexidade, implementação e aprendizados de
cada exercício.

## Objetivos

- Fortalecer lógica de programação e raciocínio computacional;
- praticar algoritmos e estruturas de dados fundamentais;
- desenvolver soluções eficientes em C++;
- comparar abordagens com diferentes custos de tempo e memória;
- criar uma base de revisão para entrevistas e desafios técnicos.

## Soluções disponíveis

| Problema | Arquivo | Dificuldade | Estratégia | Complexidade |
|---|---|---:|---|---|
| [Two Sum](https://leetcode.com/problems/two-sum/) | [`TwoSum.cpp`](./TwoSum.cpp) | Fácil | Tabela hash para buscar o complemento | O(n) tempo, O(n) espaço |

### Two Sum

Dado um vetor de inteiros e um valor-alvo, a solução deve encontrar dois
índices cujos valores somem ao alvo.

A implementação percorre o vetor uma única vez. Para cada elemento, calcula o
complemento necessário (`target - nums[i]`) e verifica se ele já foi encontrado
em um `unordered_map`. Quando encontra o complemento, retorna os dois índices.

Essa abordagem evita a comparação de todos os pares, que teria complexidade
O(n²), e reduz o tempo para O(n) usando memória adicional O(n).

## Estrutura atual

```text
.
├── TwoSum.cpp   # Solução do problema Two Sum com teste local
├── .gitignore   # Ignora executáveis gerados pela compilação
└── README.md    # Documentação do repositório
```

Conforme novas soluções forem adicionadas, a organização poderá evoluir para
categorias como:

```text
arrays/
strings/
hashing/
two-pointers/
binary-search/
linked-list/
trees/
graphs/
dynamic-programming/
```

## Tecnologias

- **C++**
- **STL (Standard Template Library)**
  - `vector` para armazenamento dos valores;
  - `unordered_map` para busca média O(1) dos complementos;
- Compilador compatível com **C++17** ou versão posterior.

## Como compilar e executar

### Windows — MinGW g++

Na raiz do repositório:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic .\TwoSum.cpp -o .\TwoSum.exe
.\TwoSum.exe
```

Saída esperada:

```text
Indices: [0, 1]
```

O arquivo `.gitignore` evita que o executável gerado seja versionado.

### Linux ou macOS

```bash
g++ -std=c++17 -Wall -Wextra -pedantic TwoSum.cpp -o TwoSum
./TwoSum
```

## Compatibilidade com o LeetCode

No ambiente do LeetCode, a plataforma fornece a classe `Solution` e executa o
método da solução. O arquivo deste repositório também contém um `main` para
permitir compilação e validação local:

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};
```

Ao enviar a solução para o LeetCode, o `main` não é necessário; normalmente
basta utilizar a classe `Solution` e a assinatura exigida pelo problema.

## Critérios para novas soluções

Cada novo exercício deve, sempre que possível:

1. usar um nome de arquivo relacionado ao problema;
2. incluir o link para o enunciado;
3. registrar a estratégia adotada;
4. informar complexidade de tempo e espaço;
5. conter casos de teste representativos;
6. evitar dependências externas desnecessárias;
7. manter o código compatível com C++17 ou posterior.

Uma entrada futura na tabela pode seguir este formato:

```markdown
| [Nome do problema](link) | [`Arquivo.cpp`](./Arquivo.cpp) | Médio |
| Estratégia principal | O(n) tempo, O(1) espaço |
```

## Próximos passos

- Adicionar soluções de arrays, strings, hashing e busca binária;
- organizar os exercícios por tema e dificuldade;
- incluir casos de borda nas execuções locais;
- registrar alternativas menos eficientes para fins de estudo;
- adicionar testes automatizados quando o volume de soluções justificar;
- documentar padrões recorrentes, como sliding window, two pointers, BFS,
  DFS e programação dinâmica.

## Status

🚧 **Em evolução** — atualmente o repositório contém a solução de
**Two Sum**. Novos problemas serão adicionados conforme o avanço dos estudos.

Sugestões de melhoria e discussões sobre as abordagens são bem-vindas.
