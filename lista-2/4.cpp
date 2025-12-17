#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Forma
{
public:
    virtual ~Forma() {}
    virtual double area() = 0;
    virtual double perimetro() = 0;
    virtual unique_ptr<Forma> clonar() = 0;
};

class Circulo : public Forma
{
    double raio;

public:
    Circulo(double r)
    {
        raio = r;
    }

    double area()
    {
        return M_PI * raio * raio;
    }

    double perimetro()
    {
        return 2 * M_PI * raio;
    }

    unique_ptr<Forma> clonar()
    {
        return make_unique<Circulo>(*this);
    }
};

class Retangulo : public Forma
{
    double largura;
    double altura;

public:
    Retangulo(double l, double a)
    {
        largura = l;
        altura = a;
    }

    double area()
    {
        return largura * altura;
    }

    double perimetro()
    {
        return 2 * (largura + altura);
    }

    unique_ptr<Forma> clonar()
    {
        return make_unique<Retangulo>(*this);
    }
};

int main()
{
    vector<unique_ptr<Forma>> formas;

    formas.push_back(make_unique<Circulo>(5));
    formas.push_back(make_unique<Retangulo>(4, 3));

    for (int i = 0; i < formas.size(); i++)
        cout << "Area: " << formas[i]->area()
             << " Perimetro: " << formas[i]->perimetro() << endl;

    return 0;
}
