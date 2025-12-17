#ifndef HORISTA_H
#define HORISTA_H

#include "Funcionario.h"

class Horista : public Funcionario
{
    double valorHora;
    int horas; // horas no periodo

public:
    Horista(int i, const std::string& n, const std::string& d, double vh, int h);
    virtual double calcularPagamento() override;
    virtual std::string demonstrativo() override;
};

#endif // HORISTA_H
