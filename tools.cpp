#include "tools.h"

Tools::Tools()
{

}
/**
 * @brief Tools::FileToString Open a file and write the content inside a string.
 * @param file_name Name of the file.
 * @return Content of the file.
 */
string Tools::FileToString(string file_name){
    std::ifstream t(file_name);
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    return str;
}
/**
 * @brief Tools::AllFileToString Open a file of whatever extetion and write it inside a string.
 * @param folder Name of the subfolder the file is in.
 * @param file Name of the file.
 * @param extention Extetion of the file (.txt,.in,...).
 * @return Content of the file.
 */
string Tools::AllFileToString(string folder,string file,string extention){
    string l_str = folder + "/" + file + "." + extention;
    std::ifstream t(l_str);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

/**
 * @brief Tools::StringToFile Creat a file and write the content of a string inside.
 * @param file_name Name of the file that will be created.
 * @param str String that will be written in the file.
 */
void Tools::StringToFile(string file_name,string str){
    ofstream myfile;
    myfile.open (file_name);
    myfile << str;
    myfile.close();
}
/**
 * @brief Tools::Stringtoi Find all the integers inside a string and add them in a vector.
 * @param str String that may content integers.
 * @return Vector of all the string's integers.
 */
vector<int> Tools::StringToVecInt(string str) {
    vector<int> out;
    stringstream ss;

    /* Storing the whole string into string stream */
    ss << str;

    /* Running loop till the end of the stream */
    string temp;
    int found;
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
            out.push_back(found);

        /* To save from space at the end of string */
        temp = "";
    }
    return out;
}

/**
 * @brief Tools::StringToVecString Split string into a vectore of string with space a separator.
 * @param str String that will be convert into vectore of string.
 * @return Vectore that content all the strings.
 */
vector<string> Tools::StringToVecString(string str) {
    std::stringstream ss(str);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> out(begin, end);
    return out;
}
/**
 * @brief Tools::ReplaceAll Change on character to an other in a string.
 * @param str String with character that need to be changed.
 * @param from Character that will be changed.
 * @param to Character that will replace it.
 * @return String with the characters changed.
 */
string Tools::ReplaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}
