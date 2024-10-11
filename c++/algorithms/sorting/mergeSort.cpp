#include <iostream>
#include <vector>
using namespace std;

void print(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void merge(int v[], int low, int mid, int high)
{
    int an = mid - low + 1;
    int bn = high - mid;

    int a[an];
    int b[bn];

    for (int i = 0; i < an; i++)
    {
        a[i] = v[low + i];
    }
    for (int i = 0; i < bn; i++)
    {
        b[i] = v[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < an && j < bn)
    {
        if (a[i] < b[j])
        {
            v[k++] = a[i++];
        }
        else
        {
            v[k++] = b[j++];
        }
    }

    while (i < an)
    {
        v[k++] = a[i++];
    }
    while (j < bn)
    {
        v[k++] = b[j++];
    }

    cout << "a : ";
    print(a, an);
    cout << "b : ";
    print(b, bn);
}

// void merge2(vector<int> &v, int low, int mid, int high)
// {

//     vector<int> temp;

//     int left = low;
//     int right = mid + 1;

//     while (left <= mid && right <= high)
//     {

//         if (v[left] <= v[right])
//         {
//             temp.push_back(v[left]);
//             left++;
//         }
//         else
//         {
//             temp.push_back(v[right]);
//             right++;
//         }
//     }

//     while (left <= mid)
//     {
//         temp.push_back(v[left]);
//         left++;
//     }
//     while (right <= high)
//     {
//         temp.push_back(v[right]);
//         right++;
//     }

//     // print(v);
//     // print(temp);
//     // for (int i = low; i <= high; i++)
//     // {
//     //     v[i] = temp[i - low];
//     // }
// }

void mergeSort(int v[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);

    merge(v, low, mid, high);
}

int main()
{

    int v[] = {3, 1, 2, 4, 5, 2, 6, 4};
    int n = 8;
    mergeSort(v, 0, n - 1);
    cout << "sorted : ";
    print(v, n);

    return 0;
}