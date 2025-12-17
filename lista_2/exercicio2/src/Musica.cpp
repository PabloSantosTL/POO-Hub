#include "Musica.h"
#include <iostream>

Musica::Musica(const std::string& t, int a, int d, const std::string& art, int br)
    : Midia(t, a, d)
{
    artista = art;
    bitrate = br;
}

void Musica::reproduzir()
{
    std::cout << "Tocando musica: " << titulo << " - " << artista << std::endl;
}

std::string Musica::infoDetalhada()
{
    return "Musica: " + titulo + " | " + artista + " | " + std::to_string(duracao) + "s";
}

bool Musica::combina(const std::string& filtro)
{
    return artista == filtro;
}
