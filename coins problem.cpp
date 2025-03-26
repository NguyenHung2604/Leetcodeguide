#include <iostream>
#include <vector>

using namespace std;




int min_ignore_negative1(int a, int b)
{
    if(a == -1) return b;
    if(b == -1) return a;
    return min(a, b);
}

int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    
    int ans = -1;

    for(int coin : coins)
    {
        int subproblem = amount - coin;
        
        if(subproblem < 0)
        {
            continue;
        }
        
        ans = min_ignore_negative1(ans, coinChange(coins, subproblem) + 1);
    }
    return ans;
}

int main()
{
    int m;
    cin >> m;
    vector <int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << coinChange(v, m);
}
