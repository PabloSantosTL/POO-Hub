#include "Podcast.h"
#include <iostream>

Podcast::Podcast(const std::string& t, int a, int d, const std::string& h)
    : Midia(t, a, d)
{
    host = h;
}

void Podcast::reproduzir()
{
    std::cout << "Podcast: " << titulo << " com " << host << std::endl;
}

std::string Podcast::infoDetalhada()
{
    return "Podcast: " + titulo + " | Host: " + host;
}

bool Podcast::combina(const std::string& filtro)
{
    return host == filtro;
}
