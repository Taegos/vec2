#pragma once
#include <ostream>

#define EPSILON 0.0015f
#define PI 3.141592f

struct Vec2 {           
    float x;
    float y;
    Vec2 operator+(Vec2) const;
    Vec2 operator-(Vec2) const;
    void operator=(Vec2);
    void operator+=(Vec2);
    void operator-=(Vec2);
    void operator*=(float);
    bool operator==(Vec2) const;
    bool operator!=(Vec2) const;
    bool operator<(Vec2) const;
    bool operator<=(Vec2) const;
    bool operator>(Vec2) const;
    bool operator>=(Vec2) const;    
    void normalize();
    Vec2 normalized() const;
    void rotate(Vec2, float);
    Vec2 rotated(Vec2, float) const;
    float cross(Vec2) const;
    float distance(Vec2) const;
    float magnitude() const;
    float dot(Vec2) const;
};

std::ostream& operator<<(std::ostream&, Vec2);

    // friend std::ostream& operator <<(std::ostream& out, Vec2 const& vec) {
    //     out << '(' << vec.x << ", " << vec.y << ')';
    //     return out;
    // }

    // Vec2 operator+(const Vec2 &other) const {
    //     return {x + other.x, y + other.y};
    // }   

    // Vec2 operator-(const Vec2 & other) const {
    //     return {x - other.x, y - other.y};
    // }

    // Vec2 operator*(const Vec2 & other) const {
    //     return {x * other.x, y * other.y};
    // }

    // Vec2 operator/(const Vec2 & other) const{
    //     return {x / other.x, y / other.y};
    // }

    // Vec2 operator*(float scale) const {
    //     return {x * scale, y * scale};
    // }

    // Vec2 operator/(float scale) const{
    //     return {x / scale, y / scale};
    // }
            
    // void operator*=(float scale) {
    //     x*=scale;
    //     y*=scale;
    // }

    // void operator/=(float scale) {
    //     x/=scale;
    //     y/=scale;
    // }

    // bool operator==(const Vec2 &other) const {
    //     return abs(x-other.x) <= EPSILON && abs(y-other.y) <= EPSILON;
    // }

    // bool operator!=(const Vec2 &other) const {
    //     return !(*this==other);
    // }

    // friend std::ostream& operator <<(std::ostream& out, Vec2 const& vec) {
    //     out << '(' << vec.x << ", " << vec.y << ')';
    //     return out;
    // }

    // Vec2 normalized() {
    //     return *this / hypot(x, y);
    // }

    // float distance(const Vec2& other) {
    //     return hypot(other.x-x, other.y-y);
    // } 

    // float cross(Vec2 other) {
    //     return x * other.y - y * other.x;
    // }