#include "CaminhaoAutonomo.h"

CaminhaoAutonomo::CaminhaoAutonomo(int id, double bateria) : VeiculoAutonomo(id, bateria) {}

double CaminhaoAutonomo::consumoPorKm()
{
    return 3.0;
}
