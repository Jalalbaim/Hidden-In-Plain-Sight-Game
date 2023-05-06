#pragma once
#include <SFML/Graphics.hpp>
#include "personnage.h"




class JoueurClavier : public Personnage {
public:
    JoueurClavier(sf::Vector2f position, sf::Vector2f vitesse, sf::Texture& texture);

    void deplacer();
};
