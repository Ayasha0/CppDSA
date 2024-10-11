#include <iostream>
using namespace std;

// print 1 to n
void print1ToN(int i, int n)
{
    if (i > n)
        return;

    cout << i << endl;
    print1ToN(i + 1, n);
}

void printNTo1(int n)
{
    if (n == 0 )
    {
        return;
    }
    cout << n-- << endl;
    printNTo1(n);
}

int main()
{

    int n = 5;

    printNTo1(n);

    return 0;
}