//
// Created by Quyen on 4/1/2022.
//

#ifndef HELLOSDL2_COMMONFUNCTION_H
#define HELLOSDL2_COMMONFUNCTION_H

#include<windows.h>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"SDL_mixer.h"
#include "SDL_ttf.h"
#include<iostream>

static SDL_Window *g_window = nullptr;
static SDL_Event g_event;
static SDL_Renderer *g_screen = nullptr;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0Xff;

#define TILE_SIZE 64
#define MAX_MAP_X 400
#define MAX_MAP_Y 10

struct Input {
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
};

struct Map {
    int start_x_;
    int start_y_;

    int max_x_;
    int max_y_;

    int tile[MAX_MAP_Y][MAX_MAP_X];
    char *filename;

};

#endif //HELLOSDL2_COMMONFUNCTION_H
