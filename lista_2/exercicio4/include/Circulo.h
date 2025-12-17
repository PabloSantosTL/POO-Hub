#ifndef CIRCULO_H
#define CIRCULO_H

#include "Forma.h"

class Circulo : public Forma
{
    double raio;

public:
    Circulo(double r);
    virtual double area() const override;
    virtual double perimetro() const override;
    virtual std::unique_ptr<Forma> clonar() const override;
};

#endif // CIRCULO_H
