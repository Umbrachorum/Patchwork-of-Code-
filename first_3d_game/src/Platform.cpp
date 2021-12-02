//
// Created by umbra on 14/06/2021.
//

#include "../include/Platform.hpp"

void Platform::init_platform(const std::string &path)
{
    this->image = LoadImage(path.c_str());
    this->cubicmap = LoadTextureFromImage(this->image);
    this->mesh = GenMeshCubicmap(this->image, Vector3{1.0f, 1.0f, 1.0f});
    this->model = LoadModelFromMesh(this->mesh);
    this->texture = LoadTexture(ASSETS_PATH "map.png");
    this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture;
    this->mapPixels = LoadImageColors(this->image);
    this->mapPosition = {-16.0f, 0.0f, -8.0f};
}

void Platform::draw_platform()
{
    DrawModel(this->model, this->mapPosition, 1.0f, WHITE);
}

void Platform::draw_mini_map()
{
    DrawTextureEx(this->cubicmap, Vector2{1920 - (float)this->cubicmap.width * 4.0f - 20, 20.0f}, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(1920 - this->cubicmap.width * 4 - 20, 20, this->cubicmap.width * 4, this->cubicmap.height * 4, GREEN);
    DrawFPS(10, 10);
}

void Platform::clear_back()
{
    ClearBackground(RAYWHITE);
}

Texture2D Platform::return_map()
{
    return this->cubicmap;
}

Color *Platform::return_color()
{
    return this->mapPixels;
}

Vector3 Platform::return_map_pos()
{
    return this->mapPosition;
}
