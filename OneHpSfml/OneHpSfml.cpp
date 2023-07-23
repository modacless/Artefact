#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Component.h"
#include "Shape.h"
#include "SpriteComponent.h"
#include "ObjectManager.h"
#include "imGUI/imgui.h"
#include "imGUI/imgui-SFML.h"
#include "Scene.h"
#include "TileObjectCollision.h"


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

    Scene* scene = new Scene("../Levels/Devs/FirstMap/Level_0.ldtkl");

    //TileObjectCollision collisionTest = TileObjectCollision("test");

    //GameObject coll1 = GameObject("Col");
    //coll1.SetPosition(sf::Vector2<float>(100.f, 100.f));
    //Shape::rect rect1 = Shape::rect(sf::Vector2f(100.f, 100.f), sf::Vector2f(1.f, 1.f));
    //CollisionComponent collision1 = CollisionComponent(rect1);
    //coll1.AddComponent(collision1);

    TileObjectCollision coll = TileObjectCollision("Test");


    SpriteComponent sprite1 = SpriteComponent("../Assets/Sprites/Test/Collisiontest.png");
    //coll1.AddComponent(sprite1);

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
    objectsManager.AddGameObject(std::make_unique<TileObjectCollision>(coll));


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
        scene->SceneDraw(window);
        ImGui::SFML::Render(window);
        objectsManager.Render(window);

        window.display();
    }
    ImGui::SFML::Shutdown();

    delete scene;

    return 0;
}