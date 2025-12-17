#ifndef CAMINHAO_AUTONOMO_H
#define CAMINHAO_AUTONOMO_H

#include "VeiculoAutonomo.h"

class CaminhaoAutonomo : public VeiculoAutonomo
{
public:
    CaminhaoAutonomo(int id, double bateria);
    virtual double consumoPorKm() override;
};

#endif // CAMINHAO_AUTONOMO_H
