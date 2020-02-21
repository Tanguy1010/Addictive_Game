#include "point.h"


Point::Point()
{

}
Point::Point(int position,int color)
{
    this->int_position = position;
    this->int_color = color;
}

Point::Point(int position,int color,int nbcolumn)
{
    this->int_position = position;
    this->int_color = color;
    this->nbcollumn = nbcolumn;
    findPositionsOfPositions(this->nbcollumn);
}

/**
 * @brief Data_input::findPositionsOfPositions The file in input give the Positions;
 * use this vectore of position and find the position r1 and c1 of the postion.
 * exemple : for a 6x4 board
 *  - 1 == (1,1)
 *  - 11 == (3,3)
 *  - 24 == (6,4)
 * @param nbcolumn Size of the column in the keyboard.
 */
void Point::findPositionsOfPositions(int nbcolumn){
    int l_int_row,l_int_column;
    const int l_const_int_position = this->int_position;
    l_int_column = l_const_int_position%nbcolumn;
    if(l_int_column==0){
        l_int_column=nbcolumn;
        l_int_row=l_const_int_position/nbcolumn;
    }
    else{
        l_int_row=(l_const_int_position/nbcolumn) + 1;
    }
    this->int_row = l_int_row;
    this->int_column = l_int_column;
}
/**
 * @brief Point::changePosition Change the postion of the Point depending of the direction.
 * @param direction Charactere that can be : N, E, S, W.
 * @return If the position have been correctly change return true.
 */
bool Point::changePosition(char direction){
    bool l_success = true;
    switch (direction) {
    case 'N':
        this->int_row--;
        break;
    case 'E':
        this->int_column++;
        break;
    case 'S':
        this->int_row++;
        break;
    case 'W':
        this->int_column--;
        break;
    default:
        l_success= false;
        break;
    }
    return l_success;
}
/**
 * @brief Point::comparePosition Compare the point with an other point.
 * @param compared Point that will be compared.
 * @return If the row and collumn are the same it will return true.
 */
bool Point::comparePosition(Point compared){
    /*if(compared.int_row==this->int_row && compared.int_column==this->int_column) return true;
    return false;*/
    return (compared.int_row==this->int_row && compared.int_column==this->int_column)?true:false;
}
