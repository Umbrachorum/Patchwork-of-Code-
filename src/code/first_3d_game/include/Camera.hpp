//
// Created by umbra on 17/06/2021.
//

#ifndef BOMBERMAN_CAMERA_HPP
#define BOMBERMAN_CAMERA_HPP

#include "raylib.h"

class Game_Camera
{
public:
    Game_Camera() = default;
    ~Game_Camera() = default;

    void init_camera_up();
    static void end_tree();
    void begin_tree();
    void camera_update();
    void init_fp(Vector2 player_pos);

private:
    Camera camera;
    Vector3 mapPosition;
    Vector3 oldCamPos;
    Vector2 pos;
};

#endif //BOMBERMAN_CAMERA_HPP
