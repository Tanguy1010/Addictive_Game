#ifndef PATH_H
#define PATH_H

#include "point.h"


class Path
{
public:
    Path(int colore,int length,Point start,Point end,vector<char> path);
    bool followPath();
    void setInvalidity(int position);
    int int_length,int_colore,int_posinvalidity;
    Point pt_startingpoint,pt_endingpoint;
    vector<char> vec_str_path;
    vector<Point> vec_pt_pathpoints;
    bool b_possible = true;


};

#endif // PATH_H
