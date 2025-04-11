#include <iostream>
#include <vector>  
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> v;
    if(nums.size() == 1)
    {
        v.push_back(nums);
        return v;
    }

    
    for(int i = 0; i < nums.size(); i++)
    {   int n = nums[i];
        nums.erase(nums.begin() + i);
       

        // goi de quy de sinh hoan vi
        vector<vector<int>> perms = permute(nums);

        for(vector<int> i : perms)
        {
            i.push_back(n);
            v.push_back(i);
        }
        
        nums.insert(nums.begin() + i, n);
        
    }
    return v;

}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<vector<int>> ans = permute(v);
    for(const auto &x : ans)
    {
        for(int i : x)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}