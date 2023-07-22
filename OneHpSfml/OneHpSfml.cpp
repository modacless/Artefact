#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Component.h"
#include "Shape.h"
#include "SpriteComponent.h"
#include "ObjectManager.h"
#include "imGUI/imgui.h"
#include "imGUI/imgui-SFML.h"
#include "Scene.h"


void test()
{
    ImGui::Begin("Tool Test");
    ImGui::End();
}

int main()
{
    //Create Window
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");
    ImGui::SFML::Init(window);

    sf::Clock Time;

    Scene scene = Scene("../Levels/Devs/FirstMap/Level_0.ldtkl");

    GameObject objtest = GameObject(std::string("test"));
    SpriteComponent sprite = SpriteComponent("../Assets/Sprites/Test/Debug.png");
    //InputComponent input = InputComponent(PlayerInput(),0.2f);
    objtest.AddComponent(sprite);
    //objtest.AddComponent(input);

    objtest.setPosition(100, 100);
    objtest.SetDebugMode(true);

    Shape::circle circle_a = Shape::circle(objtest.getPosition(), 0.5f);
    CollisionComponent collison = CollisionComponent(circle_a);
    objtest.AddComponent(collison);

    ObjectManager objectsManager;
    objectsManager.AddGameObject(std::make_unique<GameObject>(objtest));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
            {
                //delete sprite;
                window.close();
            }
            objectsManager.UpdateEvent(event);
        }
        //Get the delta time
        auto deltaTime = Time.restart();

        //Update
        ImGui::SFML::Update(window, deltaTime);
        objectsManager.Update(deltaTime.asSeconds());
        test();

        //Render
        window.clear();
        scene.SceneDraw(window);
        ImGui::SFML::Render(window);
        objectsManager.Render(window);

        window.display();
    }
    ImGui::SFML::Shutdown();

    return 0;
}