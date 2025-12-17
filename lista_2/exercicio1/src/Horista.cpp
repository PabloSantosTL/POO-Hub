#include "Horista.h"
#include <string>

Horista::Horista(int i, const std::string& n, const std::string& d, double vh, int h)
    : Funcionario(i, n, d)
{
    valorHora = vh;
    horas = h;
}

double Horista::calcularPagamento()
{
    int normais = horas > 44 ? 44 : horas;
    int extras = horas > 44 ? horas - 44 : 0;
    return normais * valorHora + extras * valorHora * 1.5;
}

std::string Horista::demonstrativo()
{
    return "Horista: " + nome + " | Total: " + std::to_string(calcularPagamento());
}
