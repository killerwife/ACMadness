#include <iostream>

struct Xmas
{
    int n;

    Xmas(int n) : n(n) {}

    const Xmas* operator[](int i) const
    {
        // Hello there, neighbour!
        return &this[i];
    }
};

int main(int argc, char **argv)
{
    Xmas array[] = {1, 2, 3};
    std::cout << __FUNCTION__ << " " << array[0][1]->n << std::endl;
    return 0;
}
