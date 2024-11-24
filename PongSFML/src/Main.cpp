#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entities/Bat.h"

int main()
{
    sf::VideoMode vm(1920, 1080);
    sf::RenderWindow window(vm, "Pong", sf::Style::Fullscreen);
    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);

    sf::Text hud;
    sf::Font font;
    
    if (font.loadFromFile("res/fonts/VT323.ttf"))
        hud.setFont(font);
    else
        std::cout << "ERROR, LOADING FONT " << font << ".";
}