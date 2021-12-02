//
// Created by umbra on 17/06/2021.
//

#include "../include/collider.hpp"
#include <cmath>

Collider::Collider(Vector3 map, Texture2D cube, Color *Pixels)
{
    this->coli_match = false;
    this->mapPixels = Pixels;
    this->cubicmap = cube;
    this->map_pos = map;
}

bool Collider::player_can_move(Vector3 &pos, float add_x, float add_y, Vector3 ennemy)
{
    int y = 0;
    int x = 0;

    for (y; y < this->cubicmap.height; y += 1)
    {
        for (x = 0; x < this->cubicmap.width; x += 1)
        {
            if (this->mapPixels[y * this->cubicmap.width + x].r == 255)
            {
                if (CheckCollisionSpheres(Vector3{pos.x + add_x, 0.0f, pos.z + add_y}, 0.2f, Vector3{map_pos.x + x, 0.0f, map_pos.z + y}, 0.5f))
                    return (false);
            }
        }
    }
    return (true);
}

void Collider::make_collision(Vector3 &pos, keys_s keys_g, Vector3 ennemy)
{
    this->coli_match = false;

    float speed = 0.1f;
    this->keys = keys_g;

    //DrawCubeV(ennemy, {1.0f, 0.5f, 1.0f}, WHITE);
    if (IsKeyDown(this->keys.right))
    {
        if (this->player_can_move(pos, 0.2f, 0.0f, ennemy))
        {
            if (!CheckCollisionSpheres(Vector3{pos.x + 0.2f, pos.y, pos.z}, 0.3f, ennemy, 0.3f))
                pos.x += speed;
        }
    }
    if (IsKeyDown(this->keys.left))
    {
        if (this->player_can_move(pos, -0.2f, 0.0f, ennemy))
        {
            if (!CheckCollisionSpheres(Vector3{pos.x - 0.2f, pos.y, pos.z}, 0.3f, ennemy, 0.3f))
                pos.x -= speed;
        }
    }
    if (IsKeyDown(this->keys.up))
    {
        if (this->player_can_move(pos, 0.2f, -0.2f, ennemy))
        {
            if (!CheckCollisionSpheres(Vector3{pos.x, pos.y, pos.z - 0.2f}, 0.3f, ennemy, 0.3f))
                pos.z -= speed;
        }
    }
    if (IsKeyDown(this->keys.down))
    {
        if (this->player_can_move(pos, 0.0f, 0.2f, ennemy))
        {
            if (!CheckCollisionSpheres(Vector3{pos.x, pos.y, pos.z + 0.2f}, 0.3f, ennemy, 0.3f))
                pos.z += speed;
        }
    }
}

void Collider::draw_indicator(Vector3 pos) const
{
    Vector2 pos_cpy;
    pos_cpy.x = pos.x;
    pos_cpy.y = pos.z;
    int playerCellX = std::lround(pos_cpy.x - this->map_pos.x + 0.5f);
    int playerCellY = std::lround(pos_cpy.y - this->map_pos.z + 0.5f);

    DrawRectangle(GetScreenWidth() - cubicmap.width * 4 - 20 + playerCellX * 4, 20 + playerCellY * 4, 4, 4, RED);
}

bool Collider::get_coli_sate() const
{
    return this->coli_match;
}

void Collider::set_in_wall()
{
    this->coli_match = true;
}

void Collider::set_ok()
{
    this->coli_match = false;
}

void Collider::update_player(Vector3 pos)
{
    this->p_pos = pos;
}

void Collider::update_color(Color *color)
{
    this->mapPixels = color;
}

bool Collider::bool_touch(Vector3 bombe_pos, Vector3 player_pos)
{
    Vector3 size = {0.5f, 2.0f, 0.5f};
    if (CheckCollisionBoxes(BoundingBox{Vector3{player_pos.x - size.x / 2,
                                                player_pos.y - size.y / 2,
                                                player_pos.z - size.z / 2},
                                        Vector3{player_pos.x + size.x / 2,
                                                player_pos.y + size.y / 2,
                                                player_pos.z + size.z / 2}},
                            BoundingBox{Vector3{bombe_pos.x - 6 / 2,
                                                bombe_pos.y - 1 / 2,
                                                bombe_pos.z - 1 / 2},
                                        Vector3{bombe_pos.x + 6 / 2,
                                                bombe_pos.y + 1 / 2,
                                                bombe_pos.z + 1 / 2}}))
    {
        std::cout << " PROUT 1" << std::endl;
        return true;
    }
    if (CheckCollisionBoxes(BoundingBox{Vector3{player_pos.x - size.x / 2,
                                                player_pos.y - size.y / 2,
                                                player_pos.z - size.z / 2},
                                        Vector3{player_pos.x + size.x / 2,
                                                player_pos.y + size.y / 2,
                                                player_pos.z + size.z / 2}},
                            BoundingBox{Vector3{bombe_pos.x - 1 / 2,
                                                bombe_pos.y - 1 / 2,
                                                bombe_pos.z - 6 / 2},
                                        Vector3{bombe_pos.x + 1 / 2,
                                                bombe_pos.y + 1 / 2,
                                                bombe_pos.z + 6 / 2}}))
    {
        std::cout << " PROUT 2" << std::endl;
        return true;
    }
    return false;
}