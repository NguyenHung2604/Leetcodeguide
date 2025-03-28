#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int n = nums.size();
    vector<int> pref(n);
    pref[0] = nums[0];
    for(int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + nums[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(pref[i] == k)
        {
            ans++;
        }
        if(mp.find(pref[i] - k) != mp.end())
        {
            ans += mp[pref[i] - k];
        }

        mp[pref[i]]++;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    cout << subarraySum(v, k);
}