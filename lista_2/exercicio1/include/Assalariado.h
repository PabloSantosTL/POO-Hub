#ifndef ASSALARIADO_H
#define ASSALARIADO_H

#include "Funcionario.h"

class Assalariado : public Funcionario
{
    double salario;

public:
    Assalariado(int i, const std::string& n, const std::string& d, double s);
    virtual double calcularPagamento() override;
    virtual std::string demonstrativo() override;
};

#endif // ASSALARIADO_H
