#include <SFML/Graphics.hpp>
#include "personnage.h"

Personnage:: Personnage(sf::Vector2f position, sf::Vector2f vitesse, sf::Texture& texture)
        : m_sprite(texture)
        , m_vitesse(vitesse)
    {
        m_sprite.setPosition(position);
    }


void Personnage::dessiner(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

sf::FloatRect Personnage::getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}

float Personnage::getVitesse() const
{
    return m_vitesse.x;
}

void Personnage::setPosition(sf::Vector2f newPos)
{
    m_sprite.setPosition(newPos);
}

sf::Vector2f Personnage::getPosition() const
{
    return m_sprite.getPosition();
}

void Personnage::deplacer(sf::Vector2f deplacement){
        m_sprite.move(deplacement);
}

