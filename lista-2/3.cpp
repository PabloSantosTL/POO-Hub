#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class VeiculoAutonomo
{
protected:
    int id;
    double bateria;

public:
    VeiculoAutonomo(int i, double b)
    {
        id = i;
        bateria = b;
    }

    virtual ~VeiculoAutonomo() {}

    virtual double consumoPorKm() = 0;
    virtual void mover()
    {
        bateria -= consumoPorKm();
    }

    virtual string relatorioStatus()
    {
        return "Veiculo " + to_string(id) + " | Bateria: " + to_string(bateria);
    }
};

class CarroAutonomo : public VeiculoAutonomo
{
public:
    CarroAutonomo(int i, double b) : VeiculoAutonomo(i, b) {}

    double consumoPorKm()
    {
        return 1.0;
    }
};

class CaminhaoAutonomo : public VeiculoAutonomo
{
public:
    CaminhaoAutonomo(int i, double b) : VeiculoAutonomo(i, b) {}

    double consumoPorKm()
    {
        return 3.0;
    }
};

class OnibusAutonomo : public VeiculoAutonomo
{
public:
    OnibusAutonomo(int i, double b) : VeiculoAutonomo(i, b) {}

    double consumoPorKm()
    {
        return 2.0;
    }
};

int main()
{
    vector<unique_ptr<VeiculoAutonomo>> frota;

    frota.push_back(make_unique<CarroAutonomo>(1, 100));
    frota.push_back(make_unique<CaminhaoAutonomo>(2, 150));
    frota.push_back(make_unique<OnibusAutonomo>(3, 120));

    for (int i = 0; i < frota.size(); i++)
    {
        frota[i]->mover();
        cout << frota[i]->relatorioStatus() << endl;
    }

    return 0;
}
