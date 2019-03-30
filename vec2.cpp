#include "vec2.h"
#include <math.h>

Vec2 Vec2::operator+(Vec2 rhs) const {
    return {x+rhs.x, y+rhs.y};
}

Vec2 Vec2::operator-(Vec2 rhs) const {
    return {x-rhs.x, y-rhs.y};
}

void Vec2::operator=(Vec2 rhs) {
    x = rhs.x;
    y = rhs.y;
}

void Vec2::operator+=(Vec2 rhs) {
    x+=rhs.x;
    y+=rhs.y;
}

void Vec2::operator-=(Vec2 rhs) {
    x-=rhs.x;
    y-=rhs.y;
}

void Vec2::operator*=(float scalar) {
    x*=scalar;
    y*=scalar;
}

bool Vec2::operator==(Vec2 rhs) const {
    return abs(x-rhs.x) <= EPSILON && abs(y-rhs.y) <= EPSILON;
}

bool Vec2::operator!=(Vec2 rhs) const {
    return !(*this==rhs);
}

bool Vec2::operator<(Vec2 rhs) const {
    return magnitude() < rhs.magnitude();
}

bool Vec2::operator<=(Vec2 rhs) const {
    return magnitude() <= rhs.magnitude();
}

bool Vec2::operator>(Vec2 rhs) const {
    return magnitude() > rhs.magnitude();
}

bool Vec2::operator>=(Vec2 rhs) const {
    return magnitude() >= rhs.magnitude();
}

std::ostream& operator<<(std::ostream& stream, Vec2 vec) {
    stream << '(' << vec.x << ", " << vec.y << ')';
    return stream;
}

void Vec2::normalize() {
    *this = normalized();
}

Vec2 Vec2::normalized() const {
    float m = magnitude();
    return { x / m, y / m};
}

float Vec2::cross(Vec2 rhs) const {
    return x * rhs.y - y * rhs.x;
}

float Vec2::distance(Vec2 rhs) const {
   return hypot(rhs.x-x, rhs.y-y);
}

float Vec2::magnitude() const {
    if (x == 0 && y == 0) {
        return 0;
    }
    return distance({0,0});
}

float Vec2::dot(Vec2 rhs) const {
    return x * rhs.x + y * rhs.y;
}

Vec2 Vec2::rotated(Vec2 center, float degrees) const {
    float radians = degrees * PI / 180;
    Vec2 centerThis = *this - center;
    Vec2 offset = {
        centerThis.dot({cosf(radians), -sinf(radians)}),
        centerThis.dot({sinf(radians), cosf(radians)})
    };
    return center + offset;
}

void Vec2::rotate(Vec2 center, float degrees) {
    *this = rotated(center, degrees);
}