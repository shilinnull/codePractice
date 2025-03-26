#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;


int main()
{
    int a[10] = { 1,2,3,4,5,6 };
    for (auto& e : a) {
        cout << e << " ";
    }

    return 0;
}