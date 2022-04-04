//
// Created by Quyen on 4/3/2022.
//

#ifndef HELLOSDL2_MAINOBJECT_H
#define HELLOSDL2_MAINOBJECT_H

#include "CommonFunction.h"
#include "BaseObject.h"

#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 8

class MainObject : public BaseObject {
public:
    MainObject();

    ~MainObject();

    enum WalkType {
        WALK_RIGHT = 0,
        WALK_LEFT = 1,
    };

    bool LoadImg( std::string path, SDL_Renderer *screen );

    void Show( SDL_Renderer *des );

    void HandleInputAction( SDL_Event events, SDL_Renderer *screen );

    void set_clips();

    void DoPlayer( Map &map_data );

    void CheckToMap( Map &map_data );

    void SetMapXY( const int map_x, const int map_y ) {
        map_x_ = map_x;
        map_y_ = map_y;
    }

    void CenterEntityOnMap( Map &map_data );

private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[8];
    Input input_type_;
    int frame_;
    int status_;
    bool on_ground;
    int map_x_;
    int map_y_;
};


#endif //HELLOSDL2_MAINOBJECT_H
