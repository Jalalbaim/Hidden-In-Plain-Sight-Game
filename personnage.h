#pragma once
#include <SFML/Graphics.hpp>



class Personnage {
public:
    Personnage(sf::Vector2f position, sf::Vector2f vitesse, sf::Texture& texture);
    void dessiner(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds() const;
    float getVitesse() const;
    void setPosition(sf::Vector2f newPos);
    sf::Vector2f getPosition() const;
    void deplacer(sf::Vector2f deplacement);

protected:
    sf::Sprite m_sprite;
    sf::Vector2f m_vitesse;
};
