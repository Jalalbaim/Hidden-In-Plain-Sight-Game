#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "personnage.h"
#include "joueurClavier.h"
#include "joueurSouris.h"



class AireDeJeu {
public:
    AireDeJeu(sf::RenderWindow& window);
    void save(JoueurClavier j1, std::ofstream &fichier);
    void ajouterPersonnage(Personnage personnage);
    void supprimerPersonnage();
    void deplacerPersonnages();
    void dessiner(sf::RenderWindow& window);
    bool saveButtonClicked(sf::Vector2f clickPos);


private:
    sf::RectangleShape saveButton;
    sf::Text saveText;
    sf::Font font;
    sf::RectangleShape m_rectangle;
    sf::Vector2f m_position;
    std::vector<Personnage> m_personnages;
    sf::Texture background;
};

