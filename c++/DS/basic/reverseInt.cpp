#include <iostream>
#include <limits.h>
using namespace std;

//  LEETCODE Q's : 7. REVERSE INTEGER

// Given a signed 32-bit integer n, return n with its digits reversed.
// If reversing n causes the value to go outside the signed 32-bit integer
// range [-231, 231 - 1], then return 0.

int reverseInt(int n)
{

    int rev = 0;

    while (n != 0)
    {

        int digit = n % 10;

        // condition for the constraint given
        // if rev * 10 > INT_MAX then it is out of range
        // also rev * 10 > INT_MAX  = rev > INT_MAX / 10
        // same goes for rev < INT_MIN / 10
        if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10))
        {
            return 0;
        }

        rev = (rev * 10) + digit;
        n /= 10;
    }
    return rev;
}

int main()
{

    int n;
    cout << "n: ";
    cin >> n;

    cout << n << " : " << reverseInt(n) << endl;

    return 0;
}