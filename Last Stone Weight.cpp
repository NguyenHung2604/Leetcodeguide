#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;

    for(int i = 0; i < stones.size(); i++)
    {
        pq.push(stones[i]);
    }  
    
    while(pq.size() > 1)
    {
        int st1 = pq.top();
        pq.pop();
        int st2 = pq.top();
        pq.pop();
        if(st1 != st2)
        {
            pq.push(st1 - st2);
        }
    }
    return pq.empty() ? 0 : pq.top();
}

int main()
{
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << lastStoneWeight(v);
}