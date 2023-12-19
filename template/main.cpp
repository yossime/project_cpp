#include <iostream>
#include <unordered_set>
#include <vector>
#include <list>

#include "iteratoer.hpp"

#include "swap.hpp"
#include "generics.hpp"

template<int N>
struct Factorial {
    static const int value = Factorial<N - 1>::value * N;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};



template<typename T>
void print(T const* begin, T const* end)
{
    if (!begin ||!end) {
        return;
    }

    if (end <= begin) {
        return;
    }
    
    assert( begin < end );
    std::cout << *begin;

    while(++begin!= end) {
        std::cout << ", " << *begin;
    }

    std::cout << std::endl;
}


int main()
{



    std::cout << '\n' << Factorial<4>::value << '\n';


    int numbers[] = {1, 2, 3, 4, 5, 6};
    size_t const N = sizeof(numbers) / sizeof(numbers[0]);
    int squares[sizeof(numbers) / sizeof(numbers[0])] = {0};

    copy_if(numbers, numbers + N, squares, even, power2);
    print(numbers, numbers + N);
    print(squares, squares + N);


    copy_if(numbers, numbers + N, squares, even, square<int>);
    print(squares, squares + N);

    Power p3{3};
    std::cout << p3(2) << std::endl;
    std::cout << p3(4) << std::endl;

    copy_if(numbers, numbers + N, squares, odd, p3);
    print(squares, squares + N);

    copy_if(numbers, numbers + N, squares, odd, Power{5});
    print(squares, squares + N);

    double zz[] = {1.5, 2.4, 3.14, 10.1};
    copy_if(zz, zz + 4, zz, GreaterThan<double>{2.0}, Exponential<double>{2});
    print(zz, zz + 4);




    auto numbers = createVector<int, std::vector<int>>();
    auto dubeles = createVector<double, std::vector<double>>();
    auto node = createVector<double, std::vector<double>>();

    int firstDuplicate = findFirstDuplicate(numbers.begin(), numbers.end());
    std::cout << "First Duplicate: " << firstDuplicate << std::endl;

    double first = findFirstDuplicate(dubeles.begin(), dubeles.end());
    std::cout << "First Duplicate: " << first << std::endl;

    double firstDuplicateList = findFirstDuplicate(node.begin(), node.end());
    std::cout << "First Duplicate: " << firstDuplicateList << std::endl;
}






