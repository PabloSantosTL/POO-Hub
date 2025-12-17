#ifndef MUSICA_H
#define MUSICA_H

#include "Midia.h"
#include <string>

class Musica : public Midia
{
    std::string artista;
    int bitrate;

public:
    Musica(const std::string& t, int a, int d, const std::string& artista, int bitrate);
    virtual void reproduzir() override;
    virtual std::string infoDetalhada() override;
    virtual bool combina(const std::string& filtro) override;
};

#endif // MUSICA_H
