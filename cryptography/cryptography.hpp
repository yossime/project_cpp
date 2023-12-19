#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace cryptography

{
    class encrypting
    {
    public:
        virtual ~encrypting() = default;
        virtual string Encrypt(string a) = 0;

    protected:
        encrypting() {  }
        encrypting(const encrypting &) = default;
        encrypting &operator=(const encrypting &) = default;
    };

    class Atbash : public encrypting
    {

    public:
        string Encrypt(string a);
        Atbash() : encrypting{} { };
        ~Atbash() {  };
    };

    class Upper_case : public encrypting
    {

    public:
        string Encrypt(string a);
        Upper_case() : encrypting{} {  }
        ~Upper_case() {  }
    };

    class Caesar : public encrypting
    {

    public:
        string Encrypt(string a);
        Caesar() : encrypting{} { }
        ~Caesar() {  }
    };


    class nocrypt : public encrypting
    {

    public:
        string Encrypt(string a)override;
        nocrypt() : encrypting{} { }
        ~nocrypt() { }
    };
}
