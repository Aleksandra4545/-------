#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArray(int (&arr)[10])
{
    for (auto &x : arr)
    {
        x = rand() % 100;
    }
}

