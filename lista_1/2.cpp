#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Musica
{
    string titulo;
    string artista;
    int duracao; // segundos

public:
    Musica(string t, string a, int d)
    {
        titulo = t;
        artista = a;
        duracao = d;
    }

    string getTitulo()
    {
        return titulo;
    }

    string getArtista()
    {
        return artista;
    }
};

class Playlist
{
    string nome;
    vector<Musica> musicas;

public:
    Playlist(string n)
    {
        nome = n;
    }

    void adicionar(Musica m)
    {
        musicas.push_back(m);
    }

    void listar()
    {
        cout << "Playlist: " << nome << "\n";
        for (int i = 0; i < (int)musicas.size(); i++)
            cout << i+1 << " - " << musicas[i].getTitulo()
                 << " (" << musicas[i].getArtista() << ")\n";
    }
};

class Usuario
{
    string nome;
    vector<Playlist> playlists;

public:
    Usuario(string n)
    {
        nome = n;
    }

    void criarPlaylist(Playlist p)
    {
        playlists.push_back(p);
    }

    void listarPlaylists()
    {
        cout << "Playlists de " << nome << ":\n";
        for (int i = 0; i < (int)playlists.size(); i++)
        {
            playlists[i].listar();
            cout << "\n";
        }
    }
};

int main()
{
    Usuario u("Pablo");

    Playlist p1("Favoritas");
    p1.adicionar(Musica("Musica A", "Artista 1", 210));
    p1.adicionar(Musica("Musica B", "Artista 2", 180));

    u.criarPlaylist(p1);

    Playlist p2("Treino");
    p2.adicionar(Musica("Track X", "DJ Y", 200));
    u.criarPlaylist(p2);

    u.listarPlaylists();

    return 0;
}
