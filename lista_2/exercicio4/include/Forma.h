#ifndef FORMA_H
#define FORMA_H

#include <memory>

class Forma
{
public:
    virtual ~Forma() {}
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual std::unique_ptr<Forma> clonar() const = 0;
};

#endif // FORMA_H
