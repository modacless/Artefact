#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Component.h"
#include "SpriteComponent.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    GameObject objtest = GameObject(std::string("test"));
    SpriteComponent sprite = SpriteComponent("../Assets/Sprites/Test/Debug.png");
    objtest.AddComponent(sprite);

    objtest.setPosition(100, 100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        objtest.RenderComponent(window);
        window.display();
    }

    return 0;
}