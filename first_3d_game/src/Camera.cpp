//
// Created by umbra on 17/06/2021.
//

#include "../include/Camera.hpp"

void Game_Camera::init_camera_up()
{
    this->camera = {{0.0f, 24.0f, 16.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0};
    SetCameraMode(camera, CAMERA_FIRST_PERSON);
}

void Game_Camera::init_fp(Vector2 player_pos)
{
    this->pos = player_pos;
    camera.position.x = this->pos.x;
    camera.position.z = this->pos.y;
    SetCameraMode(camera, CAMERA_FIRST_PERSON);
    this->oldCamPos = camera.position;
}

void Game_Camera::begin_tree()
{
    BeginMode3D(this->camera);
}

void Game_Camera::end_tree()
{
    EndMode3D();
}

void Game_Camera::camera_update()
{
    UpdateCamera(&this->camera);
}
