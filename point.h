#ifndef POINT_H
#define POINT_H

#include "tools.h"

class Point
{
public:
    Point();
    Point(int position, int color);
    Point(int position,int color,int nbcolumn);
    void findPositionsOfPositions(int nbcolumn);
    bool changePosition(char direction);
    bool comparePosition(Point compared);
    int int_position,int_color,int_column,int_row,nbcollumn;
};

#endif // POINT_H
