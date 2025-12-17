#ifndef CARRO_AUTONOMO_H
#define CARRO_AUTONOMO_H

#include "VeiculoAutonomo.h"

class CarroAutonomo : public VeiculoAutonomo
{
public:
    CarroAutonomo(int id, double bateria);
    virtual double consumoPorKm() override;
    // comportamento especifico pode ser adicionado
};

#endif // CARRO_AUTONOMO_H
