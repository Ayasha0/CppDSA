#include <iostream>
#include <algorithm>

using namespace std;

// Brute force method
bool pairSum(int arr[], int size, int n)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == n)
            {
                return true;
            }
        }
    }
    return false;
}

// two pointers approach
bool twoPointer(int arr[], int size, int n)
{

    cout << "original array : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }

    // sort the elements
    sort(arr, arr + size);

    cout << endl
         << "sorted array:   ";
    for (int i = 0; i < size; i++)
    
    {
        cout << arr[i] << "   ";
    }

    int lp, rp;

    lp = 0;
    rp = size - 1;

    while (lp < rp)
    {
        if (arr[lp] + arr[rp] == n)
        {
            return 1;
        }
        else if (arr[lp] + arr[rp] < n)
        {
            lp++;
        }
        else
        {
            rp--;
        }
    }
    return 0;
}

int main()
{

    int arr[] = {0, -1, 2, -3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int num = 2;

    if (twoPointer(arr, size, num))
    {
        cout << endl
             << "pair sum exists" << endl;
    }
    else
    {
        cout << endl
             << "pair sum does not exist" << endl;
    }

    return 0;
}
