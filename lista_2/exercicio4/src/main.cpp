#include <iostream>
#include <vector>
#include <memory>

#include "Circulo.h"
#include "Retangulo.h"

int main()
{
    std::vector<std::unique_ptr<Forma>> doc;

    doc.push_back(std::make_unique<Circulo>(5.0));
    doc.push_back(std::make_unique<Retangulo>(4.0, 3.0));

    for (auto& f : doc)
    {
        std::cout << "Area: " << f->area() << " Perimetro: " << f->perimetro() << std::endl;
        auto copia = f->clonar();
        std::cout << " -> clone area: " << copia->area() << std::endl;
    }

    return 0;
}
