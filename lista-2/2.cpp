#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Midia
{
protected:
    string titulo;
    int ano;
    int duracao;

public:
    Midia(string t, int a, int d)
    {
        titulo = t;
        ano = a;
        duracao = d;
    }

    virtual ~Midia() {}

    virtual void reproduzir() = 0;
    virtual string infoDetalhada() = 0;
    virtual bool combina(string filtro) = 0;
};

class Musica : public Midia
{
    string artista;

public:
    Musica(string t, int a, int d, string art)
        : Midia(t, a, d)
    {
        artista = art;
    }

    void reproduzir()
    {
        cout << "Tocando musica: " << titulo << endl;
    }

    string infoDetalhada()
    {
        return "Musica: " + titulo + " - " + artista;
    }

    bool combina(string filtro)
    {
        return artista == filtro;
    }
};

class Video : public Midia
{
    string resolucao;

public:
    Video(string t, int a, int d, string r)
        : Midia(t, a, d)
    {
        resolucao = r;
    }

    void reproduzir()
    {
        cout << "Reproduzindo video: " << titulo << endl;
    }

    string infoDetalhada()
    {
        return "Video: " + titulo + " (" + resolucao + ")";
    }

    bool combina(string filtro)
    {
        return resolucao == filtro;
    }
};

class Podcast : public Midia
{
    string host;

public:
    Podcast(string t, int a, int d, string h)
        : Midia(t, a, d)
    {
        host = h;
    }

    void reproduzir()
    {
        cout << "Podcast com " << host << endl;
    }

    string infoDetalhada()
    {
        return "Podcast: " + titulo + " - Host: " + host;
    }

    bool combina(string filtro)
    {
        return host == filtro;
    }
};

int main()
{
    vector<unique_ptr<Midia>> catalogo;

    catalogo.push_back(make_unique<Musica>("Song A", 2020, 200, "Artista X"));
    catalogo.push_back(make_unique<Video>("Video B", 2021, 600, "1080p"));
    catalogo.push_back(make_unique<Podcast>("Podcast C", 2022, 1800, "Joao"));

    for (int i = 0; i < catalogo.size(); i++)
    {
        cout << catalogo[i]->infoDetalhada() << endl;
        catalogo[i]->reproduzir();
    }

    return 0;
}
