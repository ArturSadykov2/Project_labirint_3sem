#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>
#include "Ball.h"

using namespace sf;

class Bullets {
public:
    Bullets(float x, float y, float vx, float vy) {
        points = 0;
        this->x = x;
        this->y = y;
        this->vx = vx;
        this->vy = vy;
        circle.setRadius(25);
        circle.setFillColor(Color::Black);
        circle.setPosition(x, y);
    }
    //~Bullets();


    void draw(RenderWindow& window) {
        circle.setPosition(x, y);
        window.draw(circle);
    }

    void move(float dt) {
        x += vx * dt;
        y += vy * dt;
        circle.setPosition(x, y);

    }
    /*
    std::pair<bool, bool> collusion(const Image& wall, const Ball& ball, float x, float y, float dt) {
        bool overlap_wall = wall.getPixel(x + vx * dt - 0, y + vy * dt - 0) != Color::Transparent;
        //bool overlap_ball = ball..getPixel(x + vx * dt - ball.x - ball.vx, y + vy * dt - ball.y - ball.vy) != Color::Transparent;
        bool kill_ball = false;
        bool kill = false;
        if (overlap_ball) {
            ball.x = x;
            ball.y = y;
            ball.vx = 0;
            ball.vy = 0;
            ball.ax = 0;
            ball.ay = 0;
            kill_ball = true;
        }
        if (overlap_wall) {
            kill = true;
        }
        return std::make_pair(kill, kill_ball);
    }*/

private:
    int points;
    float x, y, vx, vy;
    CircleShape circle;
};