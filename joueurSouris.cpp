#include <SFML/Graphics.hpp>
#include <cmath>
#include "joueurSouris.h"



JoueurSouris::JoueurSouris(sf::Vector2f position, sf::Vector2f vitesse, sf::Texture& texture, JoueurClavier& joueurClavier)
    : Personnage(position, vitesse, texture)
    , m_joueurClavier(joueurClavier)
    , m_enCible(false)
{}

void JoueurSouris::deplacer(sf::RenderWindow& window) {

    // Vérifie si le clic droit est pressé
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        // Récupère la position du clic
        sf::Vector2f posCible = sf::Vector2f(sf::Mouse::getPosition(window));

        // Vérifie si le joueur clavier est en cible
        sf::Vector2f posClavier = m_joueurClavier.getPosition();
        sf::FloatRect boundsClavier = m_joueurClavier.getGlobalBounds();
        if (posCible.x >= posClavier.x - 30 && posCible.x <= posClavier.x + boundsClavier.width + 30 &&
            posCible.y >= posClavier.y - 30 && posCible.y <= posClavier.y + boundsClavier.height + 30) {
            m_enCible = true;
            m_positionCible = posCible;
        }
        else {
            m_enCible = false;
        }
    }



}

bool JoueurSouris::estEnCible() const {
    return m_enCible;
}
