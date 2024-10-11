#include <iostream>
#include <string>
using namespace std;

void sayDigit(int n, string arr[])
{
    // base case
    if (n == 0)
        return;

    int digit = n % 10;
    n /= 10;

    // recursive call
    sayDigit(n, arr);

    cout << arr[digit] << " ";
}

int main()
{

    int n;
    cout << "n : ";
    cin >> n;

    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayDigit(n, arr);

    return 0;
}