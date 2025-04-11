#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map <int, int> mp;
int removeElement(vector<int>& nums, int val) {
    int id = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != val)
        {
            nums[id] = nums[i];
            id++;
        }
    }
    return id;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x; 
        cin >> x;
        v.push_back(x);
    }

    cout << removeElement(v, x);
    return 0;
}