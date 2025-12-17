#include "Assalariado.h"
#include <string>

Assalariado::Assalariado(int i, const std::string& n, const std::string& d, double s)
    : Funcionario(i, n, d)
{
    salario = s;
}

double Assalariado::calcularPagamento()
{
    return salario;
}

std::string Assalariado::demonstrativo()
{
    return "Assalariado: " + nome + " | Salario: " + std::to_string(salario);
}
