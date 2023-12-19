#include "send.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace sendmessage;

void to_file_text::send(string a)
{
    ofstream MyFile("filename.txt");
    if (!MyFile.is_open())
    {
        cout << "error" << std::endl;
    }

    MyFile << a;
    MyFile.close();
    cout << "your message in file filename.txt" ;
}

void to_terminal_text::send(string a)
{
    cout << "message is :" << a << std::endl;
}
