#include <iostream>
#include <vector>
#include <memory>

#include "Musica.h"
#include "Video.h"
#include "Podcast.h"

int main()
{
    std::vector<std::unique_ptr<Midia>> catalogo;

    catalogo.push_back(std::make_unique<Musica>("Song A", 2020, 200, "Artista X", 320));
    catalogo.push_back(std::make_unique<Video>("Clip B", 2021, 600, "1080p", "H264"));
    catalogo.push_back(std::make_unique<Podcast>("Talk C", 2022, 1800, "Joao"));

    std::cout << "Listando catalogo:\n";
    for (auto& m : catalogo)
    {
        std::cout << m->infoDetalhada() << "\n";
        m->reproduzir();
    }

    std::cout << "\nFiltrando por 'Artista X':\n";
    for (auto& m : catalogo)
        if (m->combina("Artista X"))
            std::cout << " -> " << m->infoDetalhada() << "\n";

    return 0;
}
