#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Funcionario
{
protected:
    int id;
    string nome;
    string documento;

public:
    Funcionario(int i, string n, string d)
    {
        id = i;
        nome = n;
        documento = d;
    }

    virtual ~Funcionario() {}

    virtual double calcularPagamento() = 0;
    virtual string demonstrativo() = 0;
};

class Assalariado : public Funcionario
{
    double salario;

public:
    Assalariado(int i, string n, string d, double s)
        : Funcionario(i, n, d)
    {
        salario = s;
    }

    double calcularPagamento()
    {
        return salario;
    }

    string demonstrativo()
    {
        return "Assalariado: " + nome + " | Salario: " + to_string(salario);
    }
};

class Horista : public Funcionario
{
    double valorHora;
    int horas;

public:
    Horista(int i, string n, string d, double vh, int h)
        : Funcionario(i, n, d)
    {
        valorHora = vh;
        horas = h;
    }

    double calcularPagamento()
    {
        int horasNormais = horas > 44 ? 44 : horas;
        int extras = horas > 44 ? horas - 44 : 0;

        return horasNormais * valorHora +
               extras * valorHora * 1.5;
    }

    string demonstrativo()
    {
        return "Horista: " + nome + " | Total: " + to_string(calcularPagamento());
    }
};

class Comissionado : public Funcionario
{
    double vendas;
    double percentual;
    double teto;
    double salarioBase;

public:
    Comissionado(int i, string n, string d,
                 double v, double p, double t, double sb)
        : Funcionario(i, n, d)
    {
        vendas = v;
        percentual = p;
        teto = t;
        salarioBase = sb;
    }

    double calcularPagamento()
    {
        double comissao = vendas * percentual / 100.0;
        if (comissao > teto)
            comissao = teto;

        return salarioBase + comissao;
    }

    string demonstrativo()
    {
        return "Comissionado: " + nome + " | Total: " + to_string(calcularPagamento());
    }
};

int main()
{
    vector<unique_ptr<Funcionario>> funcionarios;

    funcionarios.push_back(make_unique<Assalariado>(1, "Ana", "111", 3000));
    funcionarios.push_back(make_unique<Horista>(2, "Bruno", "222", 50, 50));
    funcionarios.push_back(make_unique<Comissionado>(3, "Carlos", "333", 20000, 5, 1500, 1000));

    for (int i = 0; i < funcionarios.size(); i++)
        cout << funcionarios[i]->demonstrativo() << endl;

    return 0;
}
