#pragma once

#include <SFML/Graphics.hpp>
#include "personnage.h"
#include "joueurClavier.h"



class JoueurSouris : public Personnage {
public:
    JoueurSouris(sf::Vector2f position, sf::Vector2f vitesse, sf::Texture& texture, JoueurClavier& joueurClavier);

    void deplacer(sf::RenderWindow& window) ;

    bool estEnCible() const;

private:
    sf::Vector2f m_positionCible;
    JoueurClavier& m_joueurClavier;
    bool m_enCible;
};
