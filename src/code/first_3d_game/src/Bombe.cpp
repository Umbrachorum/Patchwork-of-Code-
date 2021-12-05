//
// Created by umbra on 18/06/2021.
//

#include "../include/Bombe.hpp"

static Vector3 cpy;

void Bombe::init_bombe(Vector3 pos)
{
    this->bombe_position = pos;
    this->size = {1.0f, 1.0f, 1.0f};
    this->state = true;
    this->is_exploding = false;
    this->clock = time(nullptr);
}

void Bombe::draw_bombe()
{
    if (state)
    {
        DrawCubeV(this->bombe_position, this->size, YELLOW);
    }
}

void Bombe::explo()
{
    this->state = false;
    this->is_exploding = true;
}

void Bombe::explo_draw()
{
    if (this->is_exploding)
    {
        DrawCubeV(this->bombe_position, Vector3{6, 1, 1}, RED);
        DrawCubeV(this->bombe_position, Vector3{1, 1, 6}, RED);
        if (difftime(time(nullptr), this->clock) > 3)
        {
            this->is_exploding = false;
        }
    }
}

Rectangle Bombe::get_rect()
{
    return this->rectangle_bombe;
}

Vector3 Bombe::player_pos()
{
    return this->bombe_position;
}

Vector3 Bombe::get_size()
{
    return this->size;
}

Vector3 Bombe::return_left()
{
    return this->explo_x_left;
}

Vector3 Bombe::return_right()
{
    return this->explo_x_right;
}

Vector3 Bombe::return_up()
{
    return this->explo_z_up;
}
Vector3 Bombe::return_down()
{
    return this->explo_z_down;
}