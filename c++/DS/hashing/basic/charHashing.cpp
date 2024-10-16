#include <iostream>
#include <string>
using namespace std;

int main()
{

    // for lowercase
    string s;
    cin >> s;

    // precompute
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        char c;
        cin >> c;

        // fetch
        cout << c << ": " << hash[c - 'a'] << endl;
    }

    return 0;
}