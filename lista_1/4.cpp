#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Paciente
{
    string nome;
    int idade;

public:
    Paciente(string n, int i)
    {
        nome = n;
        idade = i;
    }

    string getNome()
    {
        return nome;
    }
};

class Medico
{
    string nome;
    string crm;

public:
    Medico(string n, string c)
    {
        nome = n;
        crm = c;
    }

    string getNome()
    {
        return nome;
    }
};

class Anotacao
{
    string texto;
    string data;

public:
    Anotacao(string t, string d)
    {
        texto = t;
        data = d;
    }

    string getTexto()
    {
        return texto;
    }

    string getData()
    {
        return data;
    }
};

class Prontuario
{
    Paciente* paciente;
    Medico* medico;
    vector<Anotacao> anotacoes;

public:
    Prontuario(Paciente* p, Medico* m)
    {
        paciente = p;
        medico = m;
    }

    void adicionarAnotacao(Anotacao a)
    {
        anotacoes.push_back(a);
    }

    void listar()
    {
        cout << "Prontuario do paciente: " << paciente->getNome()
             << " | Medico responsavel: " << medico->getNome() << "\n";
        for (int i = 0; i < (int)anotacoes.size(); i++)
            cout << anotacoes[i].getData() << " - " << anotacoes[i].getTexto() << "\n";
    }
};

int main()
{
    Paciente pac("Carlos", 45);
    Medico med("Dra. Paula", "CRM12345");

    Prontuario pr(&pac, &med);
    pr.adicionarAnotacao(Anotacao("Pressao normal", "2025-10-01"));
    pr.adicionarAnotacao(Anotacao("Solicitar exame de sangue", "2025-10-15"));

    pr.listar();

    return 0;
}
