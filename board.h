#ifndef BOARD_H
#define BOARD_H

#include "point.h"
#include "path.h"
#include "manhattandistance.h"

bool compareByColore (const ManhattanDistance first, const ManhattanDistance second);

class Board
{
public:
    Board(vector<int>);
    Board(vector<string> data);
    void printManhattanDistances();
    int int_nbcols, int_nbrows, int_nbposition,int_nbpath;
    vector<Point> vec_pt_point;
    vector<Path> vec_pth_paths;
    list<ManhattanDistance> lst_int_manhattandistances;
private:
    list<ManhattanDistance>findManhattanForeachPoint(vector<Point> Points);
    int calculateManhattan(Point first, Point second);
    Path checkPaths(Path input_path);
    void printPath(Path path);
    void addPathPoints(Path path);
};

#endif // BOARD_H
