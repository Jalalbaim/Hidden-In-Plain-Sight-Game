#include <SFML/Graphics.hpp>
#include "joueurClavier.h"

JoueurClavier::JoueurClavier(sf::Vector2f position, sf::Vector2f vitesse, sf::Texture& texture)
    : Personnage(position, vitesse, texture)
{}

void JoueurClavier::deplacer()
{

    sf::Vector2f deplacement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        deplacement.y -= 50.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        deplacement.y += 50.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        deplacement.x -= 50.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        deplacement.x += 50.f;
    }
    Personnage::deplacer(deplacement);
}
