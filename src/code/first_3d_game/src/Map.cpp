//
// Created by umbra on 14/06/2021.
//

#include "../include/Map.hpp"

Map::Map()
{
    this->now = 0;
    this->max = 5;
    this->frames = 0;
}

void Map::set_window(const int screenWidth, const int screenHeight, int fps)
{

    this->x = screenWidth;
    this->y = screenHeight;
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");
    SetTargetFPS(fps);
}

void Map::draw_window()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Map::refresh()
{
    EndDrawing();
}

void Map::set_background(std::string str)
{
    this->background = LoadImage(str.c_str());
    ImageResize(&background, this->x, this->y);
    this->texture = LoadTextureFromImage(this->background);
}

void Map::draw_background()
{
    DrawTexture(this->texture, 0, 0, WHITE);
}

bool Map::close_window()
{
    if (WindowShouldClose())
    {
        UnloadTexture(this->texture);
        UnloadImage(this->background);
        CloseWindow();
        CloseAudioDevice();
        return false;
    }
    return true;
}

void Map::load_background(std::string start, std::string end, std::string await)
{
    this->start_texture = LoadTexture(start.c_str());
    this->end_texture = LoadTexture(end.c_str());
    this->await_texture = LoadTexture(await.c_str());

    this->start_rectangle = {0, 0, (float)this->start_texture.width / (float)this->max, (float)this->start_texture.height};
    this->end_rectangle = {0, 0, (float)this->end_texture.width / (float)this->max, (float)this->end_texture.height};
    this->await_rectangle = {0, 0, (float)this->await_texture.width / (float)this->max, (float)this->await_texture.height};
}

void Map::display_start(int &game_state)
{
    this->frames += 1;
    if (this->frames >= (60 / this->max - 1))
    {
        this->frames = 0;
        this->now += 1;

        if (this->now > this->max - 1)
        {
            game_state += 1;
            this->now = 0;
        }
    }
    if (game_state == 0)
    {
        this->start_rectangle.x = (float)this->now * (float)this->start_texture.width / (float)this->max;
        DrawTextureRec(this->start_texture, this->start_rectangle, Vector2{0, 0}, WHITE);
    }
    else if (game_state == 1)
    {
        this->end_rectangle.x = (float)this->now * (float)this->end_texture.width / (float)this->max;
        DrawTextureRec(this->end_texture, this->end_rectangle, Vector2{0, 0}, WHITE);
    }
    else
    {
        this->await_rectangle.x = (float)this->now * (float)this->await_texture.width / (float)this->max;
        DrawTextureRec(this->await_texture, this->await_rectangle, Vector2{0, 0}, WHITE);
    }
}

void Map::load_parallax()
{
    this->parallax_1 = LoadTexture(ASSETS_PATH "parallax_1.png");
    this->parallax_2 = LoadTexture(ASSETS_PATH "parallax_2.png");
    this->parallax_3 = LoadTexture(ASSETS_PATH "parallax_3.png");
    this->parallax_4 = LoadTexture(ASSETS_PATH "parallax_4.png");
    this->parallax_5 = LoadTexture(ASSETS_PATH "parallax_5.png");

    this->move1 = 30.0f;
    this->move2 = 30.0f;
    this->move3 = 30.0f;
    this->move4 = 30.0f;
}

void Map::display_parallax()
{

    this->move1 -= 0.05f;
    if (this->move1 < -30.0f)
        this->move1 = 30.0f;
    this->move2 -= 0.06f;
    if (this->move2 < -30.0f)
        this->move2 = 30.0f;
    this->move3 -= 0.07f;
    if (this->move3 < -30.0f)
        this->move3 = 30.0f;
    this->move4 -= 0.08f;
    if (this->move4 < -30.0f)
        this->move4 = 30.0f;
    DrawCubeTexture(this->parallax_5, Vector3{0.0f, -1.0f, -1.5f}, 120.0f, 1.0f, 40.0f, WHITE);
    DrawCubeTexture(this->parallax_4, Vector3{this->move4, -1.0f, -1.5f}, 120.0f, 1.0f, 40.0f, WHITE);
    DrawCubeTexture(this->parallax_3, Vector3{this->move3, -1.0f, -1.5f}, 120.0f, 1.0f, 40.0f, WHITE);
    DrawCubeTexture(this->parallax_2, Vector3{this->move2, -1.0f, -1.5f}, 120.0f, 1.0f, 40.0f, WHITE);
    DrawCubeTexture(this->parallax_1, Vector3{this->move1, -1.0f, -1.5f}, 120.0f, 1.0f, 40.0f, WHITE);
}

void Map::set_how_to_play(std::string path)
{
    this->how_to_play = LoadTexture(path.c_str());
}

void Map::display_htp(void)
{
    DrawTexture(this->how_to_play, 0, 0, WHITE);
}