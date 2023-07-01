#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "ObjectManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(100.f);

    sf::Clock Time;

    GameObject objtest = GameObject(std::string("test"));
    SpriteComponent sprite = SpriteComponent("../Assets/Sprites/Test/Debug.png");
    InputComponent input = InputComponent(PlayerInput(),0.2f);
    objtest.AddComponent(sprite);
    objtest.AddComponent(input);


    objtest.setPosition(100, 100);
    objtest.SetDebugMode(true);

    ObjectManager objectsManager;
    objectsManager.AddGameObject(std::make_unique<GameObject>(objtest));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                //delete sprite;
                window.close();
            }
            objectsManager.UpdateEvent(event);
        }

        objectsManager.Update(Time.restart().asSeconds());
        window.clear();
        objectsManager.Render(window);
        window.display();
    }

    return 0;
}