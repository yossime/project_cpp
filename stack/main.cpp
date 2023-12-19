#include <iostream>
#include "stack_min.hpp"

#include <cstdlib>

int main()
{
    Stack_min b{4096};

    b.push(3);
    b.push(40);
    b.push(44);
    b.push(3);
    b.push(1);
    b.remin();
    b.pop();
    b.remin();
    b.pop();
    b.remin();
    b.pop();
    b.remin();

    std::cout << b.size() << '\n';
    std::cout << b.pop() << '\n';

    std::cout << "FIN\n";
}