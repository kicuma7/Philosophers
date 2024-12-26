# Philosophers

## Descrição
Este projeto é baseado no clássico problema dos filósofos, que demonstra os desafios da sincronização e do gerenciamento de recursos compartilhados em programação paralela. A solução utiliza threads e mutexes para garantir que os filósofos possam comer e pensar sem entrar em condições de corrida ou deadlocks.

### Descrição dos Arquivos

#### 1. **Makefile**
- Script para compilar o projeto. Inclui regras para construir, limpar e recompilar os binários.

#### 2. **README.md**
- Documento explicativo sobre o projeto, estrutura, e como utilizá-lo.

#### 3. **includes/philo.h**
- Arquivo de cabeçalho contendo as definições de estruturas, macros e declarações de funções utilizadas em todo o projeto.

#### 4. **src**
- Diretório com o código principal do projeto:
  - **init.c**: Funções para inicializar os dados necessários para a simulação.
  - **main.c**: Função principal que orquestra a execução do programa.
  - **pick_up_forks.c**: Lógica para os filósofos pegarem e soltarem os garfos.
  - **simulation.c**: Funções para gerenciar a lógica da simulação, como os estados dos filósofos (pensando, comendo, etc.).
  - **validation.c**: Verificação e validação de argumentos de entrada.

#### 5. **utls/error.c**
- Funções auxiliares para lidar com mensagens de erro e saídas seguras.

## Como Compilar

Para compilar o projeto, use o comando:

```bash
make
```

Isso criará o executável `philo` no diretório principal.

## Como Executar

Após compilar, execute o programa com os argumentos necessários:

```bash
./philo <número_de_filósofos> <tempo_para_morrer> <tempo_para_comer> <tempo_para_pensar> [número_de_vezes_para_comer]
```

### Argumentos:
- `número_de_filósofos`: Quantidade de filósofos e garfos.
- `tempo_para_morrer`: Tempo máximo (em milissegundos) que um filósofo pode ficar sem comer antes de morrer.
- `tempo_para_comer`: Tempo (em milissegundos) que um filósofo leva para comer.
- `tempo_para_pensar`: Tempo (em milissegundos) que um filósofo leva para pensar.
- `[número_de_vezes_para_comer]`: (Opcional) Quantidade de vezes que cada filósofo deve comer antes do programa terminar.

## Exemplo de Execução

```bash
./philo 5 800 200 200
```

Neste exemplo:
- Existem 5 filósofos e 5 garfos.
- Cada filósofo morre se não comer dentro de 800ms.
- Comer leva 200ms, e pensar também leva 200ms.

## Estrutura e Filosofia do Código

O projeto foi dividido de forma modular para facilitar o entendimento e a manutenção:
- **`includes`**: Centraliza definições comuns para facilitar alterações futuras.
- **`src`**: Contém a lógica principal, separada por responsabilidade.
- **`utls`**: Auxiliares para garantir a robustez do código e tratamento de erros.

## Erros Comuns
- **Argumentos inválidos**: O programa exibirá uma mensagem de erro se os argumentos de entrada não forem válidos.
- **Problemas de sincronização**: Certifique-se de que o ambiente suporta threads adequadamente.

## Próximos Passos
- Implementar melhorias na eficiência do programa.
- Adicionar mais testes para cobrir diferentes cenários e casos de borda.

## Créditos
Desenvolvido por [Seu Nome].

---
Sinta-se à vontade para contribuir ou reportar problemas encontrados durante o uso deste projeto!
