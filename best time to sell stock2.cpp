#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = prices[0];
    
    int maximum = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        if(buy < prices[i])
        {
            maximum += prices[i] - buy;
        }
        
        buy = prices[i];
    }
    return maximum;
}

int maxProfit2(vector<int> &v)
{
    int maximum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i+1] - v[i] > 0)
        {
            maximum += v[i+1] - v[i];
        }
    }

    return maximum;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << maxProfit(v) << endl;
    cout << maxProfit2(v) << endl;
    return 0;
}