#ifndef COMISSIONADO_H
#define COMISSIONADO_H

#include "Funcionario.h"

class Comissionado : public Funcionario
{
    double vendas;
    double percentual; // 0..100
    double tetoComissao;
    double salarioBase;

public:
    Comissionado(int i, const std::string& n, const std::string& d,
                 double vendas, double percentual, double teto, double salarioBase);
    virtual double calcularPagamento() override;
    virtual std::string demonstrativo() override;
};

#endif // COMISSIONADO_H
