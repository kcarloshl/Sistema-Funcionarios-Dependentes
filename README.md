# Sistema de Cadastro de Funcionários e Dependentes

Projeto desenvolvido como trabalho prático final da disciplina de **Introdução à Programação**, utilizando a linguagem C++.

## Sobre o projeto

O sistema permite cadastrar e gerenciar funcionários e seus respectivos dependentes por meio de um menu interativo no terminal. Os dados são armazenados em vetores durante a execução do programa, sem utilização de banco de dados ou armazenamento permanente em arquivos.

## Funcionalidades

- Cadastro de funcionários, incluindo nome, CPF, telefone e e-mail.
- Cadastro de dependentes, com nome, CPF e data de nascimento.
- Associação de dependentes aos funcionários por meio do CPF do responsável.
- Listagem de funcionários cadastrados.
- Listagem de dependentes cadastrados.
- Edição dos dados de funcionários.
- Edição dos dados de dependentes.
- Exclusão de funcionários e dos respectivos dependentes associados.
- Menu interativo para navegação pelas funcionalidades do sistema.

## Tecnologias utilizadas

- **Linguagem:** C++
- **Biblioteca:** `iostream`
- **Ambiente de desenvolvimento:** Visual Studio Code (VS Code)
- **Compilador:** G++ (MinGW no Windows, por exemplo)

## Estrutura do projeto

```text
sistema-funcionarios/
├── programa.cpp
├── menu.cpp
├── dados.cpp
├── README.md
└── .gitignore
```

### Descrição dos arquivos

- `programa.cpp`: contém a função principal `main()` e controla o fluxo de execução do sistema.
- `menu.cpp`: apresenta o menu principal e recebe a opção escolhida pelo usuário.
- `dados.cpp`: contém as estruturas de dados e as funções de cadastro, listagem, edição e exclusão.

## Como executar

### 1. Instale um compilador C++

No Windows, você pode utilizar o G++ por meio do MinGW-w64.

### 2. Abra o projeto no VS Code

Abra a pasta do projeto no Visual Studio Code e certifique-se de que o compilador G++ esteja instalado e acessível pelo terminal.

### 3. Compile o programa

No terminal integrado do VS Code, execute:

```bash
g++ programa.cpp -o programa
```

### 4. Execute o programa

No terminal do Windows, execute:

```powershell
.\programa.exe
```

**Observação:** o projeto utiliza `system("cls")` e `system("pause")`, comandos específicos do ambiente Windows. Por isso, a execução foi pensada para esse sistema operacional.

## Limitações atuais

- Os dados cadastrados são mantidos apenas durante a execução do programa.
- O sistema utiliza vetores com capacidade definida de até 100 funcionários e 100 dependentes.
- Não há persistência em arquivos ou banco de dados.

## Objetivo acadêmico

Aplicar os conceitos fundamentais de programação em C++, incluindo variáveis, estruturas, funções, vetores, estruturas condicionais, laços de repetição e manipulação de dados.

---

**Projeto acadêmico — Introdução à Programação.**