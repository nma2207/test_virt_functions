#ifndef NO_ABSTACT_CLASS_H
#define NO_ABSTACT_CLASS_H


class Shape1
{
public:
    float (*getArea)(Shape1*)=0;
};


float square_area(Shape1* Shape);
float rectangle_area(Shape1* Shape);
float triangle_area(Shape1* Shape);
float circle_area(Shape1* Shape);


class Square1: public Shape1
{
public:
    Square1(float side):
        _side(side)
    {
        getArea = square_area;
    }

public:
    float _side;
};

float square_area(Shape1* Shape)
{
    Square1* s = (Square1*)Shape;
    return s->_side*s->_side;
}

class Rectangle1: public Shape1
{
public:
    Rectangle1(float a, float b):
        _a(a), _b(b)
    {
        getArea = rectangle_area;
    }

public:
    float _a, _b;
};

class Triangle1: public Shape1
{
public:
    Triangle1(float a, float b):
        _a(a), _b(b)
    {
            getArea = triangle_area;
    }

public:
    float _a, _b;
};

class Circle1: public Shape1
{
public:
    Circle1(float r):
        _r(r)
    {
        getArea = circle_area;
    }

public:
    float _r;
};


float rectangle_area(Shape1* Shape)
{
    Rectangle1* s = (Rectangle1*)Shape;
    return s->_a*s->_b;
}

float triangle_area(Shape1* Shape)
{
    Triangle1* s = (Triangle1*)Shape;
    return s->_a*s->_b/2;
}
float circle_area(Shape1* Shape)
{
    Circle1* s = (Circle1*)Shape;
    return s->_r*s->_r*3.14;
}

#endif // NO_ABSTACT_CLASS_H
