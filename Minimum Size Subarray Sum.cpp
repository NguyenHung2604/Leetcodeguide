#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    
    int l = 0, m = INT_MAX;
    int sum = 0;
    for(int r = 0; r < nums.size(); r++)
    {
        sum += nums[r];
        while(sum >= target)
        {
            m = min(m, r - l + 1);
            sum -= nums[l];
            l++;
        }
    }

    return (m == INT_MAX) ? 0 : m;
   
}



int main() {
    int n, t;
    cin >> n >> t;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << minSubArrayLen(t,v);
    return 0;
}