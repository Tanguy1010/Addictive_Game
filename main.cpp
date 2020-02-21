#include <iostream>
#include "board.h"

#define LEVEL 4
#define EXO 0
#define STARTINGEXO 0

using namespace std;

void DoLevel(int lvl, int ex);

int main()
{
    for(int i=STARTINGEXO;i<=EXO;i++) DoLevel(LEVEL,i);
    return 0;
}

void DoLevel(int lvl, int ex){
    string folder = "level"+to_string(lvl);
    string str = Tools::AllFileToString(folder,folder+"-"+to_string(ex),"in");
    vector<string> data = Tools::StringToVecString(str);
    cout << folder+"-"+to_string(ex)+" :"<<endl;
    Board res(data);
    cout << endl;
}
