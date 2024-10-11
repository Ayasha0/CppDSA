#include <iostream>
using namespace std;

int min(int a, int b)
{
    return a > b ? a : b;
}

// brute force
int gcd3(int n1, int n2)
{
    int gcd = 1;

    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

// optimized solution
int gcd2(int n1, int n2)
{
    for (int i = min(n1, n2); i >= 1; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            return i;
        }
    }
    return 1;
}

// euclidean algorithm
int gcd1(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    if (a == 0)
        return b;
    else
        return a;
}

int main()
{

    int n1, n2;
    cout << "n1, n2 : ";
   
    cin >> n1 >> n2;

    cout << gcd1(n1, n2);

    return 0;
}