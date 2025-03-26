#include <iostream>
#include <vector>

using namespace std;




int min_ignore_negative1(int a, int b)
{
    if(a == -1) return b;
    if(b == -1) return a;
    return min(a, b);
}
vector <int> memo(2000, -1); 
int coinChange(vector<int>& coins, int amount) {
    if(memo[amount] != -1) return memo[amount];
    if(amount == 0) return 0;
    
    int ans = INT_MAX;

    for(int coin : coins)
    {
        int subproblem = amount - coin;
        
        if(subproblem < 0)
        {
            continue;
        }
        
        ans = min_ignore_negative1(ans, coinChange(coins, subproblem) + 1);
    }
    memo[amount] = (ans == INT_MAX) ? -1 : ans;
    return  memo[amount];
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
