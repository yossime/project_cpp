#include "get_mess.hpp"
#include <fstream>
#include <iostream>

using namespace getmessage;
using namespace std;

string from_terminal_text::get(string a)
{
    string line = a;
    getline(cin, line);
    std::cout << "message is coming" << std::endl;
    return line;
}

string from_file_text::get(string a)
{
    string myText;
    ifstream MyReadFile(a);
    if (!MyReadFile.is_open())
        return myText;
    getline(MyReadFile, myText,'\0');
    MyReadFile.close();
    std::cout << "message is coming" << std::endl;
    return myText;
}
