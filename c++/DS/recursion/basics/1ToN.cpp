#include <iostream>
using namespace std;

void print(int n)
{
    // base case
    if (n == 0)
        return;

    // recursive call
    print(n - 1);

    // to do
    cout << n << endl;
}

int main()
{

    int n;
    cout << "n: ";
    cin >> n;

    print(n);

    return 0;
}