#include <iostream>
using namespace std;

// Estrutura para armazenar informações dos funcionários
struct Funcionarios
{
    string nome, email, cpf, telefone;
};

// Estrutura para armazenar informações dos dependentes
struct Dependente
{
    string cpfDependente, cpfDoFuncionario, nomeDependente, dataNascimento;
};

// Função para cadastrar um funcionário e retornar a estrutura preenchida
Funcionarios funcionarios()
{
    Funcionarios f;
    cout << "---- CADASTRO DE FUNCIONARIOS ----" << endl;
    cout << "Nome do Funcionario: ";
    cin.ignore();
    getline(cin, f.nome); // Recebe o nome do funcionário
    cout << "CPF: ";
    cin >> f.cpf; // Recebe o CPF
    cout << "Telefone: ";
    cin >> f.telefone; // Recebe o telefone
    cout << "Email: ";
    cin.ignore();
    getline(cin, f.email); // Recebe o email
    cout << "---------------------------------" << endl;
    cout << "Funcionario cadastrado com sucesso!" << endl;
    return f;       // Retorna o funcionário cadastrado
}

// Função para cadastrar um dependente e retornar a estrutura preenchida
Dependente dependente(Funcionarios f[], int n)
{
    Dependente dp;
    int indiceFuncionario = -1; // Variável para armazenar o índice do funcionário correspondente ao CPF informado

    cout << "---- CADASTRO DE DEPENDENTES ----" << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, dp.nomeDependente); // Recebe o nome do dependente
    cout << "CPF: ";
    cin >> dp.cpfDependente; // Recebe o CPF do dependente
    cout << "Data de Nascimento: ";
    cin.ignore();
    getline(cin, dp.dataNascimento);// Recebe a data de nascimento do dependente
    cout << "CPF do Funcionario: ";
    cin >> dp.cpfDoFuncionario; // Recebe o CPF do funcionário associado
    cout << "---------------------------------" << endl;

    // Procura o CPF do funcionário no array de funcionários
    for (int i = 0; i < n; i++)
    {
        if (dp.cpfDoFuncionario == f[i].cpf) // Verifica se o CPF do funcionário existe no cadastro
        {
            indiceFuncionario = i; // Armazena o indice do funcionario
            break;                 // Interrompe o loop ao encontrar o funcionário
        }
    }
    if (indiceFuncionario != -1)
    {
        cout << "Dependente cadastrado com sucesso!" << endl; // Mensagem de sucesso se o CPF for encontrado
    }
    else
    {
        cout << "CPF de funcionario nao localizado!" << endl; // Mensagem de erro se o CPF não for encontrado
        dp.cpfDependente = "";                                // Invalida o dependente
    }

    return dp; // Retorna a estrutura de dependente, preenchida ou vazia
}

// Função para listar os funcionários cadastrados
void listarFuncionarios(Funcionarios f[], int n)
{
    if (n == 0)
    {
       cout << "Nenhum funcionario cadastrado." << endl;
       return;
    }
    
    cout << "---- FUNCIONARIOS ----" << endl;
    for (int i = 0; i < n; i++) // Percorre o vetor de funcionários
    {
        cout << "Nome: " << f[i].nome << endl;
        cout << "CPF: " << f[i].cpf << endl;
        cout << "Telefone: " << f[i].telefone << endl;
        cout << "Email: " << f[i].email << endl;
        cout << "---------------------------" << endl;
    }
}

// Função para listar os dependentes cadastrados
void listarDependentes(Dependente dp[], int n)
{
    if (n == 0)
    {
       cout << "Nenhum dependente cadastrado." << endl;
       return;
    }
    cout << "---- DEPENDENTES ----" << endl;
    for (int i = 0; i < n; i++) // Percorre o vetor de dependentes
    {
        
        cout << "Nome: " << dp[i].nomeDependente << endl;
        cout << "CPF: " << dp[i].cpfDependente << endl;
        cout << "Data de Nascimento: " << dp[i].dataNascimento << endl;
        cout << "CPF do Funcionario Responsavel: " << dp[i].cpfDoFuncionario << endl;
        cout << "---------------------------" << endl;
    }
}

// Função para editar os dados de um funcionário a partir do CPF
void editarFuncionario(Funcionarios f[], int n)
{
    string cpf;
    cout << "Digite o CPF do funcionario que voce deseja editar: " << endl;
    cin >> cpf; // Recebe o CPF do funcionário a ser editado

    for (int i = 0; i < n; i++)
    {
        if (f[i].cpf == cpf) // Verifica se o CPF corresponde
        {
            cout << "Novo nome: " << endl;
            cin.ignore();
            getline(cin, f[i].nome); // Edita o nome
            cout << "Novo Telefone: ";
            cin >> f[i].telefone; // Edita o telefone
            cout << "Novo Email: ";
            cin.ignore();
            getline(cin, f[i].email); // Edita o email
            cout << "Funcionario editado!" << endl;
            return;
        }
        else
        {
            // Se o CPF não for encontrado, exibe uma mensagem
            cout << "CPF Invalido!" << endl;
        }
    }
}
void editarDependente(Dependente dp[], int n, string cpfFuncionario)
{
    string cpfDependente;
    int indice = -1;
    cout << "Digite o CPF do dependente que voce deseja editar: " << endl;
    cin >> cpfDependente; // Recebe o CPF do dependente a ser editado

    for (int i = 0; i < n; i++)
    {
        // Verifica se o CPF corresponde e se o CPF do funcionário é o responsável por esse dependente
        if (dp[i].cpfDependente == cpfDependente && dp[i].cpfDoFuncionario == cpfFuncionario) 
        {
            indice = i;
            break;
        }
    }
    if (indice != -1)
    {
        cout << "Novo nome: " << endl;
        cin.ignore();
        getline(cin, dp[indice].nomeDependente); // Edita o nome
        cout << "Data de Nascimento: ";   
        getline(cin, dp[indice].dataNascimento);// Edita a data de nascimento do dependente
        cout << "Dependente editado!" << endl;
    }
    else
    {
         // Se o CPF não for encontrado, exibe uma mensagem
        cout << "CPF invalido ou voce nao tem permissao para editar este dependente!" << endl;
    }
}

// Função para excluir um funcionário a partir do CPF
string excluirFuncionario(Funcionarios f[], int& n)
{
    string cpf;
    cout << "Digite o CPF do funcionario que voce deseja excluir: " << endl;
    cin >> cpf;      // Recebe o CPF do funcionario a ser excluído
    int indice = -1; // Armazena o indice do funcionário, inicia com -1 indicando que não foi encontrado

    // Loop para procurar o funcionário pelo CPF
    for (int i = 0; i < n; i++)
    {

        if (f[i].cpf == cpf) // Verifica se o CPF no vetor de funcionários corresponde ao CPF informado
        {
            indice = i; // Armazena o indice do funcionario encontrado
            break;
        }
    }

    // Verifica se o CPF foi encontrado
    if (indice == -1)
    {
        cout << "Funcionario com CPF " << cpf << " nao encontrado!" << endl;
        return ""; // Retorna o número total de funcionários sem alterações
    }

    // Desloca os funcionários no vetor para "remover" o funcionário encontrado
    for (int i = indice; i < n - 1; i++)
    {
        f[i] = f[i + 1]; // Sobscreve o funcionário atual com o próximo da lista
    }
    n--; // Reduz o número total de funcionários
    cout << "Funcionario excluido com sucesso!" << endl;
    return cpf; // Retorna o CPF do funcionário excluído
}

// Função para excluir dependentes de um funcionário a partir do CPF do funcionário
int excluirDependente(Dependente dp[], Funcionarios f[], int qtdDependente, string cpfFuncionario)
{
    int novosQtdDependente = qtdDependente; // Variável para armazenar o novo número de dependentes, inicializado com o valor atual

    // Loop para percorrer todos os dependentes
    for (int i = 0; i < novosQtdDependente; i++)
    {
        // Verifica se o dependente pertence ao funcionário pelo CPF do funcionário
        if (dp[i].cpfDoFuncionario == cpfFuncionario)
        {
            // Se o dependente for encontrado, desloca os elementos no vetor para "remover" o dependente
            for (int j = i; j < novosQtdDependente - 1; j++)
            {
                dp[j] = dp[j + 1]; // Sobrescreve o dependente atual com o próximo da lista
            }
            novosQtdDependente--; // Reduz o número de dependentes após a exclusão
            i--;                  // Ajusta o índice para continuar verificando no mesmo ponto, já que o vetor foi deslocado
        }
    }

    cout << "Dependentes do funcionario com CPF " << cpfFuncionario << " excluidos!" << endl;
    return novosQtdDependente; // Retorna o novo número total de dependentes
}