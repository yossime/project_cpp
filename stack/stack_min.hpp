#pragma once

#include "stack.hpp"

class Stack_min
{
public:
    Stack_min(unsigned int capacity = 1024);
    ~Stack_min();
    void push(int data);
    int pop();
    unsigned int size();
    void remin();

private:
    bool is_full();
    bool is_empty();

private:
    Stack min;
    Stack data;
    int minimum;
};