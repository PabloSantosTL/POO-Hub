#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Livro
{
    string titulo;
    string autor;
    int ano;

public:
    Livro(string t, string a, int y)
    {
        titulo = t;
        autor = a;
        ano = y;
    }

    string getTitulo()
    {
        return titulo;
    }

    string getAutor()
    {
        return autor;
    }

    int getAno()
    {
        return ano;
    }
};

class Biblioteca
{
    string nome;
    vector<Livro> acervo;

public:
    Biblioteca(string n)
    {
        nome = n;
    }

    void adicionarLivro(Livro l)
    {
        acervo.push_back(l);
    }

    void listar()
    {
        cout << "Acervo da " << nome << ":\n";
        for (int i = 0; i < (int)acervo.size(); i++)
            cout << "- " << acervo[i].getTitulo()
                 << " | " << acervo[i].getAutor()
                 << " | " << acervo[i].getAno() << "\n";
    }
};

int main()
{
    Biblioteca bib("Central");

    Livro l1("POO em C++", "Joao Silva", 2010);
    Livro l2("Estruturas de Dados", "Maria Lima", 2015);

    bib.adicionarLivro(l1);
    bib.adicionarLivro(l2);

    bib.listar();

    return 0;
}
