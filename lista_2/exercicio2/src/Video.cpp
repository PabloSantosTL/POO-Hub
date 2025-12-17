#include "Video.h"
#include <iostream>

Video::Video(const std::string& t, int a, int d, const std::string& res, const std::string& c)
    : Midia(t, a, d)
{
    resolucao = res;
    codec = c;
}

void Video::reproduzir()
{
    std::cout << "Reproduzindo video: " << titulo << " (" << resolucao << ")" << std::endl;
}

std::string Video::infoDetalhada()
{
    return "Video: " + titulo + " | " + resolucao + " | " + codec;
}

bool Video::combina(const std::string& filtro)
{
    return resolucao == filtro || codec == filtro;
}
