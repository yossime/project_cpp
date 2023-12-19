#pragma once
#include <string>
#include "get_mess.hpp"
#include "send.hpp"
#include "cryptography.hpp"

using namespace std;
namespace managermessage

{

    class manager
    {
    public:
        virtual ~manager() = default;
        virtual getmessage::message* menu1() = 0;
        virtual cryptography::encrypting* menu2() = 0;
        virtual sendmessage::send_message* menu3() = 0;

        virtual void get(getmessage::message &mess, string a = "") = 0;
        virtual void cription(cryptography::encrypting &cryp) = 0;
        virtual void set(sendmessage::send_message &send) = 0;

    protected:
        manager() {}
        manager(const manager &) = default;
        manager &operator=(const manager &) = default;
    };

    class text : public manager
    {
        string cors{};
        string cryptography{};

    public:
        getmessage::message* menu1() override;
        cryptography::encrypting* menu2() override;
        sendmessage::send_message* menu3() override;

        void get(getmessage::message &mess, string a = "") override;
        void cription(cryptography::encrypting &cryp) override;
        void set(sendmessage::send_message &send) override;

        ~text() { }
    };

}
void display_menu();
managermessage::manager *create(int kind);
void menu();