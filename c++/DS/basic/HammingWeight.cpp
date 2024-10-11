#include <iostream>
using namespace std;

// function that takes the binary representation of a positive integer 
// and returns the number of set bits it has 
// (also known as the Hamming weight).

 
int HammingWeight(int n)
{

    int count = 0;

    while (n != 0)
    {

        if (n & 1)
        {
            count++;
        }

        n = n >> 1;
    }
    return count;
}

int main()
{

    int n;
    cout << "n: ";
    cin >> n;

    cout << HammingWeight(n) << endl;

    return 0;
}