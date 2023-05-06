#include <iostream>
#include <SFML/Graphics.hpp>
#include "joueurClavier.h"

/*int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Joueur Clavier");
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("/home/j/MiniProjet/Hidden in Plain sight/players.png")) {
            std::cout<<"no";
    }

    JoueurClavier joueur(sf::Vector2f(400, 300), sf::Vector2f(200, 200), texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Vector2f deplacement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            deplacement.x -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            deplacement.x += 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            deplacement.y -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            deplacement.y += 1.f;
        }
        joueur.deplacer(deplacement);

        window.clear();
        joueur.dessiner(window);
        window.display();
    }

    return 0;
}

*/
