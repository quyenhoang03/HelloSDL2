//
// Created by Quyen on 4/1/2022.
//

#ifndef HELLOSDL2_BASEOBJECT_H
#define HELLOSDL2_BASEOBJECT_H

#include "CommonFunction.h"

class BaseObject {
public:
    BaseObject();

    ~BaseObject();

    void SetRect( const int x, const int y ) {
        rect_.x = x;
        rect_.y = y;
    }

    SDL_Rect GetRect() { return rect_; }

    SDL_Texture *GetObject() const { return p_object_; }

    virtual bool LoadImg( std::string path, SDL_Renderer *screen );

    void Render( SDL_Renderer *des, const SDL_Rect *clip = nullptr );

    void Free();

protected:
    SDL_Texture *p_object_;
    SDL_Rect rect_;

};

#endif //HELLOSDL2_BASEOBJECT_H
