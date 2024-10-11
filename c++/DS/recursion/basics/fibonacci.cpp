#include <iostream>
using namespace std;

// using for loop
void fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << sum << " ";
        a = b;
        b = sum;
        sum = a + b;
    }
}

// recursive fibonacci
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main()
{

    int n;
    cout << "n: ";
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        cout << i << " : " << fib(i) << endl;
    } 

    return 0;
}