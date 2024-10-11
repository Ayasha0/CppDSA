#include <iostream>
using namespace std;

int sum(int a[], int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return a[0];

    return a[0] + sum(a + 1, size - 1);
}

int main()
{

    int a[] = {1, 2, 3, 4, 5};
    int size = 5;

    cout << sum(a, size);

    return 0;
}