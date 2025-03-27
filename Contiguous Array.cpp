#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;


int findMaxLength(vector<int>&nums) {
    int n = nums.size();
    vector<int> mp(2*n + 1, -2);
    int count = 0, maxsize = 0;
    mp[n] = -1;
    for(int i = 0; i < nums.size(); i++)
    {
        count += (nums[i] == 0) ? -1 : 1;
        if(mp[count + n] >= -1)
        {
            maxsize = max(maxsize, i - mp[count + n]);
        }
        else{
        mp[count + n] = i;
        }
    }
    return maxsize;
}

int findMaxLength2(vector<int>& nums)
{   
    unordered_map <int, int> mp;
    mp[0] = -1;
    int count = 0, maxlen = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(mp.find(count) != mp.end())
        {
            maxlen = max(maxlen, i - mp[count]);
        }
        else{
            mp[count] = i;
        }
    }
    return maxlen;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << findMaxLength(v) << endl;
    cout << findMaxLength2(v);
    return 0;
}