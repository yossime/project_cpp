#pragma once
#include <string>
#include <iostream>
using namespace std;
namespace getmessage

{
    class message
    {
    public:
        virtual ~message() = default;
        virtual string get(string a = "") = 0;

    protected:
        message() { }
        message(const message &) = default;
        message &operator=(const message &) = default;
    };

    class from_file_text : public message
    {

    public:
        from_file_text() : message{} { }
        ~from_file_text() { }
        string get(string a = "") override;
    };

    class from_terminal_text : public message
    {

    public:
        from_terminal_text() : message{} {  }
        ~from_terminal_text() {  }
        string get(string a = "") override;
    };

}
