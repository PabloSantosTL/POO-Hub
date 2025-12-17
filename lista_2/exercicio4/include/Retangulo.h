#ifndef RETANGULO_H
#define RETANGULO_H

#include "Forma.h"

class Retangulo : public Forma
{
    double largura;
    double altura;

public:
    Retangulo(double l, double a);
    virtual double area() const override;
    virtual double perimetro() const override;
    virtual std::unique_ptr<Forma> clonar() const override;
};

#endif // RETANGULO_H
