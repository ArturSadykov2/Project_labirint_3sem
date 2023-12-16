#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include<cmath>
using namespace sf;

class Ball {
private:
    float x, y, vx, vy;
    int R;
    bool hit, move;
    CircleShape circle;


public:
    float ax, ay;

    Ball(int x, int y, int R) {
        /*
        Set start values
        :param x: x coordinate of start ball position
        :param y: y coordinate of start ball position
        */
        this->x = x;
        this->y = y;
        circle.setRadius(R);
        circle.setFillColor(Color::Red);
        circle.setPosition(x, y);
        ax = 0;
        ay = 0;
        vx = 0;
        vy = 0;
        this->R = R;
        hit = false;
        move = false;



    }
    void draw(RenderWindow& window) {
        window.draw(circle);
    }

    void ball_boost(Event event) {
        /*
        Check buttons positions and return ball boost
        */
        float a = 0.33;
        if (event.key.code == Keyboard::S) {
            ay = a;
        }
        else if (event.key.code == Keyboard::W) {
            ay = -a;
        }
        else {
            ay = 0;
        }
        if (event.key.code == Keyboard::A) {
            ax = -a;
        }
        else if (event.key.code == Keyboard::D) {
            ax = a;
        }
        else {
            ax = 0;
        }
    }


    void ball_move(float dt) {
        /*
        Calculate speed and coordinates
        :param dt: time interval
        */
        if (abs(vx) <= 300 * dt) {
            vx += ax;
            //ax = 0;
        }
        if (abs(vy) <= 600 * dt) {
            vy += ay;
            //ay = 0;
        }
        if (vx != 0) {
            if (6 * dt >= abs(vx)) {
                vx = 0;
            }
            else if (vx >= 0) {
                vx -= 10 * dt;
            }
            else {
                vx += 10 * dt;
            }
        }
        if (vy != 0) {
            if (6 * dt >= abs(vy)) {
                vy = 0;
            }
            else if (vy >= 0) {
                vy -= 10 * dt;
            }
            else {
                vy += 10 * dt;
            }
        }
    }

    bool collusion(Image Wall, Image traps, int St_x, int St_y, int F_x, int F_y) {
        /*
        Check collision ball with walls and traps
        :param level_mask: mask with level walls
        :param ball_mask: mask with ball
        :param trap_mask: mask with level traps
        :param x: start ball x position
        :param y: start ball y position
        */



        int overlap_walls_x_R = Wall.getPixel(x + R + abs(vx) + 20, y).a;
        int overlap_walls_x_L = Wall.getPixel(x - R - abs(vx) + 20, y).a;
        int overlap_walls_y_T = Wall.getPixel(x, y - R - abs(vy) + 25).a;
        int overlap_walls_y_D = Wall.getPixel(x, y + R + abs(vy) + 25).a;
        int overlap_traps_x_R = traps.getPixel(x + R + abs(vx), y).a;
        int overlap_traps_x_L = traps.getPixel(x - R - abs(vx), y).a;
        int overlap_traps_y_T = traps.getPixel(x, y - R - abs(vy)).a;
        int overlap_traps_y_D = traps.getPixel(x, y + R + abs(vy)).a;



        if (overlap_walls_x_R >= 10) {
            vx = -vx;
            hit = true;
        }
        if (overlap_walls_y_T >= 10) {
            hit = true;
            vy = -vy;
        }
        if (overlap_walls_x_L >= 10) {
            vx = -vx;
            hit = true;
        }
        if (overlap_walls_y_D >= 10) {
            hit = true;
            vy = -vy;
        }

        x += vx;
        y += vy;


        if ((overlap_traps_x_R >= 200) || (overlap_traps_x_L >= 200) || (overlap_traps_y_T >= 200) || (overlap_traps_y_D >= 200)) {
            x = St_x;
            y = St_y;
            vx = 0;
            vy = 0;
            ax = 0;
            ay = 0;
        }
        circle.setPosition(x, y);
        if (((x - F_x) * (x - F_x) + (y - F_y) * (y - F_y)) <= 60 * 60) {
            return 1;
        }
        return 0;
    }
};