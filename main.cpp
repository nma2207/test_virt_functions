#include <iostream>
#include "abstact_class.h"
#include "switch_case.h"
#include "no_abstact_class.h"

#include <time.h>
using namespace std;

float total_area(Shape** shapes, size_t count)
{
    float acum = 0;
    for(size_t i=0; i<count; i++)
    {
        acum += shapes[i]->getArea();
    }
    return acum;
}

float total_area2(shape_union* shapes, size_t count)
{
    float acum = 0;
    for(size_t i=0; i<count; i++)
    {
        acum += GetAreaSwitch(shapes[i]);
    }
    return acum;
}

float total_area3(Shape1** shapes, size_t count)
{
    float acum = 0;
    for(size_t i=0; i<count; i++)
    {
        acum += shapes[i]->getArea(shapes[i]);
    }
    return acum;
}

float total_area4(shape_union* shapes, size_t count)
{
    float acum = 0;
    for(size_t i=0; i<count; i++)
    {
        acum += GetAreaMap(shapes[i]);
    }
    return acum;
}
int main()
{
    cout << "Hello World!" << endl;
    Shape *shapes[]={new Triangle(1.123, 31.2), new Circle(5), new Square(12), new Rectangle(55,11)};
    shape_union shapes2[]={{Shape_Triangle, 1.123, 31.2}, {Shape_Circle, 5, 5}, {Shape_Square, 12, 12}, {Shape_Rectangle, 55, 11}};
    Shape1 *shapes3[]={new Triangle1(1.123, 31.2), new Circle1(5), new Square1(12), new Rectangle1(55,11)};
    std::cout << total_area(shapes, 4) << endl;
    std::cout << total_area2(shapes2, 4) << endl;
    std::cout << total_area3(shapes3, 4) << endl;
    std::cout << total_area4(shapes2, 4) << endl;
    int n = 100000;
    float r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    {
        float sum = 0;
        clock_t start = clock();
        for(int i=0; i<n; i++)
        {
            total_area(shapes, 4);
        }
        clock_t end = clock();
        r1 = (double)(end - start)/double(CLOCKS_PER_SEC);
        cout <<sum << " "<< (double)(end - start)/double(CLOCKS_PER_SEC) << endl;
    }
    {
        float sum = 0;
        clock_t start = clock();
        for(int i=0; i<n; i++)
        {
           total_area2(shapes2, 4);
        }
        clock_t end = clock();
        r2 = (double)(end - start)/double(CLOCKS_PER_SEC);
        cout <<sum << " "<< (double)(end - start)/double(CLOCKS_PER_SEC) << endl;
    }
    {
        float sum = 0;
        clock_t start = clock();
        for(int i=0; i<n; i++)
        {
            total_area3(shapes3, 4);
        }
        clock_t end = clock();
        r3 = (double)(end - start)/double(CLOCKS_PER_SEC);
        cout <<sum << " "<< (double)(end - start)/double(CLOCKS_PER_SEC) << endl;
    }
    {
        float sum = 0;
        clock_t start = clock();
        for(int i=0; i<n; i++)
        {
            total_area4(shapes2, 4);
        }
        clock_t end = clock();
        r4 = (double)(end - start)/double(CLOCKS_PER_SEC);
        cout <<sum << " "<< (double)(end - start)/double(CLOCKS_PER_SEC) << endl;
    }
    std::cout << "  " <<endl;
    std::cout << r2 / r1 << endl;
    std::cout << r3 / r1 << endl;
    std::cout << r4 / r1 << endl;
    return 0;
}
