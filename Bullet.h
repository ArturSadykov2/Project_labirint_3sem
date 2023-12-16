#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>
#include <cassert>
#include "Ball.h"

using namespace sf;

class Bullets {
public:
    Bullets(float x, float y, float vx, float vy) {
        /*
        x, y: start bullet's position
        vx, vy: bullet's speed
        */
        points = 0;
        this->x = x;
        this->y = y;
        this->vx = vx;
        this->vy = vy;
        circle.setRadius(25);
        circle.setFillColor(Color::Black);
        circle.setPosition(x, y);
    }
    


    void draw(RenderWindow& window) {
        window.draw(circle);
    }

    void move(float dt) {
        /*
        Change coordinates of bullet
        :param dt: time interval
        */
        x += vx * dt;
        y += vy * dt;
        circle.setPosition(x, y);

    }
    
    bool collusion(const Image& wall, Ball& ball, int St_x, int St_y, float dt) {
        /*
        Collusion bullets with ball and walls
        :param wall: texture of walls
        :param ball: player's ball
        :param St_x, St_y: start ball position
        :param dt: time interval
        */
        int overlap_wall = wall.getPixel(x + vx * dt, y + vy * dt).a;
        bool overlap_ball = ((ball.x-x)* (ball.x - x)+ (ball.y - y) * (ball.y - y)<50*50);
        bool kill_ball = false;
        bool kill = false;
        if (overlap_ball) {
            ball.restart(St_x, St_y);
        }
        if (overlap_wall>=200) {
            return kill=1;
        }
    }

private:
    int points;
    float x, y, vx, vy;
    CircleShape circle;
};