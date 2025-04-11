#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 2) return 2;
    int j = 1;
    int count = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == nums[i - 1])
        {
            count++;
        }
        else{
            count = 1;
        }


        if(count <= 2)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << removeDuplicates(v) << endl;
    
    for(int i : v)
    {
        cout << i << ' ';
    }
    return 0;
}