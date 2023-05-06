#include <SFML/Graphics.hpp>
#include "personnage.h"
#include "game.cpp"
#include "airedejeu.h"
#include "joueurClavier.h"
#include "joueurSouris.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;


int main()
{
    // Fichier de sauvegarde
    ofstream fichier("positions.txt");
    // Création de la fenêtre de jeu
    sf::RenderWindow window1(sf::VideoMode(800, 600), "Hidden in Plain Sight");
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/Arial.ttf");
    // Ajouter les personnages du jeu
    sf::Texture joueur1;
    joueur1.loadFromFile("players.png");
    sf::Vector2u size = joueur1.getSize();
    sf::RenderTexture renderTexture;
    renderTexture.create(size.x / 15, size.y / 8);
    sf::Sprite sprite(joueur1);
    sprite.setScale(0.58f, 0.58f);
    renderTexture.draw(sprite);
    renderTexture.display();
    joueur1 = renderTexture.getTexture();
    // Joueur Sniper
    sf::Texture joueur2;
    joueur2.loadFromFile("crosshair.png");
    sf::Vector2u size2 = joueur2.getSize();
    sf::RenderTexture renderTexture2;
    renderTexture2.create(size2.x / 6, size2.y / 6);
    sf::Sprite sprite2(joueur2);
    sprite2.setScale(0.5f, 0.5f);
    renderTexture2.draw(sprite2);
    renderTexture2.display();
    joueur2 = renderTexture2.getTexture();
    //Ligne de départ
    sf::VertexArray lines2(sf::Lines, 2);
    lines2[0].position = sf::Vector2f(90, 0);
    lines2[0].color = sf::Color::White;
    lines2[1].position = sf::Vector2f(90, 600);
    lines2[1].color = sf::Color::White;
    //Ligne d'arrivee
    sf::VertexArray lines1(sf::Lines, 2);
    lines1[0].position = sf::Vector2f(700, 0);
    lines1[0].color = sf::Color::White;
    lines1[1].position = sf::Vector2f(700, 600);
    lines1[1].color = sf::Color::White;
    // Créer l'objet Menu
    Game menu(window1);
    int nbofSv=1;
    int linedef = 0;
    AireDeJeu aire(window1);
    // Definition des personnages non joueurs
    for(int i =0 ; i<10 ; i++){
        Personnage pnj1(sf::Vector2f (40.f,200+40*i), sf::Vector2f (5.f,5.f), joueur1 );
        aire.ajouterPersonnage(pnj1);
        Personnage pnj2(sf::Vector2f (-40.f,200+40*i), sf::Vector2f (5.f,5.f), joueur1 );
        aire.ajouterPersonnage(pnj2);
    }
    // Definition des personnages joueurs
    JoueurClavier joueurClavier(sf::Vector2f(10,220), sf::Vector2f(5.f, 5.f), joueur1);
    JoueurSouris joueurSouris(sf::Vector2f(700.f, 200.f), sf::Vector2f(5.f, 5.f), joueur2, joueurClavier);
    while (window1.isOpen())
    {
        // Gérer les événements
        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window1.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Récupérer la position du clic de souris
                    sf::Vector2f clickPos(event.mouseButton.x, event.mouseButton.y);
                    bool start = menu.isStartButtonClicked(clickPos);
                    bool save =menu.isSaveButtonClicked(clickPos);
                    if (save)
                    {
                        cout<<"players charged"<<endl;
                        linedef = 0;
                        menu.charger(aire,joueur1);
                        start =  true;
                    }
                    // Vérifier si le bouton "Start" est cliqué
                    if (start)
                    {
                        cout << "Start button clicked!" << endl;
                        if(save){
                            aire.supprimerPersonnage();
                            menu.charger(aire,joueur1);
                        }
                        sf::RenderWindow window(sf::VideoMode(800, 600), "Aire de jeu");
                        window.setFramerateLimit(100);
                        //Clock du text de position
                        sf::Clock clock;
                        while (window.isOpen()) {
                            sf::Event event;
                            sf::Text text1(" Sniper Winner :) !!", font, 50);
                            sf::Text text2(" Sniper Looser :( !!", font, 50);
                            sf::Text text;
                            //Position du joueur au depart
                            sf::Vector2f pos1=joueurClavier.getPosition();
                            sf::RectangleShape line(sf::Vector2f(30.f,30.f));
                            line.setPosition(pos1.x+2 , pos1.y +5);
                            line.setFillColor(sf::Color::Transparent);
                            line.setOutlineColor(sf::Color::Green);
                            line.setOutlineThickness(2);
                            // Déplace le joueur clavier
                            joueurClavier.deplacer();
                            joueurClavier.dessiner(window);
                            sf::Vector2f pos2=joueurClavier.getPosition();
                            //Deplacer le joueur Souris
                            sf::Vector2i posS= sf::Mouse::getPosition(window);
                            sf::Vector2f aj=sf::Vector2f(50.f,50.f);
                            sf::Vector2f dep = sf::Vector2f(posS)-aj;
                            joueurSouris.setPosition(dep);
                            // joueur clavier Position changed => move players
                            if (pos1.x != pos2.x || pos1.y != pos2.y){
                                     aire.deplacerPersonnages();
                            }
                            // Depassement des bords du joueur Clavier
                            if(joueurClavier.getPosition().x > 700){
                                    cout<<"T as echoue sniper "<<endl;
                                    window1.close();
                                    window.close();
                                    sf::RenderWindow window(sf::VideoMode(800, 600), "Resultat du jeu");
                                    while (window.isOpen())
                                    {
                                        sf::Event event;
                                        while (window.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed) {
                                                start = false;
                                                window.close();
                                            }
                                        }
                                        sf::Texture backgr;
                                        backgr.loadFromFile("bk.jpg");
                                        sf::Sprite spriteB(backgr);
                                        text=text2;
                                        text.setFillColor(sf::Color::Black);
                                        text.setStyle(sf::Text::Bold);
                                        sf::FloatRect textRect = text.getLocalBounds();
                                        text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
                                        text.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f));
                                        window.clear();
                                        window.draw(spriteB);
                                        window.draw(text);
                                        window.display();
                                    }
                            }
                            // Sniper ON:
                            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                                joueurSouris.deplacer(window);

                                // Vérifie si les joueurs sont en cible
                                if (joueurSouris.estEnCible()) {
                                    joueurSouris.dessiner(window);
                                    cout << "Les joueurs sont en cible l'un de l'autre !" << endl;
                                    window1.close();
                                    window.close();
                                    sf::RenderWindow window(sf::VideoMode(800, 600), "Resultat du jeu");
                                    while (window.isOpen())
                                    {
                                        sf::Event event;
                                        while (window.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed) {
                                                window.close();
                                            }
                                        }
                                        sf::Texture backgr;
                                        backgr.loadFromFile("bk.jpg");
                                        sf::Sprite spriteB(backgr);
                                        text = text1;
                                        text.setFillColor(sf::Color::Black);
                                        text.setStyle(sf::Text::Bold);
                                        sf::FloatRect textRect = text.getLocalBounds();
                                        text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
                                        text.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f));
                                        window.clear();
                                        window.draw(spriteB);
                                        window.draw(text);
                                        window.display();
                                    }
                                }else {
                                    joueurSouris.dessiner(window);
                                    cout<<"T as echoue sniper "<<endl;
                                    window1.close();
                                    window.close();
                                    sf::RenderWindow window(sf::VideoMode(800, 600), "Resultat du jeu");
                                    while (window.isOpen())
                                    {
                                        sf::Event event;
                                        while (window.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed) {
                                                window.close();
                                            }
                                        }
                                        sf::Texture backgr;
                                        backgr.loadFromFile("bk.jpg");
                                        sf::Sprite spriteB(backgr);
                                        text=text2;
                                        text.setFillColor(sf::Color::Black);
                                        text.setStyle(sf::Text::Bold);
                                        sf::FloatRect textRect = text.getLocalBounds();
                                        text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
                                        text.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f));
                                        window.clear();
                                        window.draw(spriteB);
                                        window.draw(text);
                                        window.display();
                                    }
                                }
                            }
                            sf::Vector2f clickPos2(event.mouseButton.x, event.mouseButton.y);
                            bool endbutton = aire.saveButtonClicked(clickPos2);
                            // End button
                            if(endbutton && nbofSv==1){
                                cout<<"Button save clicke"<<endl;
                                nbofSv = 2;
                                sf::RenderWindow window2(sf::VideoMode(400, 300), "End the game?");
                                while (window.isOpen())
                                    {
                                        sf::Event event;
                                        while (window2.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed) {
                                                window2.close();
                                            }
                                        }
                                        // End menu:
                                        sf::Texture arriere;
                                        arriere.loadFromFile("bk.jpg");
                                        sf::Sprite spritec(arriere);
                                        sf::RectangleShape saveButton;
                                        sf::RectangleShape endButton;
                                        sf::Text endText;
                                        sf::Text saveText;
                                        sf::Text Endg;
                                        saveButton.setSize(sf::Vector2f(200, 50));
                                        saveButton.setPosition(230,230);
                                        endButton.setSize(sf::Vector2f(200, 50));
                                        endButton.setPosition(20,230);
                                        saveButton.setSize(sf::Vector2f(150, 50));
                                        endButton.setSize(sf::Vector2f(150, 50));
                                        saveText.setFont(font);
                                        endText.setFont(font);
                                        Endg.setFont(font);
                                        saveText.setString("*Save*");
                                        endText.setString("*End*");
                                        Endg.setString("The End ?");
                                        Endg.setStyle(sf::Text::Bold);
                                        endText.setStyle(sf::Text::Bold | sf::Text::StrikeThrough);
                                        saveText.setStyle(sf::Text::Bold | sf::Text::StrikeThrough);
                                        saveText.setPosition(saveButton.getPosition().x+23,saveButton.getPosition().y+7);
                                        endText.setPosition(endButton.getPosition().x+25,endButton.getPosition().y+7);
                                        Endg.setPosition(sf::Vector2f(-70+window2.getSize().x/2.0f, window2.getSize().y/2.0f));
                                        endText.setFillColor(sf::Color::Black);
                                        saveText.setFillColor(sf::Color::Black);
                                        Endg.setFillColor(sf::Color::Black);
                                        // Save button clicked => recuperer les positions des joueurs
                                        sf::Vector2f clickPos3(event.mouseButton.x, event.mouseButton.y);
                                        if (saveButton.getGlobalBounds().contains(clickPos3)){
                                                aire.save(joueurClavier,fichier);
                                                cout << "players Saved"<<endl;
                                                window2.close();
                                                window.close();
                                        }else if (endButton.getGlobalBounds().contains(clickPos3)){
                                            window2.close();
                                            window.close();
                                        }
                                        //Window draw
                                        window2.draw(spritec);
                                        window2.draw(saveButton);
                                        window2.draw(endButton);
                                        window2.draw(saveText);
                                        window2.draw(endText);
                                        window2.draw(Endg);
                                        window2.display();
                                    }
                          }
                            // Effacer la fenêtre et redessiner l'aire de jeu avec les personnages
                            aire.dessiner(window);
                            // Affichage des joueurs
                            joueurClavier.dessiner(window);
                            window.draw(lines1);
                            window.draw(lines2);
                            if (linedef <40){
                                window.draw(line);
                                linedef = linedef +1;

                            }else{}
                            joueurSouris.dessiner(window);
                            window.display();
                            while (window.pollEvent(event)) {
                                if (event.type == sf::Event::Closed) {
                                    window.close();
                                }
                            }
                        }
                    }
                }
            }
        }

        // Effacer la fenêtre
        window1.clear();
        // Dessiner le menu
        menu.draw(window1);
        // Afficher la fenêtre
        window1.display();
    }
    return 0;
}









