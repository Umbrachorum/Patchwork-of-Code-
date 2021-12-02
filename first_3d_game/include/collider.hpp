//
// Created by umbra on 17/06/2021.
//

#ifndef BOMBERMAN_COLLISER_HPP
#define BOMBERMAN_COLLISER_HPP

#include "raylib.h"
#include <iostream>
#include <stdlib.h>
#include "Shared.hpp"

struct bombe_range
{
    Vector3 up;
    Vector3 down;
    Vector3 right;
    Vector3 left;
};

class Collider
{
public:
    Collider(Vector3, Texture2D, Color *);
    ~Collider() = default;
    void make_collision(Vector3 &pos, keys_s key_g, Vector3 ennemy);
    void update_player(Vector3 pos);
    void draw_indicator(Vector3 pos) const;
    void update_color(Color *color);
    void set_in_wall();
    bool get_coli_sate() const;
    void set_ok();
    static bool bool_touch(Vector3 bombe_pos, Vector3 player_pos);
    bool player_can_move(Vector3 &pos, float add_x, float add_y, Vector3 ennemy);

private:
    Vector3 p_pos{};
    Vector3 map_pos{};
    Texture2D cubicmap{};
    Color *mapPixels;
    bool coli_match;
    Vector3 player_size{};
    keys_s keys{};
};

#endif //BOMBERMAN_COLLISER_HPP
