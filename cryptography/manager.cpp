#include "manager.hpp"
#include "get_mess.hpp"
#include "send.hpp"
#include "cryptography.hpp"
#include <string>
#include <map>

using namespace getmessage;
using namespace managermessage;
using namespace sendmessage;
using namespace cryptography;
using namespace std;

void text::get(getmessage::message &mess, string a)
{
    cors = mess.get(a);
}
void text::cription(cryptography::encrypting &cryp)
{
    cryptography = cryp.Encrypt(cors);
}
void text::set(sendmessage::send_message &send)
{
    send.send(cryptography);
}
getmessage::message *text::menu1()
{
    string display = "where do you want message from?";
    int kind = 0;
    using Creator = message *(*)();
    map<int, std::pair<std::string, Creator>> factory_map = {
        {1, {"consul", []() -> message *
             { return new from_terminal_text; }}},
        {2, {"file", []() -> message *
             { return new from_file_text; }}},
    };

    cout << display << std::endl;
    for (auto &pair : factory_map)
    {
        std::cout << pair.first << ": " << pair.second.first << std::endl;
    }
    std::cin >> kind;
    if (kind == 0)
    {
        return nullptr;
    }

    message *cre = factory_map[kind].second();
    return cre;
}

cryptography::encrypting *text::menu2()
{
    string display = "how do you want to encrypt?";
    int kind = 0;
    using Creator = encrypting *(*)();
    map<int, std::pair<std::string, Creator>> factory_map = {
        {1, {"no crypt", []() -> encrypting *
             { return new nocrypt; }}},
        {2, {"atbash", []() -> encrypting *
             { return new Atbash; }}},
        {3, {"upper_case", []() -> encrypting *
             { return new Upper_case; }}},
        {4, {"caesar", []() -> encrypting *
             { return new Caesar; }}},
    };

    cout << display << std::endl;
    for (auto &pair : factory_map)
    {
        std::cout << pair.first << ": " << pair.second.first << std::endl;
    }
    std::cin >> kind;
    if (kind == 0)
    {
        return nullptr;
    }
    encrypting *cre = factory_map[kind].second();
    return cre;
}
sendmessage::send_message *text::menu3()
{
    string display = "where to send the message?";
    int kind = 0;
    using Creator = send_message *(*)();
    map<int, std::pair<std::string, Creator>> factory_map = {
        {1, {"consul", []() -> send_message *
             { return new to_terminal_text; }}},
        {2, {"file", []() -> send_message *
             { return new to_file_text; }}},
    };

    cout << display << std::endl;
    for (auto &pair : factory_map)
    {
        std::cout << pair.first << ": " << pair.second.first << std::endl;
    }
    std::cin >> kind;
    if (kind == 0)
    {
        return nullptr;
    }
    send_message *cre = factory_map[kind].second();
    return cre;
}



using Creator = managermessage::manager* (*)();
std::map<int, std::pair<std::string, Creator>> factory_map = {
    {1, {"text",  []() -> managermessage::manager* { return new managermessage::text; }}},
};

void display_menu(){
    for(auto& pair : factory_map) {
        std::cout << pair.first << ": " << pair.second.first << std::endl;
    }
}

managermessage::manager *create(int kind) {
    return factory_map[kind].second();
}

void menu()
{
   
        int kind = 0;
        std::cout << "What kind of message do you want?" << std::endl;
        display_menu();
        
        std::cin >> kind;
        if (kind == 0) {
            return;
        }
        managermessage::manager *cre = create(kind);
        delete cre;        
    
}