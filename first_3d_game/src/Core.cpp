//
// Created by umbra on 14/06/2021.
//

#include "../include/Core.hpp"

Core::Core()
{
    this->g = std::make_unique<game>();
    this->game_state = START;
}

void Core::set_player()
{
    this->g->p.push_back(Player(PLAYER_1, {KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT}, RED));
    this->g->p.push_back(Player(PLAYER_2, {KEY_W, KEY_S, KEY_D, KEY_A}, BLACK));
}

void Core::set_ennemy()
{
    this->g->platform = std::make_unique<Platform>();
}

void Core::set_button(int max)
{
    int idx = 0;

    while (idx < max)
    {
        this->g->b.push_back(Button());
        idx += 1;
    }
}

void Core::set_map()
{
    this->g->m = std::make_unique<Map>();
}

template <typename T>
void Core::print_vector(std::vector<T> v)
{
    std::cout << v.size() << std::endl;
}

void Core::choose(int n)
{
    if (n == 0)
        print_vector(this->g->p);
    if (n == 1)
        print_vector(this->g->p);
}

void Core::set_camera()
{
    this->g->camera = std::make_unique<Game_Camera>();
}

void Core::set_collision(Vector3 map, Texture2D cube, Color *Pixels)
{
    this->g->collisions.push_back(std::make_unique<Collider>(map, cube, Pixels));
}

void Core::set_musics(const std::string &path_intro, const std::string &path_game)
{
    InitAudioDevice();
    this->intro_music = LoadMusicStream(path_intro.c_str());
    this->game_music = LoadMusicStream(path_game.c_str());
    PlayMusicStream(this->intro_music);
    PlayMusicStream(this->game_music);
}

void Core::play_music()
{
    if (this->game_state == MENU || this->game_state == HOW_TO_PLAY)
        UpdateMusicStream(this->intro_music);
    if (this->game_state == GAME || this->game_state == PAUSE)
        UpdateMusicStream(this->game_music);
}

void Core::display_cursor()
{
    ShowCursor();
}

void Core::create_all_buttons(void)
{
    this->g->b[MENU_PLAY].create_button(1200, 450, ASSETS_PATH "play_button.png");
    this->g->b[MENU_EXIT].create_button(1200, 900, ASSETS_PATH "quit_button.png");
    this->g->b[CONTINUE_GAME].create_button(1200, 450, ASSETS_PATH "continue_button.png");
    this->g->b[GO_MENU].create_button(1200, 700, ASSETS_PATH "menu_button.png");
    this->g->b[GO_HTP].create_button(1200, 700, ASSETS_PATH "htp_button.png");
    this->g->platform->init_platform(ASSETS_PATH "cubicmap.png");
}

void Core::init_game(void)
{
    this->g->m->load_background(ASSETS_PATH "start.png", ASSETS_PATH "end.png", ASSETS_PATH "await.png");
    this->set_collision(this->g->platform->return_map_pos(), this->g->platform->return_map(), this->g->platform->return_color());
    this->set_collision(this->g->platform->return_map_pos(), this->g->platform->return_map(), this->g->platform->return_color());
    this->g->p[PLAYER_1].set_player_init(-15.0, 0.0, -7.0);
    this->g->p[PLAYER_2].set_player_init(14.0, 0.0, -7.0);
    this->g->m->load_parallax();
    this->set_bombs(2);
    this->set_bombe_range(2);
}

void Core::set_game(void)
{
    this->g->m->set_window(1920, 1080, 60);
    this->g->m->set_background(ASSETS_PATH "menu.png");
    this->g->m->set_how_to_play(ASSETS_PATH "how_to_play.png");

    this->set_ennemy();
    this->set_button(5);
    this->set_player();
    this->set_camera();
    this->set_musics(SOUNDS_PATH "menu.mp3", SOUNDS_PATH "game.mp3");
}

int Core::close_raylib(void)
{
    CloseWindow();
    CloseAudioDevice();
    return (0);
}

void Core::display_map(void)
{
    this->g->camera->init_camera_up();
    this->g->camera->begin_tree();
    this->g->collisions[PLAYER_1]->make_collision(this->g->p[PLAYER_1].player_pos(), this->g->p[PLAYER_1].get_keys(), this->g->p[PLAYER_2].player_pos());
    this->g->collisions[PLAYER_2]->make_collision(this->g->p[PLAYER_2].player_pos(), this->g->p[PLAYER_2].get_keys(), this->g->p[PLAYER_1].player_pos());
    this->g->platform->clear_back();
    this->g->m->display_parallax();
    this->g->platform->draw_platform();
    this->g->collisions[PLAYER_1]->update_player(this->g->p[PLAYER_1].player_pos());
    this->g->collisions[PLAYER_2]->update_player(this->g->p[PLAYER_2].player_pos());
}

void Core::restart_music(void)
{
    StopMusicStream(this->intro_music);
    PlayMusicStream(this->intro_music);
}

int Core::loop()
{
    time_t t;
    time_t cpy = time(nullptr);
    time_t tmp;
    time_t t2;
    time_t cpy2 = time(nullptr);
    time_t tmp2;
    int idx = 0;
    int idx2 = 0;

    this->set_game();
    this->create_all_buttons();
    this->init_game();

    while (1)
    {
        this->g->m->draw_window();
        if (this->game_state < MENU)
            this->start_handler();
        if (this->game_state == MENU)
        {
            if (this->menu_handler() == true)
                return (this->close_raylib());
        }
        if (this->game_state == HOW_TO_PLAY)
            this->htp_hanler();
        if (this->game_state == GAMEOVER)
        {
            this->play_music();
            this->g->m->draw_background();
            if (IsKeyPressed(KEY_R))
            {
                this->display_cursor();
                this->g->m->set_background(ASSETS_PATH "menu.png");
                this->game_state = MENU;
            }
        }
        if (this->game_state == GAME)
        {
            if (IsKeyPressed(KEY_P))
            {
                this->display_cursor();
                this->game_state = PAUSE;
            }
            if (this->game_state == GAME)
            {
                this->play_music();
                this->display_map();
                if (this->g->p[PLAYER_1].put_bombe(KEY_KP_1) && idx == 0)
                {
                    idx = 1;
                    this->g->bombe[PLAYER_1]->init_bombe(this->g->p[PLAYER_1].player_pos());
                    time(&t);
                    cpy = t + 3;
                    this->bombe_one = true;
                }
                time(&tmp);
                if (difftime(tmp, cpy) == 0 && idx == 1)
                {
                    this->g->bombe[PLAYER_1]->explo();
                    idx = 2;
                    time(&t);
                    cpy = t + 5;
                }
                time(&tmp);
                if (difftime(tmp, cpy) <= 0 && idx == 2)
                {
                    idx = 0;
                    this->bombe_one = false;
                    if (this->g->collisions[PLAYER_1]->bool_touch(this->g->bombe[PLAYER_1]->player_pos(), this->g->p[PLAYER_2].player_pos()))
                    {
                        this->g->p[PLAYER_1].set_player_init(-15.0, 0.0, -7.0);
                        this->g->p[PLAYER_2].set_player_init(14.0, 0.0, -7.0);
                        this->g->m->set_background(ASSETS_PATH "gameover.png");
                        this->game_state = GAMEOVER;
                    }
                }
                this->g->bombe[PLAYER_1]->draw_bombe();
                this->g->bombe[PLAYER_1]->explo_draw();
                this->g->bombe[PLAYER_2]->draw_bombe();
                this->g->bombe[PLAYER_2]->explo_draw();
                if (this->g->p[PLAYER_2].put_bombe(KEY_SPACE) && idx2 == 0)
                {
                    idx2 = 1;
                    this->g->bombe[PLAYER_2]->init_bombe(this->g->p[PLAYER_2].player_pos());
                    time(&t2);
                    cpy2 = t2 + 3;
                    this->bombe_two = true;
                }
                time(&tmp2);
                if (difftime(tmp2, cpy2) == 0 && idx2 == 1)
                {
                    this->g->bombe[PLAYER_2]->explo();
                    idx2 = 2;
                    time(&t2);
                    cpy2 = t2 + 5;
                }
                time(&tmp2);
                if (difftime(tmp2, cpy2) <= 0 && idx2 == 2)
                {
                    idx2 = 0;
                    this->bombe_two = false;
                    if (this->g->collisions[PLAYER_2]->bool_touch(this->g->bombe[PLAYER_2]->player_pos(), this->g->p[PLAYER_1].player_pos()))
                    {
                        this->g->p[PLAYER_1].set_player_init(-15.0, 0.0, -7.0);
                        this->g->p[PLAYER_2].set_player_init(14.0, 0.0, -7.0);
                        this->g->m->set_background(ASSETS_PATH "gameover.png");
                        this->game_state = GAMEOVER;
                    }
                }
                this->g->p[PLAYER_1].draw_cube();
                this->g->p[PLAYER_2].draw_cube();
                this->g->camera->end_tree();
                this->g->platform->draw_mini_map();
                this->g->collisions[PLAYER_2]->draw_indicator(this->g->p[PLAYER_2].player_pos());
            }
        }
        if (this->game_state == PAUSE)
        {
            this->play_music();
            this->g->m->draw_background();
            this->g->b[CONTINUE_GAME].display_button();
            this->g->b[GO_MENU].display_button();
            if (this->g->b[CONTINUE_GAME].is_clicked())
                this->game_state = GAME;
            if (this->g->b[GO_MENU].is_clicked())
            {
                this->restart_music();
                this->game_state = MENU;
            }
        }
        if (!this->g->m->close_window())
            return (0);
        this->g->m->refresh();
    }
    return (0);
}

void Core::set_bombs(int n)
{
    int idx = 0;
    while (idx < n)
    {
        this->g->bombe.push_back(std::make_shared<Bombe>());
        idx++;
    }
}

void Core::set_bombe_range(int n)
{
    int idx = 0;
    while (idx < n)
    {
        this->bs.push_back(bombe_range{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
        idx++;
    }
}

bombe_range *Core::return_bombs_range(Vector3 up, Vector3 down, Vector3 left, Vector3 right, int player)
{
    this->bs[player].right = right;
    this->bs[player].up = up;
    this->bs[player].down = down;
    this->bs[player].left = left;
    return &this->bs[player];
}

void Core::start_handler(void)
{
    if (IsKeyPressed(KEY_SPACE))
        this->game_state = MENU;
    this->g->m->display_start(this->game_state);
}

bool Core::menu_handler(void)
{
    this->play_music();
    this->g->m->draw_background();

    this->g->b[MENU_PLAY].display_button();
    this->g->b[MENU_EXIT].display_button();
    this->g->b[GO_HTP].display_button();
    if (this->g->b[MENU_PLAY].is_clicked())
        this->game_state = GAME;
    if (this->g->b[GO_HTP].is_clicked())
        this->game_state = HOW_TO_PLAY;
    if (this->g->b[MENU_EXIT].is_clicked())
    {
        this->g->m->close_window();
        return (true);
    }
    return (false);
}

void Core::htp_hanler(void)
{
    this->play_music();
    this->g->m->display_htp();
    this->g->b[MENU_EXIT].display_button();
    if (this->g->b[MENU_EXIT].is_clicked())
        this->game_state = MENU;
}