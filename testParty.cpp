
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "personnage.h"
#include "airedejeu.h"
using namespace std;
/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Grille");
    window.setFramerateLimit(60);
    AireDeJeu aire(window);

    // Ajouter des personnages pour tester
    sf::Texture joueur1;
    joueur1.loadFromFile("players.png");
    sf::Vector2u size = joueur1.getSize();
    sf::RenderTexture renderTexture;
    renderTexture.create(size.x / 15, size.y / 8);
    sf::Sprite sprite(joueur1);
    sprite.setScale(0.5f, 0.5f);
    renderTexture.draw(sprite);
    renderTexture.display();
    joueur1 = renderTexture.getTexture();

    for(int i =0 ; i<15 ; i++){
        Personnage pnj(sf::Vector2f (100.f,45*i), sf::Vector2f (5.f,5.f), joueur1 );
        aire.ajouterPersonnage(pnj);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Déplacer les personnages automatiquement
        aire.deplacerPersonnages();

        // Effacer la fenêtre et redessiner l'aire de jeu avec les personnages
        window.clear();
        aire.dessiner(window);

        window.display();
    }

    return 0;
}
*/
