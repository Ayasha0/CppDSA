#include <iostream>
using namespace std;

void reversePrint(int n)
{
    // base case
    if (n == 0)
        return;   

    // to do
    cout << n << endl;

    // recursive call
    reversePrint(n - 1);
}

int main()
{

    int n;
    cout << "n: ";
    cin >> n;

    reversePrint(n);

    return 0;
}