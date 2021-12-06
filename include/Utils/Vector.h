//
//  Vector2.h
//  bahamutGUI
//
//  Created by lochnessdragon on 11/23/21.
//
#pragma once

#include <iostream>

namespace bGUI {
    struct Vector2f {
        float x = 0; 
        float y = 0;
        
        Vector2f() : Vector2f(0, 0) {};
        Vector2f(float x, float y) : x(x), y(y) {};
    };

    inline std::ostream& operator<<(std::ostream& outStream, const Vector2f& vec) {
        outStream << "(" << vec.x << ", " << vec.y << ")";
        return outStream;
    };
    
    struct Vector2i {
        int x = 0;
        int y = 0;

        Vector2i() : Vector2i(0, 0) {};
        Vector2i(int x, int y) : x(x), y(y) {};
    };

    inline std::ostream& operator<<(std::ostream& outStream, const Vector2i& vec) {
        outStream << "(" << vec.x << ", " << vec.y << ")";
        return outStream;
    };

    struct Vector3f : public Vector2f {
        float z = 0;

        Vector3f() : Vector3f(0, 0, 0) {};
        Vector3f(float x, float y, float z) : Vector2f(x, y), z(z) {}
    };

    struct Vector3i : public Vector2i {
        int z = 0;

        Vector3i() : Vector3i(0, 0, 0) {};
        Vector3i(int x, int y, int z) : Vector2i(x, y), z(z) {}
    };

    struct Vector4f : public Vector3f {
        float w = 0;

        Vector4f() : Vector4f(0, 0, 0, 0) {};
        Vector4f(float x, float y, float z, float w) : Vector3f(x, y, z), w(w) {}
    };

    struct Vector4i : public Vector3i {
        int w = 0;

        Vector4i() : Vector4i(0, 0, 0, 0) {};
        Vector4i(int x, int y, int z, int w) : Vector3i(x, y, z), w(w) {}
    };
}
