//
// Created by umbra on 14/06/2021.
//

#ifndef B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_IGAME_HPP
#define B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_IGAME_HPP

#include <vector>
#include "raylib.h"
#include <memory>
#include <iostream>

class Button
{
public:
    Button() = default;
    ~Button() = default;

    void create_button(int pos_x, int pos_y, std::string path);
    static Rectangle create_rectangle(float pos_x, float pos_y, float size_x, float size_y);

    void display_button(void);
    void animate_button(void);

    bool is_clicked(void);

private:
    Texture2D button_sprite;
    Rectangle button_rectangle;
    Vector2 button_vector;
    Rectangle button_position;
};

#endif //B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_IGAME_HPP
