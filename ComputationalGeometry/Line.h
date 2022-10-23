#pragma once
#include <iostream>
using namespace std;

class Line
{
public:
    pair<int, int> p1;
    pair<int, int> p2;
    Line()
    {
        this->p1 = {0, 0};
        this->p2 = {0, 0};
    }
    Line(pair<int, int> point1, pair<int, int> point2)
    {
        this->p1 = point1;
        this->p2 = point2;
    }
};