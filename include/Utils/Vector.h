//
//  Vector2.h
//  bahamutGUI
//
//  Created by lochnessdragon on 11/23/21.
//
#pragma once

namespace bGUI {
    struct Vector2f {
        float x = 0; 
        float y = 0;
        
        Vector2f(float x, float y) : x(x), y(y) {};
    };
    
    struct Vector2i {
        int x = 0;
        int y = 0;

        Vector2i(int x, int y) : x(x), y(y) {};
    };

    struct Vector3f : public Vector2f {
        float z = 0;

        Vector3f(float x, float y, float z) : Vector2f(x, y), z(z) {}
    };

    struct Vector3i : public Vector2i {
        int z = 0;

        Vector3i(int x, int y, int z) : Vector2i(x, y), z(z) {}
    };

    struct Vector4i : public Vector3i {
        int w = 0;

        Vector4i(int x, int y, int z, int w) : Vector3i(x, y, z), w(w) {}
    };

    struct Vector4f : public Vector3f {
        float w = 0;

        Vector4f(float x, float y, float z, float w) : Vector3f(x, y, z), w(w) {}
    };
}
