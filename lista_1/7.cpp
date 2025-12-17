#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item
{
    string nome;

public:
    Item(string n)
    {
        nome = n;
    }

    string getNome()
    {
        return nome;
    }
};

class Arma
{
    string nome;
    int dano;

public:
    Arma(string n, int d)
    {
        nome = n;
        dano = d;
    }

    string getNome()
    {
        return nome;
    }

    int getDano()
    {
        return dano;
    }
};

class Inventario
{
    vector<Item> itens;
    vector<Arma> armas;

public:
    void adicionarItem(Item it)
    {
        itens.push_back(it);
    }

    void adicionarArma(Arma a)
    {
        armas.push_back(a);
    }

    void listar()
    {
        cout << "Itens:\n";
        for (int i = 0; i < (int)itens.size(); i++)
            cout << "- " << itens[i].getNome() << "\n";
        cout << "Armas:\n";
        for (int i = 0; i < (int)armas.size(); i++)
            cout << "- " << armas[i].getNome() << " (dano " << armas[i].getDano() << ")\n";
    }
};

class Jogador
{
    string nome;
    Inventario inv;

public:
    Jogador(string n)
    {
        nome = n;
    }

    Inventario& getInventario()
    {
        return inv;
    }

    void mostrar()
    {
        cout << "Jogador: " << nome << "\n";
        inv.listar();
    }
};

class Inimigo
{
    string tipo;
    Arma arma;

public:
    Inimigo(string t, Arma a) : tipo(t), arma(a) { }

    void mostrar()
    {
        cout << "Inimigo: " << tipo << " com arma " << arma.getNome()
             << " (dano " << arma.getDano() << ")\n";
    }
};

int main()
{
    Jogador j("Heroi");
    j.getInventario().adicionarItem(Item("Poçao"));
    j.getInventario().adicionarArma(Arma("Espada", 25));

    Inimigo inim("Goblin", Arma("Clava", 10));

    j.mostrar();
    inim.mostrar();

    return 0;
}
