#include "VeiculoAutonomo.h"
#include <string>
#include <sstream>

VeiculoAutonomo::VeiculoAutonomo(int i, double b)
{
    id = i;
    bateria = b;
}

VeiculoAutonomo::~VeiculoAutonomo() {}

void VeiculoAutonomo::mover(double km)
{
    bateria -= consumoPorKm() * km;
    if (bateria < 0) bateria = 0;
}

std::string VeiculoAutonomo::relatorioStatus()
{
    std::ostringstream oss;
    oss << "Veiculo " << id << " | Bateria: " << bateria;
    return oss.str();
}
