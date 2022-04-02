//
// Created by Quyen on 4/3/2022.
//

#ifndef HELLOSDL2_GAME_MAP_H
#define HELLOSDL2_GAME_MAP_H

#include "CommonFunction.h"
#include "BaseObject.h"

#define MAX_TILES 20

class TileMat : public BaseObject {
public:
    TileMat() { ; }

    ~TileMat() { ; }
};

class GameMap {
public:
    GameMap() { ; }

    ~GameMap() { ; }

    void LoadMap( char *name );

    void LoadTiles( SDL_Renderer *screen );

    void DrawMap( SDL_Renderer *screen );

private:
    Map game_map_;
    TileMat tile_mat[MAX_TILES];
};

#endif //HELLOSDL2_GAME_MAP_H
