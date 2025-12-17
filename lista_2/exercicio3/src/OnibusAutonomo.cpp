#include "OnibusAutonomo.h"

OnibusAutonomo::OnibusAutonomo(int id, double bateria) : VeiculoAutonomo(id, bateria) {}

double OnibusAutonomo::consumoPorKm()
{
    return 2.0;
}
