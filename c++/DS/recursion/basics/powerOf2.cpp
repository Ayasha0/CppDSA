#include <iostream>
using namespace std;

// 2^3 = 2 * 2 * 2
// 2^3 = 2 * 2^2
// 2^n = 2 * 2^n-1
// power(n) = 2 * power(n - 1)

int power(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }

    // recursive relation
    return 2 * power(n - 1);
}

int main()
{

    int n;
    cout << "n: ";
    cin >> n;

    cout << power(n);

    return 0;
}