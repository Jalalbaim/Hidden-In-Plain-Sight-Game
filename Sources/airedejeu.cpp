
#include <SFML/Graphics.hpp>
#include "airedejeu.h"
#include "personnage.h"
#include "joueurClavier.h"
#include "joueurSouris.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


AireDeJeu::AireDeJeu(sf::RenderWindow& window)
{
    int num_rows = 30;
    int num_cols = 10;
    int cell_size = 50;
    font.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/Arial.ttf");
    saveButton.setSize(sf::Vector2f(100, 40));
    saveButton.setPosition(700,0);
    saveButton.setFillColor(sf::Color::Red);
    saveText.setFont(font);
    saveText.setString("End");
    saveText.setFillColor(sf::Color::White);
    saveText.setCharacterSize(20);
    saveText.setStyle(sf::Text::Bold);
    saveText.setPosition(saveButton.getPosition().x + 25,saveButton.getPosition().y + 5);

}

void AireDeJeu::ajouterPersonnage(Personnage personnage)
{
    m_personnages.push_back(personnage);
}

void AireDeJeu::supprimerPersonnage()
{
        m_personnages.erase(m_personnages.begin());
}

void AireDeJeu::deplacerPersonnages()
{
    int num_rows = 1500;
    int num_cols = 1500;
    int cell_size = 50;
    for (auto& personnage : m_personnages) {
        // Génère un nombre aléatoire pour choisir la direction de déplacement
        int direction = rand() % 4;

        // Déplace le personnage en fonction de la direction choisie
        // Switch pour avoir toutes les directions et ne le faire bouger que si c'est horizontale comme ca on garde la partie plus de temps
        switch (direction) {
            case 3: // Vers la droite
                if (personnage.getPosition().x < (num_cols - 1) * cell_size) {
                    personnage.setPosition(sf::Vector2f(personnage.getPosition().x + cell_size, personnage.getPosition().y));
                }
                break;
            default:
                break;
        }
        sf::sleep(sf::milliseconds(50));
    }
}



bool AireDeJeu::saveButtonClicked(sf::Vector2f clickPos){
    if (saveButton.getGlobalBounds().contains(clickPos)){
        return true;
    }else{
        return false;
    }
}



void AireDeJeu::dessiner(sf::RenderWindow& window)
{
    background.loadFromFile("racing.png");
    sf::Sprite spriteB(background);
    window.draw(spriteB);
    window.draw(m_rectangle);
    for (int i = 0; i < m_personnages.size(); i++)
    {
        m_personnages[i].dessiner(window);
    }
    window.draw(saveButton);
    window.draw(saveText);


}

void AireDeJeu::save(JoueurClavier j1,ofstream &fichier)
{
    vector<sf::Vector2f> positions;
    for(int i=0; i<m_personnages.size();i++){
        positions.push_back(m_personnages[i].getPosition());
    }
    if (fichier.is_open()){
        for (int i=0; i<positions.size();i++){
            fichier <<positions[i].x << " " << positions[i].y <<endl;
        }
        sf::Vector2f posClv= j1.getPosition();
        fichier <<posClv.x<<" "<<posClv.y;
    }else{
        cerr<<"impossible d'ouvrir le fichier";
    }
}
