#include "Comissionado.h"
#include <algorithm>
#include <string>

Comissionado::Comissionado(int i, const std::string& n, const std::string& d,
                           double v, double p, double teto, double sb)
    : Funcionario(i, n, d)
{
    vendas = v;
    percentual = p;
    tetoComissao = teto;
    salarioBase = sb;
}

double Comissionado::calcularPagamento()
{
    double comissao = vendas * (percentual / 100.0);
    if (comissao > tetoComissao) comissao = tetoComissao;
    return salarioBase + comissao;
}

std::string Comissionado::demonstrativo()
{
    return "Comissionado: " + nome + " | Total: " + std::to_string(calcularPagamento());
}
