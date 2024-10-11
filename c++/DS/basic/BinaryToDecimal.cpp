#include <iostream>
using namespace std;

// custom made pow() function
int pow(int powOf, int i)
{
    int ans = 1;

    for (int j = 1; j <= i; j++)
    {
        ans *= powOf;
    }

    return ans;
}

int binaryToDecimal(int bi)
{

    int res = 0;
    int i = 0;

    while (bi != 0)
    {

        int bit = bi % 10;
        res += (pow(2, i) * bit);
        bi /= 10;

        i++;
    }

    return res;
}

int main()
{

    int n;
    cout << "n: ";
    cin >> n;

    cout << n << " : " << binaryToDecimal(n) << endl;

    return 0;
}