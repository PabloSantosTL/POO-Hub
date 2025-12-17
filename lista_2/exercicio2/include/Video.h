#ifndef VIDEO_H
#define VIDEO_H

#include "Midia.h"
#include <string>

class Video : public Midia
{
    std::string resolucao;
    std::string codec;

public:
    Video(const std::string& t, int a, int d, const std::string& res, const std::string& c);
    virtual void reproduzir() override;
    virtual std::string infoDetalhada() override;
    virtual bool combina(const std::string& filtro) override;
};

#endif // VIDEO_H
