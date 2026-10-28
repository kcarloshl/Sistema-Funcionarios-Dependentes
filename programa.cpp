#include <iostream>
#include "menu.cpp"
#include "dados.cpp"

using namespace std;

const int MAX_FUNCIONARIO = 100;
const int MAX_DEPENDENTE = 100;

int main()
{
    // Declara vetores para armazenar funcionários e dependentes
    Funcionarios f[MAX_FUNCIONARIO];
    Dependente dp[MAX_DEPENDENTE];
    int qtdFuncionario = 0; // Contador de funcionários cadastrados
    int qtdDependente = 0;  // Contador de dependentes cadastrados
    int op;                 // Variável para armazenar a opção escolhida no menu

    do
    {
        system("cls");
        op = menu(); // Chama a função menu() e armazena a opção escolhida

        if (op == 1) // Cadastro de Funcionário
        {
            system("cls");
            f[qtdFuncionario] = funcionarios(); // Chama função para cadastrar um funcionário
            qtdFuncionario++;                   // Incrementa o contador de funcionários
            system("pause");
        }

        else if (op == 2) // Cadastro de Dependente
        {
            system("cls");
            Dependente novoDependente = dependente(f, qtdFuncionario); // Cadastra um novo dependente
            if (novoDependente.cpfDependente != "") // Verifica se o cadastro foi bem-sucedido
            {

                dp[qtdDependente] = novoDependente; // Adiciona o dependente ao vetor
                qtdDependente++; // Incrementa o contador de dependentes
                system("pause");
            }
        }

        else if (op == 3) // Listar Funcionarios
        {
            system("cls");
            listarFuncionarios(f, qtdFuncionario); // Chama a função para listar os funcionários
            system("pause");
        }

        else if (op == 4) // Listar Dependentes
        {
            system("cls");
            listarDependentes(dp, qtdDependente); // Chama a função para listar os dependentes
            system("pause");
        }

        else if (op == 5) // Editar Funcionário
        {
            system("cls");
            editarFuncionario(f, qtdFuncionario); // Chama a função para editar um funcionário
            system("pause");
        }

        else if (op == 6) // Editar Dependente
        {
            system("cls");
            string cpfFuncionario;
            cout << "Digite o seu CPF (funcionario responsavel): "; // Solicita o CPF do funcionario responsável
            cin >> cpfFuncionario;
            editarDependente(dp, qtdDependente, cpfFuncionario); // Chama a função para editar um dependente
            system("pause");
        }
        
        else if (op == 7) // Excluir funcionario e dependente
        {
            system("cls");
            string cpfFuncionario = excluirFuncionario(f, qtdFuncionario); // Exclui o funcionário e recebe o CPF excluído
            if (cpfFuncionario != "") // Se o CPF não for vazio, ou seja, se o funcionário foi encontrado e excluído
            {
                qtdDependente = excluirDependente(dp, f, qtdDependente, cpfFuncionario); // Exclui os dependentes associados ao CPF
            }
            system("pause");
        }
        
        else if (op != 0)
        {
            cout << "Numero Invalido" << endl; // Exibe mensagem de erro caso a opção escolhida seja inválida
        }

    } while (op != 0); // Continua a execução até que a opção escolhida seja 0
    cout << "Saindo..." << endl;

    return 0;
}
