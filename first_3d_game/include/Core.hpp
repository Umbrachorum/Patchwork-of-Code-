//
// Created by umbra on 14/06/2021.
//

#ifndef B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_CORE_HPP
#define B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_CORE_HPP

#include <iostream>
#include <string>
#include <memory>
#include "Button.hpp"
#include <string.h>
#include "Button.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include "collider.hpp"
#include "Shared.hpp"
#include "Camera.hpp"
#include "Bombe.hpp"
#include <unordered_map>

struct game
{
    std::vector<std::shared_ptr<Bombe>> bombe;
    std::vector<Player> p;
    std::unique_ptr<Platform> platform;
    std::unique_ptr<Game_Camera> camera;
    std::vector<std::unique_ptr<Collider>> collisions;
    std::unique_ptr<Map> m;
    std::vector<Button> b;
};

enum all_buttons
{
    MENU_PLAY,
    MENU_EXIT,
    CONTINUE_GAME,
    GO_MENU,
    GO_HTP
};

enum player
{
    PLAYER_1,
    PLAYER_2
};

enum state
{
    START,
    END,
    AWAIT,
    EMPTY,
    MENU,
    GAME,
    PAUSE,
    GAMEOVER,
    HOW_TO_PLAY
};

class Core
{
public:
    Core();
    ~Core() = default;
    void disp_score();
    void set_player();
    void set_ennemy();
    void set_button(int max);
    void set_map();
    void set_collision(Vector3 map, Texture2D cube, Color *Pixels);
    void set_camera();
    void choose(int n);
    int loop();
    void set_bombs(int n);
    template <typename T>
    void print_vector(std::vector<T> v);
    void set_bombe_range(int n);
    bombe_range *return_bombs_range(Vector3 up, Vector3 down, Vector3 left, Vector3 right, int player);
    void set_musics(const std::string& path_intro, const std::string& path_game);
    void play_music();

    static void display_cursor(void);

    void start_handler(void);
    bool menu_handler(void);
    void htp_hanler(void);

    void create_all_buttons(void);
    void init_game(void);
    void set_game(void);

    void display_map(void);
    void restart_music(void);

    int close_raylib(void);

private:
    time_t clock;
    std::unique_ptr<game> g;
    int game_state;
    Music intro_music{};
    Music game_music{};
    std::vector<bombe_range> bs;
    bool bombe_one{};
    bool bombe_two{};
};

#endif //B_YEP_400_BDX_4_1_INDIESTUDIO_AXEL_FUENTES_CORE_HPP
