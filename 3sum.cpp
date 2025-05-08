#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int i = 0;
    int j = nums.size() - 1; 
    vector<vector<int>> ans;   
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {   
        if(i != 0 && nums[i] == nums[i-1]) continue;

        if(nums[i] > 0) break;
        int j = i + 1;
        int k = n - 1;
        while(j < k)
        {
            if(nums[i] + nums[j] + nums[k] == 0)
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                k--;
                j++;
                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
            else if(nums[i] + nums[j] + nums[k] < 0)
            {
                j++;
            }
            else{
                k--;
            }
            
        }
        return ans;
}

   

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> ans = threeSum(v);
    for(auto it : ans)
    {
        for(int i : it)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}