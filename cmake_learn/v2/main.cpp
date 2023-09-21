#include <iostream>
#include "calc.hpp"

using namespace std;

int main()
{
    int a = 10, b = 2;
    cout << a << " + " << b << " = " << add(a, b) << "\n";
    cout << a << " - " << b << " = " << sub(a, b) << "\n";
    cout << a << " * " << b << " = " << mul(a, b) << "\n";
    cout << a << " / " << b << " = " << div_(a, b) << "\n";
    return 0;
}