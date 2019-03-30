#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vec2.h"
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

TEST_CASE( "Operator +" ) {
    Vec2 a {-2, 2};
    Vec2 b {4, 2};
    REQUIRE( a + b == Vec2{2, 4});
}

TEST_CASE( "Operator -" ) {
    Vec2 a = {-2, 2};
    Vec2 b = {-2, 2};
    REQUIRE( a - b == Vec2{0,0});
}

TEST_CASE( "Operator =" ) {
    Vec2 a {-2, 2};
    Vec2 b {-2, 2};
    a = b;
    REQUIRE(a == b);
}

TEST_CASE( "Operator +=" ) {
    Vec2 a = {-2, 2};
    a += {-3, 10};
    REQUIRE( a == Vec2{-5, 12});
}

TEST_CASE( "Operator -=" ) {
    Vec2 a = {-2, 2};
    a -= {-3, 10};
    REQUIRE( a == Vec2{1, -8});
}

TEST_CASE( "Operator *=" ) {
    Vec2 a = {-2, 2};
    a *= 4;
    REQUIRE(a == Vec2{-8, 8});
}

TEST_CASE( "Operators ==, !=" ) {
    REQUIRE(Vec2{0,0} == Vec2{0,0});
    REQUIRE(Vec2{0,1} != Vec2{-1,0});
    REQUIRE(Vec2{0.0000024f,0} == Vec2{0,-0.0005f});
}

//https://www.wolframalpha.com/input/?i=magnitude+(10,-10)
TEST_CASE( "Magnitude" ) {
    REQUIRE(Vec2{10, -10}.magnitude() == Approx(10*sqrt(2)));
}

TEST_CASE( "Operators <, <=, >, >=,") {
    REQUIRE(Vec2{10, -10} < Vec2{-30,0});
    REQUIRE(Vec2{-30,0} <= Vec2{-30,0});
    REQUIRE(Vec2{-29,0} <= Vec2{-30,0});
    REQUIRE(Vec2{-1,100} > Vec2{0, 0});
    REQUIRE(Vec2{-1,100} >= Vec2{-1,100});
    REQUIRE(Vec2{-1,101} >= Vec2{-1,100});
}

//https://www.wolframalpha.com/input/?i=(3,3)+normalized
TEST_CASE( "Normalization" ) {
    Vec2 expected = Vec2{float(1 / sqrt(2)), float(1 / sqrt(2))};
    REQUIRE(Vec2{3,3}.normalized() == expected);
    Vec2 a = {3,3};
    a.normalize();
    REQUIRE(a == expected);
}

//https://www.wolframalpha.com/input/?i=rotate+(5,5)+around+(3,8)+by+30+degrees
TEST_CASE( "Rotation" ) {
    Vec2 vector = {5,5};
    Vec2 center {3,8};
    float degrees = 30;
    Vec2 expected = {6.2320f, 6.4019f};
    REQUIRE(vector.rotated(center, degrees) == expected);
    vector.rotate(center, degrees);
    REQUIRE(vector == expected);
}

TEST_CASE( "Cross product" ) {
    Vec2 a = {3, 3};
    Vec2 b = {-4, 1};
    REQUIRE(a.cross(b) == 15);
}

//https://www.wolframalpha.com/input/?i=distance+between+(30,+17),(+-5,-1)
TEST_CASE( "Distance" ) {
    Vec2 a = {30, 17};
    Vec2 b = {-5, -1};
    REQUIRE(a.distance(b) == Approx(sqrt(1549)));
}

TEST_CASE( "Dot" ) {
    Vec2 a = {5, 5};
    Vec2 b = {-5, 4};
    REQUIRE(a.dot(b) == -5);
}

TEST_CASE( "Output" ) {
    Vec2 a = {-2, 2};
    stringstream buffer;
    buffer << a;
    REQUIRE( buffer.str() == "(-2, 2)");
}