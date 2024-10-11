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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// pushes the max ele to last by adjacent swaps

// OPTIMIZATION
// if the 2nd loop does not performed any swaps 
// that means the array is already sorted 
// so, we can come out of the loop
// coz it is sorted

// below u can check this using UNCOMMENTING the
// print statement

void bubbleSort(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            break;

        // cout << "runs\n";
    }
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bubbleSort(a, n);

    print(a, n);

    return 0;
}