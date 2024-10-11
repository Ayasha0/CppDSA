#include <iostream>
using namespace std;

/*
1  2  3  4  5
1  2  3  4  5
1  2  3  4  5
1  2  3  4  5
1  2  3  4  5
*/
void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << "  ";
        }
        cout << endl;
    }
}

/*
 * * * * *
 * * * *
 * * *
 * *
 *

 */

void print2(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
 *
 * *
 * * *
 * * * *
 * * * * *
 */
void print3(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
 */
void print4(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
 */
void print5(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*

        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *

 */
void print6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*

* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *

 */
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < ((2 * n) - (2 * i + 1)); j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*

        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *

*/
void print8(int n)
{
    print6(n);
    print7(n);
}

/*

*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*

*/
void print9(int n)
{

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;

    print9(n);

    return 0;
}
