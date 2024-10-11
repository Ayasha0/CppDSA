#include <iostream>
using namespace std;

void reverse(int a[], int start, int end)
{
    while (start <= end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        start++;
        end--;
    }
}

int main()
{

    int a[] = {1, 2, 3, 4, 5};
    int n = 5;

    reverse(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}