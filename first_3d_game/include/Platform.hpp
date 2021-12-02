//
// Created by umbra on 14/06/2021.
//

#ifndef B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_ENNEMY_HPP
#define B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_ENNEMY_HPP

#include "raylib.h"
#include <string>

class Platform
{
public:
    Platform() = default;
    ~Platform() = default;

    void init_platform(const std::string &);
    void draw_platform();
    static void clear_back();
    void draw_mini_map();
    Color *return_color();
    Texture2D return_map();
    Vector3 return_map_pos();

private:
    Image image;
    Color *mapPixels;
    Mesh mesh;
    Texture2D cubicmap;
    Model model;
    Texture2D texture;
    Vector3 mapPosition;
};

#endif //B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_ENNEMY_HPP
