#pragma once
#include <ostream>
#include <math.h>
#include <iostream>

struct Vec2 {           
    float x;
    float y;
    
    const float EPSILON = 0.0015f;

    Vec2 operator+(const Vec2 &other) const {
        return {x + other.x, y + other.y};
    }   

    Vec2 operator-(const Vec2 & other) const {
        return {x - other.x, y - other.y};
    }

    Vec2 operator*(const Vec2 & other) const {
        return {x * other.x, y * other.y};
    }

    Vec2 operator/(const Vec2 & other) const{
        return {x / other.x, y / other.y};
    }

    Vec2 operator*(float scale) const {
        return {x * scale, y * scale};
    }

    Vec2 operator/(float scale) const{
        return {x / scale, y / scale};
    }
            
    void operator*=(float scale) {
        x*=scale;
        y*=scale;
    }

    void operator/=(float scale) {
        x/=scale;
        y/=scale;
    }

    bool operator==(const Vec2 &other) const {
        return abs(x-other.x) <= EPSILON && abs(y-other.y) <= EPSILON;
    }

    bool operator!=(const Vec2 &other) const {
        return !(*this==other);
    }

    friend std::ostream& operator <<(std::ostream& out, Vec2 const& vec) {
        out << '(' << vec.x << ", " << vec.y << ')';
        return out;
    }

    Vec2 normalized() {
        return *this / hypot(x, y);
    }

    float distance(const Vec2& other) {
        return hypot(other.x-x, other.y-y);
    } 

    float cross(Vec2 other) {
        return x * other.y - y * other.x;
    }
};
// template <typename T> struct Vec2 {           
//     T x;
//     T y;
    
//     Vec2<T> operator+(const Vec2<T> & other) const {
//         return {x + other.x, y + other.y};
//     }
    
//     Vec2<T> operator-(const Vec2<T> & other) const {
//         return {x - other.x, y - other.y};
//     }

//     Vec2<T> operator*(const Vec2<T> & other) const {
//         return {x * other.x, y * other.y};
//     }

//     Vec2<T> operator/(const Vec2<T> & other) const{
//         return {x / other.x, y / other.y};
//     }

//     Vec2<T> operator*(float scale) const {
//         return {x * scale, y * scale};
//     }

//     Vec2<T> operator/(float scale) const{
//         return {x / scale, y / scale};
//     }
    
//     void operator*=(float scale) {
//         x*=scale;
//         y*=scale;
//     }

//     void operator/=(float scale) {
//         x/=scale;
//         y/=scale;
//     }

//     bool operator==(const Vec2F &other) const {
//         float diff = abs(x-other.x + y-other.y);
//         return diff <= 0.015f;
//     }
//     bool operator!=(const Vec2F &other) const {
//         return !(*this==other);
//     }

//     friend std::ostream& operator <<(std::ostream& out, Vec2<T> const& vec) {
//         out << '(' << vec.x << ", " << vec.y << ')';
//         return out;
//     }

//     Vec2<T> normalized() {
//         float len = sqrt(pow(x, 2) + pow(y, 2));
//         return *this / len;
//     }
// };

// struct Vec2I : Vec2<int> {
//     bool operator==(const Vec2I &other) const {
//         return other.x == x && other.y == y; 
//     }
//     bool operator!=(const Vec2I &other) const {
//         return !(*this==other);
//     }
// };

// struct Vec2F : Vec2<float> {
//     bool operator==(const Vec2F &other) const {
//         float diff = abs(x-other.x + y-other.y);
//         return diff <= 0.015f;
//     }
//     bool operator!=(const Vec2F &other) const {
//         return !(*this==other);
//     }
// }; 