#ifndef SWITCH_CASE_H
#define SWITCH_CASE_H
#include <cstdint>
#include <map>
#include<functional>

enum shape_type : uint32_t
{
    Shape_Square,
    Shape_Rectangle,
    Shape_Triangle,
    Shape_Circle,

    Shape_Count,
};

struct shape_union
{
    shape_type type;
    float width;
    float height;
};

inline float square_area(shape_union shape)
{
    return shape.width*shape.width;
}
inline float rectangle_area(shape_union shape)
{
    return shape.width*shape.height;
}
inline float triangle_area(shape_union shape)
{
    return 0.5f*shape.width*shape.height;
}
inline float circle_area(shape_union shape)
{
    return 3.14*shape.width*shape.width;
}

float GetAreaSwitch(shape_union shape)
{
    switch(shape.type)
    {
        case Shape_Square:
            return square_area(shape);
            break;
        case Shape_Rectangle:
            return rectangle_area(shape);
            break;
        case Shape_Triangle:
            return triangle_area(shape);
            break;
        case Shape_Circle:
            return circle_area(shape);
            break;

        case Shape_Count: return 0;
    }
    return 0;
}

std::map<shape_type, float(*)(shape_union)> functions = {
    {Shape_Square, square_area},
    {Shape_Rectangle, rectangle_area},
    {Shape_Triangle, triangle_area},
    {Shape_Circle, circle_area}
};

float GetAreaMap(shape_union shape)
{
    return functions[shape.type](shape);
}

#endif // SWITCH_CASE_H
