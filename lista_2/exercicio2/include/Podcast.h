#ifndef PODCAST_H
#define PODCAST_H

#include "Midia.h"
#include <string>

class Podcast : public Midia
{
    std::string host;

public:
    Podcast(const std::string& t, int a, int d, const std::string& host);
    virtual void reproduzir() override;
    virtual std::string infoDetalhada() override;
    virtual bool combina(const std::string& filtro) override;
};

#endif // PODCAST_H
