#include "Circulo.h"
#include <cmath>

Circulo::Circulo(double r)
{
    raio = r;
}

double Circulo::area() const
{
    return M_PI * raio * raio;
}

double Circulo::perimetro() const
{
    return 2 * M_PI * raio;
}

std::unique_ptr<Forma> Circulo::clonar() const
{
    return std::make_unique<Circulo>(*this);
}
