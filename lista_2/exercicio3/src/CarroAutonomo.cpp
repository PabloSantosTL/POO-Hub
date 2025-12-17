#include "CarroAutonomo.h"

CarroAutonomo::CarroAutonomo(int id, double bateria) : VeiculoAutonomo(id, bateria) {}

double CarroAutonomo::consumoPorKm()
{
    return 1.0; // unidade por km (exemplo)
}
