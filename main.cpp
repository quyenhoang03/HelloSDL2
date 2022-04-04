//test for git
#include "CommonFunction.h"
#include "BaseObject.h"
#include "game_map.h"
#include "MainObject.h"
#include "ImpTimer.h"

BaseObject g_background;

bool InitData() {
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if ( ret < 0 ) return false;
    else {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        g_window = SDL_CreateWindow("Game CPP 2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                    SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if ( g_window == nullptr ) {
            success = false;
        } else {
            g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
            if ( g_screen == nullptr ) {
                SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR,
                                       RENDER_DRAW_COLOR);
                int imgFlags = IMG_INIT_PNG;
                if ( !( IMG_Init(imgFlags) && imgFlags )) {
                    success = false;
                }
            }
        }
    }
    return success;
}

bool LoadBackground() {
    bool ret = g_background.LoadImg("img/background.png", g_screen);
    return ret;
}

void close() {
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = nullptr;
    SDL_DestroyWindow(g_window);
    g_window = nullptr;
    IMG_Quit();
    SDL_Quit();
}

int main( int argc, char *argv[] ) {
    ImpTimer fps_timer;
    if ( !InitData()) {
        std::cout << "Failed to Init Data!" << std::endl;
        return -1;
    }

    if ( !LoadBackground()) {
        std::cout << "Failed to load background!" << std::endl;
        return -1;
    }

    GameMap game_map;
    game_map.LoadMap(const_cast<char *>("map/map01.dat"));
    game_map.LoadTiles(g_screen);

    MainObject p_player;
    p_player.LoadImg("img/player_right.png", g_screen);
    p_player.set_clips();

    bool is_quit = false;
    while ( !is_quit ) {
        fps_timer.start();
        while ( SDL_PollEvent(&g_event) != 0 ) {
            if ( g_event.type == SDL_QUIT ) {
                is_quit = true;
            }
            p_player.HandleInputAction(g_event, g_screen);
        }
        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);
        g_background.Render(g_screen, nullptr);


        Map map_data = game_map.getMap();
        p_player.SetMapXY(map_data.start_x_, map_data.start_y_);
        p_player.DoPlayer(map_data);
        p_player.Show(g_screen);
        game_map.SetMap(map_data);
        game_map.DrawMap(g_screen);
        SDL_RenderPresent(g_screen);

        int real_imp_time = fps_timer.get_ticks();
        int time_one_frame = 1000 / FRAME_PER_SECOND; // ms

        if ( real_imp_time < time_one_frame ) {
            int delay_time = time_one_frame - real_imp_time;
            SDL_Delay(delay_time);
        }
    }
    close();
    return 0;
}