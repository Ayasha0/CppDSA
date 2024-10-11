#include <iostream>
using namespace std;

int pow(int powOf, int i)
{
    int ans = 1;
    for (int j = 1; j <= i; j++)
    {
        ans = ans * powOf;
    }
    return ans;
}

int decimalToBinary(int n)
{
    int res = 0;
    int i = 0;
    while (n != 0)
    {

        int bit = n & 1;
        res = (bit * pow(10, i)) + res;
        n = n >> 1;

        i++;
    }

    return res;
}

int main()
{

    int n;
    cout << "n: ";
    cin >> n;

    cout << n << " in binary : " << decimalToBinary(n) << endl;

    return 0;
}