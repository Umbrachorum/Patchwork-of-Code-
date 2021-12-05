//
// Created by umbra on 14/06/2021.
//

#ifndef B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_MAP_HPP
#define B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_MAP_HPP

#include "raylib.h"
#include <string>

class Map
{
public:
    Map();
    ~Map() = default;

    void set_window(const int, const int, int);
    bool close_window();
    static void draw_window();
    static void refresh();
    void set_background(std::string);
    void draw_background();

    void load_background(std::string start, std::string end, std::string await);
    void display_start(int &game_state);

    void load_parallax(void);
    void display_parallax(void);

    void set_how_to_play(std::string path);
    void display_htp(void);

private:
    int x{};
    int y{};

    Image background{};
    Image gameover{};
    Texture2D texture{};
    Texture2D how_to_play;

    int frames;
    int max;
    int now;

    Texture2D start_texture{};
    Texture2D end_texture{};
    Texture2D await_texture{};

    Rectangle start_rectangle{};
    Rectangle end_rectangle{};
    Rectangle await_rectangle{};

    Texture2D parallax_1{};
    Texture2D parallax_2{};
    Texture2D parallax_3{};
    Texture2D parallax_4{};
    Texture2D parallax_5{};

    float move1{};
    float move2{};
    float move3{};
    float move4{};
};

#endif //B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_MAP_HPP
