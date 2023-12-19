#include "stack.hpp"
#include <iostream>
#include <cassert>

Stack::Stack(unsigned int capacity)  // ctor
: m_capacity{capacity}
, m_tos{}  //  MIL
, m_elements{new int[m_capacity]}
{
    std::cout << "Stack ctor for capacity " << m_capacity << '\n';
}

Stack::~Stack()  // dtor
{
    delete[] m_elements;
    std::cout << "Stack dtor for capacity " << m_capacity << '\n';
}

bool Stack::push(int value) 
{
    if (!is_full()){
        m_elements[m_tos++] = value;
        return 1;
    }
    return 0;
}

int Stack::pop() 
{
    assert(!is_empty());
    return m_elements[--m_tos];
}

unsigned int Stack::size()
{
    return m_tos;
}

bool Stack::is_empty()
{
    return m_tos == 0;
}

bool Stack::is_full(){
    return m_tos == m_capacity;
}