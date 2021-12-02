//
// Created by umbra on 14/06/2021.
//

#include "../include/Button.hpp"

void Button::create_button(int pos_x, int pos_y, std::string path)
{
    this->button_sprite = LoadTexture(path.c_str());
    this->button_rectangle = create_rectangle(0, 0, this->button_sprite.width, this->button_sprite.height / 2);
    this->button_position = create_rectangle(pos_x, pos_y, this->button_sprite.width, this->button_sprite.height / 2);

    this->button_vector.x = pos_x;
    this->button_vector.y = pos_y;
}

Rectangle Button::create_rectangle(float pos_x, float pos_y, float size_x, float size_y)
{
    Rectangle create = {pos_x, pos_y, size_x, size_y};
    return (create);
}

void Button::animate_button(void)
{
    int change = 0;

    if (CheckCollisionPointRec(GetMousePosition(), button_position))
    {
        if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            change = 1;
    }
    else
        change = 0;
    this->button_rectangle.y = change * this->button_sprite.height / 2;
}

void Button::display_button()
{
    this->animate_button();
    DrawTextureRec(this->button_sprite, this->button_rectangle, this->button_vector, WHITE);
}

bool Button::is_clicked()
{
    if (CheckCollisionPointRec(GetMousePosition(), button_position))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return (true);
    }
    return (false);
}