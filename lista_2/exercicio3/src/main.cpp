#include <iostream>
#include <vector>
#include <memory>

#include "CarroAutonomo.h"
#include "CaminhaoAutonomo.h"
#include "OnibusAutonomo.h"

int main()
{
    std::vector<std::unique_ptr<VeiculoAutonomo>> frota;

    frota.push_back(std::make_unique<CarroAutonomo>(1, 100.0));
    frota.push_back(std::make_unique<CaminhaoAutonomo>(2, 150.0));
    frota.push_back(std::make_unique<OnibusAutonomo>(3, 120.0));

    // atribuir rotas (simples: mover alguns kms)
    frota[0]->mover(10);
    frota[1]->mover(20);
    frota[2]->mover(15);

    for (auto& v : frota)
        std::cout << v->relatorioStatus() << std::endl;

    return 0;
}
