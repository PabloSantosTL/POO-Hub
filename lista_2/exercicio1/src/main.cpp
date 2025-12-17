#include <iostream>
#include <vector>
#include <memory>

#include "Assalariado.h"
#include "Horista.h"
#include "Comissionado.h"

int main()
{
    std::vector<std::unique_ptr<Funcionario>> lista;

    lista.push_back(std::make_unique<Assalariado>(1, "Ana", "111", 3000.0));
    lista.push_back(std::make_unique<Horista>(2, "Bruno", "222", 50.0, 50)); // 6 horas extras
    lista.push_back(std::make_unique<Comissionado>(3, "Carlos", "333", 20000.0, 5.0, 1500.0, 1000.0));

    for (size_t i = 0; i < lista.size(); ++i)
        std::cout << lista[i]->demonstrativo() << std::endl;

    return 0;
}
