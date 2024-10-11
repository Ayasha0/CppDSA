#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{

    int mini = prices[0];
    int maxProfit = 0;

    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}

int buy(vector<int> &prices)
{

    int mini = prices[0];
    int maxProfit = 0;

    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }

    return mini;
}

int sell(vector<int> &prices)
{

    int mini = prices[0];
    int maxProfit = 0;
    int sell = 0;

    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        if (maxProfit == cost)
        {
            sell = prices[i];
        }
        mini = min(mini, prices[i]);
    }

    return sell;
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "buy : " << buy(prices) << endl;
    cout << "sell : " << sell(prices) << endl;
    cout << "max profit : " << maxProfit(prices) << endl;

    return 0;
}