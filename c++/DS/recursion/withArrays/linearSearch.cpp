#include <iostream>
using namespace std;

bool linearSearch(int a[], int size, int ele)
{
    // base case
    if (size == 0)
        return false;

    if (a[0] == ele)
        return true;

    // recursive call
    linearSearch(a + 1, size - 1, ele);
}

int main()
{

    int a[] = {1, 2, 3, 4, 5};
    int size = 5;

    cout << linearSearch(a, size, 3);

    return 0;
}