
#include <SFML/Graphics.hpp>
#include "personnage.h"
#include "game.h"
#include "joueurClavier.h"
#include "joueurSouris.h"
#include <iostream>
using namespace std;

int mai()
{
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jeu");

    // Chargement des textures
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
    sf::Texture joueur2;
    joueur2.loadFromFile("sniper.png");
    sf::Sprite sprite2(joueur2);
    sprite2.setScale(0.5f, 0.5f);
    renderTexture.draw(sprite2);
    renderTexture.display();
    joueur2 = renderTexture.getTexture();

    JoueurClavier joueurClavier(sf::Vector2f(100.f, 100.f), sf::Vector2f(5.f, 5.f), joueur1);
    JoueurSouris joueurSouris(sf::Vector2f(700.f, 500.f), sf::Vector2f(5.f, 5.f), joueur2, joueurClavier);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Déplace le joueur clavier
        joueurClavier.deplacer();

        // Déplace le joueur souris
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            joueurSouris.deplacer(window);
            // Vérifie si les joueurs sont en cible
            if (joueurSouris.estEnCible()) {
                std::cout << "Les joueurs sont en cible l'un de l'autre !" << std::endl;
            }else {
                std::cout<<"T as echoue "<<endl;
            }
        }


        // Efface la fenêtre
        window.clear(sf::Color::White);

        // Affichage des joueurs
        joueurClavier.dessiner(window);
        joueurSouris.dessiner(window);

        // Affiche la fenêtre
        window.display();
    }

    return 0;
}

