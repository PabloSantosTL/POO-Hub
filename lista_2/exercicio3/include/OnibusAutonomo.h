#ifndef ONIBUS_AUTONOMO_H
#define ONIBUS_AUTONOMO_H

#include "VeiculoAutonomo.h"

class OnibusAutonomo : public VeiculoAutonomo
{
public:
    OnibusAutonomo(int id, double bateria);
    virtual double consumoPorKm() override;
};

#endif // ONIBUS_AUTONOMO_H
