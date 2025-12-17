#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Parada
{
    string nome;

public:
    Parada(string n)
    {
        nome = n;
    }

    string getNome()
    {
        return nome;
    }
};

class Rota
{
    string nome;
    vector<Parada> paradas;

public:
    Rota(string n)
    {
        nome = n;
    }

    void adicionarParada(Parada p)
    {
        paradas.push_back(p);
    }

    void listar()
    {
        cout << "Rota: " << nome << "\n";
        for (int i = 0; i < (int)paradas.size(); i++)
            cout << "- " << paradas[i].getNome() << "\n";
    }
};

class Motorista
{
    string nome;

public:
    Motorista(string n)
    {
        nome = n;
    }

    string getNome()
    {
        return nome;
    }
};

class Onibus
{
    string id;
    Rota rota;
    Motorista* motorista; // pode ser null

public:
    Onibus(string i, Rota r) : id(i), rota(r)
    {
        motorista = nullptr;
    }

    void atribuirMotorista(Motorista* m)
    {
        motorista = m;
    }

    void mostrar()
    {
        cout << "Ônibus " << id << "\n";
        if (motorista != nullptr)
            cout << "Motorista: " << motorista->getNome() << "\n";
        rota.listar();
    }
};

class Empresa
{
    string nome;
    vector<Onibus> frota;
    vector<Motorista> motoristas;

public:
    Empresa(string n)
    {
        nome = n;
    }

    void adicionarMotorista(Motorista m)
    {
        motoristas.push_back(m);
    }

    void adicionarOnibus(Onibus o)
    {
        frota.push_back(o);
    }

    void listarFrota()
    {
        cout << "Empresa: " << nome << "\n";
        for (int i = 0; i < (int)frota.size(); i++)
        {
            frota[i].mostrar();
            cout << "\n";
        }
    }

    Motorista* getMotorista(int idx)
    {
        if (idx < 0 || idx >= (int)motoristas.size()) return nullptr;
        return &motoristas[idx];
    }
};

int main()
{
    Rota r("Centro-Leste");
    r.adicionarParada(Parada("Parada A"));
    r.adicionarParada(Parada("Parada B"));

    Motorista m1("Carlos");
    Empresa emp("ViaRapida");
    emp.adicionarMotorista(m1);

    Onibus o1("100", r);
    o1.atribuirMotorista(emp.getMotorista(0));

    emp.adicionarOnibus(o1);
    emp.listarFrota();

    return 0;
}
