#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace sendmessage

{

    class send_message
    {
    public:
        virtual ~send_message() = default;
        virtual void send(string a) = 0;


    protected:
        send_message() {}
        send_message(const send_message &) = default;
        send_message &operator=(const send_message &) = default;
    };

    class to_file_text : public send_message
    {

    public:
        to_file_text() : send_message{} { }
        ~to_file_text() {}
        void send(string a) override;
    };


    class to_terminal_text : public send_message
    {

    public:
        void send(string a) override;
    };


}

