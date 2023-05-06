#include <iostream>
#include "player.h"
using namespace std;

int main()
{
    // Création d'un personnage
    Player p1("Jalal");

    // Affichage des informations du personnage
    cout << "Nom du personnage: " << p1.getNom() << std::endl;
    cout << "Position x: " << p1.getPosition().x << std::endl;
    cout << "Position y: " << p1.getPosition().y << std::endl;

    // Déplacement du personnage
    p1.deplacer(10, 20);

    // Affichage des nouvelles informations du personnage
    cout << "Nouvelle position x: " << p1.getPosition().x << std::endl;
    cout << "Nouvelle position y: " << p1.getPosition().y << std::endl;

    return 0;
}

