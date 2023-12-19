#include "stack_min.hpp"
#include "stack.hpp"
#include <iostream>
#include <cassert>
#include <limits>

Stack_min::Stack_min(unsigned int capacity) // ctor
    : min{capacity}, data{capacity}, minimum{std::numeric_limits<int>::max()}
{
}

Stack_min::~Stack_min() // dtor
{
    data.~Stack();
    min.~Stack();

    std::cout << "Stack dtor for capacity " << '\n';
}

void Stack_min::push(int value)
{
    bool solve = data.push(value);
    if (solve && value <= minimum)
    {
        min.push(value);
        minimum = value;
    }
}

int Stack_min::pop()
{
    int renumber = data.pop();
    if (renumber == minimum)
    {
        min.pop();
        minimum = min.pop();
        min.push(minimum);
    }
    return renumber;
}

unsigned int Stack_min::size()
{
    return data.size();
}
void Stack_min::remin()
{
        std::cout << "min of stack is: " <<minimum<< '\n';

}
