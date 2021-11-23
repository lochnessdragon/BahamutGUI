//
//  Vector2.h
//  bahamutGUI
//
//  Created by lochnessdragon on 11/23/21.
//
#pragma once

namespace bGUI {
    struct Vector2f{
        float x, y;
        
        Vector2f(float x, float y) : x(x), y(y) {};
    };
    
    struct Vector2i {
        int x, y;
        
        Vector2i() : x(0), y(0) {};
        Vector2i(int x, int y) : x(x), y(y) {};
    };
}
