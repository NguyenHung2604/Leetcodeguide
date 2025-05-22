#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
    {
        if(mp.find(nums[i]) == mp.end())
        {
            mp[nums[i]] = i;
        }
        else{
            if(abs(i - mp[nums[i]]) <= k)
            {
                return true;
            }
            else{
                mp[nums[i]] = i;
                continue;
            }
        }
        
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << containsNearbyDuplicate(v, k);
    return 0;
}