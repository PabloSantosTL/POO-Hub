#include "Retangulo.h"

Retangulo::Retangulo(double l, double a)
{
    largura = l;
    altura = a;
}

double Retangulo::area() const
{
    return largura * altura;
}

double Retangulo::perimetro() const
{
    return 2 * (largura + altura);
}

std::unique_ptr<Forma> Retangulo::clonar() const
{
    return std::make_unique<Retangulo>(*this);
}
