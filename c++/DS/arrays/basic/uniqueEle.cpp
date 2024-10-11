#include <iostream>
using namespace std;

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{

    int a[] = {1, 2, 3, 4, 4, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    int ans = 0;

    cout << "Array: ";
    print(a, n);

    for (int i = 0; i < n; i++)
    {
        //  XOR - xor operation on same elements is 0
        // thus using xor property, we are gonna find
        // unique element

        ans = ans ^ a[i];
    }

    cout << "Unique element : " << ans << endl;

    return 0;
}