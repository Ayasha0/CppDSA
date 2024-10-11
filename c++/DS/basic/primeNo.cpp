#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "n: ";
    cin >> n;

    if (n == 1)
    {
        cout << "neither prime nor composite" << endl;
    }
    else
    {

        bool isPrime = 1;

        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if (isPrime == 1)
        {
            cout << "is Prime Number" << endl;
        }
        else
        {
            cout << "is not a Prime Number" << endl;
        }
    }

    return 0;
}