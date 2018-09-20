#include <string>
#include <iostream>

template <typename T>
void    iter(T *array, int length, void (*g)(T const &))
{
    if (array)
        for (int i = 0 ; i < length; i += 1)
            g(array[i]);
    return ;
}

template <typename T>
void    printElement(T const &element)
{
    std::cout << element << ", ";
    return ;
}

int main(void)
{
    float         numbers[] = {4, 8, 12, 16, 20, 24};
    std::string names[] = {"Jayn", "Tom", "Merlyn", "Saharah", "Sam", "YOooooooo"};

    std::cout << "Names   : ";
    iter(names, 6, printElement);
    std::cout << std::endl;

    std::cout << "Numbers : ";
    iter <float>(numbers, 6, printElement);
    std::cout << std::endl;

    return (0);
}