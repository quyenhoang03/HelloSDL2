//
// Created by Quyen on 4/3/2022.
//

#ifndef HELLOSDL2_MAINOBJECT_H
#define HELLOSDL2_MAINOBJECT_H

#include "CommonFunction.h"
#include "BaseObject.h"

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
};


#endif //HELLOSDL2_MAINOBJECT_H
