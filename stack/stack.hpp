#pragma once

class Stack
{
public:
    Stack(unsigned int capacity = 1024);
    ~Stack();
    bool push(int data);
    int pop();
    unsigned int size();

private:
    bool is_full();
    bool is_empty();

private:
    unsigned int const m_capacity;
    unsigned int m_tos;
    int *m_elements;
};

