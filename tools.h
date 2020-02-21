#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>
#include <sstream>
#include <list>

#include <iterator>

using namespace std;


class Tools
{
public:
    Tools();
    static string FileToString(string file_name);
    static string AllFileToString(string folder,string file,string extention);
    static vector<int> StringToVecInt(string str);
    static vector<string> StringToVecString(string str);
    static vector<int> split(string str, char delimiter);
    static string ReplaceAll(string str, const string& from, const string& to);
    void StringToFile(string file_name, string str);
};

#endif // TOOLS_H
