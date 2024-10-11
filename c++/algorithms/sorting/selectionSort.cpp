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

// STEP 1
// assume ith ele to be mini
// STEP 2
// in the second loop traverse for mini ele
// STEP 3
// in the end of 2nd loop swap mini, i
void selectionSort(int a[], int n)
{
    int mini = -1;

    // loop runs from 0 to n-2
    // coz it needs only n-1 runs to
    // complete sorting
    for (int i = 0; i <= n - 2; i++)
    {
        mini = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[mini])
            {
                mini = j;
            }
        }
        swap(a[mini], a[i]);
    }
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    selectionSort(a, n);

    print(a, n);

    return 0;
}