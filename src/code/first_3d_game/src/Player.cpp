//
// Created by umbra on 14/06/2021.
//

#include "../include/Player.hpp"

Player::Player(int nbr, keys_s keys_g, Color color_p)
{
    std::cout << "Player: " << nbr << " created !" << std::endl;
    std::cout << "up: " << keys_g.up << " down: " << keys_g.down << " right: " << keys_g.right << " left: " << keys_g.left << std::endl;
    this->keys = keys_g;
    this->my_color = color_p;
}

bool Player::put_bombe(int key)
{
    if (IsKeyDown(key))
        return true;
    return false;
}

Vector3 &Player::player_pos()
{
    return this->player_position;
}

void Player::draw_cube()
{
    this->size = {0.5f, 2.0f, 0.5f};
    DrawCubeV(this->player_position, this->size, this->my_color);
}

void Player::set_player_init(float x, float y, float z)
{
    this->player_position.x = x;
    this->player_position.y = y;
    this->player_position.z = z;
}

Rectangle Player::get_rect()
{
    return this->player_rectangle;
}

Vector3 Player::get_size()
{
    return this->size;
}

keys_s Player::get_keys()
{
    return (this->keys);
}