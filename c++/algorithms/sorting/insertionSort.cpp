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

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && a[j - 1] > a[j])
        {
            swap(a[j], a[j - 1]);

            j--;
        }
    }
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertionSort(a, n);

    print(a, n);

    return 0;
}