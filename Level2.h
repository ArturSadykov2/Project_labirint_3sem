#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h";
#include "Bullet.h";


void level2()
{

    RenderWindow window(VideoMode(1608, 900), L"Labirinth", Style::Default);

    window.setVerticalSyncEnabled(true);

    Texture Texture_level_1;
    Texture_level_1.loadFromFile("image/levels_image/level_3/lv3_dark.png");
    Image level_mask;
    level_mask.loadFromFile("image/levels_image/level_3/lv3_dark.png");
    RectangleShape Wall1(Vector2f(1608, 900));
    Wall1.setTexture(&Texture_level_1);
    Wall1.setPosition(0, 0);

    Texture Floort;
    Floort.loadFromFile("image/levels_image/texture_wood.jpg");
    RectangleShape Floor(Vector2f(1608, 900));
    Floor.setTexture(&Floort);
    Floor.setPosition(0, 0);

    Texture Trap_t;
    Trap_t.loadFromFile("image/levels_image/level_3/lv3_lovyshki_dark.png");
    Image trap_mask;
    trap_mask.loadFromFile("image/levels_image/level_3/lv3_lovyshki_dark.png");
    RectangleShape Traps1(Vector2f(1608, 900));
    Traps1.setTexture(&Trap_t);
    Traps1.setPosition(0, 0);

    Texture Finish_t;
    Finish_t.loadFromFile("image/levels_image/final_hole.png");
    RectangleShape Finish(Vector2f(100, 100));
    Finish.setTexture(&Finish_t);
    Finish.setPosition(1150, 505);




    Ball ball1(1450, 105, 25);
    float dt = 0.05;
    float b = 1;
    bool win = 0;
    float time = 0;

    std::vector<Bullets> v_bullets;
    bool a = 0;
    while (win == 0)
    {
        a = 0;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();

            switch (event.type)
            {
            case Event::KeyPressed:

                if ((event.key.code == Keyboard::Numpad5) || (event.key.code == Keyboard::S)) {
                    ball1.ay = b;
                }

                if ((event.key.code == Keyboard::Numpad8) || (event.key.code == Keyboard::W)) {
                    ball1.ay = -b;
                }

                if ((event.key.code == Keyboard::Numpad4) || (event.key.code == Keyboard::A)) {
                    ball1.ax = -b;
                }
                if ((event.key.code == Keyboard::Numpad6) || (event.key.code == Keyboard::D)) {
                    ball1.ax = b;
                }
                break;
            case Event::KeyReleased:
                if ((event.key.code == Keyboard::Numpad5) || (event.key.code == Keyboard::S))
                {
                    ball1.ay = 0;
                }
                if ((event.key.code == Keyboard::Numpad8) || (event.key.code == Keyboard::W))
                {
                    ball1.ay = 0;
                }
                if ((event.key.code == Keyboard::Numpad4) || (event.key.code == Keyboard::A))
                {
                    ball1.ax = 0;
                }
                if ((event.key.code == Keyboard::Numpad6) || (event.key.code == Keyboard::D))
                {
                    ball1.ax = 0;
                }
                break;

            default:
                break;
            }
        }
        time += 1;
        if (time == 10) {
            v_bullets.push_back(Bullets(103,180,0,100));
            v_bullets.push_back(Bullets(1455, 680, 0, -100));
            time = 0;
        }


        ball1.ball_move(dt);
        win = ball1.collusion(level_mask, trap_mask, 1450, 105, 1150, 505);
        for (Bullets bullet : v_bullets) {
            bullet.move(dt);


        }



        window.clear(Color::Blue);
        window.draw(Floor);
        window.draw(Wall1);
        window.draw(Traps1);
        for (Bullets bullet : v_bullets) {
            bullet.draw(window);
        }
        window.draw(Finish);
        ball1.draw(window);
        window.display();
    }
}

