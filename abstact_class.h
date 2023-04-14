#ifndef ABSTACT_CLASS_H
#define ABSTACT_CLASS_H


class Shape
{
public:
    virtual float getArea() = 0;
};

class Square: public Shape
{
public:
    Square(float side):
        _side(side)
    {}
    virtual float getArea() override
    {
        return _side*_side;
    }
private:
    float _side;
};

class Rectangle: public Shape
{
public:
    Rectangle(float a, float b):
        _a(a), _b(b)
    {}
    virtual float getArea() override
    {
        return _a * _b;
    }
private:
    float _a, _b;
};

class Triangle: public Shape
{
public:
    Triangle(float a, float b):
        _a(a), _b(b)
    {}
    virtual float getArea() override
    {
        return _a * _b / 2;
    }
private:
    float _a, _b;
};

class Circle: public Shape
{
public:
    Circle(float r):
        _r(r)
    {}
    virtual float getArea() override
    {
        return 3.14 * _r * _r;
    }
private:
    float _r;
};

#endif // ABSTACT_CLASS_H
