#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int i = 0, n = nums.size();
    vector<int> ans;
    unordered_map<int,int> m;

    for(int i = 0; i < n; i++)
    {
        m[nums[i]] = i;
    }

    for(int i = 0; i < n; i++)
    {
        int x = nums[i];
        if(m[target - x] && m[target- x] != i)
        {
            ans.push_back(i);
            ans.push_back(m[target - x]);
            return ans;
        }
    }

    return ans;
}

vector<int> twoSum2(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
    {
        int x = target - nums[i];
        if(mp.find(x) != mp.end())
        {
            return {mp[x], i};
        }
        mp[nums[i]]= i;

    }

    return {};
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans = twoSum(v, x);
    for(int i : ans)
    {
        cout << i << ' ';
    }
    return 0;
    
}