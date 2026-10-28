#include <iostream>

using namespace std;

// Função que exibe o menu principal e retorna a opção escolhida pelo usuário
int menu()
{
    system("cls"); // Limpa a tela antes de exibir o menu
    int op;        // Variável para armazenar a opção escolhida pelo usuário

    // Exibe as opções do menu
    cout << "1. Cadastrar Funcionario." << endl;
    cout << "2. Cadastrar Dependente." << endl;
    cout << "3. Listar Funcionarios." << endl;
    cout << "4. Listar Dependente." << endl;
    cout << "5. Editar Funcionario." << endl;
    cout << "6. Editar Dependente." << endl;
    cout << "7. Excluir Funcionario." << endl;
    cout << "0. Sair." << endl;

    cin >> op;    // Lê a opção digitada pelo usuário
    return op;    // Retorna a opção escolhida
}