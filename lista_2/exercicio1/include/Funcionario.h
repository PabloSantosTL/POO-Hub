#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario
{
protected:
    int id;
    std::string nome;
    std::string documento;

public:
    Funcionario(int i, const std::string& n, const std::string& d);
    virtual ~Funcionario();

    virtual double calcularPagamento() = 0;
    virtual std::string demonstrativo() = 0;
};

#endif // FUNCIONARIO_H
