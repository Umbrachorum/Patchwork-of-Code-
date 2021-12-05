//
// Created by umbra on 14/06/2021.
//

#ifndef B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_PLAYER_HPP
#define B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_PLAYER_HPP

#include <string>
#include <iostream>
#include "raylib.h"
#include "Shared.hpp"

class Player
{
public:
    //Player() = default;
    Player(int nbr, keys_s keys, Color color_p);
    ~Player() = default;

    void set_player_init(float, float, float);
    void draw_cube();
    Vector3 &player_pos();
    Vector3 get_size();
    Rectangle get_rect();
    static bool put_bombe(int key);
    keys_s get_keys(void);

private:
    float now;
    float max;
    float frames;
    Vector3 player_position;
    Vector3 size;
    Texture2D player_texture;
    Rectangle player_rectangle;
    keys_s keys;
    Color my_color;
};

#endif //B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_PLAYER_HPP
