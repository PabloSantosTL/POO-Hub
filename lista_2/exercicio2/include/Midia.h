#ifndef MIDIA_H
#define MIDIA_H

#include <string>

class Midia
{
protected:
    std::string titulo;
    int ano;
    int duracao; // segundos

public:
    Midia(const std::string& t, int a, int d);
    virtual ~Midia();

    virtual void reproduzir() = 0;
    virtual std::string infoDetalhada() = 0;
    virtual bool combina(const std::string& filtro) = 0;
};

#endif // MIDIA_H
