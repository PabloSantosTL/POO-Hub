#ifndef VEICULO_AUTONOMO_H
#define VEICULO_AUTONOMO_H

#include <string>

class VeiculoAutonomo
{
protected:
    int id;
    double bateria; // percentual ou unidades

public:
    VeiculoAutonomo(int id, double bateria);
    virtual ~VeiculoAutonomo();

    virtual double consumoPorKm() = 0;
    virtual void mover(double km);
    virtual std::string relatorioStatus();
};

#endif // VEICULO_AUTONOMO_H
