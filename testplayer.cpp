
#include <SFML/Graphics.hpp>
#include "personnage.h"
#include "joueurClavier.h"
#include "joueurSouris.h"
#include <iostream>

using namespace std;

/*int main() {
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Joueur");
    window.setFramerateLimit(60);

    // Chargement des textures
    sf::Texture joueur1;
    if (!joueur1.loadFromFile("players.png")) {
        return -1;
    }
    sf::Vector2u size = joueur1.getSize();
    sf::RenderTexture renderTexture;
    renderTexture.create(size.x / 15, size.y / 8);
    sf::Sprite sprite(joueur1);
    sprite.setScale(0.5f, 0.5f);
    renderTexture.draw(sprite);
    renderTexture.display();
    joueur1 = renderTexture.getTexture();
    /*sf::Texture joueur2;
    if (!joueur2.loadFromFile("j2.png")) {
        return -1;
    }*/
    // Création des joueurs
    //JoueurSouris joueurSouris(sf::Vector2f(400, 300), sf::Vector2f(0, 0), joueur1);
  /*  JoueurClavier joueurClavier(sf::Vector2f(100, 100), sf::Vector2f(200, 200), joueur1);

    while (window.isOpen()) {
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Mise à jour des joueurs
        //joueurSouris.deplacer();
        joueurClavier.deplacer();

        // Affichage des joueurs
        window.clear();
        //joueurSouris.dessiner(window);
        joueurClavier.dessiner(window);
        window.display();
    }

    return 0;
}*/
