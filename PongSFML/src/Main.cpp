#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
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
    {
        hud.setFont(font);
        hud.setCharacterSize(75);
        hud.setFillColor(sf::Color::White);
        hud.setPosition(20, 20);
    }
    else
        std::cout << "ERROR, LOADING FONT";

    sf::Clock clock;

    while (window.isOpen())
    {
        //Handle player input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                bat.MoveLeft();
            else
                bat.StopLeft();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                bat.MoveRight();
            else
                bat.StopRight();

        }





        //update elements
        sf::Time dt = clock.restart();
        bat.Update(dt);

        std::stringstream ss;
        ss << "Score:" << score << " Lives:" << lives;
        hud.setString(ss.str());




        //draw elements
        window.clear();
        window.draw(hud);
        window.draw(bat.GetShape());
        window.display();
    }

    return 0;

}