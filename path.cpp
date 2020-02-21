#include "path.h"

Path::Path(int colore,int length,Point start,Point end,vector<char> path)
{
    this->int_colore = colore;
    this->pt_startingpoint = start;
    this->pt_endingpoint = end;
    this->int_length = length;
    this->vec_str_path = path;
    this->b_possible = followPath();
}
/**
 * @brief Path::followPath Creat all the points inside the path guided by the direction vec_str_path.
 * @return If the path is valide it will return true.
 */
bool Path::followPath(){
    Point tmp_pt = this->pt_startingpoint;
    vector<char> tmp_vec_str_path = this->vec_str_path;
    vector<Point> tmp_vec_point {this->pt_startingpoint};
    for(char it_char : tmp_vec_str_path){                                                   // Foreach direction
        tmp_pt.changePosition(it_char);                                                     // Change the position of the point depending of the direction
        for(auto it_pt = tmp_vec_point.begin();it_pt!=tmp_vec_point.end()-1;it_pt++){       // Check don't cross the path
            if((*it_pt).comparePosition(tmp_pt)) {                                          // CASE : CROSS PATH
                setInvalidity(tmp_vec_point.size());
                tmp_vec_point.erase(tmp_vec_point.begin());                                 // Erase starting point
                this->vec_pt_pathpoints = tmp_vec_point;
                return false;
            }
        }
        tmp_vec_point.push_back(tmp_pt);
    }
    if(this->pt_endingpoint.comparePosition(tmp_vec_point.back())){                         // CASE : CORRECT PATH
        tmp_vec_point.erase(tmp_vec_point.begin());                                         // Erase starting point
        tmp_vec_point.pop_back();                                                           // Erase ending point
        this->vec_pt_pathpoints = tmp_vec_point;
        return true;                                                                        // Check finish at the ending point
    }
    else{                                                                                   // CASE : WRONG ENDING
        setInvalidity(tmp_vec_point.size()-1);                                              // position invalidity -> size vec-1 (first point)
        tmp_vec_point.erase(tmp_vec_point.begin());                                         // Erase starting point
        this->vec_pt_pathpoints = tmp_vec_point;
        return false;
    }
}

void Path::setInvalidity(int position){
    this->b_possible = false;
    this->int_posinvalidity = position;
}
