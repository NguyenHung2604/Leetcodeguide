#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = prices[0];
    int profit = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        if(prices[i] < buy)
        {
            buy = prices[i];
        }
        else if(prices[i] - buy > profit)
        {
            profit = prices[i] - buy;
        }
    }
    return profit;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << maxProfit(v);
    return 0;
}