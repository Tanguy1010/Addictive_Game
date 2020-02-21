#include "board.h"
/**
 * @brief Data_input::Data_input Builder of the data input.
 * @param data vectore with the following form : rows cols numberOfPositions Position1 Position2 ... PositionnumberOfPositions
 */
Board::Board(vector<int> data)
{
    this->int_nbrows = data.at(0);
    this->int_nbcols = data.at(1);
    this->int_nbposition = data.at(2);
    int l_it = 3;
    for(l_it = 3;l_it<int_nbposition*2+3;l_it+=2) {                  // Creat vectore of Point
        Point l_pt_tmp(data.at(l_it),data.at(l_it+1));               // it -> Position   it+1 -> Color
        l_pt_tmp.findPositionsOfPositions(this->int_nbcols);
        this->vec_pt_point.push_back(l_pt_tmp);
    }
    this->int_nbpath = data.at(l_it);                               // Number of path
    l_it++;
    /*  for(int i=0;i<this->int_nbpath;i++){
        int tmp_colore = data.at(l_it);
        int tmp_position = data.at(l_it+1);
        int tmp_lenght = data.at(l_it+2);
        int tmp_end = l_it + tmp_lenght + 3;
        vector<string> tmp_charpath;
        for(l_it+=3;l_it<tmp_end;l_it++){
            tmp_charpath.push_back(data.at(l_it));
        }
        Path tmp_path(tmp_colore,tmp_position,tmp_lenght,tmp_charpath);
        this->vec_pth_paths.push_back(tmp_path);
    }*/

    this->lst_int_manhattandistances = findManhattanForeachPoint(this->vec_pt_point);
}
/**
 * @brief Data_input::Data_input Builder of the data input.
 * @param data vectore with the following form :
 *                                               - rows
 *                                               - cols
 *                                               - numberOfPoints
 *                                               - Point1 Point2 ... PointnumberOfPoints
 *                                               - numberOfPaths
 *                                               - Path1 Path2 ... PathnumberOfPaths
 */
Board::Board(vector<string> data)
{
    this->int_nbrows = stoi(data.at(0));
    this->int_nbcols = stoi(data.at(1));
    this->int_nbposition = stoi(data.at(2));
    int l_it = 3;
    for(l_it = 3;l_it<int_nbposition*2+3;l_it+=2) {                     // Creat vectore of Point
        Point l_pt_tmp(stoi(data.at(l_it)),stoi(data.at(l_it+1)),this->int_nbcols);      // it -> Position   it+1 -> Color
        //l_pt_tmp.findPositionsOfPositions(this->int_nbcols);
        this->vec_pt_point.push_back(l_pt_tmp);
    }
    this->int_nbpath = stoi(data.at(l_it));                              // Number of path
    l_it++;
    for(int i=0;i<this->int_nbpath;i++){                                // Foreach path
        int tmp_colore = stoi(data.at(l_it));
        int tmp_position = stoi(data.at(l_it+1));
        int tmp_lenght = stoi(data.at(l_it+2));
        int tmp_end = l_it + tmp_lenght + 3;
        Point tmp_pt_start,tmp_pt_end;
        vector<char> tmp_strpath;
        for(l_it+=3;l_it<tmp_end;l_it++){
            tmp_strpath.push_back(data.at(l_it).at(0));
        }
        int it_i=0;
        auto it_pt = this->vec_pt_point.begin();
        while(it_i!=2){                                                 // Find start/end with the colore
            if((*it_pt).int_color==tmp_colore){
                if((*it_pt).int_position == tmp_position) tmp_pt_start = *it_pt;
                else tmp_pt_end = *it_pt;
                it_i++;
            }
            it_pt++;
        }
        Path tmp_path(tmp_colore,tmp_lenght,tmp_pt_start,tmp_pt_end,tmp_strpath);
        tmp_path = checkPaths(tmp_path);
        addPathPoints(tmp_path);
        printPath(tmp_path);
        this->vec_pth_paths.push_back(tmp_path);
    }
    //this->lst_int_manhattandistances = findManhattanForeachPoint(this->vec_pt_point);
}
/**
 * @brief Board::findManhattanForeachPoint Find the points with the same colore and calculate them manhattan distance.
 * @param points Vectore that content all the points.
 * @return Return a list with Manhattan Distance and sort them by colore.
 */
list<ManhattanDistance> Board::findManhattanForeachPoint(vector<Point> points){
    vector<Point> l_vec_pts_points = points;
    list<ManhattanDistance> l_list_manhattandistances;
    while(!l_vec_pts_points.empty()){
        int l_it = 0;
        Point l_pts_backpoint = l_vec_pts_points.back();
        l_vec_pts_points.pop_back();
        while (l_pts_backpoint.int_color!=l_vec_pts_points.at(l_it).int_color) l_it++;
        Point l_pts_similarcolore = l_vec_pts_points.at(l_it);
        l_vec_pts_points.erase(l_vec_pts_points.begin()+l_it);
        ManhattanDistance l_md_tmp(calculateManhattan(l_pts_backpoint,l_pts_similarcolore),l_pts_backpoint.int_color);
        l_list_manhattandistances.push_back(l_md_tmp);
    }
    l_list_manhattandistances.sort(compareByColore);
    return l_list_manhattandistances;
}
/**
 * @brief Board::calculateManhattan Two point input in the methode and we return manhattan number.
 * @param first First point.
 * @param second Second point.
 * @return Manhattan number.
 */
int Board::calculateManhattan(Point first, Point second){
    return abs(first.int_row-second.int_row) + abs(first.int_column-second.int_column);
}
/**
 * @brief Data_input::printPositions This methode print the vectore position.
*/
void Board::printManhattanDistances(){
    for(ManhattanDistance it_md : this->lst_int_manhattandistances){
        cout << to_string(it_md.int_distance) + " ";
    }
}
/**
 * @brief Board::checkPaths Check if the path is possible inside this board :
 *                                                                            - Doesn't pass through an other point
 *                                                                            - Isn't going out of the board
 * @param input_path Path that will be checked.
 * @return If the path work it will return the same as in inptut; if the path doesn't work it will set the Invalidity.
 */
Path Board::checkPaths(Path input_path){
    Path tmp_pth = input_path;
    vector<Point> tmp_vec_pt_pathpoints = tmp_pth.vec_pt_pathpoints;
    int it_position = 1;                                                        // Position in the vectore
    for(Point it_pt_path : tmp_vec_pt_pathpoints){                              // Foreach point of the path
        if(!tmp_pth.b_possible&&tmp_pth.int_posinvalidity<=it_position) return tmp_pth;
        if(it_pt_path.int_row>this->int_nbrows){
            tmp_pth.setInvalidity(it_position);
            return tmp_pth;
        }
        if(it_pt_path.int_column>this->int_nbcols){
            tmp_pth.setInvalidity(it_position);
            return tmp_pth;
        }
        for(Point it_pt_board : this->vec_pt_point){                            //Foreach point in the board
            if(it_pt_path.comparePosition(it_pt_board)){
                tmp_pth.setInvalidity(it_position);
                return tmp_pth;
            }
        }
        it_position++;
    }
    return tmp_pth;
}
/**
 * @brief Board::addPathPoints If the path is possible will add all the pathpoints inside the boardpoints.
 * @param path
 */
void Board::addPathPoints(Path path){
    if(path.b_possible){
        for(Point it_pt_path : path.vec_pt_pathpoints) this->vec_pt_point.push_back(it_pt_path);
    }
}

void Board::printPath(Path path){
    if(path.b_possible) cout << "1 " + to_string(path.int_length)<<endl;
    else cout << "-1 " + to_string(path.int_posinvalidity)<<endl;
}

bool compareByColore (const ManhattanDistance first, const ManhattanDistance second){
    if(first.int_colore<second.int_colore) return true;
    else return false;
}
