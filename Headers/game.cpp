#pragma once
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "personnage.h"
#include "airedejeu.h"
#include "joueurClavier.h"
#include "joueurSouris.h"
#include <iostream>
#include <vector>


using namespace std;


class Game {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape startButton;
    sf::RectangleShape saveButton;
    sf::Font font;
    sf::Text startButtonText;
    sf::Text saveButtonText;
    sf::Texture backgr;
    AireDeJeu *jeu;
public:
    Game(sf::RenderWindow& window) {
        // Charger l'image du jeu
        texture.loadFromFile("name.png");
        sprite.setTexture(texture);
        sprite.setPosition((window.getSize().x - texture.getSize().x) / 2, (window.getSize().y - texture.getSize().y) / 2);
        font.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/Arial.ttf");

        // Créer le bouton "Start"
        startButton.setSize(sf::Vector2f(200, 50));
        startButton.setPosition((window.getSize().x - startButton.getSize().x) / 2,
                                 sprite.getPosition().y + texture.getSize().y + 50);
        startButton.setFillColor(sf::Color::Transparent);

        startButtonText.setFont(font);
        startButtonText.setString("*New*");
        startButtonText.setFillColor(sf::Color::Red);
        startButtonText.setCharacterSize(30);
        startButtonText.setStyle(sf::Text::Bold);
        startButtonText.setPosition(startButton.getPosition().x + 42,
                                     startButton.getPosition().y + 10);

        // Créer le bouton "Save"
        saveButton.setSize(sf::Vector2f(200, 50));
        saveButton.setPosition((window.getSize().x - saveButton.getSize().x) / 2,
                                startButton.getPosition().y + startButton.getSize().y + 20);
        saveButton.setFillColor(sf::Color::Transparent);

        saveButtonText.setFont(font);
        saveButtonText.setString("*Saved*");
        saveButtonText.setStyle(sf::Text::Bold );
        saveButtonText.setFillColor(sf::Color::Red);
        saveButtonText.setCharacterSize(30);
        saveButtonText.setPosition(saveButton.getPosition().x + 30,
                                    saveButton.getPosition().y -10);


    }

    void draw(sf::RenderWindow& window) {

        backgr.loadFromFile("bk.jpg");
        sf::Sprite spriteB(backgr);
        window.draw(spriteB);

        // Afficher l'image
        window.draw(sprite);

        // Afficher les boutons
        window.draw(startButton);
        window.draw(startButtonText);
        window.draw(saveButton);
        window.draw(saveButtonText);
    }

    bool isStartButtonClicked(sf::Vector2f clickPos) {
        // Vérifier si le bouton "Start" est cliqué
        if (startButton.getGlobalBounds().contains(clickPos)) {
            return true;
        } else {
            return false;
        }
    }

    bool isSaveButtonClicked(sf::Vector2f clickPos) {
        // Vérifier si le bouton "Save" est cliqué
        if (saveButton.getGlobalBounds().contains(clickPos)) {
            return true;
        } else {
            return false;
        }
    }

    void charger(AireDeJeu aire,sf::Texture joueur1){
        vector <sf::Vector2f> positions;
        ifstream fichier2("positions.txt");
        if(fichier2.is_open()){
            string ligne;
            while (getline(fichier2, ligne)) {
            stringstream ss(ligne);
            float x, y;
            ss >> x >> y;
            positions.push_back(sf::Vector2f(x,y));
        }
        fichier2.close();
        int sizeP = positions.size();
        aire.supprimerPersonnage();
        for (int i=0; i<sizeP-1; i++){
                Personnage pnj(positions[i],sf::Vector2f(5.f, 5.f), joueur1);
                aire.ajouterPersonnage(pnj);
        }
        JoueurClavier joueurClavier(positions[sizeP],sf::Vector2f(5.f, 5.f), joueur1);

    }


}};

