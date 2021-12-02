//
// Created by umbra on 18/06/2021.
//

#ifndef BOMBERMAN_BOMBE_HPP
#define BOMBERMAN_BOMBE_HPP

#ifdef _WIN32
#else
#include <unistd.h>
#endif

#include "raylib.h"
#include <iostream>
#include <thread>
#include <mutex>

class Bombe
{
public:
    Bombe() = default;
    ~Bombe() = default;

    void init_bombe(Vector3);
    Vector3 player_pos();
    Vector3 get_size();
    Rectangle get_rect();
    void explo();
    void explo_draw();
    void draw_bombe();
    Vector3 return_left();
    Vector3 return_right();
    Vector3 return_up();
    Vector3 return_down();

private:
    time_t clock;
    bool state;
    bool is_exploding;
    Rectangle rectangle_bombe;
    Vector3 bombe_position;
    Vector3 size;
    Vector3 explo_z_down;
    Vector3 explo_z_up;
    Vector3 explo_x_right;
    Vector3 explo_x_left;
};

#endif //BOMBERMAN_BOMBE_HPP
