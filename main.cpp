#include <iostream>
#include <memory>
#include <vector>
using namespace std;

double multiply(double x, void (*func)(double))
{
    double result;
    result = x * 2;
    (*func)(result);
    return result;
}

void printResult(double x)
{
    cout << "The result is " << x << endl;
}

typedef double arith_f(double);
typedef arith_f* arith_p;

int main()
{
    void (*printCallback)(double);
    printCallback = &printResult;
    multiply(5, printCallback);
    return 0;
}
