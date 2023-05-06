#include <SFML/Graphics.hpp>
#include "game.cpp"
#include<iostream>
/*
int main()
{
    // Créer la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Test");

    // Créer l'objet Menu
    Game menu(window);

    while (window.isOpen())
    {
        // Gérer les événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Récupérer la position du clic de souris
                    sf::Vector2f clickPos(event.mouseButton.x, event.mouseButton.y);

                    // Vérifier si le bouton "Start" est cliqué
                    if (menu.isStartButtonClicked(clickPos))
                    {
                        std::cout << "Start button clicked!" << std::endl;
                    }

                    // Vérifier si le bouton "Save" est cliqué
                    if (menu.isSaveButtonClicked(clickPos))
                    {
                        std::cout << "Save button clicked!" << std::endl;
                    }
                }
            }
        }

        // Effacer la fenêtre
        window.clear();

        // Dessiner le menu
        menu.draw(window);

        // Afficher la fenêtre
        window.display();
    }

    return 0;
}
*/
