#include "Funcionario.h"

Funcionario::Funcionario(int i, const std::string& n, const std::string& d)
{
    id = i;
    nome = n;
    documento = d;
}

Funcionario::~Funcionario() {}
