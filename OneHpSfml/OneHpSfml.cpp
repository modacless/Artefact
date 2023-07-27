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
#include <iostream>


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

    ObjectManager* objectsManager = new ObjectManager();
    //TileObjectCollision collisionTest = TileObjectCollision("test");


    TileObjectCollision coll =  TileObjectCollision("Test",sf::Vector2f(0,0));
    TileObjectCollision coll2 = TileObjectCollision("Test2", sf::Vector2f(31, 32));

    SpriteComponent sprite1 = SpriteComponent("../Assets/Sprites/Test/Collisiontest.png");

    GameObject objtest = GameObject(std::string("test"), sf::Vector2f(100, 100));
    SpriteComponent sprite = SpriteComponent("../Assets/Sprites/Test/Debug.png");
    //InputComponent input = InputComponent(PlayerInput(),0.2f);
    objtest.AddComponent(sprite);
    objtest.SetDebugMode(true);

    objectsManager->AddGameObject(std::make_unique<GameObject>(objtest));
    objectsManager->AddGameObject(std::make_unique<TileObjectCollision>(coll));
    objectsManager->AddGameObject(std::make_unique<TileObjectCollision>(coll2));

    Shape::rect *t1 = coll.GetComponent<CollisionComponent>()->rect;
    Shape::rect *t2 = coll2.GetComponent<CollisionComponent>()->rect;

    if (coll.GetComponent<CollisionComponent>()->shape->collideRectvsRect(t1, t2))
    {
        std::cout << " \n Collision \n";

    }else
    {
        std::cout << " \n Pas de Collision \n";
    }



    /*Shape::circle circle_a = Shape::circle(objtest.getPosition(), 0.5f);
    CollisionComponent collison = CollisionComponent(circle_a);
    objtest.AddComponent(collison);*/





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
            objectsManager->UpdateEvent(event);
        }
        //Get the delta time
        auto deltaTime = Time.restart();

        //Update
        ImGui::SFML::Update(window, deltaTime);
        objectsManager->Update(deltaTime.asSeconds());
        test();

        //Render
        window.clear();
        scene->SceneDraw(window);
        ImGui::SFML::Render(window);
        objectsManager->Render(window);

        window.display();
    }
    ImGui::SFML::Shutdown();

    delete scene;
    delete objectsManager;

    return 0;
}